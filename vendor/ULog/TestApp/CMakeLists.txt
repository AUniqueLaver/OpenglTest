set(TEST_PROJECT TestApp)

add_executable(${TEST_PROJECT})

set_property(TARGET ${TEST_PROJECT} PROPERTY CXX_STANDARD 20)

set(SOURCES
    TestApp/main.cpp
    )

set(HEADERS
   
    )

add_custom_target(uLogCopies_Directory ALL
  COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
  ${CMAKE_CURRENT_SOURCE_DIR}/Assets
  ${PROJECT_BINARY_DIR}/$<CONFIG>/bin/Assets
  COMMENT "Copying assets to binary dir..."
  ) 

add_dependencies(${TEST_PROJECT} uLogCopies_Directory)
 
target_sources(${TEST_PROJECT} PUBLIC ${SOURCES} ${HEADERS})

target_link_libraries(${TEST_PROJECT} PUBLIC AppLib)

add_subdirectory(Library)
