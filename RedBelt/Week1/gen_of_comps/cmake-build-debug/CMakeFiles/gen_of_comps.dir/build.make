# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/139/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/139/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dmitry/CLionProjects/RedBelt/Week1/gen_of_comps

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmitry/CLionProjects/RedBelt/Week1/gen_of_comps/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/gen_of_comps.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gen_of_comps.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gen_of_comps.dir/flags.make

CMakeFiles/gen_of_comps.dir/main.cpp.o: CMakeFiles/gen_of_comps.dir/flags.make
CMakeFiles/gen_of_comps.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CLionProjects/RedBelt/Week1/gen_of_comps/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gen_of_comps.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gen_of_comps.dir/main.cpp.o -c /home/dmitry/CLionProjects/RedBelt/Week1/gen_of_comps/main.cpp

CMakeFiles/gen_of_comps.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gen_of_comps.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CLionProjects/RedBelt/Week1/gen_of_comps/main.cpp > CMakeFiles/gen_of_comps.dir/main.cpp.i

CMakeFiles/gen_of_comps.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gen_of_comps.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CLionProjects/RedBelt/Week1/gen_of_comps/main.cpp -o CMakeFiles/gen_of_comps.dir/main.cpp.s

# Object files for target gen_of_comps
gen_of_comps_OBJECTS = \
"CMakeFiles/gen_of_comps.dir/main.cpp.o"

# External object files for target gen_of_comps
gen_of_comps_EXTERNAL_OBJECTS =

gen_of_comps: CMakeFiles/gen_of_comps.dir/main.cpp.o
gen_of_comps: CMakeFiles/gen_of_comps.dir/build.make
gen_of_comps: CMakeFiles/gen_of_comps.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmitry/CLionProjects/RedBelt/Week1/gen_of_comps/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gen_of_comps"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gen_of_comps.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gen_of_comps.dir/build: gen_of_comps

.PHONY : CMakeFiles/gen_of_comps.dir/build

CMakeFiles/gen_of_comps.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gen_of_comps.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gen_of_comps.dir/clean

CMakeFiles/gen_of_comps.dir/depend:
	cd /home/dmitry/CLionProjects/RedBelt/Week1/gen_of_comps/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmitry/CLionProjects/RedBelt/Week1/gen_of_comps /home/dmitry/CLionProjects/RedBelt/Week1/gen_of_comps /home/dmitry/CLionProjects/RedBelt/Week1/gen_of_comps/cmake-build-debug /home/dmitry/CLionProjects/RedBelt/Week1/gen_of_comps/cmake-build-debug /home/dmitry/CLionProjects/RedBelt/Week1/gen_of_comps/cmake-build-debug/CMakeFiles/gen_of_comps.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gen_of_comps.dir/depend

