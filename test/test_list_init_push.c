//
// Created by jm on 23-5-9.
//

#include <stdio.h>

#include "../include/list.h"

void test_list_init_push(void)
{
	/* initialize list from array */
#if 0
	printf("initialize list from array\n");
	int arr[5] = {5, 4, 3, 2, 1};
	list_t *list1 = list_new_from_array(arr, 5);
	printf("length of list1: %d\n\n", list1->length);
#endif

	/* initialize list with normal constructor and test the `list_push` function */
#if 1
	printf("initialize list with normal constructor\n");
	list_t* list1 = list_new();
	for (int i = 1; i <= 5; ++i) {
		list_pushl(list1, i);
	}
	list_pushr(list1, 0);
	list_pushr(list1, -1);
	printf("length of list1: %d\n\n", list1->length);
#endif

	/* print list */
#if 1
	printf("print list: \n");

	list_node_t* list_head = list1->head;
	while (list_head) {
		printf("%d ", list_head->value);
		list_head = list_head->next;
	}
	printf("\n\n");
#endif

#if 1
	/* test `list_pop` function */
	printf("list_pop\n");
	list_popl(list1);
	list_popr(list1);
#endif

	/* print reversed list */
#if 1
	printf("print list(reversed): \n");

	list_pushl(list1, 6);

	list_node_t* list_tail = list1->tail;
	while (list_tail) {
		printf("%d ", list_tail->value);
		list_tail = list_tail->prev;
	}

	printf("\n");
	printf("length of list1: %d\n\n", list1->length);
#endif

	/* peek */
#if 1
	printf("peek all: \n");
	for (int i = 0; i < list1->length; ++i) {
		printf("%d ", list_peek(list1, i));
	}
	putchar('\n');
#endif

	/* is empty */
#if 1
	printf("list empty: %s\n", list_empty(list1) ? "true" : "false");
#endif

	/* destroy list */
#if 1
	printf("list destroy: \n");
	list_destroy(&list1);
//  printf("length of list1: %d\n", list1->length);
	printf("list is NULL: %s", list1 ? "false" : "true");
#endif

	/* is empty */
#if 1
//  printf("list empty: %s\n", list_empty(list1) ? "true" : "false");
#endif
}
