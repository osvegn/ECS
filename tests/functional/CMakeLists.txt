set(ECS_FUNCTIONAL_TESTS_ROOT ${PROJECT_SOURCE_DIR}/tests/functional)

function (create_test)
    set (test_name TEST_NAME)
    set (test_src TEST_SRC TEST_DEPS TEST_INCLUDE)
    cmake_parse_arguments(create_test "" "${test_name}" "${test_src}" ${ARGN})

    if (NOT DEFINED create_test_TEST_NAME)
        message (FATAL_ERROR "create_test: TEST_NAME not defined")
    endif()
    if (NOT DEFINED create_test_TEST_SRC)
        message (FATAL_ERROR "create_test: TEST_SRC not defined")
    endif()

    set (SRC "${create_test_TEST_SRC}")
    set (TEST_NAME "${create_test_TEST_NAME}")
    set (TEST_DEPS "${create_test_TEST_DEPS}")
    set (TEST_INCLUDE "${create_test_TEST_INCLUDE}")
    add_executable(${TEST_NAME} ${SRC})
    target_include_directories(${TEST_NAME} PRIVATE ${TEST_INCLUDE})
    target_link_libraries(${TEST_NAME} ${TEST_DEPS} ${CRITERION_LIB})
    add_test(${TEST_NAME} ${TEST_NAME})
endfunction()

function (create_tests_from_sources)
    foreach(SOURCE ${SRC})
    string(REPLACE "/" ";" SOURCE_LIST ${SOURCE})
    list(GET SOURCE_LIST -1 F_NAME)
    string(REPLACE "." ";" T_NAME ${F_NAME})
    list(GET T_NAME 0 NAME)

    create_test(
        TEST_NAME ${NAME}
        TEST_SRC ${SOURCE}
        TEST_DEPS ecs
        TEST_INCLUDE ${VECTOR_INCLUDE_ROOT}
    )

    endforeach()
endfunction()

add_subdirectory(world)
