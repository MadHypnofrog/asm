# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jabba/Desktop/asm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jabba/Desktop/asm

# Include any dependencies generated for this target.
include CMakeFiles/add.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/add.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/add.dir/flags.make

CMakeFiles/add.dir/add.asm.o: CMakeFiles/add.dir/flags.make
CMakeFiles/add.dir/add.asm.o: add.asm
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jabba/Desktop/asm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building ASM object CMakeFiles/add.dir/add.asm.o"
	/usr/bin/nasm -f elf64 -g -F dwarf -o CMakeFiles/add.dir/add.asm.o /home/jabba/Desktop/asm/add.asm

CMakeFiles/add.dir/add.asm.o.requires:

.PHONY : CMakeFiles/add.dir/add.asm.o.requires

CMakeFiles/add.dir/add.asm.o.provides: CMakeFiles/add.dir/add.asm.o.requires
	$(MAKE) -f CMakeFiles/add.dir/build.make CMakeFiles/add.dir/add.asm.o.provides.build
.PHONY : CMakeFiles/add.dir/add.asm.o.provides

CMakeFiles/add.dir/add.asm.o.provides.build: CMakeFiles/add.dir/add.asm.o


# Object files for target add
add_OBJECTS = \
"CMakeFiles/add.dir/add.asm.o"

# External object files for target add
add_EXTERNAL_OBJECTS =

add: CMakeFiles/add.dir/add.asm.o
add: CMakeFiles/add.dir/build.make
add: CMakeFiles/add.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jabba/Desktop/asm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking ASM executable add"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/add.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/add.dir/build: add

.PHONY : CMakeFiles/add.dir/build

CMakeFiles/add.dir/requires: CMakeFiles/add.dir/add.asm.o.requires

.PHONY : CMakeFiles/add.dir/requires

CMakeFiles/add.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/add.dir/cmake_clean.cmake
.PHONY : CMakeFiles/add.dir/clean

CMakeFiles/add.dir/depend:
	cd /home/jabba/Desktop/asm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jabba/Desktop/asm /home/jabba/Desktop/asm /home/jabba/Desktop/asm /home/jabba/Desktop/asm /home/jabba/Desktop/asm/CMakeFiles/add.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/add.dir/depend

