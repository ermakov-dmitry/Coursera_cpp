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
CMAKE_COMMAND = /snap/clion/163/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/163/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week4/Translator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week4/Translator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Translator.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Translator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Translator.dir/flags.make

CMakeFiles/Translator.dir/main.cpp.o: CMakeFiles/Translator.dir/flags.make
CMakeFiles/Translator.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CppWs/Coursera_cpp/RedBelt/Week4/Translator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Translator.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Translator.dir/main.cpp.o -c /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week4/Translator/main.cpp

CMakeFiles/Translator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Translator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week4/Translator/main.cpp > CMakeFiles/Translator.dir/main.cpp.i

CMakeFiles/Translator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Translator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week4/Translator/main.cpp -o CMakeFiles/Translator.dir/main.cpp.s

# Object files for target Translator
Translator_OBJECTS = \
"CMakeFiles/Translator.dir/main.cpp.o"

# External object files for target Translator
Translator_EXTERNAL_OBJECTS =

Translator: CMakeFiles/Translator.dir/main.cpp.o
Translator: CMakeFiles/Translator.dir/build.make
Translator: CMakeFiles/Translator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmitry/CppWs/Coursera_cpp/RedBelt/Week4/Translator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Translator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Translator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Translator.dir/build: Translator
.PHONY : CMakeFiles/Translator.dir/build

CMakeFiles/Translator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Translator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Translator.dir/clean

CMakeFiles/Translator.dir/depend:
	cd /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week4/Translator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week4/Translator /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week4/Translator /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week4/Translator/cmake-build-debug /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week4/Translator/cmake-build-debug /home/dmitry/CppWs/Coursera_cpp/RedBelt/Week4/Translator/cmake-build-debug/CMakeFiles/Translator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Translator.dir/depend

