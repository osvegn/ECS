/*
 * Filename: world_entity_tests.c
 * Path: tests/library/ECS
 * Created Date: Sunday, January 15th 2023, 3:59:16 pm
 * Author: osvegn
 *
 * Copyright (c) 2023 ECS
 */

#include <criterion/criterion.h>
#include "world.h"
#include "world_entity.h"

Test(test, test)
{
    cr_assert_eq(1, 1);
}

Test(world_world_add_entity, world_world_add_entity)
{
    world_t world;
    entity_t entity;

    entity.id = 0;
    vector_constructor(&world.entity_list, sizeof(int), 0);
    cr_assert_eq(world_add_entity(&world, &entity), 0);
    cr_assert_eq(world.entity_list.size(&world.entity_list), 1);
}

Test(world_world_add_entity, world_world_add_entity_failure)
{
    world_t world;
    entity_t entity;

    entity.id = 0;
    vector_constructor(&world.entity_list, sizeof(int), 0);
    cr_assert_eq(world_add_entity(&world, &entity), 0);
    cr_assert_eq(world_add_entity(&world, &entity), -1);
    cr_assert_eq(world.entity_list.size(&world.entity_list), 1);
}

Test(world_world_add_entity, world_world_add_entity_success_with_two_elements)
{
    world_t world;
    entity_t entity;

    entity.id = 0;
    vector_constructor(&world.entity_list, sizeof(int), 0);
    cr_assert_eq(world_add_entity(&world, &entity), 0);
    entity.id = 1;
    cr_assert_eq(world_add_entity(&world, &entity), 0);
    cr_assert_eq(world.entity_list.size(&world.entity_list), 2);
}

Test(world_world_add_entity, world_world_remove_entity)
{
    world_t world;
    entity_t entity;

    entity.id = 0;
    vector_constructor(&world.entity_list, sizeof(int), 0);
    cr_assert_eq(world_add_entity(&world, &entity), 0);
    entity.id = 1;
    cr_assert_eq(world_add_entity(&world, &entity), 0);
    cr_assert_eq(world_remove_entity(&world, &entity), 0);
    cr_assert_eq(world.entity_list.size(&world.entity_list), 1);
}

Test(world_world_add_entity, world_world_remove_entity_failure)
{
    world_t world;
    entity_t entity;

    entity.id = 0;
    vector_constructor(&world.entity_list, sizeof(int), 0);
    cr_assert_eq(world_add_entity(&world, &entity), 0);
    entity.id = 1;
    cr_assert_eq(world_add_entity(&world, &entity), 0);
    cr_assert_eq(world_remove_entity(&world, &entity), 0);
    cr_assert_eq(world_remove_entity(&world, &entity), -1);
    cr_assert_eq(world.entity_list.size(&world.entity_list), 1);
}

Test(world_world_contains_entity, world_world_contains_entity_success)
{
    world_t world;
    entity_t entity;

    entity.id = 0;
    world_constructor(&world, stdout);
    world_add_entity(&world, &entity);
    cr_assert_eq(world_contains_entity(&world, &entity), true);
}

Test(world_world_contains_entity, world_world_contains_entity_failure)
{
    world_t world;
    entity_t entity;

    entity.id = 0;
    world_constructor(&world, stdout);
    cr_assert_eq(world_contains_entity(&world, &entity), false);
}

Test(world_world_join_entities, world_world_join_entities_1)
{
    world_t world;
    entity_t entity;
    vector_t vector;
    component_t component = {.type=1, .data=0};

    world_constructor(&world, stdout);
    entity_constructor(&entity);
    entity_add_component(&entity, &component);
    world_add_entity(&world, &entity);
    cr_assert_eq(world_join_entities(&world, &vector, 1, 1), 1);
}

Test(world_world_join_entities, world_world_join_entities_2)
{
    world_t world;
    vector_t vector;

    world_constructor(&world, stdout);
    cr_assert_eq(world_join_entities(&world, &vector, 0), -1);
}

Test(world_world_join_entities, world_world_join_entities_3)
{
    world_t world;
    vector_t vector;
    entity_t entity;
    int expected_value = 2;
    component_t component = {.type=1, .data=0};

    world_constructor(&world, stdout);
    entity_constructor(&entity);
    entity_add_component(&entity, &component);
    world_add_entity(&world, &entity);
    entity_constructor(&entity);
    entity_add_component(&entity, &component);
    world_add_entity(&world, &entity);
    cr_assert_eq(world_join_entities(&world, &vector, 1, 1), expected_value);
}

Test(world_world_join_entities, world_world_join_entities_4)
{
    world_t world;
    vector_t vector;
    entity_t entity;
    component_t component = {.type=1, .data=0};

    world_constructor(&world, stdout);
    entity_constructor(&entity);
    entity_add_component(&entity, &component);
    world_add_entity(&world, &entity);
    entity_constructor(&entity);
    component.type = 2;
    entity_add_component(&entity, &component);
    world_add_entity(&world, &entity);
    cr_assert_eq(world_join_entities(&world, &vector, 2, 1, 2), 0);
}

Test(world_world_join_entities, world_world_join_entities_5)
{
    world_t world;
    vector_t vector;
    entity_t entity;
    component_t component = {.type=1, .data=0};

    world_constructor(&world, stdout);
    entity_constructor(&entity);
    entity_add_component(&entity, &component);
    component.type = 2;
    entity_add_component(&entity, &component);
    world_add_entity(&world, &entity);
    cr_assert_eq(world_join_entities(&world, &vector, 2, 1, 2), 1);
}

Test(world_world_join_entities, world_world_join_entities_6)
{
    world_t world;
    vector_t vector;
    entity_t entity;
    vector_t *components;
    component_t component = {.type=1, .data=0};

    world_constructor(&world, stdout);
    entity_constructor(&entity);
    entity_add_component(&entity, &component);
    world_add_entity(&world, &entity);
    world_join_entities(&world, &vector, 1, 1);
    components = &(*(entity_t **)vector.at(&vector, 0))->components;
    ((component_t *)components->at(components, 0))->data = (void *)1;
    cr_assert_eq(((component_t *)entity.components.at(&entity.components, 0))->data, 1);
}

Test(world_world_join_entities, world_world_join_entities_7)
{
    world_t world;
    vector_t vector;
    entity_t entity;
    vector_t *components;
    component_t component = {.type=1, .data=0};

    world_constructor(&world, stdout);
    entity_constructor(&entity);
    entity_add_component(&entity, &component);
    world_add_entity(&world, &entity);
    world_join_entities(&world, &vector, 1, 1);
    component.type = 2;
    entity_add_component(*(entity_t **)vector.at(&vector, 0), &component);
    entity_t *ptr = world_get_entity_by_id(&world, 0);
    cr_assert_eq(ptr->components.size(&ptr->components), 2);
    components = &(*(entity_t **)vector.at(&vector, 0))->components;
    cr_assert_eq(components->size(components), 2);
}

Test(world_get_entity, world_get_entity)
{
    world_t world;
    entity_t entity;

    world_constructor(&world, stdout);
    entity_constructor(&entity);
    world_add_entity(&world, &entity);
    cr_assert_eq(((entity_t *)world_get_entity(&world, &entity))->id, entity.id);
    world_destructor(&world);
}
