/***
*
*	Copyright (c) 1996-2001, Valve LLC. All rights reserved.
*	
*	This product contains software technology licensed from Id 
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
*	All Rights Reserved.
*
*   This source code contains proprietary and confidential information of
*   Valve LLC and its suppliers.  Access to this code is restricted to
*   persons who have executed a written SDK license with Valve.  Any access,
*   use or distribution of this code by or to any unlicensed person is illegal.
*
****/
//=========================================================
// Scheduling 
//=========================================================

#ifndef	GAME_SERVER_ENTITIES_NPCS_SCHEDULE_H
#define	GAME_SERVER_ENTITIES_NPCS_SCHEDULE_H

enum TaskStatus
{
	/**
	*	Just started
	*/
	TASKSTATUS_NEW				= 0,

	/**
	*	Running task & movement
	*/
	TASKSTATUS_RUNNING			= 1,

	/**
	*	Just running movement
	*/
	TASKSTATUS_RUNNING_MOVEMENT	= 2,

	/**
	*	Just running task
	*/
	TASKSTATUS_RUNNING_TASK		= 3,

	/**
	*	Completed, get next task
	*/
	TASKSTATUS_COMPLETE			= 4,
};


//=========================================================
// These are the schedule types
//=========================================================
enum SCHEDULE_TYPE
{
	SCHED_NONE = 0,
	SCHED_IDLE_STAND,
	SCHED_IDLE_WALK,
	SCHED_WAKE_ANGRY,
	SCHED_WAKE_CALLED,
	SCHED_ALERT_FACE,
	SCHED_ALERT_SMALL_FLINCH,
	SCHED_ALERT_BIG_FLINCH,
	SCHED_ALERT_STAND,
	SCHED_INVESTIGATE_SOUND,
	SCHED_COMBAT_FACE,
	SCHED_COMBAT_STAND,
	SCHED_CHASE_ENEMY,
	SCHED_CHASE_ENEMY_FAILED,
	SCHED_VICTORY_DANCE,
	SCHED_TARGET_FACE,
	SCHED_TARGET_CHASE,
	SCHED_SMALL_FLINCH,
	SCHED_TAKE_COVER_FROM_ENEMY,
	SCHED_TAKE_COVER_FROM_BEST_SOUND,
	SCHED_TAKE_COVER_FROM_ORIGIN,
	SCHED_COWER, // usually a last resort!
	SCHED_MELEE_ATTACK1,
	SCHED_MELEE_ATTACK2,
	SCHED_RANGE_ATTACK1,
	SCHED_RANGE_ATTACK2,
	SCHED_SPECIAL_ATTACK1,
	SCHED_SPECIAL_ATTACK2,
	SCHED_STANDOFF,
	SCHED_ARM_WEAPON,
	SCHED_RELOAD,
	SCHED_GUARD,
	SCHED_AMBUSH,
	SCHED_DIE,
	SCHED_WAIT_TRIGGER,
	SCHED_FOLLOW,
	SCHED_SLEEP,
	SCHED_WAKE,
	SCHED_BARNACLE_VICTIM_GRAB,
	SCHED_BARNACLE_VICTIM_CHOMP,
	SCHED_AISCRIPT,
	SCHED_FAIL,
	
	LAST_COMMON_SCHEDULE			// Leave this at the bottom
};

