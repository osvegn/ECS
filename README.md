# ECS
Hi visitor, you're about to read some documentation about a basic and simple ECS in C language.

If you find some error or trouble in this repository, do not hesitate to contact me at thomas.prudhomme@epitech.eu to give me a feedback !

## What's an ECS ?
**E**ntity **C**omponent **S**ystem

ECS are used to create video games. The objective is to abstracte all elements in a game to create them easier instead of creating a lot of different but similary elements.

## How an ECS work ?
There is 5 parts in an ECS: the world, systems, entities, components and resources.

### World
The world is the part of the ECS which contains all elements of your project. It contains a list of system, resource and entities. It is the core of your game.

### Entity
An entity is an element which contains a list of component, and an id to be identify. An entity can be and have a lot of comportement, depending on the component it contains.

### Component
A component is an element which can be assign to an entity. For example, you can create a position component, which contains the position of the entity. You can also create a velocity component which contains the movement of the entity each frame.

### System
A system is a part of ECS which run the logical part. For example, you can use a system to move entities. You have to get all entities which contains component you need, and apply logic on them. You can get all entities which contains position and velocity component, and apply velocity to the position to move the entity.

### Resource
A resource is an element which can be used by the entire world. For example, a resource can be the game windows instance.

## How to use this ECS ?
If you're curious, you probably find a file named "CMakeLists.txt" at root. The file will build the ECS as a static library.
### Build the library
Use the following command in the repository to create a static library:
```
cmake -B build && cmake --build build
```

### Include the repository as a submodule
It is the better way to use the repository for now.
See the submodule documentation to let you know how to do it.
Otherwise, you just have to add the submodule as sub_directory in your cmake builder.