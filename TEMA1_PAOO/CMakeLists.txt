cmake_minimum_required(VERSION 3.10)
project(Tema1 LANGUAGES CXX)

include_directories(inc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    inc/Student.hpp
    src/Student.cpp
    src/main.cpp
)
