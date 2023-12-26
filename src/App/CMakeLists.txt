add_executable(${PROJECT_NAME})

set(SOURCES
    main.cpp
    )

set(HEADERS
   
    )

add_custom_target(Copies_Directory ALL
  COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
  ${PROJECT_SOURCE_DIR}/src/Assets
  ${PROJECT_BINARY_DIR}/src/App
  COMMENT "Copying assets to binary dir..."
  ) 
   
add_dependencies(${PROJECT_NAME} Copies_Directory)
target_sources(${PROJECT_NAME} PUBLIC ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} Core Project_Warnings)
