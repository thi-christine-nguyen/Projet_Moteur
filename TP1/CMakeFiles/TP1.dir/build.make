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
include CMakeFiles/TP1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TP1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TP1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP1.dir/flags.make

CMakeFiles/TP1.dir/TP1.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/TP1.cpp.o: TP1.cpp
CMakeFiles/TP1.dir/TP1.cpp.o: CMakeFiles/TP1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TP1.dir/TP1.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP1.dir/TP1.cpp.o -MF CMakeFiles/TP1.dir/TP1.cpp.o.d -o CMakeFiles/TP1.dir/TP1.cpp.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/TP1.cpp

CMakeFiles/TP1.dir/TP1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/TP1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/TP1.cpp > CMakeFiles/TP1.dir/TP1.cpp.i

CMakeFiles/TP1.dir/TP1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/TP1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/TP1.cpp -o CMakeFiles/TP1.dir/TP1.cpp.s

CMakeFiles/TP1.dir/Camera/Camera.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/Camera/Camera.cpp.o: Camera/Camera.cpp
CMakeFiles/TP1.dir/Camera/Camera.cpp.o: CMakeFiles/TP1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TP1.dir/Camera/Camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP1.dir/Camera/Camera.cpp.o -MF CMakeFiles/TP1.dir/Camera/Camera.cpp.o.d -o CMakeFiles/TP1.dir/Camera/Camera.cpp.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/Camera/Camera.cpp

CMakeFiles/TP1.dir/Camera/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/Camera/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/Camera/Camera.cpp > CMakeFiles/TP1.dir/Camera/Camera.cpp.i

CMakeFiles/TP1.dir/Camera/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/Camera/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/Camera/Camera.cpp -o CMakeFiles/TP1.dir/Camera/Camera.cpp.s

CMakeFiles/TP1.dir/Camera/Camera_Helper.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/Camera/Camera_Helper.cpp.o: Camera/Camera_Helper.cpp
CMakeFiles/TP1.dir/Camera/Camera_Helper.cpp.o: CMakeFiles/TP1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TP1.dir/Camera/Camera_Helper.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP1.dir/Camera/Camera_Helper.cpp.o -MF CMakeFiles/TP1.dir/Camera/Camera_Helper.cpp.o.d -o CMakeFiles/TP1.dir/Camera/Camera_Helper.cpp.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/Camera/Camera_Helper.cpp

CMakeFiles/TP1.dir/Camera/Camera_Helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/Camera/Camera_Helper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/Camera/Camera_Helper.cpp > CMakeFiles/TP1.dir/Camera/Camera_Helper.cpp.i

CMakeFiles/TP1.dir/Camera/Camera_Helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/Camera/Camera_Helper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/Camera/Camera_Helper.cpp -o CMakeFiles/TP1.dir/Camera/Camera_Helper.cpp.s

CMakeFiles/TP1.dir/common/shader.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/common/shader.cpp.o: ../common/shader.cpp
CMakeFiles/TP1.dir/common/shader.cpp.o: CMakeFiles/TP1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TP1.dir/common/shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP1.dir/common/shader.cpp.o -MF CMakeFiles/TP1.dir/common/shader.cpp.o.d -o CMakeFiles/TP1.dir/common/shader.cpp.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/shader.cpp

CMakeFiles/TP1.dir/common/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/common/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/shader.cpp > CMakeFiles/TP1.dir/common/shader.cpp.i

CMakeFiles/TP1.dir/common/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/common/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/shader.cpp -o CMakeFiles/TP1.dir/common/shader.cpp.s

CMakeFiles/TP1.dir/common/controls.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/common/controls.cpp.o: ../common/controls.cpp
CMakeFiles/TP1.dir/common/controls.cpp.o: CMakeFiles/TP1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TP1.dir/common/controls.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP1.dir/common/controls.cpp.o -MF CMakeFiles/TP1.dir/common/controls.cpp.o.d -o CMakeFiles/TP1.dir/common/controls.cpp.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/controls.cpp

CMakeFiles/TP1.dir/common/controls.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/common/controls.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/controls.cpp > CMakeFiles/TP1.dir/common/controls.cpp.i

CMakeFiles/TP1.dir/common/controls.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/common/controls.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/controls.cpp -o CMakeFiles/TP1.dir/common/controls.cpp.s

CMakeFiles/TP1.dir/common/texture.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/common/texture.cpp.o: ../common/texture.cpp
CMakeFiles/TP1.dir/common/texture.cpp.o: CMakeFiles/TP1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TP1.dir/common/texture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP1.dir/common/texture.cpp.o -MF CMakeFiles/TP1.dir/common/texture.cpp.o.d -o CMakeFiles/TP1.dir/common/texture.cpp.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/texture.cpp

