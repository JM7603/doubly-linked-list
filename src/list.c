/*
 * File: list.c
 * Author: JM
 * Date: 2023-5-7
 * Description: Implementation of the function in list.h
 * */

#include <malloc.h> // malloc
#include <stdlib.h>

#include "../include/list.h"

list_t *list_new() {
  list_t *new_list = malloc(sizeof(list_t));
  new_list->length = 0;
  new_list->head = NULL;
  new_list->tail = NULL;
  return new_list;
}

list_t *list_new_from_array(int *array, int length) {
  if (length <= 0) return list_new();

  list_t *new_list = malloc(sizeof(list_t));
  new_list->length = 1;
  new_list->head = list_node_new(array[0]);
  new_list->tail = new_list->head;

  list_node_t *current = new_list->head;
  for (int i = 1; i < length; ++i, ++new_list->length) {
    current->next = list_node_new(array[i]);
    current->next->prev = current;
    current = current->next;
    new_list->tail = current;
  }

  return new_list;
}

void list_destroy(list_t **list) {
  if (!list || !(*list)) return;
  list_clear(*list);
  free(*list);
  *list = NULL;
}

bool list_empty(list_t *list) {
  if (!list) return true;
  return !list->length;
}

bool list_pushl(list_t *list, int value) {
  if (!list) return false;
  if (!list->head) {
    list_node_t *new_node = list_node_new(value);
    list->head = new_node;
    list->tail = list->head;
  } else {
    list_node_t *new_node = list_node_new(value);
    new_node->prev = NULL;
    new_node->next = list->head;
    list->head->prev = new_node;
    list->head = new_node;
  }
  list->length++;
  return true;
}

bool list_pushr(list_t *list, int value) {
  if (!list) return false;
  if (!list->tail) {
    list_node_t *new_node = list_node_new(value);
    list->tail = new_node;
    list->head = list->tail;
  } else {
    list_node_t *new_node = list_node_new(value);
    new_node->next = NULL;
    new_node->prev = list->tail;
    list->tail->next = new_node;
    list->tail = new_node;
  }
  list->length++;
  return true;
}

bool list_popl(list_t *list) {
  if (!list || !list->head) return false;
  if (list->head == list->tail) {
    list_node_destroy(list->head);
    list->head = NULL;
    list->tail = list->head;
  } else {
    list_node_t *to_be_destroy = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    list_node_destroy(to_be_destroy);
  }
  list->length--;
  return true;
}

bool list_popr(list_t *list) {
  if (!list || !list->tail) return false;
  if (list->tail == list->head) {
    list_node_destroy(list->tail);
    list->tail = NULL;
    list->head = list->tail;
  } else {
    list_node_t *to_be_destroy = list->tail;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    list_node_destroy(to_be_destroy);
  }
  list->length--;
  return true;
}

bool list_clear(list_t *list) {
  if (!list) return false;
  list_node_t *node = list->head;

  while (node) {
    list_node_t *to_be_destroy = node;
    node = node->next;
    list_node_destroy(to_be_destroy);
  }

  list->head = NULL;
  list->tail = list->head;
  list->length = 0;
  return true;
}

int list_peek(list_t *list, int index) {
  if (!list) exit(-1);
  if (index < 0 || index > list->length - 1) exit(-1);
  if (index == 0) return list->head->value;
  if (index == list->length - 1) return list->tail->value;

  list_node_t *node = list->head;
  while (index-- > 0) {
    node = node->next;
  }
  return node->value;
}
