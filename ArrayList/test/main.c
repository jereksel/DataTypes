#include <stdio.h>
#include <ArrayList.h>
#include <stdlib.h>

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

void assertEqual(int num1, int num2)
{
	if (num1 != num2)
	{
		exit(1);
	}
}

int main()
{

	ArrayList *list = list_create();
	list_add(list, integerWithNumber(1));
	list_add(list, integerWithNumber(2));

	assertEqual(1, getFromList(list, 0)->number);

	list_delete_id(list, 0);

	assertEqual(2, getFromList(list, 0)->number);


	//printf("Hello World");
	return 0;
}
