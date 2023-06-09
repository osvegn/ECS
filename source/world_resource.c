/*
 * Filename: /workspaces/our_rpg/lib/ECS/source/world_resource.c
 * Path: /workspaces/our_rpg/lib/ECS/source
 * Created Date: Sunday, January 15th 2023, 3:59:16 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "world.h"

/// @brief It finds the index of a resource in a resource list
/// @param resource_list The list of resources that we're going to be adding to.
/// @param resource The resource to find.
/// @return The index of the resource in the resource list, or list size if not found.
static unsigned int find_resource(vector_t *resource_list, resource_t *resource)
{
    for (unsigned int i = 0; i < resource_list->size(resource_list); i++) {
        if (resource->type == (*(resource_t *)(resource_list->at(resource_list, i))).type) {
            return i;
        }
    }
    return resource_list->size(resource_list);
}

/// @brief It finds the index of a resource type in a resource list.
/// @param resource_list The list of resources on which find the corresponding type.
/// @param type The type of resource to find.
/// @return The index of the resource type in the resource list, or list size if not found.
static unsigned int find_resource_by_type(vector_t *resource_list, unsigned int type)
{
    for (unsigned int i = 0; i < resource_list->size(resource_list); i++) {
        if (type == (*(resource_t *)(resource_list->at(resource_list, i))).type) {
            return i;
        }
    }
    return resource_list->size(resource_list);
}

int world_add_resource(world_t *world, resource_t *resource)
{
    unsigned int index = find_resource(&world->resource_list, resource);

    if (index < world->resource_list.size(&world->resource_list)) {
        return -1;
    }
    world->resource_list.emplace_back(&world->resource_list, resource);
    return 0;
}

int world_remove_resource(world_t *world, resource_t *resource)
{
    unsigned int index = find_resource(&world->resource_list, resource);

    if (index < world->resource_list.size(&world->resource_list)) {
        world->resource_list.erase(&world->resource_list, index);
        return 0;
    }
    return -1;
}

int world_remove_resource_by_type(world_t *world, unsigned int type)
{
    unsigned int index = find_resource_by_type(&world->resource_list, type);

    if (index < world->resource_list.size(&world->resource_list)) {
        world->resource_list.erase(&world->resource_list, index);
        return 0;
    }
    return -1;
}

bool world_contains_resource(world_t *world, resource_t *resource)
{
    unsigned int index = find_resource(&world->resource_list, resource);

    if (index < world->resource_list.size(&world->resource_list)) {
        return true;
    }
    return false;
}

bool world_contains_resource_by_type(world_t *world, unsigned int type)
{
    unsigned int index = find_resource_by_type(&world->resource_list, type);

    if (index < world->resource_list.size(&world->resource_list)) {
        return true;
    }
    return false;
}

resource_t *world_get_resource(world_t *world, resource_t *resource)
{
    unsigned int index = find_resource(&world->resource_list, resource);

    if (index < world->resource_list.size(&world->resource_list)) {
        return world->resource_list.at(&world->resource_list, index);
    }
    return 0;
}

resource_t *world_get_resource_by_type(world_t *world, unsigned int type)
{
    unsigned int index = find_resource_by_type(&world->resource_list, type);

    if (index < world->resource_list.size(&world->resource_list)) {
        return world->resource_list.at(&world->resource_list, index);
    }
    return 0;
}
