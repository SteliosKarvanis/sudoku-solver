# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/samcbk/Desktop/sudokuCES11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/samcbk/Desktop/sudokuCES11/build

# Include any dependencies generated for this target.
include CMakeFiles/program.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/program.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/program.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/program.dir/flags.make

CMakeFiles/program.dir/Sudoku.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/Sudoku.cpp.o: /home/samcbk/Desktop/sudokuCES11/Sudoku.cpp
CMakeFiles/program.dir/Sudoku.cpp.o: CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samcbk/Desktop/sudokuCES11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/program.dir/Sudoku.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/program.dir/Sudoku.cpp.o -MF CMakeFiles/program.dir/Sudoku.cpp.o.d -o CMakeFiles/program.dir/Sudoku.cpp.o -c /home/samcbk/Desktop/sudokuCES11/Sudoku.cpp

CMakeFiles/program.dir/Sudoku.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program.dir/Sudoku.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samcbk/Desktop/sudokuCES11/Sudoku.cpp > CMakeFiles/program.dir/Sudoku.cpp.i

CMakeFiles/program.dir/Sudoku.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program.dir/Sudoku.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samcbk/Desktop/sudokuCES11/Sudoku.cpp -o CMakeFiles/program.dir/Sudoku.cpp.s

CMakeFiles/program.dir/SudokuSolver.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/SudokuSolver.cpp.o: /home/samcbk/Desktop/sudokuCES11/SudokuSolver.cpp
CMakeFiles/program.dir/SudokuSolver.cpp.o: CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samcbk/Desktop/sudokuCES11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/program.dir/SudokuSolver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/program.dir/SudokuSolver.cpp.o -MF CMakeFiles/program.dir/SudokuSolver.cpp.o.d -o CMakeFiles/program.dir/SudokuSolver.cpp.o -c /home/samcbk/Desktop/sudokuCES11/SudokuSolver.cpp

CMakeFiles/program.dir/SudokuSolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program.dir/SudokuSolver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samcbk/Desktop/sudokuCES11/SudokuSolver.cpp > CMakeFiles/program.dir/SudokuSolver.cpp.i

CMakeFiles/program.dir/SudokuSolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program.dir/SudokuSolver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samcbk/Desktop/sudokuCES11/SudokuSolver.cpp -o CMakeFiles/program.dir/SudokuSolver.cpp.s

CMakeFiles/program.dir/main.cpp.o: CMakeFiles/program.dir/flags.make
CMakeFiles/program.dir/main.cpp.o: /home/samcbk/Desktop/sudokuCES11/main.cpp
CMakeFiles/program.dir/main.cpp.o: CMakeFiles/program.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samcbk/Desktop/sudokuCES11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/program.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/program.dir/main.cpp.o -MF CMakeFiles/program.dir/main.cpp.o.d -o CMakeFiles/program.dir/main.cpp.o -c /home/samcbk/Desktop/sudokuCES11/main.cpp

CMakeFiles/program.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samcbk/Desktop/sudokuCES11/main.cpp > CMakeFiles/program.dir/main.cpp.i

CMakeFiles/program.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samcbk/Desktop/sudokuCES11/main.cpp -o CMakeFiles/program.dir/main.cpp.s

# Object files for target program
program_OBJECTS = \
"CMakeFiles/program.dir/Sudoku.cpp.o" \
"CMakeFiles/program.dir/SudokuSolver.cpp.o" \
"CMakeFiles/program.dir/main.cpp.o"

# External object files for target program
program_EXTERNAL_OBJECTS =

/home/samcbk/Desktop/sudokuCES11/bin/program: CMakeFiles/program.dir/Sudoku.cpp.o
/home/samcbk/Desktop/sudokuCES11/bin/program: CMakeFiles/program.dir/SudokuSolver.cpp.o
/home/samcbk/Desktop/sudokuCES11/bin/program: CMakeFiles/program.dir/main.cpp.o
/home/samcbk/Desktop/sudokuCES11/bin/program: CMakeFiles/program.dir/build.make
/home/samcbk/Desktop/sudokuCES11/bin/program: CMakeFiles/program.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/samcbk/Desktop/sudokuCES11/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable /home/samcbk/Desktop/sudokuCES11/bin/program"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/program.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/program.dir/build: /home/samcbk/Desktop/sudokuCES11/bin/program
.PHONY : CMakeFiles/program.dir/build

CMakeFiles/program.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/program.dir/cmake_clean.cmake
.PHONY : CMakeFiles/program.dir/clean

CMakeFiles/program.dir/depend:
	cd /home/samcbk/Desktop/sudokuCES11/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/samcbk/Desktop/sudokuCES11 /home/samcbk/Desktop/sudokuCES11 /home/samcbk/Desktop/sudokuCES11/build /home/samcbk/Desktop/sudokuCES11/build /home/samcbk/Desktop/sudokuCES11/build/CMakeFiles/program.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/program.dir/depend

