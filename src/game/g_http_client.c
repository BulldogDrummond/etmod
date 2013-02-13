/*********************************************************
 * Project : ETMod
 *
 * File    : g_http_client.c
 * Desc    : Web client code.
 *
 * Status  : Pending
 *
 *********************************************************/

#include "g_local.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "g_http_client.h"

int
_libhttpc_send(int fd, char *buf, int len);

void QDECL LogPrintf(const char *fmt, ...);
//bani
void QDECL LogPrintf(const char *fmt, ...) _attribute((format(printf, 1, 2)));

struct _http_client_t *
libhttpc_connect(char *address, int port)
{
    struct _http_client_t *client = 0;
    struct sockaddr_in    addr;
    int                   opt;
    int                   fd;

    if (!(address))
    {
        return 0;
    }

    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        LogPrintf("http_client.c: cannot create socket %d\n", errno);
        return 0;
    }

    addr.sin_family = AF_INET;
    if (!(inet_aton(address, &(addr.sin_addr))))
    {
        LogPrintf("http_client.c: invalid network address %s\n", address);
        close(fd);

        return 0;
    }

    addr.sin_port = htons(port);

    memset(&addr.sin_zero, 0, 8);

    opt = 1;

    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));

    fcntl(fd, F_SETFL, O_NONBLOCK);

    while ((connect(fd, (struct sockaddr *)&addr, sizeof(struct sockaddr)) == -1))
    {
        if (errno == EAGAIN)
        {
            usleep(1000);
            continue;
        }
        else if (errno == EINPROGRESS || errno == EALREADY)
        {
            usleep(500);
            continue;
        }
        else
        {
            LogPrintf("http_client.c: connection failed %d\n", errno);
            close(fd);

            return 0;
        }
    }
    fcntl(fd, F_SETFL, 0);

    if (g_debugHttpPost.integer)
    {
        LogPrintf("http_client.c: connected to %s:%d\n",
                  inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
    }

    client = (struct _http_client_t *)
             calloc(1, sizeof(struct _http_client_t));

    client->fd = fd;
    memcpy(&client->addr, &addr, sizeof(struct sockaddr_in));

    return client;
}

int
_libhttpc_send(int fd, char *buf, int len)
{
    int n;
    int count;

    if (!(buf) || !(len))
    {
        return -1;
    }

    count = 0;

    while (1)
    {
        n = send(fd, buf, len - count, MSG_DONTWAIT);

        if (n < 0)
        {
            if (errno == EAGAIN)
            {
                continue;
            }

            return -1;
        }
        else if (n == 0)
        {
            break;
        }
        else
        {
            count += n;

            if (count == len)
            {
                break;
            }
        }
    }

    return count;
}

int
libhttpc_send(struct _http_client_t *client,
              char *host, char *location, int method,
              char *buffer, int len)
{
    return libhttpc_send_multiple(client, host, location, method, &buffer, &len, 1);
}

int
libhttpc_send_multiple(struct _http_client_t *client,
                       char *host, char *location, int method,
                       char **buffers, int *lens, int buffercount)
{
    char header[4096];
    int  count = 0;
    int  totallen;
    int  i;

    if (!(client) || !(buffers) || !(lens) || !(buffers) || !(buffercount))
    {
        return -1;
    }

    totallen = 0;
    for (i = 0; i < buffercount; i++)
    {
        totallen += lens[i];
    }

    snprintf(header,
             sizeof(header),
             "POST /%s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "User-Agent: libhttpc\r\n"
             "Content-Length: %d\r\n"
             "Content-Type: text/plain\r\n\r\n",
             location, host, totallen);

    if (g_debugHttpPost.integer)
    {
        LogPrintf("http_client header: %s", header);
    }

    if (_libhttpc_send(client->fd, header, strlen(header)) == -1)
    {
        LogPrintf("http_client.c: failed to send header\n");
        return -1;
    }

    for (i = 0; i < buffercount; i++)
    {
        if (g_debugHttpPost.integer)
        {
            LogPrintf("http_client.c: sending buffer line: %i: %s\n", i, buffers[i]);
        }
        count += _libhttpc_send(client->fd, buffers[i], lens[i]);
    }

    if (g_debugHttpPost.integer)
    {
        LogPrintf("http_client.c: wrote %d bytes\n", count);
    }
    return 0;
}

int
libhttpc_close(struct _http_client_t *client)
{
    if (!(client))
    {
        return -1;
    }

    close(client->fd);

    free(client);

    return 0;
}

