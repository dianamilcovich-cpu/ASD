cmake_minimum_required(VERSION 3.30)
project(ASD)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB_3
        LAB_3/src/Structs/structs.h
        LAB_3/src/work_file/work_file.h
        LAB_3/src/work_file/work_file.cpp
        LAB_3/src/Sort/sort.h
        LAB_3/src/Sort/sort.cpp
        LAB_3/src/Barriers/barriers.cpp
        LAB_3/src/Barriers/barriers.h
        LAB_3/src/Search/search.h
        LAB_3/src/Search/search.cpp
        LAB_3/src/LAB_3.cpp)
add_executable(LAB_2
        LAB_2/src/LAB_2.cpp
        LAB_2/src/sorts/sorts.cpp
        LAB_2/src/sorts/sorts.h
        LAB_2/src/Structs/structs.cpp
        LAB_2/src/Structs/structs.h
        LAB_2/src/file_work/file_work.cpp
        LAB_2/src/file_work/file_work.h
)

add_executable(LAB4
        LAB4/src/file_work/file_work.cpp
        LAB4/LAB4.cpp
        LAB4/src/search/BMX/BMX.cpp
        LAB4/src/search/BMX/BMX.hpp
        LAB4/src/search/RK/RK.cpp
        LAB4/src/search/RK/RK.h

)
