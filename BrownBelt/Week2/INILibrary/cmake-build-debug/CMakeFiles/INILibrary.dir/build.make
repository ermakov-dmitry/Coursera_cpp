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
CMAKE_SOURCE_DIR = /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/INILibrary.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/INILibrary.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/INILibrary.dir/flags.make

CMakeFiles/INILibrary.dir/main.cpp.o: CMakeFiles/INILibrary.dir/flags.make
CMakeFiles/INILibrary.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/INILibrary.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/INILibrary.dir/main.cpp.o -c /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary/main.cpp

CMakeFiles/INILibrary.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/INILibrary.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary/main.cpp > CMakeFiles/INILibrary.dir/main.cpp.i

CMakeFiles/INILibrary.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/INILibrary.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary/main.cpp -o CMakeFiles/INILibrary.dir/main.cpp.s

CMakeFiles/INILibrary.dir/ini.cpp.o: CMakeFiles/INILibrary.dir/flags.make
CMakeFiles/INILibrary.dir/ini.cpp.o: ../ini.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/INILibrary.dir/ini.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/INILibrary.dir/ini.cpp.o -c /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary/ini.cpp

CMakeFiles/INILibrary.dir/ini.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/INILibrary.dir/ini.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary/ini.cpp > CMakeFiles/INILibrary.dir/ini.cpp.i

CMakeFiles/INILibrary.dir/ini.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/INILibrary.dir/ini.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary/ini.cpp -o CMakeFiles/INILibrary.dir/ini.cpp.s

# Object files for target INILibrary
INILibrary_OBJECTS = \
"CMakeFiles/INILibrary.dir/main.cpp.o" \
"CMakeFiles/INILibrary.dir/ini.cpp.o"

# External object files for target INILibrary
INILibrary_EXTERNAL_OBJECTS =

INILibrary: CMakeFiles/INILibrary.dir/main.cpp.o
INILibrary: CMakeFiles/INILibrary.dir/ini.cpp.o
INILibrary: CMakeFiles/INILibrary.dir/build.make
INILibrary: CMakeFiles/INILibrary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable INILibrary"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/INILibrary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/INILibrary.dir/build: INILibrary
.PHONY : CMakeFiles/INILibrary.dir/build

CMakeFiles/INILibrary.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/INILibrary.dir/cmake_clean.cmake
.PHONY : CMakeFiles/INILibrary.dir/clean

CMakeFiles/INILibrary.dir/depend:
	cd /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary/cmake-build-debug /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary/cmake-build-debug /home/dmitry/CppWs/Coursera_cpp/BrownBelt/Week2/INILibrary/cmake-build-debug/CMakeFiles/INILibrary.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/INILibrary.dir/depend

