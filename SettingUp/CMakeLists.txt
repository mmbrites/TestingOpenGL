cmake_minimum_required( VERSION 3.5 ) # Ensures that the CMake version used is at least 3.5. If an older version is used, the script will fail.

project( Hello-GLFW ) # Names the project Hello-GLFW.

find_package( OpenGL REQUIRED ) # Searches for the OpenGL library on the system and ensures it is found. The REQUIRED keyword means the script will terminate if OpenGL is not found.

include_directories( ${OPENGL_INCLUDE_DIRS} ) # Adds the OpenGL include directories to the project's include paths, allowing the code to find OpenGL headers.

# Configures GLFW to skip building its documentation (GLFW_BUILD_DOCS=OFF) and disables its installation step (GLFW_INSTALL=OFF), focusing only on building the GLFW library.
set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" ) 
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

set( GLAD_GL "" ) # Initializes an empty variable GLAD_GL, which will later hold the GLAD (OpenGL loader) source file if used.

add_subdirectory( glfw ) # Adds the glfw folder as a subdirectory for the CMake project. CMake will look for a CMakeLists.txt file in this directory to build the GLFW library.

option( Hello-GLFW-USE-GLFW-GLAD "Use GLAD from GLFW" ON ) # Creates an option Hello-GLFW-USE-GLFW-GLAD, defaulting to ON. This determines whether to use the GLAD loader provided by GLFW.

if( Hello-GLFW-USE-GLFW-GLAD ) # If Hello-GLFW-USE-GLFW-GLAD is enabled:
    include_directories("${GLFW_SOURCE_DIR}/deps") # Adds the deps directory inside GLFW's source folder to the include paths.
    set( GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/gl.h" ) # Sets the GLAD_GL variable to point to GLAD's gl.h header file, so it can be included in the project.
endif()

set( Hello-GLFW-SRC
        hello.cpp
        ) # Specifies the main source file of the project, hello.cpp.

add_executable( hello WIN32 ${Hello-GLFW-SRC} ${GLAD_GL} ) # Defines an executable named hello: The WIN32 keyword specifies that this is a Windows GUI application (doesn't show a console window). Includes the hello.cpp source file and optionally the GLAD loader file.

target_link_libraries( hello ${OPENGL_LIBRARIES} glfw ) # Links the hello executable with: OpenGL libraries (${OPENGL_LIBRARIES}) and the GLFW library.