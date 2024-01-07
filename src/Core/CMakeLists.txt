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

file(GLOB_RECURSE EXTRA
    Extra/*.cpp
    Extra/*.hpp
    )

file(GLOB_RECURSE WINDOW
    Window/*.cpp
    Window/*.hpp
    )

file(GLOB_RECURSE CORE_SINKS 
    Core/Sinks/*.cpp
    Core/Sinks/*.hpp
    )

file(GLOB_RECURSE CORE_DETAILS
    Core/Details/*.cpp
    Core/Details/*.hpp
    )

add_library(${NAME} 
            ${CURRENT_DIR} ${RENDER} ${EXTRA} ${WINDOW}
            ${CORE} ${CORE_SINKS} ${CORE_DETAILS}
           )

add_custom_target(Copies_Directory ALL
  COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
  ${CMAKE_CURRENT_SOURCE_DIR}/Assets
  ${PROJECT_BINARY_DIR}/src/App/Assets
  COMMENT "Copying assets to binary dir..."
  ) 

add_dependencies(${PROJECT_NAME} Copies_Directory)

target_link_libraries(${NAME} PUBLIC vendor)

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
