# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/alexchan_1/Project Files/C++/C++ projects/3test"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug"

# Include any dependencies generated for this target.
include vendor/sdl3/CMakeFiles/SDL3_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include vendor/sdl3/CMakeFiles/SDL3_test.dir/compiler_depend.make

# Include the progress variables for this target.
include vendor/sdl3/CMakeFiles/SDL3_test.dir/progress.make

# Include the compile flags for this target's objects.
include vendor/sdl3/CMakeFiles/SDL3_test.dir/flags.make

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_assert.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/flags.make
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_assert.c.o: /Users/alexchan_1/Project\ Files/C++/C++\ projects/3test/vendor/sdl3/src/test/SDL_test_assert.c
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_assert.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_assert.c.o"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_assert.c.o -MF CMakeFiles/SDL3_test.dir/src/test/SDL_test_assert.c.o.d -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_assert.c.o -c "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_assert.c"

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_assert.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL3_test.dir/src/test/SDL_test_assert.c.i"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_assert.c" > CMakeFiles/SDL3_test.dir/src/test/SDL_test_assert.c.i

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_assert.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL3_test.dir/src/test/SDL_test_assert.c.s"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_assert.c" -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_assert.c.s

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_common.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/flags.make
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_common.c.o: /Users/alexchan_1/Project\ Files/C++/C++\ projects/3test/vendor/sdl3/src/test/SDL_test_common.c
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_common.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_common.c.o"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_common.c.o -MF CMakeFiles/SDL3_test.dir/src/test/SDL_test_common.c.o.d -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_common.c.o -c "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_common.c"

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL3_test.dir/src/test/SDL_test_common.c.i"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_common.c" > CMakeFiles/SDL3_test.dir/src/test/SDL_test_common.c.i

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL3_test.dir/src/test/SDL_test_common.c.s"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_common.c" -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_common.c.s

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_compare.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/flags.make
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_compare.c.o: /Users/alexchan_1/Project\ Files/C++/C++\ projects/3test/vendor/sdl3/src/test/SDL_test_compare.c
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_compare.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_compare.c.o"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_compare.c.o -MF CMakeFiles/SDL3_test.dir/src/test/SDL_test_compare.c.o.d -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_compare.c.o -c "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_compare.c"

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_compare.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL3_test.dir/src/test/SDL_test_compare.c.i"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_compare.c" > CMakeFiles/SDL3_test.dir/src/test/SDL_test_compare.c.i

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_compare.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL3_test.dir/src/test/SDL_test_compare.c.s"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_compare.c" -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_compare.c.s

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_crc32.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/flags.make
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_crc32.c.o: /Users/alexchan_1/Project\ Files/C++/C++\ projects/3test/vendor/sdl3/src/test/SDL_test_crc32.c
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_crc32.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_crc32.c.o"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_crc32.c.o -MF CMakeFiles/SDL3_test.dir/src/test/SDL_test_crc32.c.o.d -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_crc32.c.o -c "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_crc32.c"

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_crc32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL3_test.dir/src/test/SDL_test_crc32.c.i"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_crc32.c" > CMakeFiles/SDL3_test.dir/src/test/SDL_test_crc32.c.i

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_crc32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL3_test.dir/src/test/SDL_test_crc32.c.s"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_crc32.c" -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_crc32.c.s

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_font.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/flags.make
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_font.c.o: /Users/alexchan_1/Project\ Files/C++/C++\ projects/3test/vendor/sdl3/src/test/SDL_test_font.c
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_font.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_font.c.o"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_font.c.o -MF CMakeFiles/SDL3_test.dir/src/test/SDL_test_font.c.o.d -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_font.c.o -c "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_font.c"

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_font.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL3_test.dir/src/test/SDL_test_font.c.i"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_font.c" > CMakeFiles/SDL3_test.dir/src/test/SDL_test_font.c.i

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_font.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL3_test.dir/src/test/SDL_test_font.c.s"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_font.c" -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_font.c.s

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_fuzzer.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/flags.make
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_fuzzer.c.o: /Users/alexchan_1/Project\ Files/C++/C++\ projects/3test/vendor/sdl3/src/test/SDL_test_fuzzer.c
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_fuzzer.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_fuzzer.c.o"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_fuzzer.c.o -MF CMakeFiles/SDL3_test.dir/src/test/SDL_test_fuzzer.c.o.d -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_fuzzer.c.o -c "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_fuzzer.c"

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_fuzzer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL3_test.dir/src/test/SDL_test_fuzzer.c.i"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_fuzzer.c" > CMakeFiles/SDL3_test.dir/src/test/SDL_test_fuzzer.c.i

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_fuzzer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL3_test.dir/src/test/SDL_test_fuzzer.c.s"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_fuzzer.c" -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_fuzzer.c.s

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_harness.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/flags.make
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_harness.c.o: /Users/alexchan_1/Project\ Files/C++/C++\ projects/3test/vendor/sdl3/src/test/SDL_test_harness.c
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_harness.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_harness.c.o"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_harness.c.o -MF CMakeFiles/SDL3_test.dir/src/test/SDL_test_harness.c.o.d -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_harness.c.o -c "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_harness.c"

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_harness.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL3_test.dir/src/test/SDL_test_harness.c.i"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_harness.c" > CMakeFiles/SDL3_test.dir/src/test/SDL_test_harness.c.i

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_harness.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL3_test.dir/src/test/SDL_test_harness.c.s"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_harness.c" -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_harness.c.s

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_log.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/flags.make
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_log.c.o: /Users/alexchan_1/Project\ Files/C++/C++\ projects/3test/vendor/sdl3/src/test/SDL_test_log.c
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_log.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building C object vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_log.c.o"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_log.c.o -MF CMakeFiles/SDL3_test.dir/src/test/SDL_test_log.c.o.d -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_log.c.o -c "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_log.c"

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL3_test.dir/src/test/SDL_test_log.c.i"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_log.c" > CMakeFiles/SDL3_test.dir/src/test/SDL_test_log.c.i

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL3_test.dir/src/test/SDL_test_log.c.s"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_log.c" -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_log.c.s

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_md5.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/flags.make
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_md5.c.o: /Users/alexchan_1/Project\ Files/C++/C++\ projects/3test/vendor/sdl3/src/test/SDL_test_md5.c
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_md5.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building C object vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_md5.c.o"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_md5.c.o -MF CMakeFiles/SDL3_test.dir/src/test/SDL_test_md5.c.o.d -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_md5.c.o -c "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_md5.c"

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_md5.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL3_test.dir/src/test/SDL_test_md5.c.i"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_md5.c" > CMakeFiles/SDL3_test.dir/src/test/SDL_test_md5.c.i

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_md5.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL3_test.dir/src/test/SDL_test_md5.c.s"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_md5.c" -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_md5.c.s

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_memory.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/flags.make
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_memory.c.o: /Users/alexchan_1/Project\ Files/C++/C++\ projects/3test/vendor/sdl3/src/test/SDL_test_memory.c
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_memory.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building C object vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_memory.c.o"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_memory.c.o -MF CMakeFiles/SDL3_test.dir/src/test/SDL_test_memory.c.o.d -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_memory.c.o -c "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_memory.c"

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_memory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL3_test.dir/src/test/SDL_test_memory.c.i"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_memory.c" > CMakeFiles/SDL3_test.dir/src/test/SDL_test_memory.c.i

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_memory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL3_test.dir/src/test/SDL_test_memory.c.s"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_memory.c" -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_memory.c.s

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_random.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/flags.make
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_random.c.o: /Users/alexchan_1/Project\ Files/C++/C++\ projects/3test/vendor/sdl3/src/test/SDL_test_random.c
vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_random.c.o: vendor/sdl3/CMakeFiles/SDL3_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building C object vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_random.c.o"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_random.c.o -MF CMakeFiles/SDL3_test.dir/src/test/SDL_test_random.c.o.d -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_random.c.o -c "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_random.c"

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_random.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL3_test.dir/src/test/SDL_test_random.c.i"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_random.c" > CMakeFiles/SDL3_test.dir/src/test/SDL_test_random.c.i

vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_random.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL3_test.dir/src/test/SDL_test_random.c.s"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3/src/test/SDL_test_random.c" -o CMakeFiles/SDL3_test.dir/src/test/SDL_test_random.c.s

# Object files for target SDL3_test
SDL3_test_OBJECTS = \
"CMakeFiles/SDL3_test.dir/src/test/SDL_test_assert.c.o" \
"CMakeFiles/SDL3_test.dir/src/test/SDL_test_common.c.o" \
"CMakeFiles/SDL3_test.dir/src/test/SDL_test_compare.c.o" \
"CMakeFiles/SDL3_test.dir/src/test/SDL_test_crc32.c.o" \
"CMakeFiles/SDL3_test.dir/src/test/SDL_test_font.c.o" \
"CMakeFiles/SDL3_test.dir/src/test/SDL_test_fuzzer.c.o" \
"CMakeFiles/SDL3_test.dir/src/test/SDL_test_harness.c.o" \
"CMakeFiles/SDL3_test.dir/src/test/SDL_test_log.c.o" \
"CMakeFiles/SDL3_test.dir/src/test/SDL_test_md5.c.o" \
"CMakeFiles/SDL3_test.dir/src/test/SDL_test_memory.c.o" \
"CMakeFiles/SDL3_test.dir/src/test/SDL_test_random.c.o"

