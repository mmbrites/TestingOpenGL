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
    src/Application.cpp src/VertexBuffer.h src/VertexBuffer.cpp src/IndexBuffer.h src/IndexBuffer.cpp src/Renderer.h src/Renderer.cpp src/VertexArray.h src/VertexArray.cpp src/VertexBufferLayout.h src/VertexBufferLayout.cpp src/Shader.h src/Shader.cpp src/vendor/stb_image/stb_image.h src/vendor/stb_image/stb_image.cpp src/Texture.h src/Texture.cpp
)

# Create the executable
add_executable(application ${SRC_FILES})

# Finds the GLM library
find_package(glm CONFIG REQUIRED)

# Link against GLFW and GLAD. Additionaly, link against GLM.
target_link_libraries(application glfw glad glm::glm)