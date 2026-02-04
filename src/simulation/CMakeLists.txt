add_library(voyage_simulation STATIC
    src/simulation.cpp
    src/time_system.cpp
    src/ecs/world.cpp
)

target_include_directories(voyage_simulation PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(voyage_simulation PUBLIC voyage_core)

set_target_properties(voyage_simulation PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
)
