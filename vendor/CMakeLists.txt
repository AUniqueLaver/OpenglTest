add_subdirectory(glad)
add_subdirectory(glm)
add_subdirectory(uLog)
add_subdirectory(stb_image)

add_library(vendor INTERFACE)

target_link_libraries(vendor INTERFACE sdl3 glad glm uLogger stb_image)