# External object files for target SDL3_test
SDL3_test_EXTERNAL_OBJECTS =

vendor/sdl3/libSDL3_test.a: vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_assert.c.o
vendor/sdl3/libSDL3_test.a: vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_common.c.o
vendor/sdl3/libSDL3_test.a: vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_compare.c.o
vendor/sdl3/libSDL3_test.a: vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_crc32.c.o
vendor/sdl3/libSDL3_test.a: vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_font.c.o
vendor/sdl3/libSDL3_test.a: vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_fuzzer.c.o
vendor/sdl3/libSDL3_test.a: vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_harness.c.o
vendor/sdl3/libSDL3_test.a: vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_log.c.o
vendor/sdl3/libSDL3_test.a: vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_md5.c.o
vendor/sdl3/libSDL3_test.a: vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_memory.c.o
vendor/sdl3/libSDL3_test.a: vendor/sdl3/CMakeFiles/SDL3_test.dir/src/test/SDL_test_random.c.o
vendor/sdl3/libSDL3_test.a: vendor/sdl3/CMakeFiles/SDL3_test.dir/build.make
vendor/sdl3/libSDL3_test.a: vendor/sdl3/CMakeFiles/SDL3_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Linking C static library libSDL3_test.a"
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && $(CMAKE_COMMAND) -P CMakeFiles/SDL3_test.dir/cmake_clean_target.cmake
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL3_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
vendor/sdl3/CMakeFiles/SDL3_test.dir/build: vendor/sdl3/libSDL3_test.a
.PHONY : vendor/sdl3/CMakeFiles/SDL3_test.dir/build

vendor/sdl3/CMakeFiles/SDL3_test.dir/clean:
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" && $(CMAKE_COMMAND) -P CMakeFiles/SDL3_test.dir/cmake_clean.cmake
.PHONY : vendor/sdl3/CMakeFiles/SDL3_test.dir/clean

vendor/sdl3/CMakeFiles/SDL3_test.dir/depend:
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/alexchan_1/Project Files/C++/C++ projects/3test" "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/sdl3" "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug" "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3" "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/build/debug/vendor/sdl3/CMakeFiles/SDL3_test.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : vendor/sdl3/CMakeFiles/SDL3_test.dir/depend

