add_library(voyage_core STATIC
    src/math.cpp
)

target_include_directories(voyage_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(voyage_core PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
)
