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

Integer *getFromList(ArrayList *list, int id)
{
	return list_get(list, id);
}

int main()
{

	ArrayList *list = list_create();
	list_add(list, integerWithNumber(0));
	list_add(list, integerWithNumber(1));
	list_add(list, integerWithNumber(2));
	list_add(list, integerWithNumber(3));
	list_add(list, integerWithNumber(4));

	assertEqual(5, list->current_size);
	assertEqual(5, list->max_size);

	list_add(list, integerWithNumber(5));

	assertEqual(6, list->current_size);
	assertEqual(10, list->max_size);

	assertEqual(0, getFromList(list, 0)->number);
	assertEqual(1, getFromList(list, 1)->number);
	assertEqual(2, getFromList(list, 2)->number);

	list_delete_id(list, 2);

	assertEqual(0, getFromList(list, 0)->number);
	assertEqual(1, getFromList(list, 1)->number);
	assertEqual(3, getFromList(list, 2)->number);


	assertEqual(5, list->current_size);
	assertEqual(5, list->max_size);


	return 0;
}
