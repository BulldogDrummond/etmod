/*********************************************************
 * Project : ETMod
 *
 * File    : ai_main.h
 * Desc    : Wolf Bot AI
 *           Originally from botai codebase.
 *
 * Status  : Accepted
 *
 *********************************************************/

#ifndef __AI_MAIN_H__
#define __AI_MAIN_H__

// Uncomment to enable DEBUG
//#define DEBUG

// Uncomment to disable repeat AI errors
//#define DONT_PRINT_REPEATED_AI_ERRORS

#define CTF

#define BOT_DEBUG_FOLLOW_PLAYER       11

// Tweak bot speeds
#define NORMALIZED_MOVEMENT_SPEED    255

#define MAX_ITEMS                    256
#define MAX_BOTAIWAYPOINTS           128

// bot flags
#define BFL_STRAFERIGHT                1    // strafe to the right
#define BFL_ATTACKED                   2    // bot has attacked last ai frame
#define BFL_ATTACKJUMPED               4    // bot jumped during attack last frame
#define BFL_AIMATENEMY                 8    // bot aimed at the enemy this frame
#define BFL_AVOIDRIGHT                16    // avoid obstacles by going to the right
#define BFL_IDEALVIEWSET              32    // bot has ideal view angles set
#define BFL_MISCFLAG                  64    // different uses for each ainode
#define BFL_DISMOUNT_MG42            128    // wanting to dismount mg42
#define BFL_SPRINT                   256    // sprint
#define BFL_FIXED_MOVEMENT_AUTONOMY  512    // player has set movement autonomy
#define BFL_FIXED_WEAPON_AUTONOMY   1024    // player has set weapon autonomy
#define BFL_BATTLE_MODE             2048    // bot is in combat mode
#define BFL_SNIPING                 4096    // bot is sniping
#define BFL_SCRIPTED_LEADER         8192    // leader is enforce via scripting

// long term goal types
#define LTG_TEAMHELP                   1    // help a team mate
#define LTG_TEAMACCOMPANY              2    // accompany a team mate
#define LTG_DEFENDKEYAREA              3    // defend a key area
#define LTG_GETFLAG                    4    // get the enemy flag
#define LTG_RUSHBASE                   5    // rush to the base
#define LTG_RETURNFLAG                 6    // return the flag
#define LTG_CAMP                       7    // camp somewhere
#define LTG_CAMPORDER                  8    // ordered to camp somewhere
#define LTG_PATROL                     9    // patrol
#define LTG_GETITEM                   10    // get an item
#define LTG_KILL                      11    // kill someone

// some goal dedication times
#define TEAM_HELP_TIME                60    // 1 minute teamplay help time
#define TEAM_ACCOMPANY_TIME          600    // 10 minutes teamplay accompany time
#define TEAM_DEFENDKEYAREA_TIME      240    // 4 minutes ctf defend base time
#define TEAM_CAMP_TIME               600    // 10 minutes camping time
#define TEAM_PATROL_TIME             600    // 10 minutes patrolling time
#define TEAM_LEAD_TIME               600    // 10 minutes taking the lead
#define TEAM_GETITEM_TIME             60    // 1 minute
#define TEAM_KILL_SOMEONE            180    // 3 minute to kill someone
#define CTF_GETFLAG_TIME             240    // 4 minutes ctf get flag time
#define CTF_RUSHBASE_TIME            120    // 2 minutes ctf rush base time
#define CTF_RETURNFLAG_TIME          180    // 3 minutes to return the flag
#define CTF_ROAM_TIME                 60    // 1 minute ctf roam time

// patrol flags
#define PATROL_LOOP                    1
#define PATROL_REVERSE                 2
#define PATROL_BACK                    4

// copied from the aas file header
#define PRESENCE_NONE                  1
#define PRESENCE_NORMAL                2
#define PRESENCE_CROUCH                4

