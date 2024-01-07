cmake_minimum_required(VERSION 3.27)
project(3test VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(Cmake/ProjectSettings.cmake)

add_library(Project_Warnings INTERFACE)
include(Cmake/ProjectWarnings.cmake)
set_project_warnings(Project_Warnings)

add_subdirectory(src)
add_subdirectory(vendor) 
