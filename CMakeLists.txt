cmake_minimum_required(VERSION 3.16)
project(ECS)

add_subdirectory(lib/vector)

set(ECS_SOURCE_ROOT ${PROJECT_SOURCE_DIR}/source)
set(ECS_INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/include)
set(TARGET ecs)
set(SOURCE
    ${ECS_SOURCE_ROOT}/world.c
    ${ECS_SOURCE_ROOT}/world_entity.c
    ${ECS_SOURCE_ROOT}/world_resource.c
    ${ECS_SOURCE_ROOT}/world_system.c
    ${ECS_SOURCE_ROOT}/world_constructor.c
    ${ECS_SOURCE_ROOT}/entity_component.c
    ${ECS_SOURCE_ROOT}/component_destructor.c
)
set_property(GLOBAL PROPERTY VECTOR_SOURCE ${VECTOR_SOURCE})

add_library(${TARGET} ${SOURCE})

target_include_directories(${TARGET}
    PUBLIC ${ECS_INCLUDE_ROOT}
)

target_link_libraries(${TARGET}
    vector
)

option(TESTING OFF)
if(TESTING)
    enable_testing()
    add_compile_options("-lcriterion" "--coverage" "-fprofile-arcs" "-ftest-coverage")
    add_link_options("-lcriterion" "--coverage" "-fprofile-arcs" "-ftest-coverage")
    add_subdirectory(tests)
endif()
