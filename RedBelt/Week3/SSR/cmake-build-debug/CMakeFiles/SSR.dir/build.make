# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/clion/149/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/149/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dmitry/CLionProjects/Coursera_cpp/RedBelt/Week3/SSR

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmitry/CLionProjects/Coursera_cpp/RedBelt/Week3/SSR/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SSR.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SSR.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SSR.dir/flags.make

CMakeFiles/SSR.dir/main.cpp.o: CMakeFiles/SSR.dir/flags.make
CMakeFiles/SSR.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CLionProjects/Coursera_cpp/RedBelt/Week3/SSR/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SSR.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SSR.dir/main.cpp.o -c /home/dmitry/CLionProjects/Coursera_cpp/RedBelt/Week3/SSR/main.cpp

CMakeFiles/SSR.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SSR.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CLionProjects/Coursera_cpp/RedBelt/Week3/SSR/main.cpp > CMakeFiles/SSR.dir/main.cpp.i

CMakeFiles/SSR.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SSR.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CLionProjects/Coursera_cpp/RedBelt/Week3/SSR/main.cpp -o CMakeFiles/SSR.dir/main.cpp.s

# Object files for target SSR
SSR_OBJECTS = \
"CMakeFiles/SSR.dir/main.cpp.o"

# External object files for target SSR
SSR_EXTERNAL_OBJECTS =

SSR: CMakeFiles/SSR.dir/main.cpp.o
SSR: CMakeFiles/SSR.dir/build.make
SSR: CMakeFiles/SSR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmitry/CLionProjects/Coursera_cpp/RedBelt/Week3/SSR/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SSR"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SSR.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SSR.dir/build: SSR

.PHONY : CMakeFiles/SSR.dir/build

CMakeFiles/SSR.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SSR.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SSR.dir/clean

CMakeFiles/SSR.dir/depend:
	cd /home/dmitry/CLionProjects/Coursera_cpp/RedBelt/Week3/SSR/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmitry/CLionProjects/Coursera_cpp/RedBelt/Week3/SSR /home/dmitry/CLionProjects/Coursera_cpp/RedBelt/Week3/SSR /home/dmitry/CLionProjects/Coursera_cpp/RedBelt/Week3/SSR/cmake-build-debug /home/dmitry/CLionProjects/Coursera_cpp/RedBelt/Week3/SSR/cmake-build-debug /home/dmitry/CLionProjects/Coursera_cpp/RedBelt/Week3/SSR/cmake-build-debug/CMakeFiles/SSR.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SSR.dir/depend
