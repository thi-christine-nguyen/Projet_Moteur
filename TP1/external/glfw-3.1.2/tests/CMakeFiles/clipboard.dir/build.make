# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/snsdt/Desktop/Projet_Moteur

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1

# Include any dependencies generated for this target.
include external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/compiler_depend.make

# Include the progress variables for this target.
include external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/progress.make

# Include the compile flags for this target's objects.
include external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/flags.make

external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/clipboard.c.o: external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/flags.make
external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/clipboard.c.o: ../external/glfw-3.1.2/tests/clipboard.c
external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/clipboard.c.o: external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/clipboard.c.o"
	cd /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/external/glfw-3.1.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/clipboard.c.o -MF CMakeFiles/clipboard.dir/clipboard.c.o.d -o CMakeFiles/clipboard.dir/clipboard.c.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/external/glfw-3.1.2/tests/clipboard.c

external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/clipboard.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/clipboard.dir/clipboard.c.i"
	cd /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/external/glfw-3.1.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/external/glfw-3.1.2/tests/clipboard.c > CMakeFiles/clipboard.dir/clipboard.c.i

external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/clipboard.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/clipboard.dir/clipboard.c.s"
	cd /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/external/glfw-3.1.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/external/glfw-3.1.2/tests/clipboard.c -o CMakeFiles/clipboard.dir/clipboard.c.s

external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o: external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/flags.make
external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o: ../external/glfw-3.1.2/deps/getopt.c
external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o: external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o"
	cd /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/external/glfw-3.1.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o -MF CMakeFiles/clipboard.dir/__/deps/getopt.c.o.d -o CMakeFiles/clipboard.dir/__/deps/getopt.c.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/external/glfw-3.1.2/deps/getopt.c

external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/clipboard.dir/__/deps/getopt.c.i"
	cd /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/external/glfw-3.1.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/external/glfw-3.1.2/deps/getopt.c > CMakeFiles/clipboard.dir/__/deps/getopt.c.i

external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/clipboard.dir/__/deps/getopt.c.s"
	cd /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/external/glfw-3.1.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/external/glfw-3.1.2/deps/getopt.c -o CMakeFiles/clipboard.dir/__/deps/getopt.c.s

# Object files for target clipboard
clipboard_OBJECTS = \
"CMakeFiles/clipboard.dir/clipboard.c.o" \
"CMakeFiles/clipboard.dir/__/deps/getopt.c.o"

# External object files for target clipboard
clipboard_EXTERNAL_OBJECTS =

external/glfw-3.1.2/tests/clipboard: external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/clipboard.c.o
external/glfw-3.1.2/tests/clipboard: external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o
external/glfw-3.1.2/tests/clipboard: external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/build.make
external/glfw-3.1.2/tests/clipboard: external/glfw-3.1.2/src/libglfw3.a
external/glfw-3.1.2/tests/clipboard: /usr/lib/x86_64-linux-gnu/librt.a
external/glfw-3.1.2/tests/clipboard: /usr/lib/x86_64-linux-gnu/libm.so
external/glfw-3.1.2/tests/clipboard: /usr/lib/x86_64-linux-gnu/libX11.so
external/glfw-3.1.2/tests/clipboard: /usr/lib/x86_64-linux-gnu/libXrandr.so
external/glfw-3.1.2/tests/clipboard: /usr/lib/x86_64-linux-gnu/libXinerama.so
external/glfw-3.1.2/tests/clipboard: /usr/lib/x86_64-linux-gnu/libXcursor.so
external/glfw-3.1.2/tests/clipboard: /usr/lib/x86_64-linux-gnu/libGL.so
external/glfw-3.1.2/tests/clipboard: external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable clipboard"
	cd /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/external/glfw-3.1.2/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clipboard.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/build: external/glfw-3.1.2/tests/clipboard
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/build

external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/clean:
	cd /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/external/glfw-3.1.2/tests && $(CMAKE_COMMAND) -P CMakeFiles/clipboard.dir/cmake_clean.cmake
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/clean

external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/depend:
	cd /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/snsdt/Desktop/Projet_Moteur /mnt/c/Users/snsdt/Desktop/Projet_Moteur/external/glfw-3.1.2/tests /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1 /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/external/glfw-3.1.2/tests /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/clipboard.dir/depend

