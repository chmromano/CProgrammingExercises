# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "/Users/christopher/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5284.51/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/christopher/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5284.51/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/christopher/CLionProjects/Exercise_10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/christopher/CLionProjects/Exercise_10/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Exercise_10.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Exercise_10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Exercise_10.dir/flags.make

CMakeFiles/Exercise_10.dir/main.c.o: CMakeFiles/Exercise_10.dir/flags.make
CMakeFiles/Exercise_10.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christopher/CLionProjects/Exercise_10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Exercise_10.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Exercise_10.dir/main.c.o -c /Users/christopher/CLionProjects/Exercise_10/main.c

CMakeFiles/Exercise_10.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Exercise_10.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/christopher/CLionProjects/Exercise_10/main.c > CMakeFiles/Exercise_10.dir/main.c.i

CMakeFiles/Exercise_10.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Exercise_10.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/christopher/CLionProjects/Exercise_10/main.c -o CMakeFiles/Exercise_10.dir/main.c.s

# Object files for target Exercise_10
Exercise_10_OBJECTS = \
"CMakeFiles/Exercise_10.dir/main.c.o"

# External object files for target Exercise_10
Exercise_10_EXTERNAL_OBJECTS =

Exercise_10: CMakeFiles/Exercise_10.dir/main.c.o
Exercise_10: CMakeFiles/Exercise_10.dir/build.make
Exercise_10: CMakeFiles/Exercise_10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/christopher/CLionProjects/Exercise_10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Exercise_10"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Exercise_10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Exercise_10.dir/build: Exercise_10
.PHONY : CMakeFiles/Exercise_10.dir/build

CMakeFiles/Exercise_10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Exercise_10.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Exercise_10.dir/clean

CMakeFiles/Exercise_10.dir/depend:
	cd /Users/christopher/CLionProjects/Exercise_10/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/christopher/CLionProjects/Exercise_10 /Users/christopher/CLionProjects/Exercise_10 /Users/christopher/CLionProjects/Exercise_10/cmake-build-debug /Users/christopher/CLionProjects/Exercise_10/cmake-build-debug /Users/christopher/CLionProjects/Exercise_10/cmake-build-debug/CMakeFiles/Exercise_10.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Exercise_10.dir/depend