// misc defines
#define BOT_FLAG_CARRIER_DEFENDERS     3
#define MAX_BOTLEADER_DIST          2048
#define MAX_BOTLEADER_TRAVEL        1000

// group formations
#define BOT_FORM_SINGLEFILE            0
#define BOT_FORM_DOUBLEFILE            1
#define BOT_FORM_PATROL_LINE           2
#define BOT_FORM_SEEK_COVER            3
#define BOT_FORM_NUM                   4

#define BOT_FOLLOW_BEHIND              0
#define BOT_FOLLOW_LEFT                1
#define BOT_FOLLOW_RIGHT               2
#define BOT_FOLLOW_NUM                 3

struct bot_state_s;

//check points
typedef struct bot_waypoint_s
{
    int           inuse;
    char          name[32];
    bot_goal_t    goal;
    struct        bot_waypoint_s *next, *prev;
} bot_waypoint_t;

#define BWPOFS(x) ((int)&(((bot_waypoint_t *)0)->x))

#define MAX_VCHATS 16

typedef struct
{
    int    time;
    int    id;
    int    client;    // who sent it
    int    mode;
} bot_chat_t;

// scripting defines
#define BOT_MAX_SCRIPT_ITEMS         512    // per character
#define BOT_MAX_SCRIPT_EVENTS        128    // per character
#define BOT_SIZE_STRING_POOL       16384

// flags
#define BSFL_FIRST_CALL                1
#define BSFL_LOGGING                   2
#define BSFL_MOUNT_MG42                4
#define BSFL_FORCED_MOVEMENT_AUTONOMY  8    // scripting has enforced movement autonomy
#define BSFL_FORCED_WEAPON_AUTONOMY   16    // scripting has enforced weapon autonomy

// flags that make bots crouch/prone through scripts
#define BSFL_CROUCH                   32
#define BSFL_PRONE                    64
//#define BSFL_TALK                  128    // flag to make bot play talk animation

// frame flags (stay resident until next script frame)
#define BSFFL_MOVETOTARGET             1
#define BSFFL_FOLLOW_LEADER            2
#define BSFFL_DIRECTMOVE               4    // move directly towards marker

// Force us to stand still
#define BSFFL_STAND                    8

// movement autonomy
#define BMA_NOVALUE                   -1
#define BMA_LOW                        0
#define BMA_MEDIUM                     1
#define BMA_HIGH                       2
#define NUM_BMA                        3

// weapon autonomy
#define BWA_NOVALUE                   -1
#define BWA_LOW                        0
#define BWA_MEDIUM                     1
#define BWA_HIGH                       2
#define NUM_BWA                        3

// How many people can each bot be scripted to watch?
#define MAX_PEOPLE_TO_WATCH            8

// script autonomy values
typedef enum
{
    BSA_NOVALUE       = -1,
    BSA_IGNOREENEMIES = 0,
    BSA_MAINTAINSCRIPT,
    BSA_NOCHASE,
    BSA_QUITSCRIPT
} scriptAutonomy_t;

// Follow behavior is different, depending on what our leader is doing
// Possible follow modes:
typedef enum
{
    FOLLOW_LINE,            // follow in a line
    FOLLOW_LINE_CROUCH,     // follow in a line, but crouched
    FOLLOW_SEEKCOVER,       // spread out and seek cover
    FOLLOW_SEEKCOVER_FAR,   // spread out further and seek cover
} followModes_t;

// Bot recon information
// Invalid - not doing recon
#define BOTRECON_INVALID 0

// No enemies spotted
#define BOTRECON_ALLCLEAR 1

// saw enemies
#define BOTRECON_ENEMYSPOTTED 2

// under attack
#define BOTRECON_UNDERFIRE 3

typedef enum {
    BSMT_DEFAULT,
    BSMT_WALKING,
    BSMT_CROUCHING,
} botScriptMovetype_t;

typedef struct
{
    char     *actionString;
    qboolean (*actionFunc)(struct bot_state_s *bs, char *params);
} bot_script_stack_action_t;

