# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/jay/Projects/GoldenPlains

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jay/Projects/GoldenPlains

# Include any dependencies generated for this target.
include CMakeFiles/button.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/button.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/button.dir/flags.make

CMakeFiles/button.dir/samples/button.cpp.o: CMakeFiles/button.dir/flags.make
CMakeFiles/button.dir/samples/button.cpp.o: samples/button.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jay/Projects/GoldenPlains/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/button.dir/samples/button.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/button.dir/samples/button.cpp.o -c /home/jay/Projects/GoldenPlains/samples/button.cpp

CMakeFiles/button.dir/samples/button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/button.dir/samples/button.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jay/Projects/GoldenPlains/samples/button.cpp > CMakeFiles/button.dir/samples/button.cpp.i

CMakeFiles/button.dir/samples/button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/button.dir/samples/button.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jay/Projects/GoldenPlains/samples/button.cpp -o CMakeFiles/button.dir/samples/button.cpp.s

# Object files for target button
button_OBJECTS = \
"CMakeFiles/button.dir/samples/button.cpp.o"

# External object files for target button
button_EXTERNAL_OBJECTS =

button: CMakeFiles/button.dir/samples/button.cpp.o
button: CMakeFiles/button.dir/build.make
button: libgoldenplains.so
button: /usr/local/lib/libglfw3.a
button: /usr/lib/x86_64-linux-gnu/librt.so
button: /usr/lib/x86_64-linux-gnu/libm.so
button: /usr/lib/x86_64-linux-gnu/libX11.so
button: /usr/lib/x86_64-linux-gnu/libvulkan.so
button: CMakeFiles/button.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jay/Projects/GoldenPlains/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable button"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/button.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/button.dir/build: button

.PHONY : CMakeFiles/button.dir/build

CMakeFiles/button.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/button.dir/cmake_clean.cmake
.PHONY : CMakeFiles/button.dir/clean

CMakeFiles/button.dir/depend:
	cd /home/jay/Projects/GoldenPlains && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jay/Projects/GoldenPlains /home/jay/Projects/GoldenPlains /home/jay/Projects/GoldenPlains /home/jay/Projects/GoldenPlains /home/jay/Projects/GoldenPlains/CMakeFiles/button.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/button.dir/depend
