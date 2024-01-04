#! /bin/bash

cmake . -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug \
  -DWARNING_AS_ERRORS=TRUE -B build/debug 
