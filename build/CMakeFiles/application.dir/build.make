# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chiono/Documents/Programming/Projects/TestingOpenGL/build

# Include any dependencies generated for this target.
include CMakeFiles/application.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/application.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/application.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/application.dir/flags.make

CMakeFiles/application.dir/src/Application.cpp.o: CMakeFiles/application.dir/flags.make
CMakeFiles/application.dir/src/Application.cpp.o: /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/Application.cpp
CMakeFiles/application.dir/src/Application.cpp.o: CMakeFiles/application.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/chiono/Documents/Programming/Projects/TestingOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/application.dir/src/Application.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/application.dir/src/Application.cpp.o -MF CMakeFiles/application.dir/src/Application.cpp.o.d -o CMakeFiles/application.dir/src/Application.cpp.o -c /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/Application.cpp

CMakeFiles/application.dir/src/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/application.dir/src/Application.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/Application.cpp > CMakeFiles/application.dir/src/Application.cpp.i

CMakeFiles/application.dir/src/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/application.dir/src/Application.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/Application.cpp -o CMakeFiles/application.dir/src/Application.cpp.s

CMakeFiles/application.dir/src/VertexBuffer.cpp.o: CMakeFiles/application.dir/flags.make
CMakeFiles/application.dir/src/VertexBuffer.cpp.o: /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/VertexBuffer.cpp
CMakeFiles/application.dir/src/VertexBuffer.cpp.o: CMakeFiles/application.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/chiono/Documents/Programming/Projects/TestingOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/application.dir/src/VertexBuffer.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/application.dir/src/VertexBuffer.cpp.o -MF CMakeFiles/application.dir/src/VertexBuffer.cpp.o.d -o CMakeFiles/application.dir/src/VertexBuffer.cpp.o -c /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/VertexBuffer.cpp

CMakeFiles/application.dir/src/VertexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/application.dir/src/VertexBuffer.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/VertexBuffer.cpp > CMakeFiles/application.dir/src/VertexBuffer.cpp.i

CMakeFiles/application.dir/src/VertexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/application.dir/src/VertexBuffer.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/VertexBuffer.cpp -o CMakeFiles/application.dir/src/VertexBuffer.cpp.s

CMakeFiles/application.dir/src/IndexBuffer.cpp.o: CMakeFiles/application.dir/flags.make
CMakeFiles/application.dir/src/IndexBuffer.cpp.o: /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/IndexBuffer.cpp
CMakeFiles/application.dir/src/IndexBuffer.cpp.o: CMakeFiles/application.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/chiono/Documents/Programming/Projects/TestingOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/application.dir/src/IndexBuffer.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/application.dir/src/IndexBuffer.cpp.o -MF CMakeFiles/application.dir/src/IndexBuffer.cpp.o.d -o CMakeFiles/application.dir/src/IndexBuffer.cpp.o -c /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/IndexBuffer.cpp

CMakeFiles/application.dir/src/IndexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/application.dir/src/IndexBuffer.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/IndexBuffer.cpp > CMakeFiles/application.dir/src/IndexBuffer.cpp.i

CMakeFiles/application.dir/src/IndexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/application.dir/src/IndexBuffer.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/IndexBuffer.cpp -o CMakeFiles/application.dir/src/IndexBuffer.cpp.s

CMakeFiles/application.dir/src/Renderer.cpp.o: CMakeFiles/application.dir/flags.make
CMakeFiles/application.dir/src/Renderer.cpp.o: /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/Renderer.cpp
CMakeFiles/application.dir/src/Renderer.cpp.o: CMakeFiles/application.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/chiono/Documents/Programming/Projects/TestingOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/application.dir/src/Renderer.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/application.dir/src/Renderer.cpp.o -MF CMakeFiles/application.dir/src/Renderer.cpp.o.d -o CMakeFiles/application.dir/src/Renderer.cpp.o -c /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/Renderer.cpp

CMakeFiles/application.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/application.dir/src/Renderer.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/Renderer.cpp > CMakeFiles/application.dir/src/Renderer.cpp.i

