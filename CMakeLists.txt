cmake_minimum_required(VERSION 3.31)
project(Rubiks)

set(CMAKE_CXX_STANDARD 20)

add_executable(Rubiks main.cpp
        Model/RubiksCube.cpp
        Model/RubiksCube.h
        Model/RubiksCube3D.cpp
        Model/RubiksCube1D.cpp
        Solver/DFS.cpp
        Solver/BFS.cpp
        Solver/IDDFS.cpp)
