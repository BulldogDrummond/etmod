#------------------------------------------------------------------------
# ETMod
# - Wolfenstein: Enemy Territory 2.60b compatible server mod
#------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.6)

project(ETMOD C CXX)
set(ETMOD_VERSION "1.0")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
include(Build)
include(GetGitRevisionDescription)

# Used to store real system processor when we overwrite CMAKE_SYSTEM_PROCESSOR for cross-compile builds
set(ETMOD_SYSTEM_PROCESSOR ${CMAKE_SYSTEM_PROCESSOR}) # See IS_64_BIT_BUILD_SYSTEM

# has to be set to "", otherwise CMake will pass -rdynamic resulting in a client crash
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

# Options
option(CROSS_COMPILE32	"Compile 32-bit version (64bit req for 2.60b)"	ON)
option(FEATURE_MYSQL	"Enable MySQL support in game code"		ON)

# Installation options
set(INSTALL_DEFAULT_MODDIR "data"       CACHE STRING "Appended to CMAKE_INSTALL_PREFIX")

#-----------------------------------------------------------------
# Platform-specific settings
#-----------------------------------------------------------------

message(STATUS "System: ${CMAKE_SYSTEM} (${ETMOD_SYSTEM_PROCESSOR})")
set(CMAKE_SYSTEM_PROCESSOR i386)
message(STATUS "Forcing ${CMAKE_SYSTEM_PROCESSOR} to cross compile 32bit")
set_property(GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS OFF)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")

set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -m32")
set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -m32")

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s -ffast-math")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s -ffast-math")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

# From ET:Legacy - may not be needed - TODO: Check these
set(OS_LIBRARIES dl m rt pthread)

set(LIB_SUFFIX ".mp.")

# These are derived from the compiler calls in the scons build - TODO: Check these
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -c -pipe -O3 -fPIC -fmessage-length=0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -finline-functions -fschedule-insns2")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-strict-aliasing")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")
add_definitions(-DNDEBUG)
add_definitions(-DUSE_MDXFILE)
add_definitions(-DNO_BOT_SUPPORT)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Winline")

# Get the system architecture
if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "i686" OR "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "i386" OR "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86")
	set(ARCH "i386")
elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64" OR "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "AMD64")
	set(ARCH "x86_64")
else()
	set(ARCH "${CMAKE_SYSTEM_PROCESSOR}")
	message(STATUS "Warning: processor architecture not recognised (${CMAKE_SYSTEM_PROCESSOR})")
endif()

#-----------------------------------------------------------------
# Sources
#-----------------------------------------------------------------

FILE(GLOB QAGAME_SRC
	"src/game/bg_animation.c"
	"src/game/bg_animgroup.c"
	"src/game/bg_campaign.c"
	"src/game/bg_character.c"
	"src/game/bg_classes.c"
	"src/game/bg_misc.c"
	"src/game/bg_pmove.c"
	"src/game/bg_slidemove.c"
	"src/game/bg_sscript.c"
	"src/game/bg_stats.c"
	"src/game/bg_tracemap.c"
	"src/game/g_active.c"
	"src/game/g_alarm.c"
	"src/game/g_antilag.c"
	"src/game/g_buddy_list.c"
	"src/game/g_character.c"
	"src/game/g_client.c"
	"src/game/g_cmds.c"
	"src/game/g_cmds_ext.c"
	"src/game/g_combat.c"
	"src/game/g_config.c"
	"src/game/g_fireteams.c"
	"src/game/g_items.c"
	"src/game/g_main.c"
	"src/game/g_match.c"
	"src/game/g_mem.c"
	"src/game/g_misc.c"
	"src/game/g_missile.c"
	"src/game/g_mover.c"
	"src/game/g_multiview.c"
	"src/game/g_props.c"
	"src/game/g_referee.c"
	"src/game/g_script.c"
	"src/game/g_script_actions.c"
	"src/game/g_session.c"
	"src/game/g_shoutcaster.c"
	"src/game/g_spawn.c"
	"src/game/g_stats.c"
	"src/game/g_svcmds.c"
	"src/game/g_syscalls.c"
	"src/game/g_systemmsg.c"
	"src/game/g_target.c"
	"src/game/g_team.c"
	"src/game/g_teammapdata.c"
	"src/game/g_trigger.c"
	"src/game/g_utils.c"
	"src/game/g_vote.c"
	"src/game/g_weapon.c"
	"src/game/q_math.c"
	"src/game/q_shared.c"
	"src/game/g_shrubbot.c"
	"src/game/etpro_mdx.c"
	"src/game/g_xpsave.c"
	"src/game/g_crash.c"
	"src/game/g_etbot_interface.cpp"
	"src/game/g_http_client.c"
	"src/game/g_matchinfo.c"
	"src/game/g_censor.c"
	"src/game/g_player_rating.c"
	"src/game/g_settings.c"
	"src/game/et-antiwarp.c"
	"src/game/geoip.c"
	"src/game/g_mysql.c"
	"src/omnibot/Common/BotLoadLibrary.cpp"
)

