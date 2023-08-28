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

static unsigned int find_entity_by_id(vector_t *entity_list, unsigned int id)
{
    for (unsigned int i = 0; i < entity_list->size(entity_list); i++) {
        if (id == (*(entity_t *)(entity_list->at(entity_list, i))).id)
            return i;
    }
    return entity_list->size(entity_list);
}

/// @brief It returns the index of the entity in the entity list if it exists, or the size of the entity list
/// if it doesn't
/// @param entity_list The list of entities to search through.
/// @param entity The entity to find.
/// @return The index of the entity in the entity list.
static unsigned int find_entity(vector_t *entity_list, entity_t *entity)
{
    return find_entity_by_id(entity_list, entity->id);
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

int world_remove_entity_by_id(world_t *world, unsigned int id)
{
    unsigned int index = find_entity_by_id(&world->entity_list, id);

    if (index < world->entity_list.size(&world->entity_list)) {
        return (world->entity_list.erase(&world->entity_list, index));
    }
    return -1;
}

int world_remove_entity(world_t *world, entity_t *entity)
{
    return world_remove_entity_by_id(world, entity->id);
}

bool world_contains_entity_by_id(world_t *world, unsigned int id)
{
    unsigned int index = find_entity_by_id(&world->entity_list, id);
    unsigned int size = world->entity_list.size(&world->entity_list);

    return (index < size);
}

bool world_contains_entity(world_t *world, entity_t *entity)
{
    return world_contains_entity_by_id(world, entity->id);
}

entity_t *world_get_entity_by_id(world_t *world, unsigned int id)
{
    unsigned int index = find_entity_by_id(&world->entity_list, id);

    return world->entity_list.at(&world->entity_list, index);
}

entity_t *world_get_entity(world_t *world, entity_t *entity)
{
    return world_get_entity_by_id(world, entity->id);
}

int world_join_entities_from_vector(world_t *world, vector_t *entities, vector_t *args)
{
    int c_type = 0;
    int count = 0;
    entity_t *e = 0;

    if (vector_constructor(entities, sizeof(vector_t *), 0) < 0)
        return -1;
    for (unsigned int index = 0; index < world->entity_list.size(&world->entity_list); index++) {
        for (unsigned int i = 0; i < args->size(args); i++) {
            e = world->entity_list.at(&world->entity_list, index);
            if (entity_contains_component_by_type(e, CAST(unsigned int, args->at(args, i)))) {
                count++;
            }
        }
        if (count == args->size(args))
            entities->emplace_back(entities, &e);
        count = 0;
    }
    return entities->size(entities);
}

int world_join_entities(world_t *world, vector_t *entities, unsigned int count, ...)
{
    va_list arg_ptr;
    int c_type = 0;
    int r_value = 0;
    vector_t args;

    if (vector_constructor(&args, sizeof(int), count) < 0)
        return -1;
    va_start(arg_ptr, count);
    for (unsigned int i = 0; i < count; i++) {
        c_type = va_arg(arg_ptr, int);
        if (args.emplace_back(&args, &c_type) < 0)
            return -1;
    }
    va_end(arg_ptr);
    r_value = world_join_entities_from_vector(world, entities, &args);
    args.destructor(&args);
    return r_value;
}
