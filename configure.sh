#! /bin/bash

cmake . -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug \
  -DDEACTIVE_LOGGING=FALSE \
  -DWARNING_AS_ERRORS=TRUE \
  -B build/debug 

#-DCMAKE_SHARED_LIBS for shared libraries
