/*
 * Filename: /workspaces/our_rpg/lib/ECS/include/system.h
 * Path: /workspaces/our_rpg/lib/ECS/include
 * Created Date: Monday, December 19th 2022, 12:26:14 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <stdbool.h>

/// @brief It's the structure of a system. A system is used to update a type
/// of component or resource. It contains a type, a boolean and a
/// function pointer.
/// Systems are called by the world to be run.
/// @note To create a new system, you have to create a new type and a new
/// function to run the system.
/// @note Good practice is to create a constructor and use it to bind the
/// function pointer to the run function.
typedef struct system_s {

    /// @brief The type of the system. It is used to know if a system already
    /// exists.
    unsigned int type;

    /// @brief The boolean is used to know if the system if active or not.
    bool active;

    /// @brief The run function pointer is used to know which function must be
    /// called to run this system.
    /// @param world The world on which the system is running.
    /// @return 0, or -1 if an error occurs.
    int (*run)(void *world);
} system_t;

#endif /* !SYSTEM_H_ */
