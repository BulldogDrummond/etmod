#define NO_OPTIMIZATIONS

#include "cg_local.h"
#include "etmodc.h"

void CG_Shutdown(void);

// yada - log to file
static FILE *crashLog=NULL;

void Crash_Printf(const char *fmt, ...){
	va_list	argptr;
	char		text[1024];

	va_start(argptr,fmt);
	Q_vsnprintf(text,sizeof(text),fmt,argptr);
	va_end(argptr);

	if(crashLog) fputs(text,crashLog);
	trap_Print(text);
}

#include <string.h>
#include <unistd.h>
#include <execinfo.h>
#define __USE_GNU
#include <link.h>
#include <sys/ucontext.h>
#include <signal.h>
#include <features.h>

#if __GLIBC__ == 2 && __GLIBC_MINOR__ == 1
#define GLIBC_21
#endif

extern char *strsignal (int __sig) __THROW;

//use sigaction instead.
__sighandler_t INTHandler (int signal, struct sigcontext ctx);
void CrashHandler(int signal, siginfo_t *siginfo, ucontext_t *ctx);
void (*OldHandler)(int signal);
struct sigaction oldact[NSIG];


int segvloop = 0;

void installcrashhandler() {

	struct sigaction act;

	memset(&act, 0, sizeof(act));
	memset(&oldact, 0, sizeof(oldact));
	act.sa_sigaction = (void *)CrashHandler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;

	sigaction(SIGSEGV, &act, &oldact[SIGSEGV]);
	sigaction(SIGILL, &act, &oldact[SIGILL]);
	sigaction(SIGFPE, &act, &oldact[SIGFPE]);
	sigaction(SIGBUS, &act, &oldact[SIGBUS]);

}

void restorecrashhandler() {
	sigaction(SIGSEGV, &oldact[SIGSEGV], NULL);
}

void installinthandler() {
	// Trap Ctrl-C
	signal(SIGINT, (void *)INTHandler);
}

void linux_siginfo(int signal, siginfo_t *siginfo) {
	Crash_Printf("Signal: %s (%d)\n", strsignal(signal), signal);
	Crash_Printf("Siginfo: %p\n", siginfo);
	if(siginfo) {
		Crash_Printf("Code: %d\n", siginfo->si_code);
		Crash_Printf("Faulting Memory Ref/Instruction: %p\n",siginfo->si_addr);
	}
}

// tjw: i'm disabling etpub_dsnoinfo() because it depends on
//      glibc 2.3.3 only  (it also won't build on earlier glibc 2.3
//      versions).
//      We're only doing glibc 2.1.3 release builds anyway.
void linux_dsoinfo(void) {
	struct link_map *linkmap = NULL;
	ElfW(Ehdr)      * ehdr = (ElfW(Ehdr) *)0x08048000;
	ElfW(Phdr)      * phdr;
	ElfW(Dyn) *dyn;
	struct r_debug *rdebug = NULL;

	phdr = (ElfW(Phdr) *)((char *)ehdr + ehdr->e_phoff);

	while (phdr++<(ElfW(Phdr) *)((char *)phdr + (ehdr->e_phnum * sizeof(ElfW(Phdr)))))
		if (phdr->p_type == PT_DYNAMIC)
			break;

	for (dyn = (ElfW(Dyn) *)phdr->p_vaddr; dyn->d_tag != DT_NULL; dyn++)
		if (dyn->d_tag == DT_DEBUG) {
			rdebug = (void *)dyn->d_un.d_ptr;
			break;
		}

		linkmap = rdebug->r_map;

		//rewind to top item.
		while(linkmap->l_prev)
			linkmap=linkmap->l_prev;

		Crash_Printf("DSO Information:\n");

		while(linkmap) {

			if(linkmap->l_addr) {

				if(strcmp(linkmap->l_name,"")==0)
					Crash_Printf("0x%08x\t(unknown)\n", linkmap->l_addr);
				else
					Crash_Printf("0x%08x\t%s\n", linkmap->l_addr, linkmap->l_name);

			}

			linkmap=linkmap->l_next;

		}
}

