# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/scottse/Desktop/INFT2503 - C++ for programmerere/exercises/solution1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/scottse/Desktop/INFT2503 - C++ for programmerere/exercises/build"

# Include any dependencies generated for this target.
include CMakeFiles/ReadTemperatures.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ReadTemperatures.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ReadTemperatures.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ReadTemperatures.dir/flags.make

CMakeFiles/ReadTemperatures.dir/read_temperatures.cpp.o: CMakeFiles/ReadTemperatures.dir/flags.make
CMakeFiles/ReadTemperatures.dir/read_temperatures.cpp.o: /Users/scottse/Desktop/INFT2503\ -\ C++\ for\ programmerere/exercises/solution1/read_temperatures.cpp
CMakeFiles/ReadTemperatures.dir/read_temperatures.cpp.o: CMakeFiles/ReadTemperatures.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/scottse/Desktop/INFT2503 - C++ for programmerere/exercises/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ReadTemperatures.dir/read_temperatures.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ReadTemperatures.dir/read_temperatures.cpp.o -MF CMakeFiles/ReadTemperatures.dir/read_temperatures.cpp.o.d -o CMakeFiles/ReadTemperatures.dir/read_temperatures.cpp.o -c "/Users/scottse/Desktop/INFT2503 - C++ for programmerere/exercises/solution1/read_temperatures.cpp"

CMakeFiles/ReadTemperatures.dir/read_temperatures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ReadTemperatures.dir/read_temperatures.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/scottse/Desktop/INFT2503 - C++ for programmerere/exercises/solution1/read_temperatures.cpp" > CMakeFiles/ReadTemperatures.dir/read_temperatures.cpp.i

CMakeFiles/ReadTemperatures.dir/read_temperatures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ReadTemperatures.dir/read_temperatures.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/scottse/Desktop/INFT2503 - C++ for programmerere/exercises/solution1/read_temperatures.cpp" -o CMakeFiles/ReadTemperatures.dir/read_temperatures.cpp.s

# Object files for target ReadTemperatures
ReadTemperatures_OBJECTS = \
"CMakeFiles/ReadTemperatures.dir/read_temperatures.cpp.o"

# External object files for target ReadTemperatures
ReadTemperatures_EXTERNAL_OBJECTS =

ReadTemperatures: CMakeFiles/ReadTemperatures.dir/read_temperatures.cpp.o
ReadTemperatures: CMakeFiles/ReadTemperatures.dir/build.make
ReadTemperatures: CMakeFiles/ReadTemperatures.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/scottse/Desktop/INFT2503 - C++ for programmerere/exercises/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ReadTemperatures"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ReadTemperatures.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ReadTemperatures.dir/build: ReadTemperatures
.PHONY : CMakeFiles/ReadTemperatures.dir/build

CMakeFiles/ReadTemperatures.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ReadTemperatures.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ReadTemperatures.dir/clean

CMakeFiles/ReadTemperatures.dir/depend:
	cd "/Users/scottse/Desktop/INFT2503 - C++ for programmerere/exercises/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/scottse/Desktop/INFT2503 - C++ for programmerere/exercises/solution1" "/Users/scottse/Desktop/INFT2503 - C++ for programmerere/exercises/solution1" "/Users/scottse/Desktop/INFT2503 - C++ for programmerere/exercises/build" "/Users/scottse/Desktop/INFT2503 - C++ for programmerere/exercises/build" "/Users/scottse/Desktop/INFT2503 - C++ for programmerere/exercises/build/CMakeFiles/ReadTemperatures.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/ReadTemperatures.dir/depend

