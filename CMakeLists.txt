cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 11)
project(test)
find_package(OpenCV REQUIRED)
include_directories(include)
set(SOURCES test.cpp src/utils.cpp)
add_executable(test ${SOURCES})
target_link_libraries(test ${OpenCV_LIBS})