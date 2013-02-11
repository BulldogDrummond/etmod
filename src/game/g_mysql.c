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

// Cvars
vmCvar_t g_dbEnable;
vmCvar_t g_dbHostname;
vmCvar_t g_dbDatabase;
vmCvar_t g_dbUsername;
vmCvar_t g_dbPassword;

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
	trap_Cvar_Register(&g_dbHostname, "db_hostname", "",  CVAR_TEMP);
	trap_Cvar_Register(&g_dbDatabase, "db_database", "",  CVAR_TEMP);
	trap_Cvar_Register(&g_dbUsername, "db_username", "",  CVAR_TEMP);
	trap_Cvar_Register(&g_dbPassword, "db_password", "",  CVAR_TEMP);

	char *dbhost;
	char *dbname;
	char *dbuser;
	char *dbpass;

	dbhost = g_dbHostname.string;
	dbname = g_dbDatabase.string;
	dbuser = g_dbUsername.string;
	dbpass = g_dbPassword.string;

	MYSQL *conn;
	MYSQL_RES *res;

	char query[100];

	G_Printf("Setting Map to %s in database.\n",server);
	sprintf(query,"UPDATE server_status SET ss_val = \"%s\" WHERE ss_key = \"Current_Map\"",server);

	conn=mysql_init(NULL);

	if(!mysql_real_connect(conn,dbhost,dbuser,dbpass,dbname,0,NULL,0)) {
		G_Printf("Database Error: %s\n",mysql_error(conn));
	} else {
		if (mysql_query(conn, query)) {
			G_Printf("Database Error: %s\n", mysql_error(conn));
		} else {
			mysql_close(conn);
		}
	}
	return;
}

void G_DB_ResetMap()
{
        trap_Cvar_Register(&g_dbHostname, "db_hostname", "",  CVAR_TEMP);
        trap_Cvar_Register(&g_dbDatabase, "db_database", "",  CVAR_TEMP);
        trap_Cvar_Register(&g_dbUsername, "db_username", "",  CVAR_TEMP);
        trap_Cvar_Register(&g_dbPassword, "db_password", "",  CVAR_TEMP);

	char *dbhost;
	char *dbname;
	char *dbuser;
	char *dbpass;

	dbhost = g_dbHostname.string;
	dbname = g_dbDatabase.string;
	dbuser = g_dbUsername.string;
	dbpass = g_dbPassword.string;

	MYSQL *conn;
	MYSQL_RES *res;

	char query[100];

	G_Printf("Resetting Map in database.\n");
	sprintf(query,"UPDATE server_status SET ss_val = \"None\" WHERE ss_key = \"Current_Map\"");

	conn=mysql_init(NULL);

	if(!mysql_real_connect(conn,dbhost,dbuser,dbpass,dbname,0,NULL,0)) {
		G_Printf("Database Error: %s\n",mysql_error(conn));
	} else {
		if (mysql_query(conn, query)) {
			G_Printf("Database Error: %s\n", mysql_error(conn));
		} else {
			mysql_close(conn);
		}
	}
	return;
}

