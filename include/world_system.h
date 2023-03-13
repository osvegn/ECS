/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/lib/ECS/include/world_system.h
 * Path: /home/thomas/Documents/Perso/our_rpg/lib/ECS/include
 * Created Date: Wednesday, March 8th 2023, 11:04:33 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#ifndef WORLD_SYSTEM_H_
#define WORLD_SYSTEM_H_

#include "world.h"
#include "system.h"

/// @brief It runs all systems which exists in the world.
/// @param world The world which contains all systems to be run.
/// It also contains all resources and entities that exists.
/// @return 0, or -1 if an error occurs.
/// @details **Example:**
/// @code
/// int example(world_t *world) {
///     int rvalue = 0;
///
///     rvalue = world_run_systems(world);
///     if (rvalue)
///         return rvalue;
///     return 0;
/// }
/// @endcode
int world_run_systems(world_t *world);

/// @brief It adds a system to the world
/// @param world The world to add the system to.
/// @param system The system to add to the world.
/// @return 0, or -1 if the system already exists.
int world_add_system(world_t *world, system_t *system);

/// @brief It removes a system from the world
/// @param world The world to remove the system from.
/// @param system The system to remove.
/// @return 0, or -1 if the system isn't found.
int world_remove_system(world_t *world, system_t *system);

/// @brief It removes a system from the world.
/// @param world The world to remove the system from.
/// @param type The system type to remove.
/// @return 0, or -1 if the system type isn't found.
int world_remove_system_by_type(world_t *world, unsigned int type);

/// @brief It returns true if the world contains the system, false otherwise
/// @param world The world to check for.
/// @param system The system to check for.
/// @return True if the system is found, false otherwise.
bool world_contains_system(world_t *world, system_t *system);

/// @brief It checks if a system type exists in the system list of the world.
/// @param world The world to check for.
/// @param type The system type to check for.
/// @return True if the system type if found, false otherwise.
bool world_contains_system_by_type(world_t *world, unsigned int type);

/// @brief It gets a system from the system list of the world.
/// @param world The world on which get a system.
/// @param system The system to be get in the world system list.
/// @return A pointer to the corresponding system, 0 otherwise.
system_t *world_get_system(world_t *world, system_t *system);

/// @brief It gets a system from the system list of the world.
/// @param world The world on which get a system.
/// @param type The system type to be get in the world system list.
/// @return A pointer to the corresponding system, 0 otherwise.
system_t *world_get_system_by_type(world_t *world, unsigned int type);

#endif