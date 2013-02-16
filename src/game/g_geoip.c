/*********************************************************
 * Project : ETMod
 *
 * File    : geoip.c
 * Desc    : Modified version of GeoIP API (simplified)
 *
 * Status  : Accepted
 *
 *********************************************************/

#include "g_local.h"

GeoIP *gidb = NULL;

// Return IPv4 Address without port
char *GeoIP_addr_clean(const char *addr)
{
    char          *cl_addr = "0.0.0.0";
    char          *sep = strstr(addr, ":");
    int           sep_pos = sep - addr;

    if (sep_pos) {
        cl_addr = strndup(addr, sep_pos);
    } else {
        cl_addr = "0.0.0.0";
    }
    return cl_addr;
}

// Return GeoIP database-friendly IP integer
unsigned long GeoIP_addr_int(const char *addr)
{
    unsigned long ip_int = 0;
    unsigned int c1,c2,c3,c4;

    sscanf(addr, "%d.%d.%d.%d", &c1, &c2, &c3, &c4);
    ip_int = (unsigned long) c4 + (c3 * 256) + (c2 * 256 * 256) + (c1 * 256 * 256 * 256);

    return ip_int;
}

unsigned long GeoIP_addr_to_num(const char *addr)
{
    int           i;
    char          tok[4];
    int           octet;
    int           j     = 0, k = 0;
    unsigned long ipnum = 0;
    char          c     = 0;

    G_Printf("GeoIP Address  : %s\n", GeoIP_addr_clean(addr));
    G_Printf("GeoIP Int Addr : %lu\n", GeoIP_addr_int(GeoIP_addr_clean(addr)));

    for (i = 0; i < 4; i++)
    {
        for (;; )
        {
            c = addr[k++];
            if (c == '.' || c == ':' || c == '\0')
            {
                tok[j] = '\0';
                octet  = atoi(tok);
                if (octet > 255)
                {
                    return 0;
                }
                ipnum += (octet << ((3 - i) * 8));
                j      = 0;
                break;
            }
            else if (c >= '0' && c <= '9')
            {
                if (j > 2)
                {
                    return 0;
                }
                tok[j++] = c;
            }
            else
            {
                return 0;
            }
        }
        if (c == '\0' && i < 3)
        {
            return 0;
        }
    }
    return ipnum;
}

unsigned int GeoIP_seek_record(GeoIP *gi, unsigned long ipnum)
{

    int                 depth;
    unsigned int        x    = 0;
    unsigned int        step = 0;
    const unsigned char *buf = NULL;

    for (depth = 31; depth >= 0; depth--)
    {

        step = 6 * x;

        if (step + 6 >= gi->memsize)
        {
            G_Printf("GeoIP: Error Traversing Database for ipnum = %lu - Possible database corruption.\n", ipnum);
            return 255;
        }

        buf = gi->cache + step;

        if (ipnum & (1 << depth))
        {
            x = (buf[3] << 0) + (buf[4] << 8) + (buf[5] << 16);
        }
        else
        {
            x = (buf[0] << 0) + (buf[1] << 8) + (buf[2] << 16);
        }

        if (x >= 16776960)
        {
            return x - 16776960;
        }
    }

    G_Printf("GeoIP: Error Traversing Database for ipnum = %lu - Possible database corruption.\n", ipnum);
    return 255;
}

void GeoIP_open(void)
{

    // basically not necessary but to get sure we close a maybe existing database
    GeoIP_close();

    if (!g_countryFlags.integer)
    {
        return;
    }

    gidb = (GeoIP *)malloc(sizeof(GeoIP));

    if (gidb == NULL)
    {
        G_Printf("GeoIP: Memory allocation error for GeoIP struct\n");
        return;
    }

    gidb->memsize = trap_FS_FOpenFile("GeoIP.dat", &gidb->GeoIPDatabase, FS_READ);

    if ((int)gidb->memsize < 0)
    {
        G_Printf("GeoIP: Error opening database.\n");
        free(gidb);
        gidb = NULL;
        return;

    }
    else if (gidb->memsize == 0)
    {
        G_Printf("GeoIP: Error zero-sized database file.\n");
        trap_FS_FCloseFile(gidb->GeoIPDatabase);
        free(gidb);
        gidb = NULL;
        return;

    }
    else
    {
        gidb->cache = (unsigned char *) calloc(gidb->memsize + 1, sizeof(unsigned char));
        if (gidb->cache != NULL)
        {
            trap_FS_Read(gidb->cache, gidb->memsize, gidb->GeoIPDatabase);
            trap_FS_FCloseFile(gidb->GeoIPDatabase);
            return;
        }
        G_Printf("GeoIP: Memory allocation error for GeoIP cache.\n");
        trap_FS_FCloseFile(gidb->GeoIPDatabase);
        free(gidb);
        gidb = NULL;
        return;
    }
}

void GeoIP_close(void)
{
    if (gidb != NULL)
    {
        free(gidb->cache);
        gidb->cache = NULL;
        free(gidb);
        gidb = NULL;
    }
}