typedef struct
{
    // set during script parsing
    bot_script_stack_action_t    *action;    // points to an action to perform
    char                         *params;
    // debugging info
    int                          lineNum;
    char                         *text;      // points to the item location in global script buffer
} bot_script_stack_item_t;

typedef struct
{
    int    startIndex;    // place in character items this stack begins
    int    numItems;      // how many items in this stack
} bot_script_stack_t;

typedef struct
{
    int                   eventNum;    // index in scriptEvents[]
    char                  *params;     // trigger targetname, etc
    bot_script_stack_t    stack;
    // debugging info
    int                   lineNum;
    char                  *text;       // points to the item location in global script buffer
} bot_script_event_t;

typedef struct
{
    char        *eventStr;
    qboolean    (*eventMatch)(bot_script_event_t *event, char *eventParm);
} bot_script_event_define_t;

// Scripting Status (NOTE: this MUST NOT contain any pointer vars)
typedef struct
{
    int                      stackHead, stackChangeTime;
    int                      eventIndex;                  // current event containing stack of actions to perform
    bot_script_stack_item_t  *currentItem;
    int                      id;                          // incremented each time the script changes
    vec3_t                   playanim_viewangles;
    int                      scriptNoAttackTime;
    int                      scriptNoMoveTime;
    int                      playAnimViewlockTime;
} bot_script_status_t;

// static parsed data
typedef struct
{
    int                        numEvents;
    char                       stringPool[BOT_SIZE_STRING_POOL];
    bot_script_stack_item_t    items[BOT_MAX_SCRIPT_ITEMS];
    bot_script_event_t         events[BOT_MAX_SCRIPT_EVENTS];    // contains a list of actions to perform for each event type
} bot_script_data_t;

typedef struct
{
    int                  lineNum;
    char                 *name;
    char                 *params;
    bot_script_data_t    *data;
} bot_script_global_data_t;

typedef struct
{
    bot_script_data_t      *data;                                  // pointer to global list of scripted characters
    bot_script_status_t    status;                                 // current status of scripting
    int                    callIndex;                              // inc'd each time a script is called
    // persistent across function calls
    int                    flags;
    int                    frameFlags;                             // cleared at start of each script frame
    int                    entityNum;
    botScriptMovetype_t    moveType;
    fileHandle_t           logFile;
    int                    mg42entnum;
    int                    weaponType;
    int                    pauseTime;                              // stop running script for some time
    int                    weaponAutonomy;
    int                    movementAutonomy;
    vec3_t                 movementAutonomyPos;
    int                    accumBuffer[MAX_SCRIPT_ACCUM_BUFFERS];  // the accumulation buffer
} bot_script_t;

#define MAX_BOT_DEFAULT_STRING 512

typedef struct BotDefaultAttributes_s
{
    // Name of the bot
    char m_botName[MAX_BOT_DEFAULT_STRING];

    // What delay is there before we react to an enemy?
    float m_reactionTime;

    // How often do we hit our target?
    float m_aimAccuracy;

    // How likely are we to run back to the player
    float m_wimpFactor;

    // How fast do we move?
    float m_speedCoefficient;

    // What % of the time will we fire?
    float m_fireRate;

    // Min fire cycle length
    int m_minFireRateCycleTime;

    // Max fire cycle length
    int m_maxFireRateCycleTime;

    // What is our scripted FOV?
    float m_scriptedFieldOfView;

    // What is our scripted hearing range?
    float m_scriptedHearingRange;

    // When an enemy is this close; we can hear them even outside our field of view
    float m_closeHearingRange;

    // How far can this bot see?
    float m_visionRange;

    // This range is range to which we can see enemies; even if they are too far to attack
    float m_farSeeingRange;

    // How independent?
    int m_movementAutonomy;

    // How likely to shoot
    int m_weaponAutonomy;
} BotDefaultAttributes_t;

