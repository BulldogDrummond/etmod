/*********************************************************
 * Project : ETMod
 *
 * File    : g_mysql.c
 * Desc    : Mysql database code.
 *
 * Status  : Pending
 *
 *********************************************************/

#ifdef FEATURE_MYSQL

#include "g_mysql.h"
#include <stdio.h>
#include <strings.h>

int G_DB_Ready()
{
    int db_ready;

    vmCvar_t dbTest;
    trap_Cvar_Register(&dbTest, "g_dbReady", "0", CVAR_SERVERINFO | CVAR_ROM);
    db_ready = dbTest.integer;

    return db_ready;
}

void G_DB_SetMap(char *server)
{
    char *dbhost;
    char *dbname;
    char *dbuser;
    char *dbpass;

    dbhost = g_dbHostname.string;
    dbname = g_dbDatabase.string;
    dbuser = g_dbUsername.string;
    dbpass = g_dbPassword.string;

    MYSQL *conn;

    char query[100];

    G_Printf("Setting Map to %s in database.\n", server);
    sprintf(query, "UPDATE server_status SET ss_val = \"%s\" WHERE ss_key = \"Current_Map\"", server);

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, dbhost, dbuser, dbpass, dbname, 0, NULL, 0))
    {
        G_Printf("Database Error: %s\n", mysql_error(conn));
    }
    else
    {
        if (mysql_query(conn, query))
        {
            G_Printf("Database Error: %s\n", mysql_error(conn));
        }
        else
        {
            mysql_close(conn);
        }
    }
    return;
}

void G_DB_ResetMap()
{
    char *dbhost;
    char *dbname;
    char *dbuser;
    char *dbpass;

    dbhost = g_dbHostname.string;
    dbname = g_dbDatabase.string;
    dbuser = g_dbUsername.string;
    dbpass = g_dbPassword.string;

    MYSQL *conn;

    char query[100];

    G_Printf("Resetting Map in database.\n");
    sprintf(query, "UPDATE server_status SET ss_val = \"None\" WHERE ss_key = \"Current_Map\"");

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, dbhost, dbuser, dbpass, dbname, 0, NULL, 0))
    {
        G_Printf("Database Error: %s\n", mysql_error(conn));
    }
    else
    {
        if (mysql_query(conn, query))
        {
            G_Printf("Database Error: %s\n", mysql_error(conn));
        }
        else
        {
            mysql_close(conn);
        }
    }
    return;
}

void G_DB_InitGameTest()
{
    G_Printf("------ Database Test ------\n");

    trap_Cvar_Set("g_dbReady", "0");

    int  use_db;
    char *dbhost;
    char *dbname;
    char *dbuser;
    char *dbpass;

    use_db = g_dbEnable.integer;

    dbhost = g_dbHostname.string;
    dbname = g_dbDatabase.string;
    dbuser = g_dbUsername.string;
    dbpass = g_dbPassword.string;

    MYSQL     *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    /* This tests that the database can be reached and login succeeds */
    if (use_db == 1)
    {
        conn = mysql_init(NULL);
        if (!mysql_real_connect(conn, dbhost, dbuser, dbpass, dbname, 0, NULL, 0))
        {
            G_Printf("Database Initialization Failed.\n");
            G_Printf("Database Error: %s\n", mysql_error(conn));
        }
        else
        {
            G_Printf("Database Client Version: %s\n", mysql_get_client_info());
            G_Printf("Database Server Version: %s\n", mysql_get_server_info(conn));
            // Read from table
            if (mysql_query(conn, "SELECT ss_val FROM server_status WHERE ss_key = \"DB_Test\""))
            {
                G_Printf("Database Status: %s\n", mysql_error(conn));
                trap_Cvar_Set("g_dbReady", "0");
            }
            else
            {
                res = mysql_use_result(conn);
                while ((row = mysql_fetch_row(res)) != NULL)
                {
                    G_Printf("Database Query Result: %s \n", row[0]);
                }
                mysql_free_result(res);
                mysql_close(conn);
                G_Printf("Database Initialized.\n");
                trap_Cvar_Set("g_dbReady", "1");
            }
        }
    }
    else
    {
        G_Printf("Database Disabled in Server Configuration.\n");
    }

    G_Printf("Database Test Complete.\n");
    return;
}

void G_DB_XPSave(char *guid, char *xpname, int xptime, float skill0, float skill1,
                 float skill2, float skill3, float skill4, float skill5,
                 float skill6, float kill_rating, float kill_variance,
                 float rating, float rating_variance, int mutetime, int hits,
                 int team_hits, int player_team, const char *teamName,
                 int player_rank, const char *rankName)
{
    char *dbhost;
    char *dbname;
    char *dbuser;
    char *dbpass;

    dbhost = g_dbHostname.string;
    dbname = g_dbDatabase.string;
    dbuser = g_dbUsername.string;
    dbpass = g_dbPassword.string;

    MYSQL     *conn;
    MYSQL_RES *res;

    G_Printf("Saving Stats for GUID %s (%s) to database.\n", guid, xpname);
    char query[1024];
    sprintf(query, "INSERT INTO player_xp (guid, name, time, skill0, skill1, skill2, skill3, \
        skill4, skill5, skill6, kill_rating, kill_variance, rating, \
        rating_variance, mutetime, hits, team_hits, team, teamName, rank, rankName) VALUES \
        (\"%s\",\"%s\",%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%i,%i,%i,%i,\"%s\",%i,\"%s\") \
        ON DUPLICATE KEY UPDATE guid=\"%s\", name=\"%s\", time=%i, skill0=%f, \
        skill1=%f, skill2=%f, skill3=%f, skill4=%f, skill5=%f, skill6=%f, \
        kill_rating=%f, kill_variance=%f, rating=%f, rating_variance=%f, mutetime=%i, \
        hits=%i, team_hits=%i, team=%i, teamName=\"%s\", rank=%i, rankName=\"%s\"",
            guid, xpname, xptime, skill0, skill1, skill2, skill3, skill4, skill5,
            skill6, kill_rating, kill_variance, rating, rating_variance, mutetime,
            hits, team_hits, player_team, teamName, player_rank, rankName,
            guid, xpname, xptime, skill0, skill1, skill2, skill3, skill4, skill5,
            skill6, kill_rating, kill_variance, rating, rating_variance, mutetime,
            hits, team_hits, player_team, teamName, player_rank, rankName);

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, dbhost, dbuser, dbpass, dbname, 0, NULL, 0))
    {
        G_Printf("Database Error: %s\n", mysql_error(conn));
    }
    else
    {
        if (mysql_query(conn, query))
        {
            G_Printf("Database Error: %s\n", mysql_error(conn));
        }
        else
        {
            mysql_close(conn);
        }
    }
    return;
}

