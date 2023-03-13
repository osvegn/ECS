/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/lib/ECS/include/world_entity.h
 * Path: /home/thomas/Documents/Perso/our_rpg/lib/ECS/include
 * Created Date: Wednesday, March 8th 2023, 11:06:14 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#ifndef WORLD_ENTITY_H_
#define WORLD_ENTITY_H_

#include "world.h"
#include "entity.h"

/// @brief It adds an entity to the world
/// @param world The world to add the entity to.
/// @param entity The entity to add to the world.
/// @return 0, or -1 if the entity already exists.
/// @note See entity.h for more information about entities.
/// @details **Example:**
/// @code
///    int example(world_t *world, entity_t *entity)
///    {
///        int rvalue = 0;
///
///        rvalue = world_add_entity(world, entity);
///        if (rvalue < 0) {
///            fprintf(stderr, "Error: world_add_entity() failed: entity already exists\n");
///            return -1;
///        }
///        return 0;
///    }
/// @endcode
int world_add_entity(world_t *world, entity_t *entity);

/// @brief It removes an entity from the world
/// @param world The world that the entity is in.
/// @param entity The entity to remove from the world.
/// @return 0, or -1 if the entity isn't found.
/// @note Prefer using world_remove_entity_by_id() instead.
/// @details **Example:**
/// @code
///    int example(world_t *world, entity_t *entity)
///    {
///        int rvalue = 0;
///
///        rvalue = world_remove_entity(world, entity);
///        if (rvalue < 0) {
///            fprintf(stderr, "Error: world_remove_entity() failed: entity not found\n");
///            return -1;
///        }
///        return 0;
///    }
/// @endcode
int world_remove_entity(world_t *world, entity_t *entity);

/// @brief It removes an entity from the world
/// @param world The world that the entity is in.
/// @param id The id of the entity to remove from the world.
/// @return 0, or -1 if the entity isn't found.
/// @details **Example:**
/// @code
///    int example(world_t *world, unsigned int id)
///    {
///        int rvalue = 0;
///
///        rvalue = world_remove_entity_by_id(world, id);
///        if (rvalue < 0) {
///            fprintf(stderr, "Error: world_remove_entity_by_id() failed: entity not found\n");
///            return -1;
///        }
///        return 0;
///    }
/// @endcode
int world_remove_entity_by_id(world_t *world, unsigned int id);

/// @brief It returns true if the entity is in the world, false otherwise
/// @param world The world that the entity is in.
/// @param entity The entity to check for.
/// @return A boolean value.
/// @note Prefer using world_contains_entity_by_id() instead.
/// @details **Example:**
/// @code
///    int example(world_t *world, entity_t *entity)
///    {
///        bool rvalue = false;
///
///        rvalue = world_contains_entity(world, entity);
///        if (rvalue == true) {
///            printf("The entity is in the world\n");
///        } else {
///            printf("The entity isn't in the world\n");
///        }
///        return 0;
///    }
/// @endcode
bool world_contains_entity(world_t *world, entity_t *entity);

/// @brief It returns true if the entity is in the world, false otherwise
/// @param world The world that the entity is in.
/// @param id The id of the entity to check for.
/// @return A boolean value.
/// @details **Example:**
/// @code
///    int example(world_t *world, unsigned int id)
///    {
///        bool rvalue = false;
///
///        rvalue = world_contains_entity_by_id(world, id);
///        if (rvalue == true) {
///            printf("The entity is in the world\n");
///        } else {
///            printf("The entity isn't in the world\n");
///        }
///        return 0;
///    }
/// @endcode
bool world_contains_entity_by_id(world_t *world, unsigned int id);

/// @brief Get an entity from the world entity list by his id.
/// @param world The world on which find the entity.
/// @param id The id of the entity to be found.
/// @return A pointer to the entity, 0 otherwise.
/// @details **Example:**
/// @code
///    int example(world_t *world, unsigned int id)
///    {
///        entity_t *entity = 0;
///
///        entity = world_get_entity_by_id(world, id);
///        if (entity == 0) {
///            fprintf(stderr, "Error: world_get_entity_by_id() failed: entity not found\n");
///            return -1;
///        }
///        return 0;
///    }
/// @endcode
entity_t *world_get_entity_by_id(world_t *world, unsigned int id);

/// @brief Initialize entities vector with entities which contain all components types asked.
/// @param world The world on which find entities.
/// @param entities The vector to store entities found.
/// @param type The number of components to find.
/// @param ... Components type to find.
/// @return The number of entity find, or -1 otherwise.
/// @details **Example:**
/// @code
///    int example(world_t *world, vector_t *entities)
///    {
///        int rvalue = 0;
///
///        rvalue = world_join_entities(world, entities, 2, COMPONENT_EXAMPLE_1, COMPONENT_EXAMPLE_2);
///        if (rvalue < 0) {
///            fprintf(stderr, "Error: world_join_entities() failed: no entity found\n");
///            return -1;
///        }
///        return 0;
///    }
/// @endcode
int world_join_entities(world_t *world, vector_t *entities, unsigned int type, ...);

#endif