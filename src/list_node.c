/*
 * File: list.c
 * Author: JM
 * Date: 2023-5-7
 * Description: Implementation of the function in list_node.h
 * */

#include <malloc.h> // malloc

#include "../include/list_node.h"

list_node_t *list_node_new(int value) {
  list_node_t *new_node = malloc(sizeof(list_node_t));
  new_node->value = value;
  new_node->prev = NULL;
  new_node->next = NULL;
  return new_node;
}

void list_node_destroy(list_node_t *node) {
  if (!node) return;
  free(node);
}
