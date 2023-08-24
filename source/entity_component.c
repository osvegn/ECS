/*
 * Filename: entity_component.c
 * Path: source
 * Created Date: Sunday, January 15th 2023, 3:59:16 pm
 * Author: osvegn
 *
 * Copyright (c) 2023 ECS
 */

#include "entity.h"
#include "world_logger.h"

/// @brief It returns the index of the component in the component list if it
/// exists, or the size of the component list.
/// @param entity The entity to search through.
/// @param type The type of component to find.
/// @return The index of the component in the component list, or the size of the
/// component list if it doesn't exist.
static unsigned int find_component_by_type(entity_t *entity, unsigned int type)
{
    for (unsigned int i = 0; i < entity->components.size(&entity->components); i++) {
        if (type == ((component_t *)entity->components.at(&entity->components, i))->type) {
            return i;
        }
    }
    return entity->components.size(&entity->components);
}

/// @brief It returns the index of the component in the component list if it
/// exists, or the size of the component list
/// @param entity The entity to search through.
/// @param component The component to find.
/// @return The index of the component in the component list, or the size of the
/// component list if it doesn't exist.
static unsigned int find_component(entity_t *entity, component_t *component)
{
    return find_component_by_type(entity, component->type);
}

bool entity_contains_component_by_type(entity_t *entity, unsigned int type)
{
    unsigned int index = find_component_by_type(entity, type);
    unsigned int size = entity->components.size(&entity->components);

    return (index < size);
}

bool entity_contains_component(entity_t *entity, component_t *component)
{
    return (entity_contains_component_by_type(entity, component->type));
}

int entity_add_component(entity_t *entity, component_t *component)
{
    unsigned int index = find_component(entity, component);

    if (index < entity->components.size(&entity->components)) {
        log_error("Entity already contains component of type %d", component->type);
        return -1;
    }
    return (entity->components.emplace_back(&entity->components, component));
}

int entity_remove_component_by_type(entity_t *entity, unsigned int type)
{
    unsigned int index = find_component_by_type(entity, type);

    if (index < entity->components.size(&entity->components)) {
        return (entity->components.erase(&entity->components, index));
    }
    log_error("Entity does not contain component of type %d.", type);
    return -1;
}

int entity_remove_component(entity_t *entity, component_t *component)
{
    return (entity_remove_component_by_type(entity, component->type));
}

component_t *entity_get_component_by_type(entity_t *entity, unsigned int type)
{
    if (entity->components.size(&entity->components) == 0) {
        log_error("Entity does not contain any components.");
        return NULL;
    }
    for (unsigned int index = 0; index < entity->components.size(&entity->components); index++) {
        if (((component_t *)entity->components.at(&entity->components, index))->type == type) {
            return entity->components.at(&entity->components, index);
        }
    }
    log_error("Entity does not contain component of type %d.", type);
    return NULL;
}

component_t *entity_get_component(entity_t *entity, component_t *component)
{
    return entity_get_component_by_type(entity, component->type);
}

int entity_constructor(entity_t *entity)
{
    static int id = 0;

    entity->id = id;
    id++;
    log_info("Entity created (id: %d)", entity->id);
    return vector_constructor(&entity->components, sizeof(component_t), 0);
}

void entity_destructor(entity_t *entity)
{
    entity->components.destructor(&entity->components);
    log_info("Entity destroyed (id: %d)", entity->id);
}
