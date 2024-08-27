cmake_minimum_required(VERSION 3.28)
project(Linkedlists)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(../Library_Mpointer ../../Library_Mpointer/cmake-build-debug/)
add_executable(Linkedlists main.cpp)

target_link_libraries(Linkedlists PRIVATE "${CMAKE_CURRENT_LIST_DIR}/../Library_Mpointer/cmake-build-debug/libLibrary_Mpointer.a")
target_include_directories(Linkedlists PRIVATE ../Library_Mpointer)