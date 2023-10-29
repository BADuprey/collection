cmake_minimum_required(VERSION 3.26)
project(Project3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project3 main.cpp
        InternationalTrade.h
        BinarySearchTree.h
        AvlTree.h
        SplayTree.h
        splayTests2.cpp)