// Allow a good number of default character attributes
#define MAX_BOT_DEFAULTS 64

#define MAX_BOT_DEFAULT_FILE_SIZE 50000

#define NUM_BOT_DEFAULT_SIZE 16

typedef enum
{
    BOT_COMMAND_NULL,
    BOT_COMMAND_FOLLOWME,
    BOT_COMMAND_SEEK_COVER,
    BOT_COMMAND_OBJECTIVE,
    BOT_COMMAND_SNIPER,
    BOT_COMMAND_COMETOME,
    BOT_COMMAND_PLANT_MINE,
    BOT_COMMAND_STANDSTILLDAMMIT,
    BOT_COMMAND_HOLDPOSITION,
    BOT_COMMAND_MOVETOLOC,         // move to the location the player is looking at
    BOT_COMMAND_REVIVE,            // medic ordered to revive an ailing teammate
    BOT_COMMAND_DISGUISE,          // covert op ordered to get an enemy uniform
    BOT_COMMAND_SUPPORTFIRE,       // lieutenant ordered to call airstrike or artillery
    BOT_COMMAND_RECON,             // bot goes on recon looking for enemies
    BOT_COMMAND_COVERTHAT,         // bot covers a location, doesn't move to it
    BOT_COMMAND_GIVEHEALTH,        // making the medic give health command an explicit state
    BOT_COMMAND_GIVEAMMO,          // similarly, making lieutenant give ammo command explicit as well
    BOT_COMMAND_TEAM_HEALTH_AMMO,  // devote yourself to giving health or ammo to the whole team - dependent on your class
    BOT_COMMAND_DETECTMINES,       // covert op looks for mines in a specified area
    BOT_COMMAND_DISARM,            // engineer disarm mine or dynamite
    BOT_COMMAND_ATTACK,            // an attack order, means we shouldn't break off from attacking our current target as easily
    BOT_COMMAND_KNIFEATTACK,       // covert ops special knife attack
} botCommand_t;

// note: these must be kept in sync with the list in ai_script.c
// TODO: This is very ambigous (poor) programming - import entire enum
typedef enum
{



    BOT_REACTION_TIME,
    BOT_AIM_ACCURACY,





    BOT_WIMP_FACTOR,
    //
    BOT_MAX_ATTRIBUTES
} botAttributes_t;

// What is our position in our cover spot chain?
typedef enum
{
    COVER_CHAIN_NONE,
    COVER_CHAIN_NORMAL,
    COVER_CHAIN_NOWHERE_TO_GO
} coverChainSpot_t;

#define MAX_IGNORE_GOALS 32

typedef struct
{
    int     entityNum;
    int     areanum;        // goal areanum
    vec3_t  autonomyPos;    // avoid it only if our autonomy position is the same as this
    int     expireTime;
} botIgnoreGoal_t;

typedef struct {
    int    (*func)(struct bot_state_s *bs);
} botMatrixFunc_t;

typedef struct {
    botMatrixFunc_t    cells[NUM_BWA][NUM_BMA];
} botMatrix_t;

// store this many of our previous seek cover seqs - used for retreating
#define MAX_STORED_SEEKCOVERS 3

