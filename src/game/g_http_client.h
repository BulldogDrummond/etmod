/*********************************************************
 * Project : ETMod
 *
 * File    : g_http_client.h
 * Desc    : Web client declarations.
 *
 * Status  : Pending
 *
 *********************************************************/

#ifndef _G_HTTP_CLIENT_H
#define _G_HTTP_CLIENT_H

#include <netinet/in.h>

struct _http_client_t
{
    int fd;
    struct sockaddr_in addr;
};

enum
{
    METHOD_POST = 0,
    METHOD_GET
};

struct _http_client_t *
libhttpc_connect(char *address, int port);

int
libhttpc_send(struct _http_client_t *client,
              char *host, char *location, int method,
              char *buffer, int len);

int
libhttpc_send_multiple(struct _http_client_t *client,
                       char *host, char *location, int method,
                       char **buffers, int *lens, int buffercount);

int
libhttpc_close(struct _http_client_t *client);

void *libhttpc_post(void *post_args);
void *libhttpc_postmatch(void *post_args);

#endif
