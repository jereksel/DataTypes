#include <stdlib.h>
#include "ArrayList.h"

#define STEP 1

ArrayList *list_create()
{
	ArrayList *list = malloc(sizeof(ArrayList));

	list->stuff = malloc(sizeof(void *) * STEP);
	list->current_size = 0;
	list->max_size = STEP;
	return list;
}

void list_add(ArrayList *list, void *item)
{
	if (list->current_size + 1 == list->max_size)
	{
		list->max_size = list->max_size + STEP;
		list->stuff = realloc(list->stuff, sizeof(void *) * list->max_size);
	}

	list->stuff[list->current_size] = item;
	list->current_size++;
}

int list_find(ArrayList *list, void *item)
{
	for (int i = 0; i < list->current_size; i++)
	{
		if (list_get(list, i) == item)
		{
			return i;
		}
	}

	return -1;
}


void *list_get(ArrayList *list, int id)
{
	return list->stuff[id];
}

void list_clear(ArrayList *list)
{

	for (int i = 0; i < list->current_size; i++)
	{
		free(list->stuff[i]);
	}

	list->current_size = 0;
	list->max_size = STEP;
	list->stuff = realloc(list->stuff, sizeof(void *) * list->max_size);

}


void list_delete_item()
{
//TODO: IMPLEMENT
}

void list_delete_id(ArrayList *list, int id)
{

	if (id >= list->current_size)
	{
		return;
	}

	free(list->stuff[id]);

	for (int i = id; i < list->current_size; i++)
	{
		list->stuff[i] = list->stuff[i + 1];
	}

	list->current_size--;

}