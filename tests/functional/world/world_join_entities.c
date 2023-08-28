/*
 * Filename: world_join_entities.c
 * Path: tests/functional/world
 * Created Date: Sunday, August 27th 2023, 9:38:12 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 ECS
 */

#include "world.h"
#include "world_entity.h"

int main(void)
{
    world_t world;
    vector_t entities;
    entity_t entity;
    entity_t *e;
    vector_t *components;
    component_t component = {.type=1, .data=0};
    component_t *c = 0;

    world_constructor(&world, stdout);
    entity_constructor(&entity);
    entity_add_component(&entity, &component);
    world_add_entity(&world, &entity);
    world_join_entities(&world, &entities, 1, 1);
    e = CAST(entity_t *, entities.at(&entities, 0));
    c = (component_t *)entity_get_component_by_type(e, 1);
    c->data = (void *)1;
    c = (component_t *)entity.components.at(&entity.components, 0);
    return 0;
}
