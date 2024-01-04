function(set_project_warnings project_name)
  option(WARNING_AS_ERRORS "Treat warnings as errors" TRUE)
   if(WARNING_AS_ERRORS)
    message(STATUS "Treating warnings as errors")
   endif()

   set(CLANG_WARNINGS
       -Wall
       -Wextra
       -Wshadow
       -Wnon-virtual-dtor
       -Wcast-align
       -Wunused
       -Woverloaded-virtual
       -Wpedantic
       -Wconversion
       -Wsign-conversion
       -Wnull-dereference
       # -Wformat=2
       )

  if(WARNING_AS_ERRORS)
    set(CLANG_WARNINGS ${CLANG_WARNINGS} -Werror)
  else()
     message("No compiler warnings set")
  endif()

  target_compile_options(${project_name} INTERFACE ${CLANG_WARNINGS})

endfunction()
