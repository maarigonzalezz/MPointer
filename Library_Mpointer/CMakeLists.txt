cmake_minimum_required(VERSION 3.28)
project(Library_Mpointer)

set(CMAKE_CXX_STANDARD 20)

add_library(Library_Mpointer STATIC
        MPointerGC.cpp
        MPointerGC.h
        LinkedList.cpp
        LinkedList.h)
