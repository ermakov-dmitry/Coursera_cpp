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
CMAKE_SOURCE_DIR = /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/CommentServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/CommentServer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CommentServer.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/CommentServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CommentServer.dir/flags.make

CMakeFiles/CommentServer.dir/main.cpp.o: CMakeFiles/CommentServer.dir/flags.make
CMakeFiles/CommentServer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/CommentServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CommentServer.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CommentServer.dir/main.cpp.o -c /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/CommentServer/main.cpp

CMakeFiles/CommentServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CommentServer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/CommentServer/main.cpp > CMakeFiles/CommentServer.dir/main.cpp.i

CMakeFiles/CommentServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CommentServer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/CommentServer/main.cpp -o CMakeFiles/CommentServer.dir/main.cpp.s

# Object files for target CommentServer
CommentServer_OBJECTS = \
"CMakeFiles/CommentServer.dir/main.cpp.o"

# External object files for target CommentServer
CommentServer_EXTERNAL_OBJECTS =

CommentServer: CMakeFiles/CommentServer.dir/main.cpp.o
CommentServer: CMakeFiles/CommentServer.dir/build.make
CommentServer: CMakeFiles/CommentServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/CommentServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CommentServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CommentServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CommentServer.dir/build: CommentServer
.PHONY : CMakeFiles/CommentServer.dir/build

CMakeFiles/CommentServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CommentServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CommentServer.dir/clean

CMakeFiles/CommentServer.dir/depend:
	cd /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/CommentServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/CommentServer /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/CommentServer /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/CommentServer/cmake-build-debug /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/CommentServer/cmake-build-debug /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/CommentServer/cmake-build-debug/CMakeFiles/CommentServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CommentServer.dir/depend
