# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ericbruh/Downloads/c-lang/learn_raylib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ericbruh/Downloads/c-lang/learn_raylib/build

# Include any dependencies generated for this target.
include CMakeFiles/ray_game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ray_game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ray_game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ray_game.dir/flags.make

CMakeFiles/ray_game.dir/src/main.c.o: CMakeFiles/ray_game.dir/flags.make
CMakeFiles/ray_game.dir/src/main.c.o: ../src/main.c
CMakeFiles/ray_game.dir/src/main.c.o: CMakeFiles/ray_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ericbruh/Downloads/c-lang/learn_raylib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ray_game.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ray_game.dir/src/main.c.o -MF CMakeFiles/ray_game.dir/src/main.c.o.d -o CMakeFiles/ray_game.dir/src/main.c.o -c /home/ericbruh/Downloads/c-lang/learn_raylib/src/main.c

CMakeFiles/ray_game.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ray_game.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ericbruh/Downloads/c-lang/learn_raylib/src/main.c > CMakeFiles/ray_game.dir/src/main.c.i

CMakeFiles/ray_game.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ray_game.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ericbruh/Downloads/c-lang/learn_raylib/src/main.c -o CMakeFiles/ray_game.dir/src/main.c.s

# Object files for target ray_game
ray_game_OBJECTS = \
"CMakeFiles/ray_game.dir/src/main.c.o"

# External object files for target ray_game
ray_game_EXTERNAL_OBJECTS =

ray_game: CMakeFiles/ray_game.dir/src/main.c.o
ray_game: CMakeFiles/ray_game.dir/build.make
ray_game: /usr/local/lib/libraylib.so
ray_game: CMakeFiles/ray_game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ericbruh/Downloads/c-lang/learn_raylib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ray_game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ray_game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ray_game.dir/build: ray_game
.PHONY : CMakeFiles/ray_game.dir/build

CMakeFiles/ray_game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ray_game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ray_game.dir/clean

CMakeFiles/ray_game.dir/depend:
	cd /home/ericbruh/Downloads/c-lang/learn_raylib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ericbruh/Downloads/c-lang/learn_raylib /home/ericbruh/Downloads/c-lang/learn_raylib /home/ericbruh/Downloads/c-lang/learn_raylib/build /home/ericbruh/Downloads/c-lang/learn_raylib/build /home/ericbruh/Downloads/c-lang/learn_raylib/build/CMakeFiles/ray_game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ray_game.dir/depend

