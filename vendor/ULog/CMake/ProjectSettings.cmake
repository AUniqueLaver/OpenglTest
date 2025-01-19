    message(STATUS "===========================")

option(DEACTIVATE_LOGGING "Disable logging" OFF)
  if(DEACTIVATE_LOGGING)
    message(STATUS "Logging deactivated")
    add_compile_definitions(DEACTIVATE_LOGGING)
  endif()

option(DEBUG "Enable debugging or logging" ON)
  if(DEBUG OR CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Building debug mode")
     add_compile_definitions(DEBUG)
  endif()

option(ENABLE_TEST_APP "Enable app cmake for testing" OFF)
  if(ENABLE_TEST_APP)
    message(STATUS "Building test app")
  endif()

  option(WARNING_AS_ERRORS "Treat warnings as errors" TRUE)
   if(WARNING_AS_ERRORS)
    message(STATUS "Treating warnings as errors")
   endif()

  message(STATUS "===========================")