CMakeFiles/application.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/application.dir/src/Renderer.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/Renderer.cpp -o CMakeFiles/application.dir/src/Renderer.cpp.s

CMakeFiles/application.dir/src/VertexArray.cpp.o: CMakeFiles/application.dir/flags.make
CMakeFiles/application.dir/src/VertexArray.cpp.o: /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/VertexArray.cpp
CMakeFiles/application.dir/src/VertexArray.cpp.o: CMakeFiles/application.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/chiono/Documents/Programming/Projects/TestingOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/application.dir/src/VertexArray.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/application.dir/src/VertexArray.cpp.o -MF CMakeFiles/application.dir/src/VertexArray.cpp.o.d -o CMakeFiles/application.dir/src/VertexArray.cpp.o -c /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/VertexArray.cpp

CMakeFiles/application.dir/src/VertexArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/application.dir/src/VertexArray.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/VertexArray.cpp > CMakeFiles/application.dir/src/VertexArray.cpp.i

CMakeFiles/application.dir/src/VertexArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/application.dir/src/VertexArray.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/VertexArray.cpp -o CMakeFiles/application.dir/src/VertexArray.cpp.s

CMakeFiles/application.dir/src/VertexBufferLayout.cpp.o: CMakeFiles/application.dir/flags.make
CMakeFiles/application.dir/src/VertexBufferLayout.cpp.o: /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/VertexBufferLayout.cpp
CMakeFiles/application.dir/src/VertexBufferLayout.cpp.o: CMakeFiles/application.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/chiono/Documents/Programming/Projects/TestingOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/application.dir/src/VertexBufferLayout.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/application.dir/src/VertexBufferLayout.cpp.o -MF CMakeFiles/application.dir/src/VertexBufferLayout.cpp.o.d -o CMakeFiles/application.dir/src/VertexBufferLayout.cpp.o -c /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/VertexBufferLayout.cpp

CMakeFiles/application.dir/src/VertexBufferLayout.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/application.dir/src/VertexBufferLayout.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/VertexBufferLayout.cpp > CMakeFiles/application.dir/src/VertexBufferLayout.cpp.i

CMakeFiles/application.dir/src/VertexBufferLayout.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/application.dir/src/VertexBufferLayout.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/VertexBufferLayout.cpp -o CMakeFiles/application.dir/src/VertexBufferLayout.cpp.s

CMakeFiles/application.dir/src/Shader.cpp.o: CMakeFiles/application.dir/flags.make
CMakeFiles/application.dir/src/Shader.cpp.o: /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/Shader.cpp
CMakeFiles/application.dir/src/Shader.cpp.o: CMakeFiles/application.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/chiono/Documents/Programming/Projects/TestingOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/application.dir/src/Shader.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/application.dir/src/Shader.cpp.o -MF CMakeFiles/application.dir/src/Shader.cpp.o.d -o CMakeFiles/application.dir/src/Shader.cpp.o -c /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/Shader.cpp

CMakeFiles/application.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/application.dir/src/Shader.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/Shader.cpp > CMakeFiles/application.dir/src/Shader.cpp.i

CMakeFiles/application.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/application.dir/src/Shader.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/Shader.cpp -o CMakeFiles/application.dir/src/Shader.cpp.s

CMakeFiles/application.dir/src/vendor/stb_image/stb_image.cpp.o: CMakeFiles/application.dir/flags.make
CMakeFiles/application.dir/src/vendor/stb_image/stb_image.cpp.o: /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/vendor/stb_image/stb_image.cpp
CMakeFiles/application.dir/src/vendor/stb_image/stb_image.cpp.o: CMakeFiles/application.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/chiono/Documents/Programming/Projects/TestingOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/application.dir/src/vendor/stb_image/stb_image.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/application.dir/src/vendor/stb_image/stb_image.cpp.o -MF CMakeFiles/application.dir/src/vendor/stb_image/stb_image.cpp.o.d -o CMakeFiles/application.dir/src/vendor/stb_image/stb_image.cpp.o -c /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/vendor/stb_image/stb_image.cpp

