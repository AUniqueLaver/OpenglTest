
option(DEACTIVATE_LOGGING "Disable logging" OFF)
  if(DEACTIVATE_LOGGING)
    add_compile_definitions(DEACTIVATE_LOGGING)
  endif()

option(DEBUG "Enable debugging or logging" ON)
  if(DEBUG OR CMAKE_BUILD_TYPE STREQUAL "Debug")
     add_compile_definitions(DEBUG)
  endif()
