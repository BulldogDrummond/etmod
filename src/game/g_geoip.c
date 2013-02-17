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
#include "g_mysql.h"

// Return IPv4 Address without port
char *GeoIP_addr_clean(const char *addr)
{
    char *cl_addr = "0.0.0.0";
    char *sep     = strstr(addr, ":");
    int  sep_pos  = sep - addr;

    if (sep_pos)
    {
        cl_addr = strndup(addr, sep_pos);
    }
    else
    {
        cl_addr = "0.0.0.0";
    }
    return cl_addr;
}

// Return GeoIP database-friendly IP integer
unsigned long GeoIP_addr_int(const char *addr)
{
    unsigned long ip_int = 0;
    unsigned int  c1, c2, c3, c4;

    sscanf(addr, "%d.%d.%d.%d", &c1, &c2, &c3, &c4);
    ip_int = (unsigned long) c4 + (c3 * 256) + (c2 * 256 * 256) + (c1 * 256 * 256 * 256);

    return ip_int;
}

char *GeoIP_country(const char *addr)
{
    trap_Cvar_Set("g_country", G_DB_GeoIPCountry(GeoIP_addr_int(GeoIP_addr_clean(addr))));
    return G_DB_GeoIPCountry(GeoIP_addr_int(GeoIP_addr_clean(addr)));
}
