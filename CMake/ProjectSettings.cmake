
option(DEACTIVATE_LOGGING "Disable logging" OFF)
  if(DEACTIVATE_LOGGING)
   message(STATUS "Deactivating logging")
    add_compile_definitions(DEACTIVATE_LOGGING)
  endif()

option(DEBUG "Enable debugging or logging" ON)
  if(DEBUG OR CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug mode")
     add_compile_definitions(DEBUG)
  endif()
