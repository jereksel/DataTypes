#include <stdio.h>
#include "Stack.h"
#include <stdlib.h>

#define assertEqual(a, b)  do { if (a != b) exit(1); } while ( 0 )

typedef struct integer Integer;

struct integer
{
	int number;
} INTEGER;

Integer *getFromStack(Stack *stack)
{
	return stack_pop(stack);
}

Integer *integerWithNumber(int number)
{
	Integer *integer1 = malloc(sizeof(Integer));
	integer1->number = number;
	return integer1;
}

int main()
{

	Stack *stack = stack_create();

	assertEqual(true, stack_empty(stack));


	stack_push(stack, integerWithNumber(0));
	stack_push(stack, integerWithNumber(1));
	stack_push(stack, integerWithNumber(2));
	stack_push(stack, integerWithNumber(3));
	stack_push(stack, integerWithNumber(4));


	assertEqual(false, stack_empty(stack));


	stack_push(stack, integerWithNumber(5));


	assertEqual(5, getFromStack(stack)->number);
	assertEqual(4, getFromStack(stack)->number);
	assertEqual(3, getFromStack(stack)->number);
	assertEqual(2, getFromStack(stack)->number);
	assertEqual(1, getFromStack(stack)->number);
	assertEqual(0, getFromStack(stack)->number);

	assertEqual(true, stack_empty(stack));


	return 0;
}
