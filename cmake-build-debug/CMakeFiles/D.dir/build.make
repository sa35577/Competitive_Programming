# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\satcl\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\201.7846.88\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\satcl\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\201.7846.88\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\satcl\CLionProjects\Competitive Programming"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\satcl\CLionProjects\Competitive Programming\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/D.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/D.dir/flags.make

CMakeFiles/D.dir/AtCoder/DP/D.cpp.obj: CMakeFiles/D.dir/flags.make
CMakeFiles/D.dir/AtCoder/DP/D.cpp.obj: ../AtCoder/DP/D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\satcl\CLionProjects\Competitive Programming\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/D.dir/AtCoder/DP/D.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\D.dir\AtCoder\DP\D.cpp.obj -c "C:\Users\satcl\CLionProjects\Competitive Programming\AtCoder\DP\D.cpp"

CMakeFiles/D.dir/AtCoder/DP/D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/D.dir/AtCoder/DP/D.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\satcl\CLionProjects\Competitive Programming\AtCoder\DP\D.cpp" > CMakeFiles\D.dir\AtCoder\DP\D.cpp.i

CMakeFiles/D.dir/AtCoder/DP/D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/D.dir/AtCoder/DP/D.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\satcl\CLionProjects\Competitive Programming\AtCoder\DP\D.cpp" -o CMakeFiles\D.dir\AtCoder\DP\D.cpp.s

# Object files for target D
D_OBJECTS = \
"CMakeFiles/D.dir/AtCoder/DP/D.cpp.obj"

# External object files for target D
D_EXTERNAL_OBJECTS =

D.exe: CMakeFiles/D.dir/AtCoder/DP/D.cpp.obj
D.exe: CMakeFiles/D.dir/build.make
D.exe: CMakeFiles/D.dir/linklibs.rsp
D.exe: CMakeFiles/D.dir/objects1.rsp
D.exe: CMakeFiles/D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\satcl\CLionProjects\Competitive Programming\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable D.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\D.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/D.dir/build: D.exe

.PHONY : CMakeFiles/D.dir/build

CMakeFiles/D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\D.dir\cmake_clean.cmake
.PHONY : CMakeFiles/D.dir/clean

CMakeFiles/D.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\satcl\CLionProjects\Competitive Programming" "C:\Users\satcl\CLionProjects\Competitive Programming" "C:\Users\satcl\CLionProjects\Competitive Programming\cmake-build-debug" "C:\Users\satcl\CLionProjects\Competitive Programming\cmake-build-debug" "C:\Users\satcl\CLionProjects\Competitive Programming\cmake-build-debug\CMakeFiles\D.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/D.dir/depend

