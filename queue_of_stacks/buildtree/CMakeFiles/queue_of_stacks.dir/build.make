# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pdi-5391/Documentos/data-structures/queue_of_stacks

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pdi-5391/Documentos/data-structures/queue_of_stacks/buildtree

# Include any dependencies generated for this target.
include CMakeFiles/queue_of_stacks.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/queue_of_stacks.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/queue_of_stacks.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/queue_of_stacks.dir/flags.make

CMakeFiles/queue_of_stacks.dir/src/main.cpp.o: CMakeFiles/queue_of_stacks.dir/flags.make
CMakeFiles/queue_of_stacks.dir/src/main.cpp.o: /home/pdi-5391/Documentos/data-structures/queue_of_stacks/src/main.cpp
CMakeFiles/queue_of_stacks.dir/src/main.cpp.o: CMakeFiles/queue_of_stacks.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pdi-5391/Documentos/data-structures/queue_of_stacks/buildtree/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/queue_of_stacks.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/queue_of_stacks.dir/src/main.cpp.o -MF CMakeFiles/queue_of_stacks.dir/src/main.cpp.o.d -o CMakeFiles/queue_of_stacks.dir/src/main.cpp.o -c /home/pdi-5391/Documentos/data-structures/queue_of_stacks/src/main.cpp

CMakeFiles/queue_of_stacks.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queue_of_stacks.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pdi-5391/Documentos/data-structures/queue_of_stacks/src/main.cpp > CMakeFiles/queue_of_stacks.dir/src/main.cpp.i

CMakeFiles/queue_of_stacks.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queue_of_stacks.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pdi-5391/Documentos/data-structures/queue_of_stacks/src/main.cpp -o CMakeFiles/queue_of_stacks.dir/src/main.cpp.s

# Object files for target queue_of_stacks
queue_of_stacks_OBJECTS = \
"CMakeFiles/queue_of_stacks.dir/src/main.cpp.o"

# External object files for target queue_of_stacks
queue_of_stacks_EXTERNAL_OBJECTS =

queue_of_stacks: CMakeFiles/queue_of_stacks.dir/src/main.cpp.o
queue_of_stacks: CMakeFiles/queue_of_stacks.dir/build.make
queue_of_stacks: CMakeFiles/queue_of_stacks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pdi-5391/Documentos/data-structures/queue_of_stacks/buildtree/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable queue_of_stacks"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/queue_of_stacks.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/queue_of_stacks.dir/build: queue_of_stacks
.PHONY : CMakeFiles/queue_of_stacks.dir/build

CMakeFiles/queue_of_stacks.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/queue_of_stacks.dir/cmake_clean.cmake
.PHONY : CMakeFiles/queue_of_stacks.dir/clean

CMakeFiles/queue_of_stacks.dir/depend:
	cd /home/pdi-5391/Documentos/data-structures/queue_of_stacks/buildtree && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pdi-5391/Documentos/data-structures/queue_of_stacks /home/pdi-5391/Documentos/data-structures/queue_of_stacks /home/pdi-5391/Documentos/data-structures/queue_of_stacks/buildtree /home/pdi-5391/Documentos/data-structures/queue_of_stacks/buildtree /home/pdi-5391/Documentos/data-structures/queue_of_stacks/buildtree/CMakeFiles/queue_of_stacks.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/queue_of_stacks.dir/depend
