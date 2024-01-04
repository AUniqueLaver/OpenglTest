add_executable(${PROJECT_NAME})

set(SOURCES
    main.cpp
    )

set(HEADERS
   
    )
 
target_sources(${PROJECT_NAME} PUBLIC ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PUBLIC Core Project_Warnings)
