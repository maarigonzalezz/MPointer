cmake_minimum_required(VERSION 3.28)
project(Linkedlists)

set(CMAKE_CXX_STANDARD 20)

# Añadir GoogleTest
add_subdirectory(lib/googletest)

# Añadir subdirectorio de la librería MPointer
add_subdirectory(../Library_Mpointer ../../Library_Mpointer/cmake-build-debug/)

# Compilar el proyecto principal
add_executable(Linkedlists
        src/main.cpp
        src/DoubleLinkedList.cpp
        src/DoubleLinkedList.h
        src/Sorters.cpp
        src/Sorters.h
)

target_link_libraries(Linkedlists PRIVATE "${CMAKE_CURRENT_LIST_DIR}/../Library_Mpointer/cmake-build-debug/libLibrary_Mpointer.a")
target_include_directories(Linkedlists PRIVATE ../Library_Mpointer)

# Añadir el ejecutable de pruebas
enable_testing()
add_executable(Linkedlists_tests tst/test_main.cpp)
target_link_libraries(Linkedlists_tests gtest gtest_main "${CMAKE_CURRENT_LIST_DIR}/../Library_Mpointer/cmake-build-debug/libLibrary_Mpointer.a")
target_include_directories(Linkedlists_tests PRIVATE ../Library_Mpointer)

# Definir las pruebas
add_test(NAME Linkedlists_tests COMMAND Linkedlists_tests)