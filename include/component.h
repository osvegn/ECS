/*
 * Filename: /workspaces/our_rpg/lib/ECS/include/component.h
 * Path: /workspaces/our_rpg/lib/ECS/include
 * Created Date: Monday, December 19th 2022, 12:26:14 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

/// @brief It's the structure of a component. A component is a part of an
/// entity use to describe what is the entity and what it is able to do.
/// Only systems can update component data.
/// Components are only stores in entities.
/// A component contains a type and some data.
/// @note To create a new component, you have to create a new type and a new
/// structure to store data.
/// @note Good practice is to create a constructor, a getter and a
/// setter functions for your component.
typedef struct component_s {

    /// @brief The type of the component. It is used to know if this component
    /// type already exists in a list. It is also used to know how to cast
    /// data.
    unsigned int type;

    /// @brief The data of the component. It stores all informations needed
    /// by the component. Use the type of a component to know how to cast data
    /// to use it properly.
    void *data;
} component_t;

/// @brief Free the data of a component.
/// @param c The component to free.
void component_destructor(component_t *c);

#endif /* !COMPONENT_H_ */
