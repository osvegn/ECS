/*
 * Filename: test_world_destructor_with_entity.c
 * Path: tests/functional/world
 * Created Date: Saturday, August 19th 2023, 12:16:37 am
 * Author: osvegn
 * 
 * Copyright (c) 2023 ECS
 */

#include "world.h"

int test_world_destructor_with_entity(void)
{
    world_t world;
    entity_t entity = {0};
    component_t component = {.type=1};

    entity_constructor(&entity);
    entity_add_component(&entity, &component);
    world_constructor(&world, stdout);
    world.entity_list.emplace_back(&world.entity_list, &entity);
    if (world.entity_list.size(&world.entity_list) != 1)
        return 1;
    world_destructor(&world);
    if (world.entity_list.size(&world.entity_list) != 0)
        return 1;
    return 0;
}

int main(void)
{
    return test_world_destructor_with_entity();
}
