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
CMAKE_SOURCE_DIR = /media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn/build

# Include any dependencies generated for this target.
include 三、移步现代C++/CMakeFiles/base10.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include 三、移步现代C++/CMakeFiles/base10.dir/compiler_depend.make

# Include the progress variables for this target.
include 三、移步现代C++/CMakeFiles/base10.dir/progress.make

# Include the compile flags for this target's objects.
include 三、移步现代C++/CMakeFiles/base10.dir/flags.make

三、移步现代C++/CMakeFiles/base10.dir/base10.cpp.o: 三、移步现代C++/CMakeFiles/base10.dir/flags.make
三、移步现代C++/CMakeFiles/base10.dir/base10.cpp.o: ../三、移步现代C++/base10.cpp
三、移步现代C++/CMakeFiles/base10.dir/base10.cpp.o: 三、移步现代C++/CMakeFiles/base10.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 三、移步现代C++/CMakeFiles/base10.dir/base10.cpp.o"
	cd /media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn/build/三、移步现代C++ && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 三、移步现代C++/CMakeFiles/base10.dir/base10.cpp.o -MF CMakeFiles/base10.dir/base10.cpp.o.d -o CMakeFiles/base10.dir/base10.cpp.o -c /media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn/三、移步现代C++/base10.cpp

三、移步现代C++/CMakeFiles/base10.dir/base10.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base10.dir/base10.cpp.i"
	cd /media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn/build/三、移步现代C++ && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn/三、移步现代C++/base10.cpp > CMakeFiles/base10.dir/base10.cpp.i

三、移步现代C++/CMakeFiles/base10.dir/base10.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base10.dir/base10.cpp.s"
	cd /media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn/build/三、移步现代C++ && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn/三、移步现代C++/base10.cpp -o CMakeFiles/base10.dir/base10.cpp.s

# Object files for target base10
base10_OBJECTS = \
"CMakeFiles/base10.dir/base10.cpp.o"

# External object files for target base10
base10_EXTERNAL_OBJECTS =

../bin/base10: 三、移步现代C++/CMakeFiles/base10.dir/base10.cpp.o
../bin/base10: 三、移步现代C++/CMakeFiles/base10.dir/build.make
../bin/base10: 三、移步现代C++/CMakeFiles/base10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/base10"
	cd /media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn/build/三、移步现代C++ && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
三、移步现代C++/CMakeFiles/base10.dir/build: ../bin/base10
.PHONY : 三、移步现代C++/CMakeFiles/base10.dir/build

三、移步现代C++/CMakeFiles/base10.dir/clean:
	cd /media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn/build/三、移步现代C++ && $(CMAKE_COMMAND) -P CMakeFiles/base10.dir/cmake_clean.cmake
.PHONY : 三、移步现代C++/CMakeFiles/base10.dir/clean

三、移步现代C++/CMakeFiles/base10.dir/depend:
	cd /media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn /media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn/三、移步现代C++ /media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn/build /media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn/build/三、移步现代C++ /media/pluto/04f2ae43-8638-4f49-90d3-8cd4387797e6/ttzn/C++_learn/build/三、移步现代C++/CMakeFiles/base10.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 三、移步现代C++/CMakeFiles/base10.dir/depend

