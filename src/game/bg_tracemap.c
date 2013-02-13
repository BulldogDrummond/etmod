/*********************************************************
 * Project : ETMod
 *
 * File    : bg_tracemap.c
 * Desc    : Map tracemap view generation.
 *
 * Status  : Pending
 *
 *********************************************************/

#include "g_local.h"

#define    MAX_WORLD_HEIGHT MAX_MAP_SIZE               // maximum world height
#define    MIN_WORLD_HEIGHT -MAX_MAP_SIZE               // minimum world height

#define TRACEMAP_SIZE 256

typedef struct tracemap_s
{
    qboolean loaded;
    float sky[TRACEMAP_SIZE][TRACEMAP_SIZE];
    float skyground[TRACEMAP_SIZE][TRACEMAP_SIZE];
    float ground[TRACEMAP_SIZE][TRACEMAP_SIZE];
    vec2_t world_mins, world_maxs;
    int groundfloor, groundceil;
} tracemap_t;

static tracemap_t tracemap;

static vec2_t one_over_mapgrid_factor;

void etpro_FinalizeTracemapClamp(int *x, int *y);

qboolean BG_LoadTraceMap(char *rawmapname, vec2_t world_mins, vec2_t world_maxs)
{
    int          i, j;
    fileHandle_t f;
    byte         data, datablock[TRACEMAP_SIZE][4];
    int          sky_min, sky_max;
    int          ground_min, ground_max;
    int          skyground_min, skyground_max;
    float        scalefactor;
    //int startTime = trap_Milliseconds();

    ground_min    = ground_max = MIN_WORLD_HEIGHT;
    skyground_min = skyground_max = MAX_WORLD_HEIGHT;
    sky_min       = sky_max = MAX_WORLD_HEIGHT;

    if (trap_FS_FOpenFile(va("maps/%s_tracemap.tga", Q_strlwr(rawmapname)), &f, FS_READ) >= 0)
    {
        // skip over header
        for (i = 0; i < 18; i++)
        {
            trap_FS_Read(&data, 1, f);
        }

        for (i = 0; i < TRACEMAP_SIZE; i++)
        {
            trap_FS_Read(&datablock, sizeof(datablock), f);    // TRACEMAP_SIZE * { b g r a }

            for (j = 0; j < TRACEMAP_SIZE; j++)
            {
                if (i == 0 && j < 6)
                {
                    // abuse first six pixels for our extended data
                    switch (j)
                    {
                    case 0:    ground_min    = datablock[j][0] | (datablock[j][1] << 8) | (datablock[j][2] << 16) | (datablock[j][3] << 24); break;
                    case 1:    ground_max    = datablock[j][0] | (datablock[j][1] << 8) | (datablock[j][2] << 16) | (datablock[j][3] << 24); break;
                    case 2:    skyground_min = datablock[j][0] | (datablock[j][1] << 8) | (datablock[j][2] << 16) | (datablock[j][3] << 24); break;
                    case 3:    skyground_max = datablock[j][0] | (datablock[j][1] << 8) | (datablock[j][2] << 16) | (datablock[j][3] << 24); break;
                    case 4:    sky_min       = datablock[j][0] | (datablock[j][1] << 8) | (datablock[j][2] << 16) | (datablock[j][3] << 24); break;
                    case 5:    sky_max       = datablock[j][0] | (datablock[j][1] << 8) | (datablock[j][2] << 16) | (datablock[j][3] << 24); break;
                    }
                    tracemap.sky[TRACEMAP_SIZE - 1 - i][j]       = MAX_WORLD_HEIGHT;
                    tracemap.skyground[TRACEMAP_SIZE - 1 - i][j] = MAX_WORLD_HEIGHT;
                    tracemap.ground[TRACEMAP_SIZE - 1 - i][j]    = MIN_WORLD_HEIGHT;
                    continue;
                }

                tracemap.sky[TRACEMAP_SIZE - 1 - i][j] = (float)datablock[j][0];    // FIXME: swap
                if (tracemap.sky[TRACEMAP_SIZE - 1 - i][j] == 0)
                {
                    tracemap.sky[TRACEMAP_SIZE - 1 - i][j] = MAX_WORLD_HEIGHT;
                }

                tracemap.skyground[TRACEMAP_SIZE - 1 - i][j] = (float)datablock[j][1];    // FIXME: swap
                if (tracemap.skyground[TRACEMAP_SIZE - 1 - i][j] == 0)
                {
                    tracemap.skyground[TRACEMAP_SIZE - 1 - i][j] = MAX_WORLD_HEIGHT;
                }

                tracemap.ground[TRACEMAP_SIZE - 1 - i][j] = (float)datablock[j][2];    // FIXME: swap
                if (tracemap.ground[TRACEMAP_SIZE - 1 - i][j] == 0)
                {
                    tracemap.ground[TRACEMAP_SIZE - 1 - i][j] = MIN_WORLD_HEIGHT;
                }

                if (datablock[j][3] == 0)
                {
                    // just in case
                    tracemap.skyground[TRACEMAP_SIZE - 1 - i][j] = MAX_WORLD_HEIGHT;
                    tracemap.ground[TRACEMAP_SIZE - 1 - i][j]    = MIN_WORLD_HEIGHT;
                }
            }
        }

        trap_FS_FCloseFile(f);

        // Ground
        // calculate scalefactor
        if (ground_max - ground_min == 0)
        {
            scalefactor = 1.f;
        }
        else
        {
            // rain - scalefactor 254 to compensate for broken etmain behavior
            scalefactor = 254.f / (ground_max - ground_min);
        }

        // scale properly
        for (i = 0; i < TRACEMAP_SIZE; i++)
        {
            for (j = 0; j < TRACEMAP_SIZE; j++)
            {
                if (tracemap.ground[i][j] != MIN_WORLD_HEIGHT)
                {
                    tracemap.ground[i][j] = ground_min + (tracemap.ground[i][j] / scalefactor);
                }
            }
        }

        // SkyGround
        // calculate scalefactor
        if (skyground_max - skyground_min == 0)
        {
            scalefactor = 1.f;
        }
        else
        {
            // rain - scalefactor 254 to compensate for broken etmain behavior
            scalefactor = 254.f / (skyground_max - skyground_min);
        }

        // scale properly
        for (i = 0; i < TRACEMAP_SIZE; i++)
        {
            for (j = 0; j < TRACEMAP_SIZE; j++)
            {
                if (tracemap.skyground[i][j] != MAX_WORLD_HEIGHT)
                {
                    tracemap.skyground[i][j] = skyground_min + (tracemap.skyground[i][j] / scalefactor);
                }
            }
        }

        // Sky
        // calculate scalefactor
        if (sky_max - sky_min == 0)
        {
            scalefactor = 1.f;
        }
        else
        {
            // rain - scalefactor 254 to compensate for broken etmain behavior
            scalefactor = 254.f / (sky_max - sky_min);
        }

        // scale properly
        for (i = 0; i < TRACEMAP_SIZE; i++)
        {
            for (j = 0; j < TRACEMAP_SIZE; j++)
            {
                if (tracemap.sky[i][j] != MAX_WORLD_HEIGHT)
                {
                    tracemap.sky[i][j] = sky_min + (tracemap.sky[i][j] / scalefactor);
                }
            }
        }
    }
    else
    {
        return(tracemap.loaded = qfalse);
    }

    tracemap.world_mins[0] = world_mins[0];
    tracemap.world_mins[1] = world_mins[1];
    tracemap.world_maxs[0] = world_maxs[0];
    tracemap.world_maxs[1] = world_maxs[1];

    one_over_mapgrid_factor[0] = 1.f / ((tracemap.world_maxs[0] - tracemap.world_mins[0]) / (float)TRACEMAP_SIZE);
    one_over_mapgrid_factor[1] = 1.f / ((tracemap.world_maxs[1] - tracemap.world_mins[1]) / (float)TRACEMAP_SIZE);

    tracemap.groundfloor = ground_min;
    tracemap.groundceil  = ground_max;

    return(tracemap.loaded = qtrue);
}

