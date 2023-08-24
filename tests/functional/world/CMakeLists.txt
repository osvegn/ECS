set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/functional/world)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/functional/world)

set(SRC
    ${SRC_ROOT}/test_world_destructor_with_entity.c
    ${SRC_ROOT}/test_world_destructor_with_resource.c
)
create_tests_from_sources()

add_subdirectory(system)