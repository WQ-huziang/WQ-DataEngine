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
CMAKE_SOURCE_DIR = /home/luojunbin/project/WQ_project/DataEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luojunbin/project/WQ_project/DataEngine/build

# Include any dependencies generated for this target.
include src/CMakeFiles/WZMongodbEngine.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/WZMongodbEngine.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/WZMongodbEngine.dir/flags.make

src/CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.o: src/CMakeFiles/WZMongodbEngine.dir/flags.make
src/CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.o: ../src/WZMongodbEngine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luojunbin/project/WQ_project/DataEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.o"
	cd /home/luojunbin/project/WQ_project/DataEngine/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.o -c /home/luojunbin/project/WQ_project/DataEngine/src/WZMongodbEngine.cpp

src/CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.i"
	cd /home/luojunbin/project/WQ_project/DataEngine/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luojunbin/project/WQ_project/DataEngine/src/WZMongodbEngine.cpp > CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.i

src/CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.s"
	cd /home/luojunbin/project/WQ_project/DataEngine/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luojunbin/project/WQ_project/DataEngine/src/WZMongodbEngine.cpp -o CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.s

src/CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.o.requires:

.PHONY : src/CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.o.requires

src/CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.o.provides: src/CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/WZMongodbEngine.dir/build.make src/CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.o.provides.build
.PHONY : src/CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.o.provides

src/CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.o.provides.build: src/CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.o


# Object files for target WZMongodbEngine
WZMongodbEngine_OBJECTS = \
"CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.o"

# External object files for target WZMongodbEngine
WZMongodbEngine_EXTERNAL_OBJECTS =

../lib/libWZMongodbEngine.so.1.1: src/CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.o
../lib/libWZMongodbEngine.so.1.1: src/CMakeFiles/WZMongodbEngine.dir/build.make
../lib/libWZMongodbEngine.so.1.1: src/CMakeFiles/WZMongodbEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luojunbin/project/WQ_project/DataEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../lib/libWZMongodbEngine.so"
	cd /home/luojunbin/project/WQ_project/DataEngine/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WZMongodbEngine.dir/link.txt --verbose=$(VERBOSE)
	cd /home/luojunbin/project/WQ_project/DataEngine/build/src && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/libWZMongodbEngine.so.1.1 ../../lib/libWZMongodbEngine.so.1 ../../lib/libWZMongodbEngine.so

../lib/libWZMongodbEngine.so.1: ../lib/libWZMongodbEngine.so.1.1
	@$(CMAKE_COMMAND) -E touch_nocreate ../lib/libWZMongodbEngine.so.1

../lib/libWZMongodbEngine.so: ../lib/libWZMongodbEngine.so.1.1
	@$(CMAKE_COMMAND) -E touch_nocreate ../lib/libWZMongodbEngine.so

# Rule to build all files generated by this target.
src/CMakeFiles/WZMongodbEngine.dir/build: ../lib/libWZMongodbEngine.so

.PHONY : src/CMakeFiles/WZMongodbEngine.dir/build

src/CMakeFiles/WZMongodbEngine.dir/requires: src/CMakeFiles/WZMongodbEngine.dir/WZMongodbEngine.cpp.o.requires

.PHONY : src/CMakeFiles/WZMongodbEngine.dir/requires

src/CMakeFiles/WZMongodbEngine.dir/clean:
	cd /home/luojunbin/project/WQ_project/DataEngine/build/src && $(CMAKE_COMMAND) -P CMakeFiles/WZMongodbEngine.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/WZMongodbEngine.dir/clean

src/CMakeFiles/WZMongodbEngine.dir/depend:
	cd /home/luojunbin/project/WQ_project/DataEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luojunbin/project/WQ_project/DataEngine /home/luojunbin/project/WQ_project/DataEngine/src /home/luojunbin/project/WQ_project/DataEngine/build /home/luojunbin/project/WQ_project/DataEngine/build/src /home/luojunbin/project/WQ_project/DataEngine/build/src/CMakeFiles/WZMongodbEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/WZMongodbEngine.dir/depend
