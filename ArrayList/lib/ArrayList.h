#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED


typedef struct arraylist ArrayList;

typedef struct arraylist
{
	int current_size;
	int max_size;
	void **stuff;  //Array of stuff
} LIST;

ArrayList *list_create();
void list_add(ArrayList *list, void* item);
void* list_get(ArrayList *list, int id);
int list_find(ArrayList *list, void* item);
void list_clear(ArrayList *list);
void list_delete_id(ArrayList *list, int id);

#endif
