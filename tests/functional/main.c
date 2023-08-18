/*
 * Filename: main.c
 * Path: functional
 * Created Date: Friday, August 18th 2023, 10:19:27 pm
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

int test_world_destructor_with_resource(void)
{
    world_t world;
    resource_t resource = {.type=1};

    world_constructor(&world, stdout);
    world_add_resource(&world, &resource);
    if (world.resource_list.size(&world.resource_list) != 1)
        return 1;
    world_destructor(&world);
    if (world.resource_list.size(&world.resource_list) != 0)
        return 1;
    return 0;
}

int (*tests [])(void) = {
    &test_world_destructor_with_entity,
    &test_world_destructor_with_resource,
    0
};

int main(void)
{
    int res = 0;

    printf("Start functional tests:\n");
    for (int i = 0; tests[i]; i++) {
        printf("Launch functional tests: %i\n", i);
        res = tests[i]();
        printf("Test %i: %s\n", i, (res) ? "Failure" : "Success");
    }
    printf("End functional tests:\n");
    return 0;
}
