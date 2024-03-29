/*********************************************************
 * Project : ETMod
 *
 * File    : g_sha1.c
 * Desc    : Sha-1 handling code.
 *
 * Status  : Pending
 *
 *********************************************************/

#include "g_local.h"
#include "g_sha1.h"

char *G_SHA1(char *string)
{
    SHA1Context sha;

    SHA1Reset(&sha);
    SHA1Input(&sha, (const unsigned char *)string, strlen(string));

    if (!SHA1Result(&sha))
    {
        G_Error("sha1: could not compute message digest");
        return "";
    }
    else
    {
        return va("%08X%08X%08X%08X%08X",
                  sha.Message_Digest[0],
                  sha.Message_Digest[1],
                  sha.Message_Digest[2],
                  sha.Message_Digest[3],
                  sha.Message_Digest[4]);
    }
}
