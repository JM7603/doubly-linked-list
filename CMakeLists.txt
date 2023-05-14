cmake_minimum_required(VERSION 3.25)
project(doubly_linked_list C)

set(CMAKE_C_STANDARD 11)

add_executable(doubly_linked_list main.c src/list_node.c src/list.c test/test_list_init_push.c)
target_link_libraries(doubly_linked_list m)
