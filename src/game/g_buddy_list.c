/*********************************************************
 * Project : ETMod
 *
 * File    : g_buddy_list.c
 * Desc    : Ignore list handling code
 *
 * Status  : Accepted
 *
 *********************************************************/

#include "g_local.h"

void G_RemoveFromAllIgnoreLists(int clientNum) {
    int i;

    for(i = 0; i < MAX_CLIENTS; i++) {
        COM_BitClear(level.clients[i].sess.ignoreClients, clientNum);
    }
}

