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
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week4/UniquePtr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week4/UniquePtr/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/UniquePtr.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/UniquePtr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UniquePtr.dir/flags.make

CMakeFiles/UniquePtr.dir/main.cpp.o: CMakeFiles/UniquePtr.dir/flags.make
CMakeFiles/UniquePtr.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week4/UniquePtr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UniquePtr.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UniquePtr.dir/main.cpp.o -c /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week4/UniquePtr/main.cpp

CMakeFiles/UniquePtr.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UniquePtr.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week4/UniquePtr/main.cpp > CMakeFiles/UniquePtr.dir/main.cpp.i

CMakeFiles/UniquePtr.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UniquePtr.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week4/UniquePtr/main.cpp -o CMakeFiles/UniquePtr.dir/main.cpp.s

# Object files for target UniquePtr
UniquePtr_OBJECTS = \
"CMakeFiles/UniquePtr.dir/main.cpp.o"

# External object files for target UniquePtr
UniquePtr_EXTERNAL_OBJECTS =

UniquePtr: CMakeFiles/UniquePtr.dir/main.cpp.o
UniquePtr: CMakeFiles/UniquePtr.dir/build.make
UniquePtr: CMakeFiles/UniquePtr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week4/UniquePtr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable UniquePtr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UniquePtr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UniquePtr.dir/build: UniquePtr
.PHONY : CMakeFiles/UniquePtr.dir/build

CMakeFiles/UniquePtr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UniquePtr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UniquePtr.dir/clean

CMakeFiles/UniquePtr.dir/depend:
	cd /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week4/UniquePtr/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week4/UniquePtr /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week4/UniquePtr /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week4/UniquePtr/cmake-build-debug /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week4/UniquePtr/cmake-build-debug /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week4/UniquePtr/cmake-build-debug/CMakeFiles/UniquePtr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UniquePtr.dir/depend

