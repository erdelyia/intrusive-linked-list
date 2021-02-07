cmake_minimum_required(VERSION 3.10)

project(intrusive-linked-list VERSION 0.0.1)

#single-ill demo
add_library(single-intrusive-linked-list-lib
            data.h
            single_intrusive_linked_list.h
            single_intrusive_linked_list.c
            )

add_executable(single-intrusive-linked-list-demo single_demo.c)

target_link_libraries(single-intrusive-linked-list-demo PRIVATE single-intrusive-linked-list-lib)
