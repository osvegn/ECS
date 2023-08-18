/*
 * Filename: world_constructor.c
 * Path: source
 * Created Date: Monday, January 2nd 2023, 2:38:37 pm
 * Author: osvegn
 *
 * Copyright (c) 2023 ECS
 */

#include "world.h"
#include "world_logger.h"

int world_constructor(world_t *world, FILE *log_file)
{
    int rvalue = 0;

    rvalue = vector_constructor(&world->resource_list, sizeof(resource_t), 0);
    if (rvalue < 0)
        return -1;
    rvalue = vector_constructor(&world->entity_list, sizeof(entity_t), 0);
    if (rvalue < 0)
        return -1;
    rvalue = vector_constructor(&world->system_list, sizeof(system_t), 0);
    if (rvalue < 0) {
        return -1;
    }
    world_log_init(log_file);
    log_debug("World created");
    return 0;
}

void world_destructor(world_t *world)
{
    entity_t *entity = 0;
    resource_t *resource = 0;

    while (world->entity_list.size(&world->entity_list)) {
        entity = world->entity_list.back(&world->entity_list);
        while (entity->components.size(&entity->components)) {
            component_destructor(entity->components.back(&entity->components));
            entity->components.pop_back(&entity->components);
        }
        entity->components.destructor(&entity->components);
        world->entity_list.pop_back(&world->entity_list);
    }
    world->entity_list.destructor(&world->entity_list);
    world->system_list.destructor(&world->system_list);
    while (world->resource_list.size(&world->resource_list)) {
        resource = world->resource_list.back(&world->resource_list);
        if (resource->destructor)
            resource->destructor(resource);
        world->resource_list.pop_back(&world->resource_list);
    }
    world->resource_list.destructor(&world->resource_list);
    world_log_destroy();
}
