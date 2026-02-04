find_package(SDL2 CONFIG REQUIRED)

add_library(voyage_ui STATIC
    src/application.cpp
    src/renderer.cpp
    src/drawing/primitives.cpp
    src/panel/panel.cpp
    src/panel/system_view.cpp
)

target_include_directories(voyage_ui PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(voyage_ui PUBLIC
    voyage_core
    voyage_simulation
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

set_target_properties(voyage_ui PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
)