static void BG_ClampPointToTracemapExtends(vec3_t point, vec2_t out)
{

    if (point[0] < tracemap.world_mins[0])
    {
        out[0] = tracemap.world_mins[0];
    }
    else if (point[0] > tracemap.world_maxs[0])
    {
        out[0] = tracemap.world_maxs[0];
    }
    else
    {
        out[0] = point[0];
    }

    if (point[1] < tracemap.world_maxs[1])
    {
        out[1] = tracemap.world_maxs[1];
    }
    else if (point[1] > tracemap.world_mins[1])
    {
        out[1] = tracemap.world_mins[1];
    }
    else
    {
        out[1] = point[1];
    }
}

float BG_GetSkyHeightAtPoint(vec3_t pos)
{
    int    i, j;
    vec2_t point;

    if (!tracemap.loaded)
    {
        return MAX_WORLD_HEIGHT;
    }

    BG_ClampPointToTracemapExtends(pos, point);

    i = myftol((point[0] - tracemap.world_mins[0]) * one_over_mapgrid_factor[0]);
    j = myftol((point[1] - tracemap.world_mins[1]) * one_over_mapgrid_factor[1]);

    // rain - re-clamp the points, because a rounding error can cause
    // them to go outside the array
    etpro_FinalizeTracemapClamp(&i, &j);

    return(tracemap.sky[j][i]);
}

