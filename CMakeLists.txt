cmake_minimum_required(VERSION 3.30)
project(ASD)

set(CMAKE_CXX_STANDARD 20)

add_executable(ASD main.cpp)
add_executable(LAB_2
        src/LAB_2.cpp
        src/sorts/sorts.cpp
        src/sorts/sorts.h
        src/Structs/structs.cpp
        src/Structs/structs.h
)

