cmake_minimum_required(VERSION 3.22)
project(freq_dict)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES ${CMAKE_SOURCE_DIR}/src/main.cpp
            ${CMAKE_SOURCE_DIR}/src/freq_parser.cpp)
set(HEADERS ${CMAKE_SOURCE_DIR}/src/freq_parser.hpp)
add_executable(freq_dict ${SOURCES})
