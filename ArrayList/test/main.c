#include <stdio.h>
#include <ArrayList.h>
#include <stdlib.h>

#define assertEqual(a, b)  do { if (a != b) exit(1); } while ( 0 )

typedef struct integer Integer;

struct integer
{
	int number;
} INTEGER;


Integer *integerWithNumber(int number)
{
	Integer *integer1 = malloc(sizeof(Integer));
	integer1->number = number;
	return integer1;
}

Integer *getFromStack(ArrayList *list, int id)
{
	return array_list_get(list, id);
}

int main()
{

	ArrayList *list = array_list_create();
	array_list_add(list, integerWithNumber(0));
	array_list_add(list, integerWithNumber(1));
	array_list_add(list, integerWithNumber(2));
	array_list_add(list, integerWithNumber(3));
	array_list_add(list, integerWithNumber(4));

	assertEqual(5, list->current_size);
	assertEqual(5, list->max_size);

	array_list_add(list, integerWithNumber(5));

	assertEqual(6, list->current_size);
	assertEqual(10, list->max_size);

	assertEqual(0, getFromStack(list, 0)->number);
	assertEqual(1, getFromStack(list, 1)->number);
	assertEqual(2, getFromStack(list, 2)->number);

	array_list_delete_id(list, 2);

	assertEqual(0, getFromStack(list, 0)->number);
	assertEqual(1, getFromStack(list, 1)->number);
	assertEqual(3, getFromStack(list, 2)->number);


	assertEqual(5, list->current_size);
	assertEqual(5, list->max_size);


	return 0;
}
