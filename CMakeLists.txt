cmake_minimum_required(VERSION 3.10)

project(intrusive-linked-list VERSION 0.0.1)

#single-ill demo
add_library(single-intrusive-linked-list-lib
            include/data.h
            include/single_intrusive_linked_list.h
            src/single_intrusive_linked_list.c
            )
target_include_directories(single-intrusive-linked-list-lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(single-intrusive-linked-list-demo test/single_demo.c)
target_include_directories(single-intrusive-linked-list-demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(single-intrusive-linked-list-demo PRIVATE single-intrusive-linked-list-lib)

#double-ill demo
add_library(double-intrusive-linked-list-lib
            include/data.h
            include/double_intrusive_linked_list.h
            src/double_intrusive_linked_list.c
            )
target_include_directories(double-intrusive-linked-list-lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(double-intrusive-linked-list-demo test/double_demo.c)
target_include_directories(double-intrusive-linked-list-demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(double-intrusive-linked-list-demo PRIVATE double-intrusive-linked-list-lib)
