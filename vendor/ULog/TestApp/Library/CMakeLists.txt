set(NAME "AppLib")

include(Cmake/ProjectSettings.cmake)

file(GLOB_RECURSE LIBS
    Library/*.cpp
    Library/*.hpp
    )

add_library(${NAME}
              ${LIBS}
           )

if(ENABLE_TEST_APP)
target_link_libraries(${NAME} PUBLIC uLogger uLog_PWarnings)
endif()

target_link_libraries(${NAME} PUBLIC uLogger)

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