CMakeFiles/TP1.dir/common/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/common/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/texture.cpp > CMakeFiles/TP1.dir/common/texture.cpp.i

CMakeFiles/TP1.dir/common/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/common/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/texture.cpp -o CMakeFiles/TP1.dir/common/texture.cpp.s

CMakeFiles/TP1.dir/common/objloader.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/common/objloader.cpp.o: ../common/objloader.cpp
CMakeFiles/TP1.dir/common/objloader.cpp.o: CMakeFiles/TP1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/TP1.dir/common/objloader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP1.dir/common/objloader.cpp.o -MF CMakeFiles/TP1.dir/common/objloader.cpp.o.d -o CMakeFiles/TP1.dir/common/objloader.cpp.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/objloader.cpp

CMakeFiles/TP1.dir/common/objloader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/common/objloader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/objloader.cpp > CMakeFiles/TP1.dir/common/objloader.cpp.i

CMakeFiles/TP1.dir/common/objloader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/common/objloader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/objloader.cpp -o CMakeFiles/TP1.dir/common/objloader.cpp.s

CMakeFiles/TP1.dir/common/vboindexer.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/common/vboindexer.cpp.o: ../common/vboindexer.cpp
CMakeFiles/TP1.dir/common/vboindexer.cpp.o: CMakeFiles/TP1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/TP1.dir/common/vboindexer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP1.dir/common/vboindexer.cpp.o -MF CMakeFiles/TP1.dir/common/vboindexer.cpp.o.d -o CMakeFiles/TP1.dir/common/vboindexer.cpp.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/vboindexer.cpp

CMakeFiles/TP1.dir/common/vboindexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/common/vboindexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/vboindexer.cpp > CMakeFiles/TP1.dir/common/vboindexer.cpp.i

CMakeFiles/TP1.dir/common/vboindexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/common/vboindexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/vboindexer.cpp -o CMakeFiles/TP1.dir/common/vboindexer.cpp.s

CMakeFiles/TP1.dir/common/stb_image.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/common/stb_image.cpp.o: ../common/stb_image.cpp
CMakeFiles/TP1.dir/common/stb_image.cpp.o: CMakeFiles/TP1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/TP1.dir/common/stb_image.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP1.dir/common/stb_image.cpp.o -MF CMakeFiles/TP1.dir/common/stb_image.cpp.o.d -o CMakeFiles/TP1.dir/common/stb_image.cpp.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/stb_image.cpp

CMakeFiles/TP1.dir/common/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/common/stb_image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/stb_image.cpp > CMakeFiles/TP1.dir/common/stb_image.cpp.i

CMakeFiles/TP1.dir/common/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/common/stb_image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/common/stb_image.cpp -o CMakeFiles/TP1.dir/common/stb_image.cpp.s

CMakeFiles/TP1.dir/imgui/imgui.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/imgui/imgui.cpp.o: ../imgui/imgui.cpp
CMakeFiles/TP1.dir/imgui/imgui.cpp.o: CMakeFiles/TP1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/TP1.dir/imgui/imgui.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP1.dir/imgui/imgui.cpp.o -MF CMakeFiles/TP1.dir/imgui/imgui.cpp.o.d -o CMakeFiles/TP1.dir/imgui/imgui.cpp.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui.cpp

CMakeFiles/TP1.dir/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/imgui/imgui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui.cpp > CMakeFiles/TP1.dir/imgui/imgui.cpp.i

CMakeFiles/TP1.dir/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/imgui/imgui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui.cpp -o CMakeFiles/TP1.dir/imgui/imgui.cpp.s

CMakeFiles/TP1.dir/imgui/imgui_demo.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/imgui/imgui_demo.cpp.o: ../imgui/imgui_demo.cpp
CMakeFiles/TP1.dir/imgui/imgui_demo.cpp.o: CMakeFiles/TP1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/TP1.dir/imgui/imgui_demo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP1.dir/imgui/imgui_demo.cpp.o -MF CMakeFiles/TP1.dir/imgui/imgui_demo.cpp.o.d -o CMakeFiles/TP1.dir/imgui/imgui_demo.cpp.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_demo.cpp

CMakeFiles/TP1.dir/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/imgui/imgui_demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_demo.cpp > CMakeFiles/TP1.dir/imgui/imgui_demo.cpp.i

CMakeFiles/TP1.dir/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/imgui/imgui_demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_demo.cpp -o CMakeFiles/TP1.dir/imgui/imgui_demo.cpp.s

CMakeFiles/TP1.dir/imgui/imgui_draw.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/imgui/imgui_draw.cpp.o: ../imgui/imgui_draw.cpp
CMakeFiles/TP1.dir/imgui/imgui_draw.cpp.o: CMakeFiles/TP1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/TP1.dir/imgui/imgui_draw.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP1.dir/imgui/imgui_draw.cpp.o -MF CMakeFiles/TP1.dir/imgui/imgui_draw.cpp.o.d -o CMakeFiles/TP1.dir/imgui/imgui_draw.cpp.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_draw.cpp

