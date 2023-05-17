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

/*
 * Struct: list
 * Description: linked list structure
 * Member: head   - the head node
 *         tail   - the tail node
 *         length - length of the linked list(node count)
 * Alias : list_t
 * */
typedef struct list {
  list_node_t *head;
  list_node_t *tail;
  int length;
} list_t;

// =========================================
// ===== list creation and destruction =====
// =========================================

/*
 * Function: list_new
 * Description: create an empty linked list
 * Input: None
 * Output: None
 * Return: a pointer to the list structure
 * */
list_t *list_new();

/*
 * Function: list_new_from_array
 * Description: create an empty linked list and add the contents of the existing array to it
 * Input: array  - an array of data
 *        length - length of array
 * Output: None
 * Return: a pointer to the list structure
 * */
list_t *list_new_from_array(int *array, int length);

/*
 * Function: list_destroy
 * Description: frees all nodes and list
 * Input: list - a pointer to the list pointer
 * Output: None
 * Return: None
 * */
void list_destroy(list_t **list);

// =========================================
// ===== list creation and destruction =====
// =========================================

/*
 * Function: list_empty
 * Description: determines whether the linked list is empty
 * Input: list - a pointer to the list
 * Output: None
 * Return: true if the list is empty, false otherwise
 * */
bool list_empty(list_t *list);

/*
 * Function: list_pushl
 * Description: insert a node into the list header
 * Input: list  - a pointer to the list
 *        value - data in node
 * Output: None
 * Return: true if successful operation, false otherwise
 * */
bool list_pushl(list_t *list, int value);

/*
 * Function: list_pushr
 * Description: insert a node into the list tail
 * Input: list  - a pointer to the list
 *        value - data in node
 * Output: None
 * Return: true if successful operation, false otherwise
 * */
bool list_pushr(list_t *list, int value);

/*
 * Function: list_popl
 * Description: destroy the head node
 * Input: list  - a pointer to the list
 * Output: None
 * Return: true if successful operation, false otherwise
 * */
bool list_popl(list_t *list);


/*
 * Function: list_popr
 * Description: destroy the tail node
 * Input: list  - a pointer to the list
 * Output: None
 * Return: true if successful operation, false otherwise
 * */
bool list_popr(list_t *list);

/*
 * Function: list_clear
 * Description: destroy all node
 * Input: list  - a pointer to the list
 * Output: None
 * Return: true if successful operation, false otherwise
 * */
bool list_clear(list_t *list);

/*
 * Function: list_peek
 * Description: get the value in the linked list with n - 1
 * Input: list  - a pointer to the list
 *        index - index
 * Output: None
 * Return: the value of the n - 1 element
 * */
int list_peek(list_t *list, int index);

/* TODO: */
int  list_value_at_l(list_t *list, int value);
int  list_value_at_r(list_t *list, int value);
bool list_insert(list_t *list, int index);
bool list_modify_value(list_t *list, int index);
bool list_move(list_t *list, int index);

#endif //DOUBLY_LINKED_LIST__LIST_H_
