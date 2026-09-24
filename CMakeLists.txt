cmake_minimum_required(VERSION 4.2)
project(ed1_list_cpp)

set(CMAKE_CXX_STANDARD 20)

#add_executable(ed1_list_cpp main.cpp
#        include/List.h
#        include/ArrayList.h
#        src/ArrayListTest.cpp)

add_executable(ArrayListTest
        src/ArrayListTest.cpp
        include/ArrayList.h)

# Se ainda mantiver um main.cpp na raiz, declare-o aqui:
add_executable(Main main.cpp)