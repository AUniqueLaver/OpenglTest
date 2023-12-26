set(NAME "Core")

set(SOURCES
    MockClass.cpp
    )

set(HEADERS
    MockClass.hpp
    )

add_library(${NAME} ${SOURCES} ${HEADERS})
