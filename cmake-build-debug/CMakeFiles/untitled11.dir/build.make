# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\jjami\CLionProjects\untitled11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jjami\CLionProjects\untitled11\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled11.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/untitled11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled11.dir/flags.make

CMakeFiles/untitled11.dir/main.c.obj: CMakeFiles/untitled11.dir/flags.make
CMakeFiles/untitled11.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jjami\CLionProjects\untitled11\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untitled11.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\untitled11.dir\main.c.obj -c C:\Users\jjami\CLionProjects\untitled11\main.c

CMakeFiles/untitled11.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled11.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\jjami\CLionProjects\untitled11\main.c > CMakeFiles\untitled11.dir\main.c.i

CMakeFiles/untitled11.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled11.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\jjami\CLionProjects\untitled11\main.c -o CMakeFiles\untitled11.dir\main.c.s

# Object files for target untitled11
untitled11_OBJECTS = \
"CMakeFiles/untitled11.dir/main.c.obj"

# External object files for target untitled11
untitled11_EXTERNAL_OBJECTS =

untitled11.exe: CMakeFiles/untitled11.dir/main.c.obj
untitled11.exe: CMakeFiles/untitled11.dir/build.make
untitled11.exe: CMakeFiles/untitled11.dir/linklibs.rsp
untitled11.exe: CMakeFiles/untitled11.dir/objects1.rsp
untitled11.exe: CMakeFiles/untitled11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jjami\CLionProjects\untitled11\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable untitled11.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untitled11.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled11.dir/build: untitled11.exe
.PHONY : CMakeFiles/untitled11.dir/build

CMakeFiles/untitled11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled11.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled11.dir/clean

CMakeFiles/untitled11.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jjami\CLionProjects\untitled11 C:\Users\jjami\CLionProjects\untitled11 C:\Users\jjami\CLionProjects\untitled11\cmake-build-debug C:\Users\jjami\CLionProjects\untitled11\cmake-build-debug C:\Users\jjami\CLionProjects\untitled11\cmake-build-debug\CMakeFiles\untitled11.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled11.dir/depend

