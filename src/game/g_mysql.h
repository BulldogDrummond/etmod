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

char *G_DB_GeoIPCountry(unsigned long ip_int);

void G_DB_ServerStatSave(float s_rating, float s_rating_variance,
                         float s_distance_rating, float s_distance_variance);

void G_DB_MapStatSave(char *mapname, float rating, float rating_variance, int spree_record, char *spree_name);

void G_DB_XPSave(char *guid, char *name, int time, float skill0, float skill1,
                 float skill2, float skill3, float skill4, float skill5,
                 float skill6, float kill_rating, float kill_variance,
                 float rating, float rating_variance, int mutetime, int hits,
                 int team_hits, int player_team, const char *teamName, int player_rank,
                 const char *rankName);

#endif /* ifdef FEATURE_MYSQL */

#endif /* ifndef _Q_MYSQL_H */
