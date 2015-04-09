#include <stdlib.h>
#include "ArrayList.h"

#define STEP 5

void basicRemover(void *item)
{
	free(item);
}

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


void list_clear_with_remover(ArrayList *list, void (*remover)(void *))
{

	for (int i = 0; i < list->current_size; i++)
	{
		remover(list->stuff[i]);
	}

	list->current_size = 0;
	list->max_size = STEP;
	list->stuff = realloc(list->stuff, sizeof(void *) * list->max_size);

}

void list_clear(ArrayList *list)
{
	list_clear_with_remover(list, basicRemover);
}

void list_delete_id_with_remover(ArrayList *list, int id, void (*remover)(void *))
{

	if (id >= list->current_size)
	{
		return;
	}

	remover(list->stuff[id]);

	for (int i = id; i < list->current_size; i++)
	{
		list->stuff[i] = list->stuff[i + 1];
	}

	list->current_size--;

}


void list_delete_id(ArrayList *list, int id)
{
	list_delete_id_with_remover(list, id, basicRemover);
}

