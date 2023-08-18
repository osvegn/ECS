set(ECS_FUNCTIONAL_TESTS_ROOT ${PROJECT_SOURCE_DIR}/tests/functional)

set(TARGET ecs_functional_tests)
set(SOURCE
    ${ECS_FUNCTIONAL_TESTS_ROOT}/main.c
)

add_executable(${TARGET} ${SOURCE})

target_link_libraries(${TARGET}
    ecs
)

target_include_directories(${TARGET}
    PRIVATE ${VECTOR_INCLUDE_ROOT}
)

# set_target_properties(${TARGET}
#     PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/
# )