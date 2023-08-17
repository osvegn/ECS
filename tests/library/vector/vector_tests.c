/*
 * Filename:vector_tests.c
 * Path: tests/library/vector
 * Created Date: Thursday, December 29th 2022, 10:41:19 pm
 * Author: osvegn
 *
 * Copyright (c) 2023 ECS
 */

#include <criterion/criterion.h>
#include "vector.h"

Test(a, a)
{
    cr_assert_eq(1, 1);
}

Test(construct_vector, construct_vector)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);

    cr_assert_eq(rvalue, 0);
    vector.destructor(&vector);
    cr_assert_eq(0, 0);
}

Test(vector_emplace_back, vector_emplace_back)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    vector.destructor(&vector);
    cr_assert_eq(0, 0);
}

Test(vector_emplace, vector_emplace)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace(&vector, &data, 0);
    vector.destructor(&vector);
    cr_assert_eq(0, 0);
}

Test(vector_clear, vector_clear)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    vector.emplace_back(&vector, &data);
    vector.emplace_back(&vector, &data);
    vector.emplace_back(&vector, &data);
    rvalue = vector.size(&vector);
    cr_assert_eq(rvalue, 4);
    vector.clear(&vector);
    rvalue = vector.size(&vector);
    cr_assert_eq(rvalue, 0);
    vector.destructor(&vector);
}

Test(vector_at, vector_at_valid)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    rvalue = *(int *)vector.at(&vector, 0);
    cr_assert_eq(rvalue, 10);
    vector.destructor(&vector);
}

Test(vector_at, vector_at_too_high_index)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;
    void *ptr;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    ptr = vector.at(&vector, 10);
    cr_assert_eq(ptr, 0);
    vector.destructor(&vector);
}

Test(vector_at, vector_at_invalid_pointer)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    void *ptr;

    cr_assert_eq(rvalue, 0);
    free(vector.pointer);
    vector.pointer = NULL;
    vector._size = 1;
    ptr = vector.at(&vector, 0);
    cr_assert_eq(ptr, 0);
}

Test(vector_front, vector_front)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    data = 5;
    vector.emplace_back(&vector, &data);
    rvalue = *(int *)vector.front(&vector);
    cr_assert_eq(rvalue, 10);
    vector.destructor(&vector);
}

Test(vector_back, vector_back)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    data = 5;
    vector.emplace_back(&vector, &data);
    rvalue = *(int *)vector.back(&vector);
    cr_assert_eq(rvalue, 5);
    vector.destructor(&vector);
}

Test(vector_back, vector_back_invalid_pointer)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    void *ptr;

    cr_assert_eq(rvalue, 0);
    free(vector.pointer);
    vector.pointer = NULL;
    ptr = vector.back(&vector);
    cr_assert_eq(ptr, 0);
}

Test(vector_capacity, vector_capacity)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);
    unsigned int data = 0;

    cr_assert_eq(rvalue, 0);
    data = vector.capacity(&vector);
    cr_assert_eq(data, 10);
    vector.destructor(&vector);
}

Test(vector_empty, vector_empty_true)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);

    cr_assert_eq(rvalue, 0);
    cr_assert_eq(vector.empty(&vector), true);
}

Test(vector_empty, vector_empty_false)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    cr_assert_eq(vector.empty(&vector), false);
}

Test(vector_swap, vector_swap_valid)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    for (int i = 0; i < 10; i++) {
        vector.emplace_back(&vector, &data);
        data++;
    }
    vector.swap(&vector, 0, 1);
    rvalue = *(int *)vector.at(&vector, 0);
    cr_assert_eq(rvalue, 11);
    rvalue = *(int *)vector.at(&vector, 1);
    cr_assert_eq(rvalue, 10);
    vector.destructor(&vector);
}

Test(vector_swap, vector_swap_element1_invalid_size)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    for (int i = 0; i < 10; i++) {
        vector.emplace_back(&vector, &data);
        data++;
    }
    vector.swap(&vector, 100, 1);
    rvalue = *(int *)vector.at(&vector, 0);
    cr_assert_eq(rvalue, 10);
    rvalue = *(int *)vector.at(&vector, 1);
    cr_assert_eq(rvalue, 11);
    vector.destructor(&vector);
}

Test(vector_swap, vector_swap_element2_invalid_size)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    for (int i = 0; i < 10; i++) {
        vector.emplace_back(&vector, &data);
        data++;
    }
    vector.swap(&vector, 1, 100);
    rvalue = *(int *)vector.at(&vector, 0);
    cr_assert_eq(rvalue, 10);
    rvalue = *(int *)vector.at(&vector, 1);
    cr_assert_eq(rvalue, 11);
    vector.destructor(&vector);
}

Test(vector_shrink_to_fit, vector_shrink_to_fit_failure)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);

    cr_assert_eq(rvalue, 0);
    cr_assert_eq(vector.capacity(&vector), 10);
    cr_assert_eq(vector.shrink_to_fit(&vector), -1);
    cr_assert_eq(vector.capacity(&vector), 0);
    vector.destructor(&vector);
}

Test(vector_shrink_to_fit, vector_shrink_to_fit_success)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    cr_assert_eq(vector.capacity(&vector), 10);
    cr_assert_eq(vector.shrink_to_fit(&vector), 0);
    cr_assert_eq(vector.capacity(&vector), 1);
    vector.destructor(&vector);
}

Test(vecotr_erase, vector_erase_valid)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 10);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    for (int i = 0; i < 10; i++) {
        vector.emplace_back(&vector, &data);
        data++;
    }
    cr_assert_eq(vector.erase(&vector, 1), 0);
    cr_assert_eq(*(int *)vector.at(&vector, 1), 12);
    vector.destructor(&vector);
}