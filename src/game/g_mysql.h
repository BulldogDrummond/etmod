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

/*
  guid varchar(32)
  name varchar(40)
  time bigint(20) unsigned
  skill0 decimal(9,6) unsigned zerofill
  skill1 decimal(9,6) unsigned zerofill
  skill2 decimal(9,6) unsigned zerofill
  skill3 decimal(9,6) unsigned zerofill
  skill4 decimal(9,6) unsigned zerofill
  skill5 decimal(9,6) unsigned zerofill
  skill6 decimal(9,6) unsigned zerofill
  kill_rating decimal(7,6) unsigned zerofill
  kill_variance decimal(7,6) unsigned zerofill
  rating decimal(7,6) unsigned zerofill
  rating_variance decimal(7,6) unsigned zerofill
*/

void G_DB_XPSave(char *guid, char *name, int time, float skill0, float skill1,
                 float skill2, float skill3, float skill4, float skill5,
                 float skill6, float kill_rating, float kill_variance,
                 float rating, float rating_variance);

#endif /* ifdef FEATURE_MYSQL */

#endif /* ifndef _Q_MYSQL_H */

