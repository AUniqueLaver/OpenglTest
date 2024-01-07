set(NAME "ULogger")

file(GLOB CURRENT_DIR
     *.cpp
     *.hpp
    )

file(GLOB_RECURSE CORE
    ULogger/*.cpp
    ULogger/*.hpp
    )

file(GLOB_RECURSE CORE_SINKS 
    ULogger/Sinks/*.cpp
    ULogger/Sinks/*.hpp
    )

file(GLOB_RECURSE CORE_DETAILS
    ULogger/Details/*.cpp
    ULogger/Details/*.hpp
    )

add_library(${NAME} SHARED
              ${CURRENT_DIR} ${CORE} ${CORE_SINKS} ${CORE_DETAILS}
           )

target_link_libraries(${NAME} PRIVATE vendor)

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