float BG_GetSkyGroundHeightAtPoint(vec3_t pos)
{
    int    i, j;
    vec2_t point;

    if (!tracemap.loaded)
    {
        return MAX_WORLD_HEIGHT;
    }

    BG_ClampPointToTracemapExtends(pos, point);

    i = myftol((point[0] - tracemap.world_mins[0]) * one_over_mapgrid_factor[0]);
    j = myftol((point[1] - tracemap.world_mins[1]) * one_over_mapgrid_factor[1]);

    // rain - re-clamp the points, because a rounding error can cause
    // them to go outside the array
    etpro_FinalizeTracemapClamp(&i, &j);

    return(tracemap.skyground[j][i]);
}

float BG_GetGroundHeightAtPoint(vec3_t pos)
{
    int    i, j;
    vec2_t point;

    if (!tracemap.loaded)
    {
        return MIN_WORLD_HEIGHT;
    }

    BG_ClampPointToTracemapExtends(pos, point);

    i = myftol((point[0] - tracemap.world_mins[0]) * one_over_mapgrid_factor[0]);
    j = myftol((point[1] - tracemap.world_mins[1]) * one_over_mapgrid_factor[1]);

    // rain - re-clamp the points, because a rounding error can cause
    // them to go outside the array
    etpro_FinalizeTracemapClamp(&i, &j);

    return(tracemap.ground[j][i]);
}

int BG_GetTracemapGroundFloor(void)
{
    if (!tracemap.loaded)
    {
        return MIN_WORLD_HEIGHT;
    }
    return tracemap.groundfloor;
}

int BG_GetTracemapGroundCeil(void)
{
    if (!tracemap.loaded)
    {
        return MAX_WORLD_HEIGHT;
    }
    return tracemap.groundceil;
}

// rain - re-clamp the points, because a rounding error can cause
// them to go outside the array
void etpro_FinalizeTracemapClamp(int *x, int *y)
{
    if (*x < 0)
    {
        *x = 0;
    }
    else if (*x > TRACEMAP_SIZE - 1)
    {
        *x = TRACEMAP_SIZE - 1;
    }

    if (*y < 0)
    {
        *y = 0;
    }
    else if (*y > TRACEMAP_SIZE - 1)
    {
        *y = TRACEMAP_SIZE - 1;
    }
}