CMakeFiles/application.dir/src/vendor/stb_image/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/application.dir/src/vendor/stb_image/stb_image.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/vendor/stb_image/stb_image.cpp > CMakeFiles/application.dir/src/vendor/stb_image/stb_image.cpp.i

CMakeFiles/application.dir/src/vendor/stb_image/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/application.dir/src/vendor/stb_image/stb_image.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/vendor/stb_image/stb_image.cpp -o CMakeFiles/application.dir/src/vendor/stb_image/stb_image.cpp.s

CMakeFiles/application.dir/src/Texture.cpp.o: CMakeFiles/application.dir/flags.make
CMakeFiles/application.dir/src/Texture.cpp.o: /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/Texture.cpp
CMakeFiles/application.dir/src/Texture.cpp.o: CMakeFiles/application.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/chiono/Documents/Programming/Projects/TestingOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/application.dir/src/Texture.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/application.dir/src/Texture.cpp.o -MF CMakeFiles/application.dir/src/Texture.cpp.o.d -o CMakeFiles/application.dir/src/Texture.cpp.o -c /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/Texture.cpp

CMakeFiles/application.dir/src/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/application.dir/src/Texture.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/Texture.cpp > CMakeFiles/application.dir/src/Texture.cpp.i

CMakeFiles/application.dir/src/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/application.dir/src/Texture.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting/src/Texture.cpp -o CMakeFiles/application.dir/src/Texture.cpp.s

# Object files for target application
application_OBJECTS = \
"CMakeFiles/application.dir/src/Application.cpp.o" \
"CMakeFiles/application.dir/src/VertexBuffer.cpp.o" \
"CMakeFiles/application.dir/src/IndexBuffer.cpp.o" \
"CMakeFiles/application.dir/src/Renderer.cpp.o" \
"CMakeFiles/application.dir/src/VertexArray.cpp.o" \
"CMakeFiles/application.dir/src/VertexBufferLayout.cpp.o" \
"CMakeFiles/application.dir/src/Shader.cpp.o" \
"CMakeFiles/application.dir/src/vendor/stb_image/stb_image.cpp.o" \
"CMakeFiles/application.dir/src/Texture.cpp.o"

# External object files for target application
application_EXTERNAL_OBJECTS =

application: CMakeFiles/application.dir/src/Application.cpp.o
application: CMakeFiles/application.dir/src/VertexBuffer.cpp.o
application: CMakeFiles/application.dir/src/IndexBuffer.cpp.o
application: CMakeFiles/application.dir/src/Renderer.cpp.o
application: CMakeFiles/application.dir/src/VertexArray.cpp.o
application: CMakeFiles/application.dir/src/VertexBufferLayout.cpp.o
application: CMakeFiles/application.dir/src/Shader.cpp.o
application: CMakeFiles/application.dir/src/vendor/stb_image/stb_image.cpp.o
application: CMakeFiles/application.dir/src/Texture.cpp.o
application: CMakeFiles/application.dir/build.make
application: glfw/src/libglfw3.a
application: libglad.a
application: /usr/lib64/librt.a
application: /usr/lib64/libm.so
application: CMakeFiles/application.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/chiono/Documents/Programming/Projects/TestingOpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable application"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/application.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/application.dir/build: application
.PHONY : CMakeFiles/application.dir/build

CMakeFiles/application.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/application.dir/cmake_clean.cmake
.PHONY : CMakeFiles/application.dir/clean

CMakeFiles/application.dir/depend:
	cd /home/chiono/Documents/Programming/Projects/TestingOpenGL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting /home/chiono/Documents/Programming/Projects/TestingOpenGL/Abstracting /home/chiono/Documents/Programming/Projects/TestingOpenGL/build /home/chiono/Documents/Programming/Projects/TestingOpenGL/build /home/chiono/Documents/Programming/Projects/TestingOpenGL/build/CMakeFiles/application.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/application.dir/depend