//bot state
typedef struct bot_state_s
{
    int              inuse;                                       // true if this state is used by a bot client
    int              botthink_residual;                           // residual for the bot thinks
    int              client;                                      // client number of the bot
    int              entitynum;                                   // entity number of the bot
    playerState_t    cur_ps;                                      // current player state
    int              last_eFlags;                                 // last ps flags
    usercmd_t        lastucmd;                                    // usercmd from last frame
    int              entityeventTime[1024];                       // last entity event time
    bot_settings_t   settings;                                    // several bot settings
    int              (*ainode)(struct bot_state_s *bs);           // current AI node
    char             *ainodeText;
    float            thinktime;                                   // time the bot thinks this frame
    vec3_t           origin;                                      // origin of the bot
    vec3_t           velocity;                                    // velocity of the bot
    vec3_t           eye;                                         // eye coordinates of the bot
    int              areanum;                                     // the number of the area the bot is in
    int              inventory[MAX_ITEMS];                        // string with items amounts the bot has
    int              tfl;                                         // the travel flags the bot uses
    int              flags;                                       // several flags
    int              respawn_wait;                                // wait until respawned
    int              lasthealth;                                  // health value previous frame
    int              setupcount;                                  // true when the bot has just been setup
    int              num_deaths;                                  // number of time this bot died
    int              num_kills;                                   // number of kills of this bot
    int              lastframe_health;                            // health value the last frame
    float            walker;                                      // walker charactertic
    float            respawn_time;                                // time the bot takes to respawn
    float            respawnchat_time;                            // time the bot started a chat during respawn
    float            chase_time;                                  // time the bot will chase the enemy
    float            enemyvisible_time;                           // time the enemy was last visible
    float            stand_time;                                  // time the bot is standing still
    float            lastchat_time;                               // time the bot last selected a chat
    float            standfindenemy_time;                         // time to find enemy while standing
    float            attackstrafe_time;                           // time the bot is strafing in one dir
    float            attackcrouch_time;                           // time the bot will stop crouching
    float            attackchase_time;                            // time the bot chases during actual attack
    float            attackjump_time;                             // time the bot jumped during attack
    float            enemysight_time;                             // time before reacting to enemy
    float            enemydeath_time;                             // time the enemy died
    float            enemyposition_time;                          // time the position and velocity of the enemy were stored
    float            activate_time;                               // time to activate something
    float            ctfroam_time;                                // time the bot is roaming in ctf
    int              arrive_time;                                 // time arrived (at companion)
    float            teleport_time;                               // last time the bot teleported
    float            camp_time;                                   // last time camped
    float            weaponchange_time;                           // time the bot started changing weapons
    float            firethrottlewait_time;                       // amount of time to wait
    float            firethrottleshoot_time;                      // amount of time to shoot
    vec3_t           aimtarget;
    vec3_t           enemyvelocity;                               // enemy velocity 0.5 secs ago during battle
    vec3_t           enemyorigin;                                 // enemy origin 0.5 secs ago during battle
    int              character;                                   // the bot character
    int              ms;                                          // move state of the bot
    int              gs;                                          // goal state of the bot
    int              cs;                                          // chat state of the bot
    int              ws;                                          // weapon state of the bot
    int              enemy;                                       // enemy entity number
    int              lastenemyareanum;                            // last reachability area the enemy was in
    vec3_t           lastenemyorigin;                             // last origin of the enemy in the reachability area
    int              weaponnum;                                   // current weapon number
    vec3_t           viewangles;                                  // current view angles
    vec3_t           ideal_viewangles;                            // ideal view angles
    int              ltgtype;                                     // long term goal type
    int              teammate;                                    // team mate
    bot_goal_t       teamgoal;                                    // the team goal
    float            teammessage_time;                            // time to message team mates what the bot is doing
    float            teamgoal_time;                               // time to stop helping team mate
    bot_goal_t       lead_teamgoal;                               // team goal while leading
    float            lead_time;                                   // time leading someone
    char             teamleader[32];                              // netname of the team leader
    int              numteammates;                                // number of team mates
    int              flagcarrier;                                 // team mate carrying the enemy flag
    char             subteam[32];                                 // sub team name
    bot_waypoint_t   *checkpoints;                                // check points
    bot_waypoint_t   *patrolpoints;                               // patrol points
    bot_waypoint_t   *curpatrolpoint;                             // current patrol point the bot is going for
    int              mpTeam;                                      // like cvars for real players
    int              mpClass;                                     // like cvars for real players
    int              mpWeapon;                                    // like cvars for real players
    int              lastClassCheck;
    bot_goal_t       target_goal;
    bot_goal_t       avoid_goal;                                  // the item we are avoiding
    bot_goal_t       alt_goal;                                    // alternative route goal
    bot_goal_t       nearbygoal;
    bot_goal_t       defendgoal;
    bot_goal_t       hidegoal;
    bot_goal_t       messageGoal;                                 // the message we must deliver
    bot_goal_t       activategoal;                                // goal to activate (buttons etc.)
    clientSession_t  sess;                                        // copied from gclient_t for convenience
    int              viewtype;
    int              viewchangetime;
    int              ignore_specialgoal_time;
    int              give_health_time;
    int              blockent;
    int              blockentTime;
    int              last_fire;
    bot_chat_t       vchats[MAX_VCHATS];                          // record of voice chats sent to us
    int              altenemy;
    int              last_findspecialgoal;
    int              last_voice_chat;
    qboolean         alreadySaidOutOfAmmo;                        // if we just ran out of ammo, have we said it?
    int              last_kill_time;
    int              shorterm_kill_count;
    int              last_checkvoice_health;
    int              last_helped_client;
    int              last_helped_time;
    int              last_checkemergencytargets;
    int              last_findspecialgoals;
    int              last_findenemy;
    int              last_findenemy_enemy;
    int              last_SparseDefense;
    int              last_avoiddangerarea;
    int              last_dangerousgoal;
    int              last_botcheckattack;
    int              last_botcheckattack_weapon;
    int              last_botcheckattack_enemy;
    int              last_pain;
    int              last_pain_client;
    int              last_enemysight;
    int              last_heardShooting;                          // the last time we heard shooting
    int              last_heardFootSteps;                         // the last time we heard people moving around
    int              last_attackShout;                            // the last time we shout attack/kill/etc.
    int              next_nearbygoal;
    int              mobileMG42ProneTime;
    int              nextRetreatCheck;                            // when should we check to see if we should retreat to the player
    int              lastRetreatTime;                             // the last time we retreated
    float            retreatLikeliness;                           // chance that we will retreat
    qboolean         shouldRetreat;                               // should we retreat to the player?
    vec3_t           defendgoal_origin;
    int              leader;
    int              leader_tagent;                               // follow this entity for formation only
    vec3_t           lastLeaderPosition;                          // track when the player last moved - relevant in FollowLeader
    int              lastLeaderMoveTime;
    int              leaderStanceChangeTime;                      // time leader changed stance
    int              lastLeaderStance;                            // standing, prone, crouched
    int              avoid_spawnCount;
    botIgnoreGoal_t  ignoreGoals[MAX_IGNORE_GOALS];
    float            attribs[BOT_MAX_ATTRIBUTES];
    bot_script_t     script;
    int              movementAutonomy;
    vec3_t           movementAutonomyPos;
    int              enteredCurrentAINodeTime;                    // When did we enter the current AI Node?
    aistateEnum_t    alertState;                                  // Has the bot seen an enemy yet?
    int              alertStateChangeTime;                        // the time alert state was changed to the current state. 
    int              alertStateSetTime;                           // the time we attempt to set alert state to the same state. 
    int              alertStateAllowChangeTime;                   // when are we free to change alertState - required by scripting system
    float            scriptedFieldOfView;                         // What is our scripted FOV?
    float            scriptedHearingRange;                        // What is our scripted hearing range?
    float            visionRange;                                 // How far can this bot see for choosing attack targets?
    float            farSeeingRange;                              // range to which we can see enemies - even if cannot attack
    float            closeHearingRange;                           // When an enemy is this close, we can hear them even outside field of view
    int              scriptedWeapon;                              // What weapon are the scripts telling us to use?
    qboolean         scriptedSleep;                               // Have we been scripted to be asleep
    qboolean         movementFailedBadly;                         // Did our latest path planning fail?
    int              scriptAnimTime;                              // last time an anim was played using scripting
    int              whenToFindNewCombatSpot;                     // When should we change to a new seek cover spot?
    int              seekCoverSpot;                               // The current spot we're looking for
    qboolean         amIHiding;                                   // Are we currently hiding?
    int              toggleHidingTime;                            // When should we stop hiding
    g_serverEntity_t *scriptedCoverSpot;                          // Do we have a specfic scripted cover spot
    int              lastSeekCoverSpots[MAX_STORED_SEEKCOVERS];   // Store the last few seek cover sequences
    coverChainSpot_t coverSpotType;                               // What sort of spot are we in?  Is it an end spot?
    float            speedCoefficient;                            // Scripted speed for the bot
    qboolean         isBotSelectable;                             // Is this bot selectable - it might be "hidden" from the player
    qboolean         overrideMovementScripts;                     // Have we received player command that should override movement scripts?
    gentity_t*       indicator;                                   // Each bot is allowed to have 1 indicator for where it is going
    qboolean         isPOW;                                       // are we a pow?
    int              reconInfo;                                   // keep track of recon info for a bot - have we seen an enemy, are we under attack
    int              returnToLeader;                              // Return to following this leader when our current goal is completed
    int              commandedWeapon;                             // if this bot has been commanded to use a particular weapon - this is it
    int              haveQueuedCmd;                               // queued action? what type? 0 means no action, 1 means location, 2 means vchat
    int              queuedAction;                                // the botaction index - also could be used to store voice chat id
    int              queuedEntity;                                // the entity
    int              queuedSource;                                // which player gave the cmd?
    vec3_t           queuedLoc;                                   // the location
    vec3_t           queuedPlayerLoc;                             // the player's loc at the time of the queuing
    scriptAutonomy_t scriptAutonomy;                              // how much are we allowed to break from our scripted commands?
    followModes_t    followMode;                                  // we don't want to switch between followmodes too frequently, so store the mode
    int              nextFollowModeTime;                          // next time to update the followMode
    botMatrix_t      *objectiveMatrix;
    botMatrix_t      *behaviourMatrix;
    botMatrix_t      *engagementMatrix;
    int              lastAttackShared;
    float            fireRate;                                    // the ratio of actual firing speed vs. maximum(normal) firing speed
    int              fireRateCheckTime;                           // the next time we should check for fire rate
    int              minFireRateCycleTime;                        // during a fire rate cycle, bot will fire for a duration of fireRate * cylcleTime
    int              maxFireRateCycleTime;                        // and will not fire for the rest of the cycle - (1-fireRate) * cycleTime
    qboolean         arrived;                                     // Have we gotten to our next spot yet?
    int              clientCheckTime;                             // pows check for enemies/friends nearby
} bot_state_t;

