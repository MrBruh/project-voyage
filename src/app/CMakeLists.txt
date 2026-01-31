add_executable(ProjectVoyage main.cpp)

set_target_properties(ProjectVoyage PROPERTIES OUTPUT_NAME "project-voyage")

target_link_libraries(ProjectVoyage PRIVATE voyage_ui)
