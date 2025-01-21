cmake_minimum_required(VERSION 3.5)

project(project)

# Add GLFW
add_subdirectory(glfw)

# Add GLAD manually
set(GLAD_SOURCES "${PROJECT_SOURCE_DIR}/glad/src/gl.c")
include_directories("${PROJECT_SOURCE_DIR}/glad/include")
add_library(glad STATIC ${GLAD_SOURCES})

# Source files for your project
set(SRC_FILES
    src/Application.cpp src/VertexBuffer.h src/VertexBuffer.cpp src/IndexBuffer.h src/IndexBuffer.cpp src/Renderer.h src/Renderer.cpp
)

# Create the executable
add_executable(application ${SRC_FILES})

# Link against GLFW and GLAD
target_link_libraries(application glfw glad)