# Version generation
# TODO: Fix this
git_describe(GIT_DESCRIBE)
git_describe(GIT_DESCRIBE_TAG "--abbrev=0")
if(GIT_DESCRIBE)
	set(ETMOD_CMAKE_VERSION ${GIT_DESCRIBE})
	set(ETMOD_CMAKE_VERSION_SHORT ${GIT_DESCRIBE_TAG})
else() # Not using source from git repo
	set(ETMOD_CMAKE_VERSION ${ETMOD_VERSION})
	set(ETMOD_CMAKE_VERSION_SHORT ${ETMOD_VERSION})
endif()
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/git_version.h.in" "${CMAKE_CURRENT_BINARY_DIR}/src/game/git_version.h" @ONLY)
list(APPEND QAGAME_SRC "${CMAKE_CURRENT_BINARY_DIR}/src/game/git_version.h")

#-----------------------------------------------------------------
# Build
#-----------------------------------------------------------------
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/game
	${CMAKE_CURRENT_SOURCE_DIR}/src/botai
	${CMAKE_CURRENT_SOURCE_DIR}/src/omnibot/Common
	${CMAKE_CURRENT_SOURCE_DIR}/src/omnibot/ET)

# qagame
add_library(qagame${LIB_SUFFIX}${ARCH} MODULE ${QAGAME_SRC})
if(FEATURE_MYSQL)
	find_package(Mysql REQUIRED)
	include_directories(${MYSQL_INCLUDE_DIR})
	add_definitions(-DFEATURE_MYSQL)
	target_link_libraries(qagame${LIB_SUFFIX}${ARCH} ${MYSQL_LIBRARY} ${MYSQL_EXTRA_LIBRARIES})
	message("-- Added MySQL Includes and Client Lib.")
endif(FEATURE_MYSQL)

set_target_properties(qagame${LIB_SUFFIX}${ARCH}
	PROPERTIES COMPILE_DEFINITIONS "GAMEDLL"
	PREFIX ""
	LINKER_LANGUAGE CXX
	LIBRARY_OUTPUT_DIRECTORY "etmod"
)

# install qagame
install(TARGETS qagame${LIB_SUFFIX}${ARCH}
	LIBRARY DESTINATION "${INSTALL_DEFAULT_MODDIR}/etmod"
	ARCHIVE DESTINATION "${INSTALL_DEFAULT_MODDIR}/etmod"
)

# install pak2.pk3
add_custom_target(
	pak2_pk3 ALL
	COMMAND zip -r ${CMAKE_CURRENT_BINARY_DIR}/etmod/pak2.pk3 *
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/resource-pak2/
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/etmod/pak2.pk3
	DESTINATION "${INSTALL_DEFAULT_MODDIR}/etmod"
)

# install sample configs
message(STATUS "Adding sample config files")
add_custom_target(
	sample_configs ALL
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		"${CMAKE_CURRENT_SOURCE_DIR}/resource-config"
		"${CMAKE_CURRENT_BINARY_DIR}/etmod"
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/resource-config/*"
        DESTINATION "${INSTALL_DEFAULT_MODDIR}/etmod"
)

# install omni-bot
message(STATUS "Adding Omni-Bot library and files")
add_custom_target(
        omnibot ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${CMAKE_CURRENT_SOURCE_DIR}/resource-omnibot"
                "${CMAKE_CURRENT_BINARY_DIR}/etmod/omni-bot"
)

install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/resource-omnibot"
        DESTINATION "${INSTALL_DEFAULT_MODDIR}/etmod/omni-bot"
)

