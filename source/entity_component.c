/*
 * Filename: source/entity_component.c
 * Path: source
 * Created Date: Sunday, January 15th 2023, 3:59:16 pm
 * Author: osvegn
 *
 * Copyright (c) 2023 our_rpg
 */

#include "entity.h"
#include "world_logger.h"

/// @brief It returns the index of the component in the component list if it
/// exists, or the size of the component list
/// @param entity The entity to search through.
/// @param component The component to find.
/// @return The index of the component in the component list, or the size of the
/// component list if it doesn't exist.
static unsigned int find_component(entity_t *entity, component_t *component)
{
    for (unsigned int i = 0; i < entity->components.size(&entity->components); i++) {
        if (component->type == ((component_t *)entity->components.at(&entity->components, i))->type) {
            return i;
        }
    }
    return entity->components.size(&entity->components);
}

bool entity_contains_component(entity_t *entity, component_t *component)
{
    unsigned int index = find_component(entity, component);

    if (index < entity->components.size(&entity->components)) {
        world_log(WORLD_LOG_LEVEL_INFO, "Component found (type: %d) in entity (type: %d))", component->type,
                  entity->id);
        return true;
    }
    world_log(WORLD_LOG_LEVEL_INFO, "Component not found (type: %d) in entity (type: %d))", component->type,
              entity->id);
    return false;
}

bool entity_contains_component_by_type(entity_t *entity, unsigned int type)
{
    component_t component = {type, 0};
    unsigned int index = find_component(entity, &component);

    if (index < entity->components.size(&entity->components)) {
        world_log(WORLD_LOG_LEVEL_INFO, "Component found (type: %d) in entity (type: %d))", type, entity->id);
        return true;
    }
    world_log(WORLD_LOG_LEVEL_INFO, "Component not found (type: %d) in entity (type: %d))", type, entity->id);
    return false;
}

int entity_add_component(entity_t *entity, component_t *component)
{
    unsigned int index = find_component(entity, component);

    if (index < entity->components.size(&entity->components)) {
        world_log(WORLD_LOG_LEVEL_WARN, "Component already exists (type: %d) in entity (type: %d))",
                  component->type, entity->id);
        return -1;
    }
    world_log(WORLD_LOG_LEVEL_INFO, "Component added (type: %d) in entity (type: %d))", component->type,
              entity->id);
    entity->components.emplace_back(&entity->components, component);
    return 0;
}

int entity_remove_component(entity_t *entity, component_t *component)
{
    unsigned int index = find_component(entity, component);

    if (index < entity->components.size(&entity->components)) {
        entity->components.erase(&entity->components, index);
        world_log(WORLD_LOG_LEVEL_INFO, "Component removed (type: %d) in entity (type: %d))", component->type,
                  entity->id);
        return 0;
    }
    world_log(WORLD_LOG_LEVEL_WARN, "Component not found (type: %d) in entity (type: %d))", component->type,
              entity->id);
    return -1;
}

component_t *entity_get_component(entity_t *entity, unsigned int type)
{
    if (entity->components.size(&entity->components) <= 0) {
        world_log(WORLD_LOG_LEVEL_WARN, "Entity (%d) has no components", entity->id);
        return 0;
    }
    for (unsigned int index = 0; index < entity->components.size(&entity->components); index++) {
        if (((component_t *)entity->components.at(&entity->components, index))->type == type) {
            world_log(WORLD_LOG_LEVEL_INFO, "Component found (type: %d) in entity (type: %d))", type,
                      entity->id);
            return entity->components.at(&entity->components, index);
        }
    }
    world_log(WORLD_LOG_LEVEL_WARN, "Component not found (type: %d) in entity (type: %d))", type, entity->id);
    return 0;
}

int entity_constructor(entity_t *entity)
{
    static int id = 0;

    entity->id = id;
    id++;
    world_log(WORLD_LOG_LEVEL_INFO, "Entity created (type: %d)", entity->id);
    return vector_constructor(&entity->components, sizeof(component_t), 0);
}

void entity_destructor(entity_t *entity)
{
    entity->components.destructor(&entity->components);
    world_log(WORLD_LOG_LEVEL_INFO, "Entity destroyed (type: %d)", entity->id);
}
