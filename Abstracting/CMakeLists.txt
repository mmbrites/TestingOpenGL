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

set(IMGUI_DIRECTORY "${PROJECT_SOURCE_DIR}/resources/libraries/imgui-1.91.8")
set(IMGUI_SOURCES 
    ${IMGUI_DIRECTORY}/imconfig.h
    ${IMGUI_DIRECTORY}/imgui_demo.cpp
    ${IMGUI_DIRECTORY}/imgui_draw.cpp
    ${IMGUI_DIRECTORY}/imgui_internal.h
    ${IMGUI_DIRECTORY}/imgui_tables.cpp
    ${IMGUI_DIRECTORY}/imgui_widgets.cpp
    ${IMGUI_DIRECTORY}/imgui.cpp
    ${IMGUI_DIRECTORY}/imgui.h
    ${IMGUI_DIRECTORY}/imstb_rectpack.h
    ${IMGUI_DIRECTORY}/imstb_textedit.h
    ${IMGUI_DIRECTORY}/imstb_truetype.h
    ${IMGUI_DIRECTORY}/backends/imgui_impl_glfw.h
    ${IMGUI_DIRECTORY}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIRECTORY}/backends/imgui_impl_opengl3.h
    ${IMGUI_DIRECTORY}/backends/imgui_impl_opengl3.cpp
    ${IMGUI_DIRECTORY}/backends/imgui_impl_opengl3_loader.h)

include_directories(${IMGUI_DIRECTORY} ${IMGUI_DIRECTORY}/backends)

add_library(imgui STATIC ${IMGUI_SOURCES})
target_link_libraries(imgui glfw glad)

# Create the executable
add_executable(application ${SRC_FILES})

# Finds the GLM library
find_package(glm CONFIG REQUIRED)

# Link against GLFW and GLAD. Additionaly, link against GLM.
target_link_libraries(application glfw glad glm::glm imgui)