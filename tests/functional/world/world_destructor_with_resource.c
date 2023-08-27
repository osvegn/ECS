/*
 * Filename: test_world_destructor_with_resource.c
 * Path: tests/functional/world
 * Created Date: Saturday, August 19th 2023, 12:17:39 am
 * Author: osvegn
 * 
 * Copyright (c) 2023 ECS
 */

#include "world.h"

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

int main(void)
{
    return test_world_destructor_with_resource();
}
