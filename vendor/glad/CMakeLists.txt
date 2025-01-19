cmake_minimum_required(VERSION 3.27)
project(Glad DESCRIPTION "Glad loader" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(LIBRARY "glad")

set(SOURCES
    include/glad/glad.h
    include/KHR/khrplatform.h
    src/glad.c
   )

add_library(${LIBRARY} STATIC ${SOURCES})

target_include_directories(${LIBRARY} PUBLIC include/)
