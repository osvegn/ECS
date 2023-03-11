set(VECTOR_SOURCE_ROOT ${PROJECT_SOURCE_DIR}/lib/vector/source)
set(VECTOR_INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/lib/vector/include)
set(TARGET vector)
set(VECTOR_SOURCE
    ${VECTOR_SOURCE_ROOT}/vector.c
)
set_property(GLOBAL PROPERTY VECTOR_SOURCE ${VECTOR_SOURCE})

add_library(${TARGET} ${VECTOR_SOURCE})

target_include_directories(${TARGET}
    PUBLIC ${VECTOR_INCLUDE_ROOT}
)
