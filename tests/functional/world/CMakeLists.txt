set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/functional/world)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/functional/world)

set(SRC
    ${SRC_ROOT}/test_world_destructor_with_entity.c
)

create_test(
    TEST_NAME test_world_destructor_with_entity
    TEST_SRC ${SRC}
    TEST_DEPS ecs
    TEST_INCLUDE ${VECTOR_INCLUDE_ROOT}
)

set(SRC
    ${SRC_ROOT}/test_world_destructor_with_resource.c
)

create_test(
    TEST_NAME test_world_destructor_with_resource
    TEST_SRC ${SRC}
    TEST_DEPS ecs
    TEST_INCLUDE ${VECTOR_INCLUDE_ROOT}
)
