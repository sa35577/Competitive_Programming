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
include CMakeFiles/IOI94p1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IOI94p1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IOI94p1.dir/flags.make

CMakeFiles/IOI94p1.dir/IOI/IOI94p1.cpp.obj: CMakeFiles/IOI94p1.dir/flags.make
CMakeFiles/IOI94p1.dir/IOI/IOI94p1.cpp.obj: ../IOI/IOI94p1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\satcl\CLionProjects\Competitive Programming\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/IOI94p1.dir/IOI/IOI94p1.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\IOI94p1.dir\IOI\IOI94p1.cpp.obj -c "C:\Users\satcl\CLionProjects\Competitive Programming\IOI\IOI94p1.cpp"

CMakeFiles/IOI94p1.dir/IOI/IOI94p1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IOI94p1.dir/IOI/IOI94p1.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\satcl\CLionProjects\Competitive Programming\IOI\IOI94p1.cpp" > CMakeFiles\IOI94p1.dir\IOI\IOI94p1.cpp.i

CMakeFiles/IOI94p1.dir/IOI/IOI94p1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IOI94p1.dir/IOI/IOI94p1.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\satcl\CLionProjects\Competitive Programming\IOI\IOI94p1.cpp" -o CMakeFiles\IOI94p1.dir\IOI\IOI94p1.cpp.s

# Object files for target IOI94p1
IOI94p1_OBJECTS = \
"CMakeFiles/IOI94p1.dir/IOI/IOI94p1.cpp.obj"

# External object files for target IOI94p1
IOI94p1_EXTERNAL_OBJECTS =

IOI94p1.exe: CMakeFiles/IOI94p1.dir/IOI/IOI94p1.cpp.obj
IOI94p1.exe: CMakeFiles/IOI94p1.dir/build.make
IOI94p1.exe: CMakeFiles/IOI94p1.dir/linklibs.rsp
IOI94p1.exe: CMakeFiles/IOI94p1.dir/objects1.rsp
IOI94p1.exe: CMakeFiles/IOI94p1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\satcl\CLionProjects\Competitive Programming\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable IOI94p1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\IOI94p1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IOI94p1.dir/build: IOI94p1.exe

.PHONY : CMakeFiles/IOI94p1.dir/build

CMakeFiles/IOI94p1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\IOI94p1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/IOI94p1.dir/clean

CMakeFiles/IOI94p1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\satcl\CLionProjects\Competitive Programming" "C:\Users\satcl\CLionProjects\Competitive Programming" "C:\Users\satcl\CLionProjects\Competitive Programming\cmake-build-debug" "C:\Users\satcl\CLionProjects\Competitive Programming\cmake-build-debug" "C:\Users\satcl\CLionProjects\Competitive Programming\cmake-build-debug\CMakeFiles\IOI94p1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/IOI94p1.dir/depend