void linux_backtrace(ucontext_t *ctx) {

	// See <asm/sigcontext.h>

	// ctx.eip contains the actual value of eip
	// when the signal was generated.

	// ctx.cr2 contains the value of the cr2 register
	// when the signal was generated.

	// the cr2 register on i386 contains the address
	// that caused the page fault if there was one.

	int i;

	char **strings;
	void *array[1024];
	size_t size = (size_t)backtrace(array, 1024);

	//Set the actual calling address for accurate stack traces.
	//If we don't do this stack traces are less accurate.
#ifdef GLIBC_21
	Crash_Printf("Stack frames: %Zd entries\n", size-1);
#ifndef __x86_64__
	array[1] = (void *)ctx->uc_mcontext.gregs[EIP];
#else
	array[1] = (void *)ctx->uc_mcontext.gregs[RIP];
#endif
#else
	Crash_Printf("Stack frames: %zd entries\n", size-1);
#ifndef __x86_64__
	array[1] = (void *)ctx->uc_mcontext.gregs[REG_EIP];
#else
	array[1] = (void *)ctx->uc_mcontext.gregs[REG_RIP];
#endif
#endif
	Crash_Printf("Backtrace:\n");

	strings = (char **)backtrace_symbols(array, (int)size);

	//Start at one and climb up.
	//The first entry points back to this function.
	for (i = 1; i < (int)size; i++)
		Crash_Printf("(%i) %s\n", i, strings[i]);

	free(strings);
}

__sighandler_t INTHandler(int signal, struct sigcontext ctx) {
	CG_Printf("------------------------------------------------\n");
	CG_Printf("Ctrl-C is not the proper way to kill the server.\n");
	CG_Printf("------------------------------------------------\n");
	return 0;
}

void CrashHandler(int signal, siginfo_t *siginfo, ucontext_t *ctx) {
	char gamepath[MAX_CVAR_VALUE_STRING];
	char homepath[MAX_CVAR_VALUE_STRING];

	//we are real cautious here.
	restorecrashhandler();

	if(signal == SIGSEGV)
		segvloop++;

	if(segvloop < 2) {
		// yada - try logging to disk too
		trap_Cvar_VariableStringBuffer("fs_homepath", homepath, sizeof(homepath));
		trap_Cvar_VariableStringBuffer("fs_game", gamepath, sizeof(gamepath));
		crashLog=fopen(va("%s/%s/etmodc_crash.log",homepath,gamepath),"w");

		Crash_Printf("-8<------- Crash Information ------->8-\n");
		Crash_Printf("     Please forward to etmod team.     \n");
		Crash_Printf("---------------------------------------\n");
		Crash_Printf("Version: %s Linux\n", ETMODC_VERSION);
		Crash_Printf("Map: %s\n",cgs.rawmapname);
		linux_siginfo(signal, siginfo);
		linux_dsoinfo();
		linux_backtrace(ctx);
		CG_Printf("-8<--------------------------------->8-\n\n");
		CG_Printf("Attempting to clean up.\n");
		if(crashLog) fclose(crashLog);

		CG_Shutdown();
		//pass control to the default handler.
		if(signal == SIGSEGV) {
			OldHandler = (void *)oldact[SIGSEGV].sa_sigaction;
			(*OldHandler)(signal);
		} else {
			exit(1);
		}
	} else {
		//end this madness we are looping.
		CG_Error("Recursive segfault. Bailing out.");
		OldHandler = (void *)oldact[SIGSEGV].sa_sigaction;
		(*OldHandler)(signal);
	}

	return;

}

void EnableCoreDumps() {

}

void DisableCoreDump() {

}

void EnableStackTrace() {
	installcrashhandler();
}

void DisableStackTrace() {
	restorecrashhandler();
}

