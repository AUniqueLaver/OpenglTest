set(NAME "Core")

file(GLOB CURRENT_DIR
     *.cpp
     *.hpp
    )

file(GLOB_RECURSE CORE
     Core/*.cpp
     Core/*.hpp
    )

file(GLOB_RECURSE RENDER
    Render/*.cpp
    Render/*.hpp
    )

file(GLOB_RECURSE SCENES
     Render/Scenes/Scene1/*.cpp
     Render/Scenes/Scene1/*.hpp
    )

file(GLOB_RECURSE EXTRA
     Extra/*.cpp
     Extra/*.hpp
    )

file(GLOB_RECURSE WINDOW
    Window/*.cpp
    Window/*.hpp
    )

add_library(${NAME} STATIC
            ${CURRENT_DIR} ${RENDER} ${EXTRA} ${WINDOW}
            ${CORE} ${SCENES}
           )

#When making new directories, remember to
#update the copy command.

add_custom_target(Copies_Directory ALL
  COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
  ${CMAKE_CURRENT_SOURCE_DIR}/Assets
  ${PROJECT_BINARY_DIR}/$<CONFIG>/bin/Assets
  COMMENT "Copying assets to binary dir..."
  ) 

add_dependencies(${PROJECT_NAME} Copies_Directory)

target_link_libraries(${NAME} PUBLIC vendor Project_Warnings)

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
