cmake_minimum_required(VERSION 3.25)
project(SetsTheory)

set(CMAKE_CXX_STANDARD 14)

add_executable(SetsTheory
        main.cpp Interface.h Interface.cpp Utils/Scanner.cpp Utils/Scanner.h Utils/PreprocessInput.cpp Utils/PreprocessInput.cpp Set.h Set.cpp)
