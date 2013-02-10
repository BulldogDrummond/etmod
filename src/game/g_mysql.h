/*********************************************************
 * Project : ETMod
 *
 * File    : g_mysql.h
 * Desc    : Mysql database declarations.
 *
 * Status  : Pending
 *
 *********************************************************/

#ifndef _Q_MYSQL_H
#define _Q_MYSQL_H

#ifdef FEATURE_MYSQL

#include "q_shared.h"
#include "g_local.h"

#include "mysql/my_global.h"
#include "mysql/mysql.h"

#include <unistd.h>

int G_DB_Ready();
void G_DB_InitGameTest();
void G_DB_SetMap(char *server);
void G_DB_ResetMap();

#endif /* ifdef FEATURE_MYSQL */

#endif /* ifndef _Q_MYSQL_H */

