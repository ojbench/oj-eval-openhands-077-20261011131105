cmake_minimum_required(VERSION 3.10)

project(CrossArrayProject CXX)

# Set C++ standard
cmake_policy(SET CMP0014 NEW)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    main.cpp
    src/CrossArray.cpp
)

# Create executable
add_executable(code ${SOURCES})

# Include directories
target_include_directories(code PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(code PRIVATE -Wall -Wextra -Werror)