#define BFOFS(x) ((int)&(((bot_state_t *)0)->x))

// Used in ai_team.c for BotClosestSeekCoverSpot_r
typedef qboolean (*fCoverSpotCheck)(bot_state_t *bs, int leader, vec3_t leaderPos, g_serverEntity_t *coverSpot, float *bestDist);

// resets the whole bot state
void BotResetState(bot_state_t *bs);

// returns the number of bots in the game
int NumBots(void);

// returns info about the entity
void BotEntityInfo(int entnum, aas_entityinfo_t *info);

int BotAI_GetNumBots(void);
void BotAI_SetNumBots(int numbots);

gentity_t *BotFindEntityForName(char *name);

int BotTravelFlagsForClient(int client);

// We need to support more than 64 bot scripts.  Note that this doesn't mean more than
// 64 simultaneous bots, but separate bot scritps.
#define MAX_BOT_SCRIPT_CHARACTERS 256

extern bot_script_global_data_t botCharacterScriptData[MAX_BOT_SCRIPT_CHARACTERS];

void Bot_ScriptLoad(void);
void Bot_ScriptParse(bot_script_data_t *bsd, char **text);
qboolean Bot_ScriptInitBot(int entnum);
qboolean Bot_ScriptRun(bot_state_t *bs, qboolean force);
void Bot_ScriptLog_Entry(bot_state_t *bs, qboolean showDetails, char *preText, char *fmt, ...);
int Bot_Script_GetCurrentLine(bot_state_t *bs);
void Bot_ScriptThink(void);
int Bot_FindSriptGlobalData(bot_script_data_t *data);

