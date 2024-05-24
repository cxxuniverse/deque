cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(DEQUE VERSION 0.1 DESCRIPTION "Deque Implementation in C" LANGUAGES C)

set(CMAKE_C_STANDARD 17)

include_directories(include)

add_library(deque src/deque.c)
set_target_properties(deque PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_subdirectory(examples)