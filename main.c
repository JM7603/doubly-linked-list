/*
 * File: main.c
 * Author: JM
 * Date: 2023-5-7
 * Description: call test function
 * */

/* from `test/test_list_init_push.c` */
extern void test_list_init_push(void);

int main(int argc, char** argv)
{
	test_list_init_push();

	return 0;
}
