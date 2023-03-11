/*
 * Filename: /workspaces/our_rpg/lib/ECS/source/world_system.c
 * Path: /workspaces/our_rpg/lib/ECS/source
 * Created Date: Sunday, January 15th 2023, 3:59:16 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "world.h"

/// @brief It finds the index of a system in a list of systems
/// @param system_list The list of systems to search through.
/// @param system The system to find.
/// @return The index of the system in the system_list vector, or list size if not found.
static unsigned int find_system(vector_t *system_list, system_t *system)
{
    for (unsigned int i = 0; i < system_list->size(system_list); i++) {
        if (system->type == (*(system_t *)(system_list->at(system_list, i))).type)
            return i;
    }
    return system_list->size(system_list);
}

static unsigned int find_system_by_type(vector_t *system_list, unsigned int type)
{
    for (unsigned int i = 0; i < system_list->size(system_list); i++) {
        if (type == (*(system_t *)(system_list->at(system_list, i))).type) {
            return i;
        }
    }
    return system_list->size(system_list);
}

int world_add_system(world_t *world, system_t *system)
{
    unsigned int index = find_system(&world->system_list, system);

    if (index < world->system_list.size(&world->system_list)) {
        return -1;
    }
    world->system_list.emplace_back(&world->system_list, system);
    return 0;
}

int world_remove_system(world_t *world, system_t *system)
{
    unsigned int index = find_system(&world->system_list, system);

    if (index < world->system_list.size(&world->system_list)) {
        world->system_list.erase(&world->system_list, index);
        return 0;
    }
    return -1;
}

int world_remove_system_by_type(world_t *world, unsigned int type)
{
    unsigned int index = find_system_by_type(&world->system_list, type);

    if (index < world->system_list.size(&world->system_list)) {
        world->system_list.erase(&world->system_list, index);
        return 0;
    }
    return -1;
}

bool world_contains_system(world_t *world, system_t *system)
{
    unsigned int index = find_system(&world->system_list, system);

    if (index < world->system_list.size(&world->system_list)) {
        return true;
    }
    return false;
}

bool world_contains_system_by_type(world_t *world, unsigned int type)
{
    unsigned int index = find_system_by_type(&world->system_list, type);

    if (index < world->system_list.size(&world->system_list)) {
        return true;
    }
    return false;
}

system_t *world_get_system(world_t *world, system_t *system)
{
    unsigned int index = find_system(&world->system_list, system);

    if (index < world->system_list.size(&world->system_list)) {
        return world->system_list.at(&world->system_list, index);
    }
    return 0;
}

system_t *world_get_system_by_type(world_t *world, unsigned int type)
{
    unsigned int index = find_system_by_type(&world->system_list, type);

    if (index < world->system_list.size(&world->system_list)) {
        return world->system_list.at(&world->system_list, index);
    }
    return 0;
}