//=========================================================
// These are the shared tasks
//=========================================================
enum SHARED_TASKS
{
	TASK_INVALID = 0,
	TASK_WAIT,
	TASK_WAIT_FACE_ENEMY,
	TASK_WAIT_PVS,
	TASK_SUGGEST_STATE,
	TASK_WALK_TO_TARGET,
	TASK_RUN_TO_TARGET,
	TASK_MOVE_TO_TARGET_RANGE,
	TASK_GET_PATH_TO_ENEMY,
	TASK_GET_PATH_TO_ENEMY_LKP,
	TASK_GET_PATH_TO_ENEMY_CORPSE,
	TASK_GET_PATH_TO_LEADER,
	TASK_GET_PATH_TO_SPOT,
	TASK_GET_PATH_TO_TARGET,
	TASK_GET_PATH_TO_HINTNODE,
	TASK_GET_PATH_TO_LASTPOSITION,
	TASK_GET_PATH_TO_BESTSOUND,
	TASK_GET_PATH_TO_BESTSCENT,
	TASK_RUN_PATH,	
	TASK_WALK_PATH,	
	TASK_STRAFE_PATH,
	TASK_CLEAR_MOVE_WAIT,
	TASK_STORE_LASTPOSITION,
	TASK_CLEAR_LASTPOSITION,
	TASK_PLAY_ACTIVE_IDLE,
	TASK_FIND_HINTNODE,
	TASK_CLEAR_HINTNODE,
	TASK_SMALL_FLINCH,
	TASK_FACE_IDEAL,
	TASK_FACE_ROUTE,
	TASK_FACE_ENEMY,
	TASK_FACE_HINTNODE,
	TASK_FACE_TARGET,
	TASK_FACE_LASTPOSITION,
	TASK_RANGE_ATTACK1,
	TASK_RANGE_ATTACK2,		
	TASK_MELEE_ATTACK1,		
	TASK_MELEE_ATTACK2,		
	TASK_RELOAD,
	TASK_RANGE_ATTACK1_NOTURN,
	TASK_RANGE_ATTACK2_NOTURN,		
	TASK_MELEE_ATTACK1_NOTURN,		
	TASK_MELEE_ATTACK2_NOTURN,		
	TASK_RELOAD_NOTURN,
	TASK_SPECIAL_ATTACK1,
	TASK_SPECIAL_ATTACK2,
	TASK_CROUCH,
	TASK_STAND,
	TASK_GUARD,
	TASK_STEP_LEFT,
	TASK_STEP_RIGHT,
	TASK_STEP_FORWARD,
	TASK_STEP_BACK,
	TASK_DODGE_LEFT,
	TASK_DODGE_RIGHT,
	TASK_SOUND_ANGRY,
	TASK_SOUND_DEATH,
	TASK_SET_ACTIVITY,
	TASK_SET_SCHEDULE,
	TASK_SET_FAIL_SCHEDULE,
	TASK_CLEAR_FAIL_SCHEDULE,
	TASK_PLAY_SEQUENCE,
	TASK_PLAY_SEQUENCE_FACE_ENEMY,
	TASK_PLAY_SEQUENCE_FACE_TARGET,
	TASK_SOUND_IDLE,
	TASK_SOUND_WAKE,
	TASK_SOUND_PAIN,
	TASK_SOUND_DIE,
	TASK_FIND_COVER_FROM_BEST_SOUND,// tries lateral cover first, then node cover
	TASK_FIND_COVER_FROM_ENEMY,// tries lateral cover first, then node cover
	TASK_FIND_LATERAL_COVER_FROM_ENEMY,
	TASK_FIND_NODE_COVER_FROM_ENEMY,
	TASK_FIND_NEAR_NODE_COVER_FROM_ENEMY,// data for this one is the MAXIMUM acceptable distance to the cover.
	TASK_FIND_FAR_NODE_COVER_FROM_ENEMY,// data for this one is there MINIMUM aceptable distance to the cover.
	TASK_FIND_COVER_FROM_ORIGIN,
	TASK_EAT,
	TASK_DIE,
	TASK_WAIT_FOR_SCRIPT,
	TASK_PLAY_SCRIPT,
	TASK_ENABLE_SCRIPT,
	TASK_PLANT_ON_SCRIPT,
	TASK_FACE_SCRIPT,
	TASK_WAIT_RANDOM,
	TASK_WAIT_INDEFINITE,
	TASK_STOP_MOVING,
	TASK_TURN_LEFT,
	TASK_TURN_RIGHT,
	TASK_REMEMBER,
	TASK_FORGET,
	TASK_WAIT_FOR_MOVEMENT,			// wait until MovementIsComplete()
	LAST_COMMON_TASK, // LEAVE THIS AT THE BOTTOM!! (sjb)
};


// These go in the flData member of the TASK_WALK_TO_TARGET, TASK_RUN_TO_TARGET
enum 
{
	TARGET_MOVE_NORMAL = 0,
	TARGET_MOVE_SCRIPTED = 1,
};


// A goal should be used for a task that requires several schedules to complete.  
// The goal index should indicate which schedule (ordinally) the monster is running.  
// That way, when tasks fail, the AI can make decisions based on the context of the 
// current goal and sequence rather than just the current schedule.
enum
{
	GOAL_ATTACK_ENEMY,
	GOAL_MOVE,
	GOAL_TAKE_COVER,
	GOAL_MOVE_TARGET,
	GOAL_EAT,
};

