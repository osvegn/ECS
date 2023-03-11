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
int world_add_entity(world_t *world, entity_t *entity);

/// @brief It removes an entity from the world
/// @param world The world that the entity is in.
/// @param entity The entity to remove from the world.
/// @return 0, or -1 if the entity isn't found.
int world_remove_entity(world_t *world, entity_t *entity);

/// @brief It returns true if the entity is in the world, false otherwise
/// @param world The world that the entity is in.
/// @param entity The entity to check for.
/// @return A boolean value.
bool world_contains_entity(world_t *world, entity_t *entity);

/// @brief Get an entity from the world entity list by his id.
/// @param world The world on which find the entity.
/// @param id The id of the entity to be found.
/// @return A pointer to the entity, 0 otherwise.
entity_t *world_get_entity_by_id(world_t *world, unsigned int id);

/// @brief Initialize entities vector with entities which contain all components types asked.
/// @param world The world on which find entities.
/// @param entities The vector to store entities found.
/// @param type The number of components to find.
/// @param ... Components type to find.
/// @return The number of entity find, or -1 otherwise.
int world_join_entities(world_t *world, vector_t *entities, unsigned int type, ...);

#endif