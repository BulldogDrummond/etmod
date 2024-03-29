/*********************************************************
 * Project : ETMod
 *
 * File    : g_threads.c
 * Desc    : Thread handling code.
 *
 * Status  : Pending
 *
 *********************************************************/

#include "g_local.h"
#include "q_shared.h"

#include <gnu/lib-names.h>

#include <pthread.h>
#include <dlfcn.h>

// tjw: handle for libpthread.so
void *g_pthreads = NULL;

// tjw: pointer to pthread_create() from libpthread.so
static int (*g_pthread_create)
(pthread_t *,
 __const pthread_attr_t *,
 void * (*)(void *),
 void *) = NULL;

void G_InitThreads(void)
{
    if (g_pthreads != NULL)
    {
        G_Printf("pthreads already loaded\n");
        return;
    }
    g_pthreads = dlopen(LIBPTHREAD_SO, RTLD_NOW);
    if (g_pthreads == NULL)
    {
        G_Printf("could not load libpthread\n%s\n",
                 dlerror());
        return;
    }
    G_Printf("loaded libpthread\n");
    g_pthread_create = dlsym(g_pthreads, "pthread_create");
    if (g_pthread_create == NULL)
    {
        G_Printf("could not locate pthread_create\n%s\n",
                 dlerror());
        return;
    }
    G_Printf("found pthread_create\n");
}

int
create_thread(void *(*thread_function)(void *), void *arguments)
{
    pthread_t thread_id;

    if (g_pthread_create == NULL)
    {
        // tjw: pthread_create() returns non 0 for failure
        //      but I don't know what's proper here.
        return -1;
    }
    return g_pthread_create(&thread_id, NULL, thread_function, arguments);
}