/**
*	An array of tasks is a task list
*	An array of schedules is a schedule list
*/
struct Task_t
{
	int		iTask;
	float	flData;
};

/**
*	Represents a single schedule.
*/
struct Schedule_t
{
	const Task_t* pTasklist;
	size_t	cTasks;

	/**
	*	A bit mask of conditions that can interrupt this schedule 
	*/
	int		iInterruptMask;
	
	/**
	*	A more specific mask that indicates which TYPES of sounds will interrupt the schedule in the 
	*	event that the schedule is broken by COND_HEAR_SOUND
	*/
	int		iSoundMask;
	const	char *pName;
};

/**
*	These bits represent conditions that may befall the monster, of which some are allowed 
*	to interrupt certain schedules.
*/
enum MonsterCondition
{
	/**
	*	Weapon needs to be reloaded!
	*/
	bits_COND_NO_AMMO_LOADED			= 1 << 0,

	/**
	*	See something that you hate.
	*/
	bits_COND_SEE_HATE					= 1 << 1, 

	/**
	*	See something that you are afraid of.
	*/
	bits_COND_SEE_FEAR					= 1 << 2,

	/**
	*	See something that you dislike.
	*/
	bits_COND_SEE_DISLIKE				= 1 << 3,

	/**
	*	Target entity is in full view.
	*/
	bits_COND_SEE_ENEMY					= 1 << 4,

	/**
	*	Target entity occluded by the world.
	*/
	bits_COND_ENEMY_OCCLUDED			= 1 << 5,
	bits_COND_SMELL_FOOD				= 1 << 6,
	bits_COND_ENEMY_TOOFAR				= 1 << 7,

	/**
	*	Hurt a little.
	*/
	bits_COND_LIGHT_DAMAGE				= 1 << 8,

	/**
	*	Hurt a lot.
	*/
	bits_COND_HEAVY_DAMAGE				= 1 << 9,
	bits_COND_CAN_RANGE_ATTACK1			= 1 << 10,
	bits_COND_CAN_MELEE_ATTACK1			= 1 << 11,
	bits_COND_CAN_RANGE_ATTACK2			= 1 << 12,
	bits_COND_CAN_MELEE_ATTACK2			= 1 << 13,
	//bits_COND_CAN_RANGE_ATTACK3		= 1 << 14,
	bits_COND_PROVOKED					= 1 << 15,
	bits_COND_NEW_ENEMY					= 1 << 16,

	/**
	*	There is an interesting sound.
	*/
	bits_COND_HEAR_SOUND				= 1 << 17,

	/**
	*	There is an interesting scent.
	*/
	bits_COND_SMELL						= 1 << 18,

	/**
	*	Enemy is facing me.
	*/
	bits_COND_ENEMY_FACING_ME			= 1 << 19,

	/**
	*	Enemy was killed. If you get this in combat, try to find another enemy. If you get it in alert, victory dance.
	*/
	bits_COND_ENEMY_DEAD				= 1 << 20,

	/**
	*	Dee a client.
	*/
	bits_COND_SEE_CLIENT				= 1 << 21,

	/**
	*	Dee my nemesis.
	*/
	bits_COND_SEE_NEMESIS				= 1 << 22,
	
	/**
	*	Defined by individual monster.
	*/
	bits_COND_SPECIAL1					= 1 << 28,

	/**
	*	Defined by individual monster.
	*/
	bits_COND_SPECIAL2					= 1 << 29,
	
	bits_COND_TASK_FAILED				= 1 << 30,
	bits_COND_SCHEDULE_DONE				= 1 << 31,
	
	
	bits_COND_ALL_SPECIAL				= bits_COND_SPECIAL1 | bits_COND_SPECIAL2,
	
	bits_COND_CAN_ATTACK				= bits_COND_CAN_RANGE_ATTACK1 | bits_COND_CAN_MELEE_ATTACK1 | bits_COND_CAN_RANGE_ATTACK2 | bits_COND_CAN_MELEE_ATTACK2
};

#endif //GAME_SERVER_ENTITIES_NPCS_SCHEDULE_H
