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
CMAKE_SOURCE_DIR = /home/dmitry/CLionProjects/YellowBelt/Week6/Final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmitry/CLionProjects/YellowBelt/Week6/Final/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Final.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Final.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Final.dir/flags.make

CMakeFiles/Final.dir/main.cpp.o: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CLionProjects/YellowBelt/Week6/Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Final.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Final.dir/main.cpp.o -c /home/dmitry/CLionProjects/YellowBelt/Week6/Final/main.cpp

CMakeFiles/Final.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CLionProjects/YellowBelt/Week6/Final/main.cpp > CMakeFiles/Final.dir/main.cpp.i

CMakeFiles/Final.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CLionProjects/YellowBelt/Week6/Final/main.cpp -o CMakeFiles/Final.dir/main.cpp.s

CMakeFiles/Final.dir/token.cpp.o: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/token.cpp.o: ../token.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CLionProjects/YellowBelt/Week6/Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Final.dir/token.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Final.dir/token.cpp.o -c /home/dmitry/CLionProjects/YellowBelt/Week6/Final/token.cpp

CMakeFiles/Final.dir/token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/token.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CLionProjects/YellowBelt/Week6/Final/token.cpp > CMakeFiles/Final.dir/token.cpp.i

CMakeFiles/Final.dir/token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/token.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CLionProjects/YellowBelt/Week6/Final/token.cpp -o CMakeFiles/Final.dir/token.cpp.s

CMakeFiles/Final.dir/condition_parser.cpp.o: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/condition_parser.cpp.o: ../condition_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CLionProjects/YellowBelt/Week6/Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Final.dir/condition_parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Final.dir/condition_parser.cpp.o -c /home/dmitry/CLionProjects/YellowBelt/Week6/Final/condition_parser.cpp

CMakeFiles/Final.dir/condition_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/condition_parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CLionProjects/YellowBelt/Week6/Final/condition_parser.cpp > CMakeFiles/Final.dir/condition_parser.cpp.i

CMakeFiles/Final.dir/condition_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/condition_parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CLionProjects/YellowBelt/Week6/Final/condition_parser.cpp -o CMakeFiles/Final.dir/condition_parser.cpp.s

CMakeFiles/Final.dir/condition_parser_test.cpp.o: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/condition_parser_test.cpp.o: ../condition_parser_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CLionProjects/YellowBelt/Week6/Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Final.dir/condition_parser_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Final.dir/condition_parser_test.cpp.o -c /home/dmitry/CLionProjects/YellowBelt/Week6/Final/condition_parser_test.cpp

CMakeFiles/Final.dir/condition_parser_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/condition_parser_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CLionProjects/YellowBelt/Week6/Final/condition_parser_test.cpp > CMakeFiles/Final.dir/condition_parser_test.cpp.i

CMakeFiles/Final.dir/condition_parser_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/condition_parser_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CLionProjects/YellowBelt/Week6/Final/condition_parser_test.cpp -o CMakeFiles/Final.dir/condition_parser_test.cpp.s

CMakeFiles/Final.dir/date.cpp.o: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/date.cpp.o: ../date.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CLionProjects/YellowBelt/Week6/Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Final.dir/date.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Final.dir/date.cpp.o -c /home/dmitry/CLionProjects/YellowBelt/Week6/Final/date.cpp

CMakeFiles/Final.dir/date.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/date.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CLionProjects/YellowBelt/Week6/Final/date.cpp > CMakeFiles/Final.dir/date.cpp.i

CMakeFiles/Final.dir/date.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/date.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CLionProjects/YellowBelt/Week6/Final/date.cpp -o CMakeFiles/Final.dir/date.cpp.s

CMakeFiles/Final.dir/database.cpp.o: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/database.cpp.o: ../database.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CLionProjects/YellowBelt/Week6/Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Final.dir/database.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Final.dir/database.cpp.o -c /home/dmitry/CLionProjects/YellowBelt/Week6/Final/database.cpp

CMakeFiles/Final.dir/database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/database.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CLionProjects/YellowBelt/Week6/Final/database.cpp > CMakeFiles/Final.dir/database.cpp.i

CMakeFiles/Final.dir/database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/database.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CLionProjects/YellowBelt/Week6/Final/database.cpp -o CMakeFiles/Final.dir/database.cpp.s

CMakeFiles/Final.dir/node.cpp.o: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/node.cpp.o: ../node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CLionProjects/YellowBelt/Week6/Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Final.dir/node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Final.dir/node.cpp.o -c /home/dmitry/CLionProjects/YellowBelt/Week6/Final/node.cpp

