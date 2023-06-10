/*
 * File: list.h
 * Author: JM
 * Date: 2023-5-7
 * Description: list structure declaration and related function declaration
 * */

#ifndef DOUBLY_LINKED_LIST__LIST_H_
#define DOUBLY_LINKED_LIST__LIST_H_

#include <stdbool.h> // bool, true, false

#include "list_node.h"

typedef struct list {
	list_node_t* head;
	list_node_t* tail;
	int length;
} list_t;

list_t* list_new();
list_t* list_new_from_array(int* array, int length);
void list_destroy(list_t** list);

bool list_empty(list_t* list);
bool list_pushl(list_t* list, int value);
bool list_pushr(list_t* list, int value);
bool list_popl(list_t* list);
bool list_popr(list_t* list);
bool list_clear(list_t* list);
int list_peek(list_t* list, int index);

/* TODO: */
int list_value_at_l(list_t* list, int value);
int list_value_at_r(list_t* list, int value);
bool list_insert(list_t* list, int index);
bool list_modify_value(list_t* list, int index);
bool list_move(list_t* list, int index);

#endif //DOUBLY_LINKED_LIST__LIST_H_