void G_DB_ServerStatSave(float s_rating, float s_rating_variance,
                         float s_distance_rating, float s_distance_variance)
{
    char *dbhost;
    char *dbname;
    char *dbuser;
    char *dbpass;

    dbhost = g_dbHostname.string;
    dbname = g_dbDatabase.string;
    dbuser = g_dbUsername.string;
    dbpass = g_dbPassword.string;

    MYSQL *conn;

    G_Printf("Saving Server Stats to Database.\n");

    char query1[512];
    char query2[512];
    char query3[512];
    char query4[512];
    sprintf(query1, "UPDATE server_status SET ss_val = %f WHERE ss_key = \"rating\"", s_rating);
    sprintf(query2, "UPDATE server_status SET ss_val = %f WHERE ss_key = \"rating_variance\"", s_rating_variance);
    sprintf(query3, "UPDATE server_status SET ss_val = %f WHERE ss_key = \"distance_rating\"", s_distance_rating);
    sprintf(query4, "UPDATE server_status SET ss_val = %f WHERE ss_key = \"distance_variance\"", s_distance_variance);

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, dbhost, dbuser, dbpass, dbname, 0, NULL, 0))
    {
        G_Printf("Database Error: %s\n", mysql_error(conn));
    }
    else
    {
        if (mysql_query(conn, query1))
        {
            G_Printf("Database Error: %s\n", mysql_error(conn));
        }
        if (mysql_query(conn, query2))
        {
            G_Printf("Database Error: %s\n", mysql_error(conn));
        }
        if (mysql_query(conn, query3))
        {
            G_Printf("Database Error: %s\n", mysql_error(conn));
        }
        if (mysql_query(conn, query4))
        {
            G_Printf("Database Error: %s\n", mysql_error(conn));
        }
        mysql_close(conn);
    }
    return;
}

void G_DB_MapStatSave(char *mapname, float rating, float rating_variance, int spree_record, char *spree_name)
{
    char *dbhost;
    char *dbname;
    char *dbuser;
    char *dbpass;

    dbhost = g_dbHostname.string;
    dbname = g_dbDatabase.string;
    dbuser = g_dbUsername.string;
    dbpass = g_dbPassword.string;

    MYSQL *conn;

    G_Printf("Saving Map Stats for %s to database.\n", mapname);

    char query1[512];
    char query2[512];
    sprintf(query1, "DELETE FROM map_stats WHERE map_name = \"%s\"", mapname);
    sprintf(query2, "INSERT INTO map_stats (map_name, rating, rating_variance, spree_record, spree_name) VALUES (\"%s\",%f,%f,%i,\"%s\")",
            mapname, rating, rating_variance, spree_record, spree_name);

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, dbhost, dbuser, dbpass, dbname, 0, NULL, 0))
    {
        G_Printf("Database Error: %s\n", mysql_error(conn));
    }
    else
    {
        if (mysql_query(conn, query1))
        {
            G_Printf("Database Error: %s\n", mysql_error(conn));
        }
        if (mysql_query(conn, query2))
        {
            G_Printf("Database Error: %s\n", mysql_error(conn));
        }
        mysql_close(conn);
    }

    return;
}

char *G_DB_GeoIPCountry(long unsigned ip_int)
{
    char *dbhost;
    char *dbname;
    char *dbuser;
    char *dbpass;

    dbhost = g_dbHostname.string;
    dbname = g_dbDatabase.string;
    dbuser = g_dbUsername.string;
    dbpass = g_dbPassword.string;

    MYSQL     *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char* buf = (char*)malloc(4);

    char query[200];
    sprintf(query, "SELECT country_code FROM server_geoip WHERE %lu BETWEEN start_integer AND end_integer LIMIT 1", ip_int);

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, dbhost, dbuser, dbpass, dbname, 0, NULL, 0))
    {
        G_Printf("Database Error: %s\n", mysql_error(conn));
    }
    else
    {
        if (mysql_query(conn, query))
        {
            G_Printf("Database Status: %s\n", mysql_error(conn));
            Q_strncpyz(buf,"ERR",sizeof(buf));
            mysql_close(conn);
        }
        else
        {
            res = mysql_use_result(conn);
            while ((row = mysql_fetch_row(res)) != NULL)
            {
                Q_strncpyz(buf,row[0],sizeof(buf));
            }
            mysql_free_result(res);
            mysql_close(conn);
        }
    }

    return buf;
}

#endif /* FEATURE_MYSQL */
