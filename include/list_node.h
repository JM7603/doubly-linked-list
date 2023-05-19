/*
 * File: list.h
 * Author: JM
 * Date: 2023-5-7
 * Description: list node structure declaration and related function declaration
 * */

#ifndef DOUBLY_LINKED_LIST__LIST_NODE_H_
#define DOUBLY_LINKED_LIST__LIST_NODE_H_

typedef struct list_node {
  int value;
  struct list_node *prev;
  struct list_node *next;
} list_node_t;


list_node_t *list_node_new(int value);
void list_node_destroy(list_node_t *node);

#endif //DOUBLY_LINKED_LIST__LIST_NODE_H_
