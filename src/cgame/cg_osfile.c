/*
 * cg_osfile.c
 *
 * This code is taken from No Quarter. All credits go to their team especially Lucel!
 * http://shitstorm.org
 *
 * pheno: small modifications are done
 *
 */

#include "cg_osfile.h"
#include <errno.h>

char* CG_BuildFilePath(char const* path, char const* file, char const* ext, char* dest, int destsz)
{
	int pathsz = strlen(path);

	// Wipe the destination string
	dest[0] = 0;

	// Add the path
	Q_strcat(dest, destsz, path);
	if ( pathsz && !(path[pathsz-1] == '\\' || path[pathsz-1] == '/') )
	Q_strcat(dest, destsz, "/");

	// Add the file
	Q_strcat(dest, destsz, file);

	// Add the extension
	Q_strcat(dest, destsz, ext);

	return dest;
}

qboolean CG_IsFile(char const* path)
{
	struct stat	sb;
	int			result	= stat(path, &sb);
	if ( -1 == result || sb.st_mode & S_IFDIR )
		return qfalse;
	return qtrue;
}

qboolean CG_IsDirectory(char const* path)
{
	struct stat	sb;
	int			result	= stat(path, &sb);
	if ( -1 == result )
		return qfalse;
	if ( sb.st_mode & S_IFDIR )
		return qtrue;
	return qfalse;
}

void CG_IterateDirectory(char const* path, Fn_IterateDirectory handler)
{
	struct dirent*	dir;
	DIR*			handle;

	// Open the directory
	handle = opendir(path);
	if ( NULL == handle )
	{
		CG_Printf("CG_IterateDirectory: failed to open path: %s: %d\n", path, errno);
		return;
	}

	// Iterate over each file in the directory in turn calling the handler as we go...
	while ( (dir = readdir(handle)) )
	{
		char 		buf[MAX_PATH];
		qboolean	directory		= qfalse;

		// Skip current/previous directory files...
		if ( 0 == Q_strncmp(dir->d_name, ".", 1) ||
			 0 == Q_strncmp(dir->d_name, "..", 2) )
			continue;

		// Build the path...
		CG_BuildFilePath(path, dir->d_name, "", buf, MAX_PATH);

		// Directory?
		if ( dir->d_type == DT_DIR )
			directory = qtrue;

		// Call the handler with the details
		if ( qfalse == handler(dir->d_name, buf, directory) )
			// return qfalse to terminate processing
			break;
	}

	// Close the directory handle
	closedir(handle);
}

int CG_WriteDataToFile(char const* path, char const* data, int sz)
{
	// Open the file
	int fd = open(path, O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
	if ( -1 == fd )
	{
		CG_Printf("CG_WriteDataToFile: failed to open file: %s: %d\n", path, errno);
		return -1;
	}

	// Write the data
	if ( -1 == write(fd, data, sz) )
	{
		CG_Printf("CG_WriteDataToFile: failed to write data to file: %s: %d\n", path, errno);
		return -1;
	}

	// Close the file
	if ( -1 == close(fd) )
	{
		CG_Printf("CG_WriteDataToFile: failed to close file: %s: %d\n", path, errno);
		return -1;
	}

	// Success
	return 0;
}

int CG_ReadDataFromFile(char const* path, char* data, int sz)
{
	int		byte_count;

	// Open the file
	int fd = open(path, O_RDONLY, 0);
	if ( -1 == fd )
	{
		CG_Printf("CG_ReadDataFromFile: failed to open file: %s: %d\n", path, errno);
		return -1;
	}

	// Read the data
	byte_count = read(fd, data, sz);
	if ( byte_count != sz )
	{
		CG_Printf("CG_ReadDataFromFile: failed to read data from file (%d/%d): %s: %d\n", byte_count, sz, path, errno);
		return -1;
	}

	// Close the file
	if ( -1 == close(fd) )
	{
		CG_Printf("CG_ReadDataFromFile: failed to close file: %s: %d\n", path, errno);
		return -1;
	}

	// Success
	return 0;
}

qboolean CG_DeleteFile(char const* path)
{
	return (-1 == unlink(path) ? qfalse : qtrue);
}

qboolean CG_RenameFile(char const* src, char const* dest)
{
	return (rename(src, dest) == 0 ? qtrue : qfalse);
}