void G_DB_InitGameTest()
{
	G_Printf("------ Database Test ------\n");

	trap_Cvar_Register(&g_dbEnable,   "db_enable",   "0", CVAR_TEMP);
        trap_Cvar_Register(&g_dbHostname, "db_hostname", "",  CVAR_TEMP);
        trap_Cvar_Register(&g_dbDatabase, "db_database", "",  CVAR_TEMP);
        trap_Cvar_Register(&g_dbUsername, "db_username", "",  CVAR_TEMP);
        trap_Cvar_Register(&g_dbPassword, "db_password", "",  CVAR_TEMP);

	trap_Cvar_Set("g_dbReady","0");

	int use_db;
	char *dbhost;
	char *dbname;
	char *dbuser;
	char *dbpass;

	use_db = g_dbEnable.integer;

	dbhost = g_dbHostname.string;
	dbname = g_dbDatabase.string;
	dbuser = g_dbUsername.string;
	dbpass = g_dbPassword.string;

	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	/* This tests that the database can be reached and login succeeds */
	if ( use_db == 1 ) {
		conn=mysql_init(NULL);
		if(!mysql_real_connect(conn,dbhost,dbuser,dbpass,dbname,0,NULL,0)) {
			G_Printf("Database Initialization Failed.\n");
			G_Printf("Database Error: %s\n",mysql_error(conn));
		} else{
			G_Printf("Database Client Version: %s\n",mysql_get_client_info());
			G_Printf("Database Server Version: %s\n",mysql_get_server_info(conn));
			// Read from table
			if (mysql_query(conn, "SELECT ss_val FROM server_status WHERE ss_key = \"DB_Test\"")) {
				G_Printf("Database Status: %s\n", mysql_error(conn));
				trap_Cvar_Set("g_dbReady","0");
			} else {
				res = mysql_use_result(conn);
				while ((row = mysql_fetch_row(res)) != NULL)
					G_Printf("Database Query Result: %s \n", row[0]);
				mysql_free_result(res);
				mysql_close(conn);
				G_Printf("Database Initialized.\n");
				trap_Cvar_Set("g_dbReady","1");
			}
		}
	} else {
		G_Printf("Database Disabled in Server Configuration.\n");
	}

	G_Printf("Database Test Complete.\n");
	return;
}

void G_DB_XPSave(char *guid, char *xpname, int xptime, float skill0, float skill1,
                 float skill2, float skill3, float skill4, float skill5,
                 float skill6, float kill_rating, float kill_variance,
                 float rating, float rating_variance) 
{
    trap_Cvar_Register(&g_dbHostname, "db_hostname", "",  CVAR_TEMP);
    trap_Cvar_Register(&g_dbDatabase, "db_database", "",  CVAR_TEMP);
    trap_Cvar_Register(&g_dbUsername, "db_username", "",  CVAR_TEMP);
    trap_Cvar_Register(&g_dbPassword, "db_password", "",  CVAR_TEMP);

    char *dbhost;
    char *dbname;
    char *dbuser;
    char *dbpass;

    dbhost = g_dbHostname.string;
    dbname = g_dbDatabase.string;
    dbuser = g_dbUsername.string;
    dbpass = g_dbPassword.string;

    MYSQL *conn;
    MYSQL_RES *res;

    G_Printf("Saving XP for GUID %s (%s)\n",guid,xpname);
    char query[1024];
    sprintf(query, "INSERT INTO player_xp (guid, name, time, skill0, skill1, skill2, skill3, \
        skill4, skill5, skill6, kill_rating, kill_variance, rating, \
        rating_variance) VALUES \
        (\"%s\",\"%s\",%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f) \
        ON DUPLICATE KEY UPDATE guid=\"%s\", name=\"%s\", time=%i, skill0=%f, \
        skill1=%f, skill2=%f, skill3=%f, skill4=%f, skill5=%f, skill6=%f, \
        kill_rating=%f, kill_variance=%f, rating=%f, rating_variance=%f",
        guid, xpname, xptime, skill0, skill1, skill2, skill3, skill4, skill5,
        skill6, kill_rating, kill_variance, rating, rating_variance,
        guid, xpname, xptime, skill0, skill1, skill2, skill3, skill4, skill5,
        skill6, kill_rating, kill_variance, rating, rating_variance);

    conn=mysql_init(NULL);

    if(!mysql_real_connect(conn,dbhost,dbuser,dbpass,dbname,0,NULL,0)) {
        G_Printf("Database Error: %s\n",mysql_error(conn));
    } else {
        if (mysql_query(conn, query)) {
            G_Printf("Database Error: %s\n", mysql_error(conn));
        } else {
            mysql_close(conn);
        }
    }
    return;
}

#endif /* FEATURE_MYSQL */

