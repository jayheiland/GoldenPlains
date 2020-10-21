# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/cmake-gui -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jay/Projects/GoldenPlains/CMakeFiles /home/jay/Projects/GoldenPlains/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jay/Projects/GoldenPlains/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named text

# Build rule for target.
text: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 text
.PHONY : text

# fast build rule for target.
text/fast:
	$(MAKE) -f CMakeFiles/text.dir/build.make CMakeFiles/text.dir/build
.PHONY : text/fast

#=============================================================================
# Target rules for targets named stress

# Build rule for target.
stress: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 stress
.PHONY : stress

# fast build rule for target.
stress/fast:
	$(MAKE) -f CMakeFiles/stress.dir/build.make CMakeFiles/stress.dir/build
.PHONY : stress/fast

#=============================================================================
# Target rules for targets named basic

# Build rule for target.
basic: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 basic
.PHONY : basic

# fast build rule for target.
basic/fast:
	$(MAKE) -f CMakeFiles/basic.dir/build.make CMakeFiles/basic.dir/build
.PHONY : basic/fast

#=============================================================================
# Target rules for targets named goldenplains

# Build rule for target.
goldenplains: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 goldenplains
.PHONY : goldenplains

# fast build rule for target.
goldenplains/fast:
	$(MAKE) -f CMakeFiles/goldenplains.dir/build.make CMakeFiles/goldenplains.dir/build
.PHONY : goldenplains/fast

samples/basic.o: samples/basic.cpp.o

.PHONY : samples/basic.o

# target to build an object file
samples/basic.cpp.o:
	$(MAKE) -f CMakeFiles/basic.dir/build.make CMakeFiles/basic.dir/samples/basic.cpp.o
.PHONY : samples/basic.cpp.o

samples/basic.i: samples/basic.cpp.i

.PHONY : samples/basic.i

# target to preprocess a source file
samples/basic.cpp.i:
	$(MAKE) -f CMakeFiles/basic.dir/build.make CMakeFiles/basic.dir/samples/basic.cpp.i
.PHONY : samples/basic.cpp.i

samples/basic.s: samples/basic.cpp.s

.PHONY : samples/basic.s

# target to generate assembly for a file
samples/basic.cpp.s:
	$(MAKE) -f CMakeFiles/basic.dir/build.make CMakeFiles/basic.dir/samples/basic.cpp.s
.PHONY : samples/basic.cpp.s

samples/stress.o: samples/stress.cpp.o

.PHONY : samples/stress.o

# target to build an object file
samples/stress.cpp.o:
	$(MAKE) -f CMakeFiles/stress.dir/build.make CMakeFiles/stress.dir/samples/stress.cpp.o
.PHONY : samples/stress.cpp.o

samples/stress.i: samples/stress.cpp.i

.PHONY : samples/stress.i

# target to preprocess a source file
samples/stress.cpp.i:
	$(MAKE) -f CMakeFiles/stress.dir/build.make CMakeFiles/stress.dir/samples/stress.cpp.i
.PHONY : samples/stress.cpp.i

samples/stress.s: samples/stress.cpp.s

.PHONY : samples/stress.s

# target to generate assembly for a file
samples/stress.cpp.s:
	$(MAKE) -f CMakeFiles/stress.dir/build.make CMakeFiles/stress.dir/samples/stress.cpp.s
.PHONY : samples/stress.cpp.s

samples/text.o: samples/text.cpp.o

.PHONY : samples/text.o

# target to build an object file
samples/text.cpp.o:
	$(MAKE) -f CMakeFiles/text.dir/build.make CMakeFiles/text.dir/samples/text.cpp.o
.PHONY : samples/text.cpp.o

samples/text.i: samples/text.cpp.i

.PHONY : samples/text.i

# target to preprocess a source file
samples/text.cpp.i:
	$(MAKE) -f CMakeFiles/text.dir/build.make CMakeFiles/text.dir/samples/text.cpp.i
.PHONY : samples/text.cpp.i

samples/text.s: samples/text.cpp.s

.PHONY : samples/text.s

# target to generate assembly for a file
samples/text.cpp.s:
	$(MAKE) -f CMakeFiles/text.dir/build.make CMakeFiles/text.dir/samples/text.cpp.s
.PHONY : samples/text.cpp.s

src/golden_plains.o: src/golden_plains.cpp.o

.PHONY : src/golden_plains.o

# target to build an object file
src/golden_plains.cpp.o:
	$(MAKE) -f CMakeFiles/goldenplains.dir/build.make CMakeFiles/goldenplains.dir/src/golden_plains.cpp.o
.PHONY : src/golden_plains.cpp.o

src/golden_plains.i: src/golden_plains.cpp.i

.PHONY : src/golden_plains.i

# target to preprocess a source file
src/golden_plains.cpp.i:
	$(MAKE) -f CMakeFiles/goldenplains.dir/build.make CMakeFiles/goldenplains.dir/src/golden_plains.cpp.i
.PHONY : src/golden_plains.cpp.i

src/golden_plains.s: src/golden_plains.cpp.s

.PHONY : src/golden_plains.s

# target to generate assembly for a file
src/golden_plains.cpp.s:
	$(MAKE) -f CMakeFiles/goldenplains.dir/build.make CMakeFiles/goldenplains.dir/src/golden_plains.cpp.s
.PHONY : src/golden_plains.cpp.s

src/vulkan_handler.o: src/vulkan_handler.cpp.o

.PHONY : src/vulkan_handler.o

# target to build an object file
src/vulkan_handler.cpp.o:
	$(MAKE) -f CMakeFiles/goldenplains.dir/build.make CMakeFiles/goldenplains.dir/src/vulkan_handler.cpp.o
.PHONY : src/vulkan_handler.cpp.o

src/vulkan_handler.i: src/vulkan_handler.cpp.i

.PHONY : src/vulkan_handler.i

# target to preprocess a source file
src/vulkan_handler.cpp.i:
	$(MAKE) -f CMakeFiles/goldenplains.dir/build.make CMakeFiles/goldenplains.dir/src/vulkan_handler.cpp.i
.PHONY : src/vulkan_handler.cpp.i

src/vulkan_handler.s: src/vulkan_handler.cpp.s

.PHONY : src/vulkan_handler.s

# target to generate assembly for a file
src/vulkan_handler.cpp.s:
	$(MAKE) -f CMakeFiles/goldenplains.dir/build.make CMakeFiles/goldenplains.dir/src/vulkan_handler.cpp.s
.PHONY : src/vulkan_handler.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... install/strip"
	@echo "... text"
	@echo "... stress"
	@echo "... basic"
	@echo "... install/local"
	@echo "... goldenplains"
	@echo "... samples/basic.o"
	@echo "... samples/basic.i"
	@echo "... samples/basic.s"
	@echo "... samples/stress.o"
	@echo "... samples/stress.i"
	@echo "... samples/stress.s"
	@echo "... samples/text.o"
	@echo "... samples/text.i"
	@echo "... samples/text.s"
	@echo "... src/golden_plains.o"
	@echo "... src/golden_plains.i"
	@echo "... src/golden_plains.s"
	@echo "... src/vulkan_handler.o"
	@echo "... src/vulkan_handler.i"
	@echo "... src/vulkan_handler.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

