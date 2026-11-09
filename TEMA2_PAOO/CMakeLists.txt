
cmake_minimum_required(VERSION 3.16)

project(TEMA2_PAOO LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TEMA2_PAOO
    src/main.cpp
    src/Instrument.cpp
    src/Magazin.cpp
    src/Boxa.cpp
    src/Item5.cpp
)

target_include_directories(TEMA2_PAOO PRIVATE inc)
