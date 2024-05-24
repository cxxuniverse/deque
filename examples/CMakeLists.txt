add_executable(examples examples.c)

set_target_properties(examples PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

target_compile_options(examples PRIVATE -g -Wall)

target_link_libraries(examples deque)