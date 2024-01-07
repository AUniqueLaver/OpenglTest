add_subdirectory(glad)
add_subdirectory(glm)
add_subdirectory(sdl3)
add_subdirectory(uLog)

add_library(vendor INTERFACE)

target_link_libraries(vendor INTERFACE SDL3::SDL3 glad glm ULogger)
