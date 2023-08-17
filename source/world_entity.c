/*
 * Filename: world_entity.c
 * Path: source
 * Created Date: Sunday, January 15th 2023, 3:59:16 pm
 * Author: osvegn
 *
 * Copyright (c) 2023 ECS
 */

#include "world.h"
#include "component.h"
#include <stdarg.h>

/// @brief It returns the index of the entity in the entity list if it exists, or the size of the entity list
/// if it doesn't
/// @param entity_list The list of entities to search through.
/// @param entity The entity to find.
/// @return The index of the entity in the entity list.
static unsigned int find_entity(vector_t *entity_list, entity_t *entity)
{
    for (unsigned int i = 0; i < entity_list->size(entity_list); i++) {
        if (entity->id == (*(entity_t *)(entity_list->at(entity_list, i))).id)
            return i;
    }
    return entity_list->size(entity_list);
}

static unsigned int find_entity_by_id(vector_t *entity_list, unsigned int id)
{
    for (unsigned int i = 0; i < entity_list->size(entity_list); i++) {
        if (id == (*(entity_t *)(entity_list->at(entity_list, i))).id)
            return i;
    }
    return entity_list->size(entity_list);
}

int world_add_entity(world_t *world, entity_t *entity)
{
    unsigned int index = find_entity(&world->entity_list, entity);

    if (index < world->entity_list.size(&world->entity_list)) {
        return -1;
    }
    world->entity_list.emplace_back(&world->entity_list, entity);
    return 0;
}

int world_remove_entity(world_t *world, entity_t *entity)
{
    unsigned int index = find_entity(&world->entity_list, entity);

    if (index < world->entity_list.size(&world->entity_list)) {
        world->entity_list.erase(&world->entity_list, index);
        return 0;
    }
    return -1;
}

int world_remove_entity_by_id(world_t *world, unsigned int id)
{
    unsigned int index = find_entity_by_id(&world->entity_list, id);

    if (index < world->entity_list.size(&world->entity_list)) {
        world->entity_list.erase(&world->entity_list, index);
        return 0;
    }
    return -1;
}

bool world_contains_entity(world_t *world, entity_t *entity)
{
    unsigned int index = find_entity(&world->entity_list, entity);

    if (index < world->entity_list.size(&world->entity_list))
        return true;
    return false;
}

bool world_contains_entity_by_id(world_t *world, unsigned int id)
{
    unsigned int index = find_entity_by_id(&world->entity_list, id);

    if (index < world->entity_list.size(&world->entity_list))
        return true;
    return false;
}

entity_t *world_get_entity_by_id(world_t *world, unsigned int id)
{
    unsigned int index = 0;

    index = find_entity_by_id(&world->entity_list, id);
    return world->entity_list.at(&world->entity_list, index);
}

int world_join_entities(world_t *world, vector_t *entities, unsigned int type, ...)
{
    va_list argptr;
    int component;
    bool first_element = true;
    void *ptr;

    vector_constructor(entities, sizeof(entity_t *), 0);
    va_start(argptr, type);
    for (unsigned index = 0; index < type; index++) {
        component = va_arg(argptr, int);
        if (first_element) {
            for (unsigned int i = 0; i < world->entity_list.size(&world->entity_list); i++) {
                if (entity_contains_component_by_type(world->entity_list.at(&world->entity_list, i), component)) {
                    ptr = world->entity_list.at(&world->entity_list, i);
                    entities->emplace_back(entities, &ptr);
                }
            }
            first_element = false;
        } else {
            for (unsigned int i = 0; i < entities->size(entities); i++) {
                if (!entity_contains_component_by_type(*(entity_t **)entities->at(entities, i), component)) {
                    entities->erase(entities, i);
                    i--;
                }
            }
            entities->shrink_to_fit(entities);
        }
    }
    va_end(argptr);
    if (first_element)
        return -1;
    return entities->size(entities);
}
