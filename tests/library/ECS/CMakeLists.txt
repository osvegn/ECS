set(ECS_TESTS_ROOT ${PROJECT_SOURCE_DIR}/tests/library/ECS)
set(TARGET ecs_tests)
set(SOURCE
    ${ECS_TESTS_ROOT}/world_entity_tests.c
    ${ECS_TESTS_ROOT}/world_resource_tests.c
    ${ECS_TESTS_ROOT}/world_system_tests.c
    ${ECS_TESTS_ROOT}/world_constructor_tests.c
    ${ECS_TESTS_ROOT}/entity_component_tests.c
    ${ECS_TESTS_ROOT}/world_logger_tests.c
    ${ECS_TESTS_ROOT}/world_tests.c
)

add_executable(${TARGET} ${SOURCE})

target_link_libraries(${TARGET}
    ecs
)

add_test(${TARGET} ${TARGET})

# set_target_properties(${TARGET}
#     PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/
# )