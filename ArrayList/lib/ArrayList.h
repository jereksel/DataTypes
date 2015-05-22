#ifndef ARRAY_LIST_H_INCLUDED
#define ARRAY_LIST_H_INCLUDED


typedef struct arraylist ArrayList;

typedef struct arraylist
{
	int current_size;
	int max_size;
	void **stuff;  //Array of stuff
} ARRAYLIST;

ArrayList *array_list_create();

void array_list_add(ArrayList *list, void *item);

void *array_list_get(ArrayList *list, int id);

int array_list_find(ArrayList *list, void *item);

void array_list_clear(ArrayList *list);

void array_list_clear_with_remover(ArrayList *list, void (*remover)(void *));

void array_list_delete_id(ArrayList *list, int id);

void array_list_delete_id_with_remover(ArrayList *list, int id, void (*remover)(void *));


#endif
