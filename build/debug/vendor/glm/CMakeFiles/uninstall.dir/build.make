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

# Utility rule file for uninstall.

# Include any custom commands dependencies for this target.
include vendor/glm/CMakeFiles/uninstall.dir/compiler_depend.make

# Include the progress variables for this target.
include vendor/glm/CMakeFiles/uninstall.dir/progress.make

vendor/glm/CMakeFiles/uninstall:
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/vendor/glm" && /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -P /Users/alexchan_1/Project\ Files/C++/C++\ projects/3test/build/debug/cmake_uninstall.cmake

uninstall: vendor/glm/CMakeFiles/uninstall
uninstall: vendor/glm/CMakeFiles/uninstall.dir/build.make
.PHONY : uninstall

# Rule to build all files generated by this target.
vendor/glm/CMakeFiles/uninstall.dir/build: uninstall
.PHONY : vendor/glm/CMakeFiles/uninstall.dir/build

vendor/glm/CMakeFiles/uninstall.dir/clean:
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/vendor/glm" && $(CMAKE_COMMAND) -P CMakeFiles/uninstall.dir/cmake_clean.cmake
.PHONY : vendor/glm/CMakeFiles/uninstall.dir/clean

vendor/glm/CMakeFiles/uninstall.dir/depend:
	cd "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/alexchan_1/Project Files/C++/C++ projects/3test" "/Users/alexchan_1/Project Files/C++/C++ projects/3test/vendor/glm" "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug" "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/vendor/glm" "/Users/alexchan_1/Project Files/C++/C++ projects/3test/build/debug/vendor/glm/CMakeFiles/uninstall.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : vendor/glm/CMakeFiles/uninstall.dir/depend

