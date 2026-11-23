cmake_minimum_required(VERSION 3.16)
project(BankAccountsEffectiveCpp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME}
    inc/Account.hpp
    inc/Client.hpp
    src/Account.cpp
    src/Client.cpp
    src/main.cpp
)
