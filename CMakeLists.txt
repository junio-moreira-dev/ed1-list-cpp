cmake_minimum_required(VERSION 4.2)
project(ed1_list_cpp)

set(CMAKE_CXX_STANDARD 20)

#add_executable(ed1_list_cpp main.cpp
#        include/ArrayList.h
#        include/LinkedList.h)

include_directories(include)

# Executáveis independentes (cada um com seu próprio main):
add_executable(ArrayListTest src/ArrayListTest.cpp)
add_executable(LinkedListTest src/LinkedListTest.cpp)

# Se for manter o main.cpp da raiz do projeto:
add_executable(main_app main.cpp)