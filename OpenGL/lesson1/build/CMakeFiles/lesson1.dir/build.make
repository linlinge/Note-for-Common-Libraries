# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/linlinge/ZJU/OpenGL_LESSONS/lesson1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/linlinge/ZJU/OpenGL_LESSONS/lesson1/build

# Include any dependencies generated for this target.
include CMakeFiles/lesson1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lesson1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lesson1.dir/flags.make

CMakeFiles/lesson1.dir/main.cpp.o: CMakeFiles/lesson1.dir/flags.make
CMakeFiles/lesson1.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/linlinge/ZJU/OpenGL_LESSONS/lesson1/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lesson1.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lesson1.dir/main.cpp.o -c /home/linlinge/ZJU/OpenGL_LESSONS/lesson1/main.cpp

CMakeFiles/lesson1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lesson1.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/linlinge/ZJU/OpenGL_LESSONS/lesson1/main.cpp > CMakeFiles/lesson1.dir/main.cpp.i

CMakeFiles/lesson1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lesson1.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/linlinge/ZJU/OpenGL_LESSONS/lesson1/main.cpp -o CMakeFiles/lesson1.dir/main.cpp.s

CMakeFiles/lesson1.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/lesson1.dir/main.cpp.o.requires

CMakeFiles/lesson1.dir/main.cpp.o.provides: CMakeFiles/lesson1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/lesson1.dir/build.make CMakeFiles/lesson1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/lesson1.dir/main.cpp.o.provides

CMakeFiles/lesson1.dir/main.cpp.o.provides.build: CMakeFiles/lesson1.dir/main.cpp.o

# Object files for target lesson1
lesson1_OBJECTS = \
"CMakeFiles/lesson1.dir/main.cpp.o"

# External object files for target lesson1
lesson1_EXTERNAL_OBJECTS =

lesson1: CMakeFiles/lesson1.dir/main.cpp.o
lesson1: CMakeFiles/lesson1.dir/build.make
lesson1: CMakeFiles/lesson1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable lesson1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lesson1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lesson1.dir/build: lesson1
.PHONY : CMakeFiles/lesson1.dir/build

CMakeFiles/lesson1.dir/requires: CMakeFiles/lesson1.dir/main.cpp.o.requires
.PHONY : CMakeFiles/lesson1.dir/requires

CMakeFiles/lesson1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lesson1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lesson1.dir/clean

CMakeFiles/lesson1.dir/depend:
	cd /home/linlinge/ZJU/OpenGL_LESSONS/lesson1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linlinge/ZJU/OpenGL_LESSONS/lesson1 /home/linlinge/ZJU/OpenGL_LESSONS/lesson1 /home/linlinge/ZJU/OpenGL_LESSONS/lesson1/build /home/linlinge/ZJU/OpenGL_LESSONS/lesson1/build /home/linlinge/ZJU/OpenGL_LESSONS/lesson1/build/CMakeFiles/lesson1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lesson1.dir/depend
