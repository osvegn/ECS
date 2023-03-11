/*
 * Filename: /workspaces/our_rpg/lib/ECS/include/entity.h
 * Path: /workspaces/our_rpg/lib/ECS/include
 * Created Date: Sunday, January 15th 2023, 3:59:16 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "vector.h"
#include "component.h"

/// @brief It's the structure of an entity. An entity contains an id,
/// a name and a list of components.
/// Only systems can update an entity.
/// Entities are only store in the world.
/// @note To create a new entity, you have to fill the components list with
/// components.
typedef struct entity_s {

    /// @brief The id is used to differentiate two entities with the same name
    /// and the same component list.
    unsigned int id;

    /// @brief It stores a list of components.
    /// It describes what is the entity.
    vector_t components;
} entity_t;

/// @brief Constructor for the entity struct
/// @param entity The entity to construct
/// @return 0 on success, -1 on failure
/// @details **Example**
/// @code
///    int main(void)
///    {
///        entity_t entity;
///
///        entity_constructor(&entity);
///        entity_destructor(&entity);
///        return 0;
///    }
/// @endcode
int entity_constructor(entity_t *entity);

/// @brief Destructor for the entity struct
/// @param entity The entity to destroy
/// @details **Example**
/// @code
///    int main(void)
///    {
///        entity_t entity;
///
///        entity_constructor(&entity);
///        entity_destructor(&entity);
///        return 0;
///    }
/// @endcode
void entity_destructor(entity_t *entity);

/// @brief Check if an entity contains a component
/// @param entity The entity to check
/// @param component The component to check for
/// @return true if the entity contains the component, false if not
/// @details **Example**
/// @code
///    int main(void) {
///        entity_t entity;
///        component_t component;
///
///        component.type = 0;
///        entity_constructor(&entity);
///        entity_add_component(&entity, component);
///        if (entity_contains_component(&entity, component) == false)
///            return 1;
///        entity_destructor(&entity);
///        return 0;
///    }
/// @endcode
bool entity_contains_component(entity_t *entity, component_t *component);

/// @brief Remove a component from an entity
/// @param entity The entity to remove the component from
/// @param component The component to remove
/// @return 0 on success, -1 on failure
/// @details **Example**
/// @code
///    int main(void) {
///        entity_t entity;
///        component_t component;
///
///        component.type = 0;
///        entity_constructor(&entity);
///        entity_add_component(&entity, component);
///        if (entity_remove_component(&entity, component) == -1)
///            return 1;
///        entity_destructor(&entity);
///        return 0;
///    }
/// @endcode
int entity_remove_component(entity_t *entity, component_t *component);

/// @brief Add a component to an entity
/// @param entity The entity to add the component to
/// @param component The component to add
/// @return 0 on success, -1 on failure
/// @details **Example**
/// @code
///    int main(void) {
///        entity_t entity;
///        component_t component;
///
///        component.type = 0;
///        entity_constructor(&entity);
///        if (entity_add_component(&entity, component) == -1)
///            return 1;
///        entity_destructor(&entity);
///        return 0;
///    }
/// @endcode
int entity_add_component(entity_t *entity, component_t *component);

/// @brief Get a component from an entity
/// @param entity The entity to get the component from
/// @param type The type of the component to get
/// @return The component if found, NULL if not found
/// @details **Example**
/// @code
///    int main(void) {
///        entity_t entity;
///        component_t component;
///        component_t *component2;
///
///        component.type = 0;
///        entity_constructor(&entity);
///        entity_add_component(&entity, component);
///        component2 = entity_get_component(&entity, 0);
///        if (component2 == 0)
///            return 1;
///        entity_destructor(&entity);
///        return 0;
///    }
/// @endcode
component_t *entity_get_component(entity_t *entity, unsigned int type);

#endif /* !ENTITY_H_ */
