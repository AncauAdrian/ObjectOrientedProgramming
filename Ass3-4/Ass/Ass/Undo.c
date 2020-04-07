#include "Undo.h"
#include <stdlib.h>
#include <assert.h>
#include <crtdbg.h>

UndoArray* create_Undo_Array(int capacity)
{
	UndoArray *d = (UndoArray*)malloc(sizeof(UndoArray) * capacity);

	if (d == NULL)
		return NULL;

	d->length = 0;
	d->cur_index = -1;
	d->capacity = capacity;

	d->elems = (RElement*)malloc(sizeof(RElement) * capacity);

	if (d->elems == NULL)
		return NULL;

	return d;
}

void destroy_Undo_Array(UndoArray *d)
{
	if (d == NULL)
		return;

	int i = 0;
	for (i; i < d->length; i++)
		destroy_Dynamic_Array(d->elems[i]);

	free(d->elems);
	d->elems = NULL;

	free(d);
	d = NULL;
}

void resize_Undo_Array(UndoArray *d)
{
	if (d == NULL)
		return;

	d->capacity *= 2;
	RElement* aux = (RElement*)realloc(d->elems, d->capacity * sizeof(RElement));

	if (aux == NULL)
		return;

	d->elems = aux;
}

void r_add(UndoArray *d, RElement e)
{
	if (d == NULL)
		return;

	if (d->elems == NULL)
		return;

	if (d->length == d->capacity)
		resize_Undo_Array(d);

	RElement a = create_Dynamic_Array(64);
	hard_copy(a, e);

	d->elems[d->length] = a;
	d->length++;
	d->cur_index = d->length - 1;
}

void r_remove(UndoArray *d)
{
	if (d == NULL)
		return;

	if (d->elems == NULL)
		return;

	int i = d->cur_index + 1;
	for (i; i < d->length; i++)
		destroy_Dynamic_Array(d->elems[i]);
	
	d->length = d->cur_index + 1;
}

void test_redo()
{
	UndoArray *u = create_Undo_Array(64);
	DynamicArray *d = create_Dynamic_Array(64);

	d_add(d, create_drug("Test", 1, 1, 1));
	r_add(u, d);

	assert(u->elems[0]->elems[0].quantity = 1);

	d_add(d, create_drug("Test2", 22, 22, 22));
	r_add(u, d);

	assert(strcmp(u->elems[0]->elems[0].name, "Test2") == 0);
	assert(u->length == 2);
	assert(u->cur_index == 1);

	u->cur_index--;
	hard_copy(d, u->elems[u->cur_index]);

	d_add(d, create_drug("Test3", 3, 33, 33));
	r_remove(u);
	r_add(u, d);


	destroy_Dynamic_Array(d);
	destroy_Undo_Array(u);

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
}