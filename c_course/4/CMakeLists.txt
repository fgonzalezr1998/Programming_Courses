cmake_minimum_required(VERSION 2.8)

project(double_linked_list)

include_directories(
    include/
)

add_library(my_list STATIC src/my_list/my_list.c)

add_executable(double_linked_list src/double_linked_list.c)
target_link_libraries(double_linked_list my_list)