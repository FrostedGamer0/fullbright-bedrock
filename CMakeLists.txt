cmake_minimum_required(VERSION 3.16)

# Set the project name and language
project(Fullbright LANGUAGES CXX)

# Ensure we are targeting C++17 or higher for modern memory types (like uintptr_t)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Force the output to be a 64-bit DLL (Minecraft Bedrock is strictly 64-bit)
if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "You must configure CMake for a 64-bit target architecture (x64)!")
endif()

# Gather all source files from the src directory
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.h")

# Define the build target as a DLL (SHARED library)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

# Include windows.h natively without bloating the build
target_compile_definitions(${PROJECT_NAME} PRIVATE WIN32_LEAN_AND_MEAN)