/*
 * Filename: /workspaces/our_rpg/lib/vector/source/vector.c
 * Path: /workspaces/our_rpg/lib/vector/source
 * Created Date: Thursday, December 29th 2022, 10:41:19 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/// @brief It swaps two elements in the vector.
/// @param this The vector_t object.
/// @param first_element The index of the first element to swap.
/// @param second_element the index of the second element to swap.
/// @return 0, or -1 if an error occurs.
static int swap(vector_t *this, unsigned int first_element, unsigned int second_element)
{
    void *tmp = NULL;
    void *first = NULL;
    void *second = NULL;

    if (first_element > this->_size || second_element > this->_size)
        return -1;
    tmp = malloc(this->_element_size);
    if (!tmp)
        return -1;
    first = (char *)this->pointer + first_element * this->_element_size;
    second = (char *)this->pointer + second_element * this->_element_size;
    memcpy(tmp, first, this->_element_size);
    memcpy(first, second, this->_element_size);
    memcpy(second, tmp, this->_element_size);
    free(tmp);
    return 0;
}

/// @brief It returns a pointer to the first element of the vector.
/// @param this The vector on which find an element.
/// @return A pointer to the last element.
static void *front(vector_t *this)
{
    return this->pointer;
}

/// @brief It returns a pointer to the last element of the vector.
/// @param this The vector on which find an element.
/// @return A pointer to the last element.
static void *back(vector_t *this)
{
    if (!this->pointer)
        return NULL;
    return (char *)this->pointer + (this->_size - 1) * this->_element_size;
}

/// @brief It returns a pointer to the element ask at position index.
/// @param this The vector on which find an element.
/// @param index The position of the element in the vector.
/// @return A pointer to the element asked.
static void *at(vector_t *this, unsigned int index)
{
    if (index >= this->_size || !this->pointer)
        return NULL;
    return (char *)this->pointer + index * this->_element_size;
}

/// @brief It resizes the allocated memory to fix with the actual memory usage.
/// @param this The vector the to be udpate.
/// @return 0, or -1 if an error occurs.
static int shrink_to_fit(vector_t *this)
{
    this->pointer = realloc(this->pointer, this->_size * this->_element_size);
    this->_capacity = this->_size;
    if (!this->pointer)
        return -1;
    return 0;
}

/// @brief It returns the capacity of the vector.
/// @param this The vector to be ckeck.
/// @return The capacity of the vector as unsigned int.
static unsigned int capacity(vector_t *this)
{
    return this->_capacity;
}

/// @brief It returns the this of the vector.
/// @param this The vector to be check.
/// @return The size of the vector as unsigned int.
static unsigned int size(vector_t *this)
{
    return this->_size;
}

/// @brief It returns if the vector is empty or not.
/// @param this The vector to be check.
/// @return True, or false if the vector isn't empty.
static bool empty(vector_t *this)
{
    if (this->_size)
        return false;
    return true;
}

/// @brief It clears the vector, by setting the size to 0.
/// @param this The vector to be clear.
/// @return 0.
static int clear(vector_t *this)
{
    this->_size = 0;
    return 0;
}

/// @brief It erases an element of a vector at a given index.
/// It also moves all following elements in the vector.
/// @param this The vector on which the element will be removed.
/// @param index The element position on the vector to be removed.
/// @return 0, or -1 if an error occurs.
static int erase(vector_t *this, unsigned int index)
{
    if (index > this->_size)
        return -1;
    memcpy((char *)this->pointer + index * this->_element_size, (char *)this->pointer + (index + 1) * this->_element_size, (this->_size - (index + 1)) * this->_element_size);
    this->_size--;
    return 0;
}

/// @brief It removes the last element of a vector.
/// @param this The vector on which the element will be removed.
/// @return 0.
static int pop_back(vector_t *this)
{
    this->_size--;
    return 0;
}

/// @brief The print_at function prints an element at the given index
/// using print_fct function pointer.
/// The format dependant on how print_fct function pointer print the data.
/// @param this The vector on which print an element.
/// @param index The position of the element to print.
/// @param print_fct The function pointer used to know how to print an
/// element.
/// @return It returns the value of print_fct, or -1 if an error occurs.
static int print_at(vector_t *this, unsigned int index, int (*print_fct)(void *data))
{
    if (index > this->_size)
        return -1;
    return print_fct((char *)this->pointer + index * this->_element_size);
}

/// @brief The print function prints all elements of the vector.
/// The format dependant on how print_fct function pointer print the data.
/// @param this The vector on which print all elements.
/// @param print_fct The function pointer used to know how to print an
/// element.
/// @return 0, or -1 if print_fct return -1.
static int print(vector_t *this, int (*print_fct)(void *data))
{
    printf("[");
    fflush(stdout);
    for (unsigned int i = 0; i < this->_size; i++) {
        if (this->print_at(this, i, print_fct) < 0)
            return -1;
        if (i + 1 < this->_size) {
            printf(", ");
            fflush(stdout);
        }
    }
    printf("]\n");
    fflush(stdout);
    return 0;
}

/// @brief The emplace function adds an element at the given index.
/// It increases the capacity of the vector if needed.
/// @param this The vector on which adds an element.
/// @param data The data to be added.
/// @param index The index where the data must be added.
/// @return 0, or -1 if an error occurs.
static int emplace(vector_t *this, void *data, unsigned int index)
{
    void *ptr = NULL;

    if (index > this->_capacity)
        return -1;
    if (this->_size == this->_capacity) {
        this->pointer = realloc(this->pointer, (this->_capacity + 1) * this->_element_size);
        if (!this->pointer)
            return -1;
        this->_capacity++;
    }
    ptr = (char *)this->pointer + index * this->_element_size;
    for (unsigned int i = this->_size; i > index; i--) {
        memcpy((char *)this->pointer + i * this->_element_size, (char *)this->pointer + (i - 1) * this->_element_size, this->_element_size);
    }
    memcpy(ptr, data, this->_element_size);
    this->_size++;
    return 0;
}

/// @brief The emplace_back function adds an element at the end.
/// It increases the capacity of the vector if needed.
/// @param this The vector on which adds an element.
/// @param data The data to be added.
/// @return 0, or -1 if an error occurs.
static int emplace_back(vector_t *this, void *data)
{
    if (this->_size == this->_capacity) {
        this->pointer = realloc(this->pointer, (this->_capacity + 1) * this->_element_size);
        if (!this->pointer)
            return -1;
        this->_capacity++;
    }
    memcpy((char *)this->pointer + this->_size * this->_element_size, data, this->_element_size);
    this->_size++;
    return 0;
}

/// @brief This is the destructor of a vector. It frees the pointer.
/// @param this The vector to be free.
static void destructor(vector_t *this)
{
    if (this->pointer)
        free(this->pointer);
}

int vector_constructor(vector_t *this, unsigned int element_size, unsigned int element_number)
{
    this->_element_size = element_size;
    this->pointer = malloc(this->_element_size * element_number);
    if (!this->pointer)
        return - 1;
    this->_size = 0;
    this->_capacity = element_number;
    this->destructor = &destructor;
    this->emplace = &emplace;
    this->emplace_back = &emplace_back;
    this->print_at = &print_at;
    this->print = &print;
    this->clear = &clear;
    this->erase = &erase;
    this->pop_back = &pop_back;
    this->swap = &swap;
    this->at = &at;
    this->back = &back;
    this->front = &front;
    this->empty = &empty;
    this->size = &size;
    this->capacity = &capacity;
    this->shrink_to_fit = &shrink_to_fit;
    return 0;
}
