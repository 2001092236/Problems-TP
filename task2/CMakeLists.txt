cmake_minimum_required(VERSION 3.0)
project(Project)

execute_process(COMMAND python3 preparing.py WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/A)

add_executable(Project C/main.cpp)

target_include_directories(Project PUBLIC ${PROJECT_SOURCE_DIR})

add_subdirectory(B ${PROJECT_SOURCE_DIR}/lib)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set_target_properties(Library PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(Project Library)