// bot states
extern bot_state_t botstates[MAX_CLIENTS];

// from the game source
void  QDECL BotAI_Print(int type, char *fmt, ...);
void  QDECL QDECL BotAI_BotInitialChat(bot_state_t *bs, char *type, ...);

void  BotAI_Trace(bsp_trace_t *bsptrace, vec3_t start, vec3_t mins, vec3_t maxs, vec3_t end, int passent, int contentmask);
int   BotAI_GetClientState(int clientNum, playerState_t *state);
int   BotAI_GetEntityState(int entityNum, entityState_t *state);
int   BotAI_GetSnapshotEntity(int clientNum, int sequence, entityState_t *state);

// the static entity cache, to reduce load on G_Find()
//    !!! NOTE: must be in synch with string list in ai_main.c
typedef enum {
    BOTSTATICENTITY_CHECKPOINT,
    BOTSTATICENTITY_FLAGONLY,
    BOTSTATICENTITY_MG42,
    BOTSTATICENTITY_OBJECTIVE_INFO,
    BOTSTATICENTITY_CTF_REDFLAG,
    BOTSTATICENTITY_CTF_BLUEFLAG,
    BOTSTATICENTITY_FUNC_EXPLOSIVE,
    BOTSTATICENTITY_FUNC_DOOR,
    BOTSTATICENTITY_FUNC_DOOR_ROTATING,
    BOTSTATICENTITY_FUNC_CONSTRUCTIBLE,
    BOTSTATICENTITY_TRIGGER_MULTIPLE,
    BOTSTATICENTITY_FLAGONLY_MULTIPLE,
    BOTSTATICENTITY_BOT_LANDMINE_AREA,
    BOTSTATICENTITY_BOT_ATTRACTOR,
    BOTSTATICENTITY_BOT_SNIPERSPOT,
    BOTSTATICENTITY_BOT_LANDMINESPOTINGSPOT,
    //
    NUM_BOTSTATICENTITY
} botStaticEntityEnum_t;