CMakeFiles/TP1.dir/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/imgui/imgui_draw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_draw.cpp > CMakeFiles/TP1.dir/imgui/imgui_draw.cpp.i

CMakeFiles/TP1.dir/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/imgui/imgui_draw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_draw.cpp -o CMakeFiles/TP1.dir/imgui/imgui_draw.cpp.s

CMakeFiles/TP1.dir/imgui/imgui_impl_glfw.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/imgui/imgui_impl_glfw.cpp.o: ../imgui/imgui_impl_glfw.cpp
CMakeFiles/TP1.dir/imgui/imgui_impl_glfw.cpp.o: CMakeFiles/TP1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/TP1.dir/imgui/imgui_impl_glfw.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP1.dir/imgui/imgui_impl_glfw.cpp.o -MF CMakeFiles/TP1.dir/imgui/imgui_impl_glfw.cpp.o.d -o CMakeFiles/TP1.dir/imgui/imgui_impl_glfw.cpp.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_impl_glfw.cpp

CMakeFiles/TP1.dir/imgui/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/imgui/imgui_impl_glfw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_impl_glfw.cpp > CMakeFiles/TP1.dir/imgui/imgui_impl_glfw.cpp.i

CMakeFiles/TP1.dir/imgui/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/imgui/imgui_impl_glfw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_impl_glfw.cpp -o CMakeFiles/TP1.dir/imgui/imgui_impl_glfw.cpp.s

CMakeFiles/TP1.dir/imgui/imgui_impl_opengl3.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/imgui/imgui_impl_opengl3.cpp.o: ../imgui/imgui_impl_opengl3.cpp
CMakeFiles/TP1.dir/imgui/imgui_impl_opengl3.cpp.o: CMakeFiles/TP1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/TP1.dir/imgui/imgui_impl_opengl3.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP1.dir/imgui/imgui_impl_opengl3.cpp.o -MF CMakeFiles/TP1.dir/imgui/imgui_impl_opengl3.cpp.o.d -o CMakeFiles/TP1.dir/imgui/imgui_impl_opengl3.cpp.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_impl_opengl3.cpp

CMakeFiles/TP1.dir/imgui/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/imgui/imgui_impl_opengl3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_impl_opengl3.cpp > CMakeFiles/TP1.dir/imgui/imgui_impl_opengl3.cpp.i

CMakeFiles/TP1.dir/imgui/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/imgui/imgui_impl_opengl3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_impl_opengl3.cpp -o CMakeFiles/TP1.dir/imgui/imgui_impl_opengl3.cpp.s

CMakeFiles/TP1.dir/imgui/imgui_tables.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/imgui/imgui_tables.cpp.o: ../imgui/imgui_tables.cpp
CMakeFiles/TP1.dir/imgui/imgui_tables.cpp.o: CMakeFiles/TP1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/TP1.dir/imgui/imgui_tables.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP1.dir/imgui/imgui_tables.cpp.o -MF CMakeFiles/TP1.dir/imgui/imgui_tables.cpp.o.d -o CMakeFiles/TP1.dir/imgui/imgui_tables.cpp.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_tables.cpp

CMakeFiles/TP1.dir/imgui/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/imgui/imgui_tables.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_tables.cpp > CMakeFiles/TP1.dir/imgui/imgui_tables.cpp.i

CMakeFiles/TP1.dir/imgui/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/imgui/imgui_tables.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_tables.cpp -o CMakeFiles/TP1.dir/imgui/imgui_tables.cpp.s

CMakeFiles/TP1.dir/imgui/imgui_widgets.cpp.o: CMakeFiles/TP1.dir/flags.make
CMakeFiles/TP1.dir/imgui/imgui_widgets.cpp.o: ../imgui/imgui_widgets.cpp
CMakeFiles/TP1.dir/imgui/imgui_widgets.cpp.o: CMakeFiles/TP1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/TP1.dir/imgui/imgui_widgets.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP1.dir/imgui/imgui_widgets.cpp.o -MF CMakeFiles/TP1.dir/imgui/imgui_widgets.cpp.o.d -o CMakeFiles/TP1.dir/imgui/imgui_widgets.cpp.o -c /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_widgets.cpp

CMakeFiles/TP1.dir/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1.dir/imgui/imgui_widgets.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_widgets.cpp > CMakeFiles/TP1.dir/imgui/imgui_widgets.cpp.i

CMakeFiles/TP1.dir/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1.dir/imgui/imgui_widgets.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/snsdt/Desktop/Projet_Moteur/imgui/imgui_widgets.cpp -o CMakeFiles/TP1.dir/imgui/imgui_widgets.cpp.s