CMakeFiles/Final.dir/node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CLionProjects/YellowBelt/Week6/Final/node.cpp > CMakeFiles/Final.dir/node.cpp.i

CMakeFiles/Final.dir/node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CLionProjects/YellowBelt/Week6/Final/node.cpp -o CMakeFiles/Final.dir/node.cpp.s

CMakeFiles/Final.dir/test_db.cpp.o: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/test_db.cpp.o: ../test_db.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CLionProjects/YellowBelt/Week6/Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Final.dir/test_db.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Final.dir/test_db.cpp.o -c /home/dmitry/CLionProjects/YellowBelt/Week6/Final/test_db.cpp

CMakeFiles/Final.dir/test_db.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/test_db.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CLionProjects/YellowBelt/Week6/Final/test_db.cpp > CMakeFiles/Final.dir/test_db.cpp.i

CMakeFiles/Final.dir/test_db.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/test_db.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CLionProjects/YellowBelt/Week6/Final/test_db.cpp -o CMakeFiles/Final.dir/test_db.cpp.s

CMakeFiles/Final.dir/overloaded_operators.cpp.o: CMakeFiles/Final.dir/flags.make
CMakeFiles/Final.dir/overloaded_operators.cpp.o: ../overloaded_operators.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmitry/CLionProjects/YellowBelt/Week6/Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Final.dir/overloaded_operators.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Final.dir/overloaded_operators.cpp.o -c /home/dmitry/CLionProjects/YellowBelt/Week6/Final/overloaded_operators.cpp

CMakeFiles/Final.dir/overloaded_operators.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Final.dir/overloaded_operators.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmitry/CLionProjects/YellowBelt/Week6/Final/overloaded_operators.cpp > CMakeFiles/Final.dir/overloaded_operators.cpp.i

CMakeFiles/Final.dir/overloaded_operators.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Final.dir/overloaded_operators.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmitry/CLionProjects/YellowBelt/Week6/Final/overloaded_operators.cpp -o CMakeFiles/Final.dir/overloaded_operators.cpp.s

# Object files for target Final
Final_OBJECTS = \
"CMakeFiles/Final.dir/main.cpp.o" \
"CMakeFiles/Final.dir/token.cpp.o" \
"CMakeFiles/Final.dir/condition_parser.cpp.o" \
"CMakeFiles/Final.dir/condition_parser_test.cpp.o" \
"CMakeFiles/Final.dir/date.cpp.o" \
"CMakeFiles/Final.dir/database.cpp.o" \
"CMakeFiles/Final.dir/node.cpp.o" \
"CMakeFiles/Final.dir/test_db.cpp.o" \
"CMakeFiles/Final.dir/overloaded_operators.cpp.o"

# External object files for target Final
Final_EXTERNAL_OBJECTS =

Final: CMakeFiles/Final.dir/main.cpp.o
Final: CMakeFiles/Final.dir/token.cpp.o
Final: CMakeFiles/Final.dir/condition_parser.cpp.o
Final: CMakeFiles/Final.dir/condition_parser_test.cpp.o
Final: CMakeFiles/Final.dir/date.cpp.o
Final: CMakeFiles/Final.dir/database.cpp.o
Final: CMakeFiles/Final.dir/node.cpp.o
Final: CMakeFiles/Final.dir/test_db.cpp.o
Final: CMakeFiles/Final.dir/overloaded_operators.cpp.o
Final: CMakeFiles/Final.dir/build.make
Final: CMakeFiles/Final.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmitry/CLionProjects/YellowBelt/Week6/Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable Final"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Final.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Final.dir/build: Final

.PHONY : CMakeFiles/Final.dir/build

CMakeFiles/Final.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Final.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Final.dir/clean

CMakeFiles/Final.dir/depend:
	cd /home/dmitry/CLionProjects/YellowBelt/Week6/Final/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmitry/CLionProjects/YellowBelt/Week6/Final /home/dmitry/CLionProjects/YellowBelt/Week6/Final /home/dmitry/CLionProjects/YellowBelt/Week6/Final/cmake-build-debug /home/dmitry/CLionProjects/YellowBelt/Week6/Final/cmake-build-debug /home/dmitry/CLionProjects/YellowBelt/Week6/Final/cmake-build-debug/CMakeFiles/Final.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Final.dir/depend

