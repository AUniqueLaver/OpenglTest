cmake_minimum_required(VERSION 3.27)
project(uLog VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(Cmake/ProjectSettings.cmake)

if(ENABLE_TEST_APP)
add_library(uLog_PWarnings INTERFACE)
include(Cmake/ProjectWarnings.cmake)
set_project_warnings(uLog_PWarnings)
endif()


if(ENABLE_TEST_APP)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
  "${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
  "${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/lib")
endif()

if(ENABLE_TEST_APP)
  add_subdirectory(TestApp)
endif()

add_subdirectory(src)
add_subdirectory(uLogVendors) 
