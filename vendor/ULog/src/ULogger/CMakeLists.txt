set(NAME "uLogger")

file(GLOB CURRENT_DIR
     *.cpp
     *.hpp
    )

file(GLOB_RECURSE CORE
    uLogger/*.cpp
    uLogger/*.hpp
    )

file(GLOB_RECURSE CORE_SINKS 
    uLogger/Sinks/*.cpp
    uLogger/Sinks/*.hpp
    )

file(GLOB_RECURSE CORE_DETAILS
    uLogger/Details/*.cpp
    uLogger/Details/*.hpp
    )

add_library(${NAME} SHARED
              ${CURRENT_DIR} ${CORE} ${CORE_SINKS} ${CORE_DETAILS}
           )

# target_link_libraries(${NAME} PRIVATE vendor)

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
