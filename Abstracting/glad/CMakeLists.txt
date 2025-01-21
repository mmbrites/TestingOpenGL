cmake_minimum_required(VERSION 3.5) # Minimum CMake version required

set(GLAD_SOURCES_DIR "${PROJECT_SOURCE_DIR}/glad/") # Path to glad directory

add_library(glad STATIC "${GLAD_SOURCES_DIR}/src/glad.c") # Create a target for the GLAD library

target_include_directories(glad PUBLIC include) # Include the GLAD headers