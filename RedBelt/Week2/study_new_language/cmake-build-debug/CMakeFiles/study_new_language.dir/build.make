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
CMAKE_SOURCE_DIR = /home/dmitry/CLionProjects/RedBelt/Week2/study_new_language

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmitry/CLionProjects/RedBelt/Week2/study_new_language/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/study_new_language.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/study_new_language.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/study_new_language.dir/flags.make

CMakeFiles/study_new_language.dir/main.cpp.o: CMakeFiles/study_new_language.dir/flags.make
CMakeFiles/study_new_language.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CLionProjects/RedBelt/Week2/study_new_language/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/study_new_language.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/study_new_language.dir/main.cpp.o -c /home/dmitry/CLionProjects/RedBelt/Week2/study_new_language/main.cpp

CMakeFiles/study_new_language.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/study_new_language.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CLionProjects/RedBelt/Week2/study_new_language/main.cpp > CMakeFiles/study_new_language.dir/main.cpp.i

CMakeFiles/study_new_language.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/study_new_language.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CLionProjects/RedBelt/Week2/study_new_language/main.cpp -o CMakeFiles/study_new_language.dir/main.cpp.s

# Object files for target study_new_language
study_new_language_OBJECTS = \
"CMakeFiles/study_new_language.dir/main.cpp.o"

# External object files for target study_new_language
study_new_language_EXTERNAL_OBJECTS =

study_new_language: CMakeFiles/study_new_language.dir/main.cpp.o
study_new_language: CMakeFiles/study_new_language.dir/build.make
study_new_language: CMakeFiles/study_new_language.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmitry/CLionProjects/RedBelt/Week2/study_new_language/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable study_new_language"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/study_new_language.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/study_new_language.dir/build: study_new_language

.PHONY : CMakeFiles/study_new_language.dir/build

CMakeFiles/study_new_language.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/study_new_language.dir/cmake_clean.cmake
.PHONY : CMakeFiles/study_new_language.dir/clean

CMakeFiles/study_new_language.dir/depend:
	cd /home/dmitry/CLionProjects/RedBelt/Week2/study_new_language/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmitry/CLionProjects/RedBelt/Week2/study_new_language /home/dmitry/CLionProjects/RedBelt/Week2/study_new_language /home/dmitry/CLionProjects/RedBelt/Week2/study_new_language/cmake-build-debug /home/dmitry/CLionProjects/RedBelt/Week2/study_new_language/cmake-build-debug /home/dmitry/CLionProjects/RedBelt/Week2/study_new_language/cmake-build-debug/CMakeFiles/study_new_language.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/study_new_language.dir/depend

