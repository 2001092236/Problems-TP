cmake_minimum_required(VERSION 3.0)
project(Project)

find_package(GTest)
find_package(Threads)

target_include_directories(${GTEST_INCLUDE_DIRS})

execute_process(COMMAND python3 preparing.py WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/A)

add_subdirectory(B ${PROJECT_SOURCE_DIR}/lib)

add_executable(Project C/main.cpp)
add_executable(CTest C/main_test.cpp)

target_link_libraries(CTest Library ${GTEST_LIBRARIES} Threads::Threads)
target_link_libraries(Project Library)

target_include_directories(CTest PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(Project PUBLIC ${PROJECT_SOURCE_DIR})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set_target_properties(Library PROPERTIES LINKER_LANGUAGE CXX)
