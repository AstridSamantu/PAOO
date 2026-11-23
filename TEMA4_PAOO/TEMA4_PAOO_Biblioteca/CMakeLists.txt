cmake_minimum_required(VERSION 3.16)
project(TEMA4_PAOO_Biblioteca LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME}
    inc/Book.hpp
    inc/Library.hpp
    src/Book.cpp
    src/Library.cpp
    src/main.cpp
)
