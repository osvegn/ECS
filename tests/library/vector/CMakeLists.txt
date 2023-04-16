set(VECTOR_TESTS_ROOT ${PROJECT_SOURCE_DIR}/tests/library/vector)
set(TARGET vector_tests)
set(SOURCE
    ${VECTOR_TESTS_ROOT}/vector_tests.c
)

add_executable(${TARGET} ${SOURCE})

target_link_libraries(${TARGET}
    vector
)

add_test(${TARGET} ${TARGET})

# set_target_properties(${TARGET}
#     PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/
# )