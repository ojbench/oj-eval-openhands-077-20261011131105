cmake_minimum_required(VERSION 3.10)

project(CrossArrayProject CXX)

# Set C++ standard
cmake_policy(SET CMP0014 NEW)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# We don't need a main file for the OJ, but we need a code executable for the build process
# Create an empty main file for compilation
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/empty_main.cpp "#include \"CrossArray.hpp\"\nint main() { return 0; }\n")

# Add source files
set(SOURCES
    ${CMAKE_CURRENT_BINARY_DIR}/empty_main.cpp
)

# Create executable
add_executable(code ${SOURCES})

# Include current directory for CrossArray.hpp
target_include_directories(code PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(code PRIVATE -Wall -Wextra -Werror)