void *libhttpc_post(void *post_args)
{
    g_httpinfo_t          *post_info = (g_httpinfo_t *)post_args;
    struct _http_client_t *client;
    char                  *ip, *buf, *host, *location, *portstring;
    int                   port = 80, count = 0;
    struct hostent        *h;
    struct in_addr        addr;
    //struct addr_info *result;
    char *url     = &post_info->url[0];
    char *message = &post_info->message[0];
    char empty[]  = "";
    if (g_debugHttpPost.integer)
    {
        LogPrintf("HTTP POST: Original URL: %s\n", url);
    }

    // split url into raw IP and location
    buf = strsep(&url, "/");
    // buf = "http:"
    // url = "/server:port/location"
    buf = strsep(&url, "/");
    // buf = ""
    // url = "server:port/location"
    buf = strsep(&url, "/");
    // buf = "server:port"
    // url = "location"
    host       = strsep(&buf, ":");
    portstring = buf;
    location   = url;

    if (!location)
    {
        location = &empty[0];
    }

    if (portstring)
    {
        port = atoi(portstring);
    }

    if (g_debugHttpPost.integer)
    {
        LogPrintf("HTTP POST: host: %s:%d,"
                  " location: %s,"
                  " message %s\n",
                  host, port, location, message);
    }
    // end parsing

    h = gethostbyname(host);
    if (!h)
    {
        LogPrintf("http_client: Couldn't gethostbyname\n");
        free(post_info);
        return 0;
    }
    memcpy(&addr.s_addr, h->h_addr_list[0], sizeof(addr.s_addr));

    ip = inet_ntoa(addr);

    client = libhttpc_connect(ip, port);
    if (!client)
    {
        LogPrintf("http_client.c: cannot create client\n");
        return 0;
    }
    else
    {
        count = libhttpc_send(client, host, location, METHOD_POST,
                              message, strlen(message));
    }
    libhttpc_close(client);
    free(post_info);
    return 0;
}

#ifdef UNIT_TEST

int
main(int argc, char **argv)
{
    libhttpc_post(argv[1], argv[2]);
    return 0;
}

#endif

/*
=================
LogPrintf

Print to the logfile with a time stamp if it is open
Makes sure no threads are made inside here.
=================
*/
void QDECL LogPrintf(const char *fmt, ...)
{
    va_list argptr;
    char    string[1024];
    int     min, tens, sec, l;

    sec = level.time / 1000;

    // dvl - real time stamps
    if (g_logOptions.integer & LOGOPTS_REALTIME)
    {
        Com_sprintf(string, sizeof(string), "%s ", G_GetRealTime());
    }
    else
    {

        min  = sec / 60;
        sec -= min * 60;
        tens = sec / 10;
        sec -= tens * 10;
        Com_sprintf(string,
                    sizeof(string),
                    "%i:%i%i ",
                    min, tens, sec);
    }

    l = strlen(string);

    va_start(argptr, fmt);
    Q_vsnprintf(string + l, sizeof(string) - l, fmt, argptr);
    va_end(argptr);

    if (g_dedicated.integer)
    {
        G_Printf("%s", string + l);
    }

    if (!level.logFile)
    {
        return;
    }

    trap_FS_Write(string, strlen(string), level.logFile);

}

void *libhttpc_postmatch(void *post_args)
{
    g_http_matchinfo_t    *post_matchinfo = (g_http_matchinfo_t *)post_args;
    struct _http_client_t *client;
    char                  *ip, *buf, *host, *location, *portstring;
    int                   port = 80, count = 0;
    int                   line;
    struct hostent        *h;
    struct in_addr        addr;
    //struct addr_info *result;
    char *url    = &post_matchinfo->url[0];
    char empty[] = "";
    if (g_debugHttpPost.integer)
    {
        LogPrintf("HTTP POST: Original URL: %s\n", url);
    }

    // split url into raw IP and location
    buf = strsep(&url, "/");
    // buf = "http:"
    // url = "/server:port/location"
    buf = strsep(&url, "/");
    // buf = ""
    // url = "server:port/location"
    buf = strsep(&url, "/");
    // buf = "server:port"
    // url = "location"
    host       = strsep(&buf, ":");
    portstring = buf;
    location   = url;

    if (!location)
    {
        location = &empty[0];
    }

    if (portstring)
    {
        port = atoi(portstring);
    }

    if (g_debugHttpPost.integer)
    {
        LogPrintf("HTTP POST: host: %s:%d,"
                  " location: %s,"
                  " Multi-lines",
                  host, port, location); //,message);
    }
    // end parsing

    h = gethostbyname(host);
    if (!h)
    {
        LogPrintf("http_client: Couldn't gethostbyname\n");
        for (line = 0; line < post_matchinfo->num_lines; ++line)
        {
            free(post_matchinfo->info_lines[line]);
        }
        free(post_matchinfo->info_lines);
        free(post_matchinfo->info_lines_lengths);
        free(post_matchinfo);
        return 0;
    }
    memcpy(&addr.s_addr, h->h_addr_list[0], sizeof(addr.s_addr));

    ip = inet_ntoa(addr);

    client = libhttpc_connect(ip, port);
    if (!client)
    {
        LogPrintf("http_client.c: cannot create client\n");
        return 0;
    }
    else
    {
        for (line = 0; line < post_matchinfo->num_lines; line++)
        {
            post_matchinfo->info_lines_lengths[line] -= 1; // (-1) to ignore the null terminator; is safe to do here since we'll not use this again
        }

        count = libhttpc_send_multiple(client, host, location, METHOD_POST,
                                       post_matchinfo->info_lines, post_matchinfo->info_lines_lengths,
                                       post_matchinfo->num_lines);

        for (line = 0; line < post_matchinfo->num_lines; line++)
        {
            free(post_matchinfo->info_lines[line]);
        }
    }
    free(post_matchinfo->info_lines);
    free(post_matchinfo->info_lines_lengths);
    libhttpc_close(client);
    free(post_matchinfo);
    return 0;
}
// etded +set com_hunkmegs 256 +set sv_maxclients 64 +set fs_game etmod +set net_port 5123 +map oasis +set g_etmod_stats_id 0 +set g_tactics 1 +set g_warmup 10 +set g_log etserver.log +set g_logsync 1