void BotBuildStaticEntityCache(void);
gentity_t *BotFindNextStaticEntity(gentity_t *start, botStaticEntityEnum_t entityEnum);
gentity_t *BotSpawnGameEntity(void);
gentity_t *BotGetEntity(int entityNum);
 
// Get the bot state of a named bot
bot_state_t *FindBotByName(char * botName);

int BotGetTargetExplosives(team_t team, int *list, int listSize, qboolean ignoreDynamite);
int BotGetTargetsForSatchelCharge(team_t team, int *list, int listSize, qboolean ignoreDynamite);
int BotGetTargetDynamite(int *list, int listSize, gentity_t* target);
void BotDebugViewClient(int client);

// profiling vars
extern int botTime_EmergencyGoals;
extern int botTime_FindGoals;
extern int botTime_FindEnemy;
extern vmCvar_t bot_profile;

extern vmCvar_t bot_findgoal;

typedef enum botgoalFindType_e {
    /* *cough* */
    BFG_FOLLOW_LEADER = 0,
    BFG_CONSTRUCT,
    BFG_TRIGGER,
    BFG_DESTRUCTION_EXPLOSIVE,
    BFG_DESTRUCTION_BUILDING,
    BFG_MG42_REPAIR,
    BFG_MINE,
    BFG_ATTRACTOR,
    BFG_SNIPERSPOT,
    BFG_MG42,
    BFG_SCANFORMINES,
    BFG_DESTRUCTION_SATCHEL,
    BFG_NUMBOTGOALTYPES,
} botgoalFindType_t;

extern int botgoalMaxCloser[BFG_NUMBOTGOALTYPES];

#endif

