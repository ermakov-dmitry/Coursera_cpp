# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/164/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/164/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week5/BlogsResearch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week5/BlogsResearch/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BlogsResearch.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/BlogsResearch.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BlogsResearch.dir/flags.make

CMakeFiles/BlogsResearch.dir/main.cpp.o: CMakeFiles/BlogsResearch.dir/flags.make
CMakeFiles/BlogsResearch.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CppWs/Coursera_cpp/RedBelt/Week5/BlogsResearch/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BlogsResearch.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BlogsResearch.dir/main.cpp.o -c /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week5/BlogsResearch/main.cpp

CMakeFiles/BlogsResearch.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BlogsResearch.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week5/BlogsResearch/main.cpp > CMakeFiles/BlogsResearch.dir/main.cpp.i

CMakeFiles/BlogsResearch.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BlogsResearch.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week5/BlogsResearch/main.cpp -o CMakeFiles/BlogsResearch.dir/main.cpp.s

# Object files for target BlogsResearch
BlogsResearch_OBJECTS = \
"CMakeFiles/BlogsResearch.dir/main.cpp.o"

# External object files for target BlogsResearch
BlogsResearch_EXTERNAL_OBJECTS =

BlogsResearch: CMakeFiles/BlogsResearch.dir/main.cpp.o
BlogsResearch: CMakeFiles/BlogsResearch.dir/build.make
BlogsResearch: CMakeFiles/BlogsResearch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmitry/CppWs/Coursera_cpp/RedBelt/Week5/BlogsResearch/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BlogsResearch"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BlogsResearch.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BlogsResearch.dir/build: BlogsResearch
.PHONY : CMakeFiles/BlogsResearch.dir/build

CMakeFiles/BlogsResearch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BlogsResearch.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BlogsResearch.dir/clean

CMakeFiles/BlogsResearch.dir/depend:
	cd /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week5/BlogsResearch/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week5/BlogsResearch /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week5/BlogsResearch /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week5/BlogsResearch/cmake-build-debug /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week5/BlogsResearch/cmake-build-debug /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week5/BlogsResearch/cmake-build-debug/CMakeFiles/BlogsResearch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BlogsResearch.dir/depend

