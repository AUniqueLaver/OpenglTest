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
CMAKE_BINARY_DIR = "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug"

# Utility rule file for Copies_Directory.

# Include any custom commands dependencies for this target.
include src/App/CMakeFiles/Copies_Directory.dir/compiler_depend.make

# Include the progress variables for this target.
include src/App/CMakeFiles/Copies_Directory.dir/progress.make

src/App/CMakeFiles/Copies_Directory:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir="/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Copying assets to binary dir..."
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/src/App" && /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -E copy_directory_if_different /Users/alexchan_1/Project\ Files/C++/C++\ projects/3test/src/Assets /Users/alexchan_1/Project\ Files/C++/C++\ projects/3test/build/debug/src/App

Copies_Directory: src/App/CMakeFiles/Copies_Directory
Copies_Directory: src/App/CMakeFiles/Copies_Directory.dir/build.make
.PHONY : Copies_Directory

# Rule to build all files generated by this target.
src/App/CMakeFiles/Copies_Directory.dir/build: Copies_Directory
.PHONY : src/App/CMakeFiles/Copies_Directory.dir/build

src/App/CMakeFiles/Copies_Directory.dir/clean:
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/src/App" && $(CMAKE_COMMAND) -P CMakeFiles/Copies_Directory.dir/cmake_clean.cmake
.PHONY : src/App/CMakeFiles/Copies_Directory.dir/clean

src/App/CMakeFiles/Copies_Directory.dir/depend:
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/alexchan_1/Project Files/C++/C++ projects/3test" "/Users/alexchan_1/Project Files/C++/C++ projects/3test/src/App" "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug" "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/src/App" "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/src/App/CMakeFiles/Copies_Directory.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : src/App/CMakeFiles/Copies_Directory.dir/depend

