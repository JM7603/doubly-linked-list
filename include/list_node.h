/*
 * File: list.h
 * Author: JM
 * Date: 2023-5-7
 * Description: list node structure declaration and related function declaration
 * */

#ifndef DOUBLY_LINKED_LIST__LIST_NODE_H_
#define DOUBLY_LINKED_LIST__LIST_NODE_H_

/*
 * Struct: list_node
 * Description: list node structure
 * Member: value  - data field
 *         prev   - a pointer to the previous node
 *         next   - a pointer to the next node
 * Alias : list_node_t
 * */
typedef struct list_node {
  int value;
  struct list_node *prev;
  struct list_node *next;
} list_node_t;

/*
 * Function: list_new
 * Description: create a new node
 * Input: value - the value to store
 * Output: None
 * Return: a pointer to the list node structure
 * */
list_node_t *list_node_new(int value);

/*
 * Function: list_new
 * Description: destroy node
 * Input: node - a pointer to list node
 * Output: None
 * Return: None
 * */
void list_node_destroy(list_node_t *node);

#endif //DOUBLY_LINKED_LIST__LIST_NODE_H_
