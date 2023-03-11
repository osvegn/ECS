/*
 * Filename: /workspaces/our_rpg/lib/ECS/include/world.h
 * Path: /workspaces/our_rpg/lib/ECS/include
 * Created Date: Sunday, January 15th 2023, 3:59:16 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#ifndef WORLD_H_
#define WORLD_H_

#include "vector.h"
#include "system.h"
#include "resource.h"
#include "entity.h"

/// @brief It's the structure of a world. A world contains a list of systems,
/// a list of resources, and a list of entities.
/// @warning This ECS architecture should have only one world. You must write
/// a program as much as possible coplient to this information.
typedef struct world_s {

    /// @brief The list of systems to be run by the world.
    vector_t system_list;

    /// @brief The list of resources contains in the world.
    vector_t resource_list;

    /// @brief The list of entities contains in the world.
    vector_t entity_list;
} world_t;

/// @brief It creates a new world by creating a new resource list, entity list, and system
/// list
/// @param world a pointer to the world_t struct
/// @return 0, or -1 on failure
/// @details **Example**
/// @code
///    int main(void) {
///        world_t world;
///        int rvalue = 0;
///
///        rvalue = world_constructor(&world);
///        if (rvalue < 0)
///            return -1;
///        return 0;
///    }
/// @endcode
int world_constructor(world_t *world);

/// @brief It calls the destructor of each of the three lists in the world
/// @param world The world to be destructed.
/// @details **Example**
/// @code
///    int main(void) {
///        world_t world;
///        int rvalue = 0;
///
///        rvalue = world_constructor(&world);
///        if (rvalue < 0)
///            return -1;
///        world_destructor(&world);
///        return 0;
///    }
/// @endcode
void world_destructor(world_t *world);

#endif /* !WORLD_H_ */
