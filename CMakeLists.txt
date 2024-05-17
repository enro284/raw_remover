cmake_minimum_required(VERSION 3.10)
project(raw_remover)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(raw_remover main.cpp file_extension.cpp)