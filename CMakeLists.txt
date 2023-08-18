cmake_minimum_required(VERSION 3.16)
project(ECS)

set(ECS_SOURCE_ROOT ${PROJECT_SOURCE_DIR}/source)
set(ECS_INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/include)
set(VECTOR_INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/submodules/vector/include)

set(VECTOR_LIB ${PROJECT_SOURCE_DIR}/submodules/vector/bin/libvector.a)

set(TARGET ecs)

execute_process(COMMAND git submodule update --init --recursive --remote)

option(TESTING OFF)
if(TESTING)
    enable_testing()
    add_compile_options("--coverage" "-fprofile-arcs" "-ftest-coverage")
    add_link_options("--coverage" "-fprofile-arcs" "-ftest-coverage")
    add_subdirectory(tests)
endif()

set(SOURCE
    ${ECS_SOURCE_ROOT}/world.c
    ${ECS_SOURCE_ROOT}/world_entity.c
    ${ECS_SOURCE_ROOT}/world_resource.c
    ${ECS_SOURCE_ROOT}/world_system.c
    ${ECS_SOURCE_ROOT}/world_constructor.c
    ${ECS_SOURCE_ROOT}/entity_component.c
    ${ECS_SOURCE_ROOT}/component_destructor.c
    ${ECS_SOURCE_ROOT}/world_logger.c
)
set_property(GLOBAL PROPERTY VECTOR_SOURCE ${VECTOR_SOURCE})

option(SHARED OFF)
if(SHARED)
    add_library(${TARGET} SHARED ${SOURCE})
else()
    add_library(${TARGET} ${SOURCE})
endif()

target_include_directories(${TARGET}
    PUBLIC ${ECS_INCLUDE_ROOT}
    PRIVATE ${VECTOR_INCLUDE_ROOT}
)

target_link_libraries(${TARGET}
    ${VECTOR_LIB}
)