# Object files for target TP1
TP1_OBJECTS = \
"CMakeFiles/TP1.dir/TP1.cpp.o" \
"CMakeFiles/TP1.dir/Camera/Camera.cpp.o" \
"CMakeFiles/TP1.dir/Camera/Camera_Helper.cpp.o" \
"CMakeFiles/TP1.dir/common/shader.cpp.o" \
"CMakeFiles/TP1.dir/common/controls.cpp.o" \
"CMakeFiles/TP1.dir/common/texture.cpp.o" \
"CMakeFiles/TP1.dir/common/objloader.cpp.o" \
"CMakeFiles/TP1.dir/common/vboindexer.cpp.o" \
"CMakeFiles/TP1.dir/common/stb_image.cpp.o" \
"CMakeFiles/TP1.dir/imgui/imgui.cpp.o" \
"CMakeFiles/TP1.dir/imgui/imgui_demo.cpp.o" \
"CMakeFiles/TP1.dir/imgui/imgui_draw.cpp.o" \
"CMakeFiles/TP1.dir/imgui/imgui_impl_glfw.cpp.o" \
"CMakeFiles/TP1.dir/imgui/imgui_impl_opengl3.cpp.o" \
"CMakeFiles/TP1.dir/imgui/imgui_tables.cpp.o" \
"CMakeFiles/TP1.dir/imgui/imgui_widgets.cpp.o"

# External object files for target TP1
TP1_EXTERNAL_OBJECTS =

TP1: CMakeFiles/TP1.dir/TP1.cpp.o
TP1: CMakeFiles/TP1.dir/Camera/Camera.cpp.o
TP1: CMakeFiles/TP1.dir/Camera/Camera_Helper.cpp.o
TP1: CMakeFiles/TP1.dir/common/shader.cpp.o
TP1: CMakeFiles/TP1.dir/common/controls.cpp.o
TP1: CMakeFiles/TP1.dir/common/texture.cpp.o
TP1: CMakeFiles/TP1.dir/common/objloader.cpp.o
TP1: CMakeFiles/TP1.dir/common/vboindexer.cpp.o
TP1: CMakeFiles/TP1.dir/common/stb_image.cpp.o
TP1: CMakeFiles/TP1.dir/imgui/imgui.cpp.o
TP1: CMakeFiles/TP1.dir/imgui/imgui_demo.cpp.o
TP1: CMakeFiles/TP1.dir/imgui/imgui_draw.cpp.o
TP1: CMakeFiles/TP1.dir/imgui/imgui_impl_glfw.cpp.o
TP1: CMakeFiles/TP1.dir/imgui/imgui_impl_opengl3.cpp.o
TP1: CMakeFiles/TP1.dir/imgui/imgui_tables.cpp.o
TP1: CMakeFiles/TP1.dir/imgui/imgui_widgets.cpp.o
TP1: CMakeFiles/TP1.dir/build.make
TP1: /usr/lib/x86_64-linux-gnu/libGL.so
TP1: /usr/lib/x86_64-linux-gnu/libGLU.so
TP1: external/glfw-3.1.2/src/libglfw3.a
TP1: external/libGLEW_1130.a
TP1: /usr/lib/x86_64-linux-gnu/librt.a
TP1: /usr/lib/x86_64-linux-gnu/libm.so
TP1: /usr/lib/x86_64-linux-gnu/libX11.so
TP1: /usr/lib/x86_64-linux-gnu/libXrandr.so
TP1: /usr/lib/x86_64-linux-gnu/libXinerama.so
TP1: /usr/lib/x86_64-linux-gnu/libXcursor.so
TP1: /usr/lib/x86_64-linux-gnu/librt.a
TP1: /usr/lib/x86_64-linux-gnu/libm.so
TP1: /usr/lib/x86_64-linux-gnu/libX11.so
TP1: /usr/lib/x86_64-linux-gnu/libXrandr.so
TP1: /usr/lib/x86_64-linux-gnu/libXinerama.so
TP1: /usr/lib/x86_64-linux-gnu/libXcursor.so
TP1: /usr/lib/x86_64-linux-gnu/libGL.so
TP1: /usr/lib/x86_64-linux-gnu/libGLU.so
TP1: CMakeFiles/TP1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable TP1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP1.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -E copy /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/./TP1 /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/

# Rule to build all files generated by this target.
CMakeFiles/TP1.dir/build: TP1
.PHONY : CMakeFiles/TP1.dir/build

CMakeFiles/TP1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TP1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TP1.dir/clean

CMakeFiles/TP1.dir/depend:
	cd /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/snsdt/Desktop/Projet_Moteur /mnt/c/Users/snsdt/Desktop/Projet_Moteur /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1 /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1 /mnt/c/Users/snsdt/Desktop/Projet_Moteur/TP1/CMakeFiles/TP1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TP1.dir/depend

