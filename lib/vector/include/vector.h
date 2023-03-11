/*
 * Filename: /workspaces/our_rpg/lib/vector/include/vector.h
 * Path: /workspaces/our_rpg/lib/vector/include
 * Created Date: Thursday, December 29th 2022, 10:41:19 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdbool.h>

/// @brief The vector structure is used to store multiple data from the same
/// type allong the memory.
/// It stores some informations such as the size of an element, the number of
/// element, the total number of element, the available number of element, and
/// a pointer to the beginning of the memory.
typedef struct vector_s {

    /// @brief The size of an element.
    unsigned int _element_size;

    /// @brief The number of element.
    unsigned int _size;

    /// @brief The capacity of element in the vector.
    unsigned int _capacity;

    /// @brief The pointer to the memory.
    void *pointer;

    /// @brief This is the destructor of a vector. It frees the pointer.
    /// @param this The vector to be free.
    void (*destructor)(struct vector_s *this);

    /// @brief The emplace function adds an element at the given index.
    /// It increases the capacity of the vector if needed.
    /// @param this The vector on which adds an element.
    /// @param data The data to be added.
    /// @param index The index where the data must be added.
    /// @return 0, or -1 if an error occurs.
    int (*emplace)(struct vector_s *this, void *data, unsigned int index);

    /// @brief The emplace_back function adds an element at the end.
    /// It increases the capacity of the vector if needed.
    /// @param this The vector on which adds an element.
    /// @param data The data to be added.
    /// @return 0, or -1 if an error occurs.
    int (*emplace_back)(struct vector_s *this, void *data);

    /// @brief The print_at function prints an element at the given index
    /// using print_fct function pointer.
    /// The format dependant on how print_fct function pointer print the data.
    /// @param this The vector on which print an element.
    /// @param index The position of the element to print.
    /// @param print_fct The function pointer used to know how to print an
    /// element.
    /// @return It returns the value of print_fct.
    int (*print_at)(struct vector_s *this, unsigned int index, int (*print_fct)(void *data));

    /// @brief The print function prints all elements of the vector.
    /// The format dependant on how print_fct function pointer print the data.
    /// @param this The vector on which print all elements.
    /// @param print_fct The function pointer used to know how to print an
    /// element.
    /// @return 0, or -1 if print_fct return -1.
    int (*print)(struct vector_s *this, int (*print_fct)(void *data));

    /// @brief It clears the vector, by setting the size to 0.
    /// @param this The vector to be clear.
    /// @return 0.
    int (*clear)(struct vector_s *this);

    /// @brief It erases an element of a vector at a given index.
    /// It also moves all following elements in the vector.
    /// @param this The vector on which the element will be removed.
    /// @param index The element position on the vector to be removed.
    /// @return 0, or -1 if an error occurs.
    int (*erase)(struct vector_s *this, unsigned int index);

    /// @brief It removes the last element of a vector.
    /// @param this The vector on which the element will be removed.
    /// @return 0.
    int (*pop_back)(struct vector_s *this);

    /// @brief It swaps two elements in the vector.
    /// @param this The vector_t object.
    /// @param first_element The index of the first element to swap.
    /// @param second_element the index of the second element to swap.
    /// @return 0, or -1 if an error occurs.
    int (*swap)(struct vector_s *this, unsigned int first_element, unsigned int second_element);

    /// @brief It returns a pointer to the element ask at position index.
    /// @param this The vector on which find an element.
    /// @param index The position of the element in the vector.
    /// @return A pointer to the element asked.
    void *(*at)(struct vector_s *this, unsigned int index);

    /// @brief It returns a pointer to the last element of the vector.
    /// @param this The vector on which find an element.
    /// @return A pointer to the last element.
    void *(*back)(struct vector_s *this);

    /// @brief It returns a pointer to the first element of the vector.
    /// @param this The vector on which find an element.
    /// @return A pointer to the last element.
    void *(*front)(struct vector_s *this);

    /// @brief It returns if the vector is empty or not.
    /// @param this The vector to be check.
    /// @return True, or false if the vector isn't empty.
    bool (*empty)(struct vector_s *this);

    /// @brief It returns the this of the vector.
    /// @param this The vector to be check.
    /// @return The size of the vector as unsigned int.
    unsigned int (*size)(struct vector_s *this);

    /// @brief It returns the capacity of the vector.
    /// @param this The vector to be ckeck.
    /// @return The capacity of the vector as unsigned int.
    unsigned int (*capacity)(struct vector_s *this);

    /// @brief It resizes the allocated memory to fix with the actual memory usage.
    /// @param this The vector the to be udpate.
    /// @return 0, or -1 if an error occurs.
    int (*shrink_to_fit)(struct vector_s *this);
} vector_t;

/// @brief This is the constructor of the vector structure.
/// It set all default value and member function pointer.
/// @param this The vector to be construct.
/// @param element_size The size of an element of the vector.
/// Use sizeof() to know the size of your type.
/// @param element_number The number of element you want to allow in vector
/// memory at the beginning. It can be increase during the runtime.
/// @return 0, or -1 if an error occurs.
int vector_constructor(vector_t *this, unsigned int element_size, unsigned int element_number);


#endif /* !VECTOR_H_ */
