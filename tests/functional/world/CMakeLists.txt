set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/functional/world)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/functional/world)

set(SRC
    ${SRC_ROOT}/world_destructor_with_entity.c
    ${SRC_ROOT}/world_destructor_with_resource.c
    ${SRC_ROOT}/world_join_entities.c
    ${SRC_ROOT}/client.c
    ${SRC_ROOT}/server.c
)
create_tests_from_sources()

add_subdirectory(system)