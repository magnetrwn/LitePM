# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /home/eye/Developer/litepm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eye/Developer/litepm/build

# Include any dependencies generated for this target.
include src/CMakeFiles/litepm_demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/litepm_demo.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/litepm_demo.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/litepm_demo.dir/flags.make

src/CMakeFiles/litepm_demo.dir/codegen:
.PHONY : src/CMakeFiles/litepm_demo.dir/codegen

src/CMakeFiles/litepm_demo.dir/main.c.o: src/CMakeFiles/litepm_demo.dir/flags.make
src/CMakeFiles/litepm_demo.dir/main.c.o: /home/eye/Developer/litepm/src/main.c
src/CMakeFiles/litepm_demo.dir/main.c.o: src/CMakeFiles/litepm_demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/eye/Developer/litepm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/litepm_demo.dir/main.c.o"
	cd /home/eye/Developer/litepm/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/litepm_demo.dir/main.c.o -MF CMakeFiles/litepm_demo.dir/main.c.o.d -o CMakeFiles/litepm_demo.dir/main.c.o -c /home/eye/Developer/litepm/src/main.c

src/CMakeFiles/litepm_demo.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/litepm_demo.dir/main.c.i"
	cd /home/eye/Developer/litepm/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eye/Developer/litepm/src/main.c > CMakeFiles/litepm_demo.dir/main.c.i

src/CMakeFiles/litepm_demo.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/litepm_demo.dir/main.c.s"
	cd /home/eye/Developer/litepm/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eye/Developer/litepm/src/main.c -o CMakeFiles/litepm_demo.dir/main.c.s

# Object files for target litepm_demo
litepm_demo_OBJECTS = \
"CMakeFiles/litepm_demo.dir/main.c.o"

# External object files for target litepm_demo
litepm_demo_EXTERNAL_OBJECTS =

litepm_demo: src/CMakeFiles/litepm_demo.dir/main.c.o
litepm_demo: src/CMakeFiles/litepm_demo.dir/build.make
litepm_demo: src/CMakeFiles/litepm_demo.dir/compiler_depend.ts
litepm_demo: liblitepm_core.a
litepm_demo: src/CMakeFiles/litepm_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/eye/Developer/litepm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../litepm_demo"
	cd /home/eye/Developer/litepm/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/litepm_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/litepm_demo.dir/build: litepm_demo
.PHONY : src/CMakeFiles/litepm_demo.dir/build

src/CMakeFiles/litepm_demo.dir/clean:
	cd /home/eye/Developer/litepm/build/src && $(CMAKE_COMMAND) -P CMakeFiles/litepm_demo.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/litepm_demo.dir/clean

src/CMakeFiles/litepm_demo.dir/depend:
	cd /home/eye/Developer/litepm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eye/Developer/litepm /home/eye/Developer/litepm/src /home/eye/Developer/litepm/build /home/eye/Developer/litepm/build/src /home/eye/Developer/litepm/build/src/CMakeFiles/litepm_demo.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/litepm_demo.dir/depend

