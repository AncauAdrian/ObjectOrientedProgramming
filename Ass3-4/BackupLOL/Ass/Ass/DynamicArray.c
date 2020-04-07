#include "DynamicArray.h"
#include "Drug.h">
#include <stdlib.h>
#include <assert.h>
#include <crtdbg.h>

DynamicArray* create_Dynamic_Array(int capacity)
{
	DynamicArray *d = (DynamicArray*)malloc(sizeof(DynamicArray) * capacity);

	if (d == NULL)
		return NULL;

	d->length = 0;
	d->capacity = capacity;

	d->elems = (TElement*)malloc(sizeof(TElement) * capacity);

	if (d->elems == NULL)
		return NULL;

	return d;
}

void destroy_Dynamic_Array(DynamicArray *d)
{
	if (d == NULL)
		return;

	free(d->elems);
	d->elems = NULL;

	free(d);
	d = NULL;
}

void resize_Dynamic_Array(DynamicArray *d)
{
	if (d == NULL)
		return;

	d->capacity *= 2;
	TElement* aux = (TElement*)realloc(d->elems, d->capacity * sizeof(TElement));

	if (aux == NULL)
		return;

	d->elems = aux;
}

void d_add(DynamicArray *d, TElement e)
{
	if (d == NULL)
		return;

	if (d->elems == NULL)
		return;

	if (d->length == d->capacity)
		resize_Dynamic_Array(d);

	d->elems[d->length] = e;
	d->length++;
}

int d_find(DynamicArray *d, TElement e, int(*comp)(TElement *a, TElement *b))
{
	if (d == NULL)
		return;

	if (d->elems == NULL)
		return;

	int i = 0;
	for (i; i < d->length; i++)
		if (comp(&(d->elems[i]), &e) == 1)
			return i;

	return -1;
}

int d_remove(DynamicArray *d, TElement e, int(*comp)(TElement *a, TElement *b))
{
	if (d == NULL)
		return 0;

	if (d->elems == NULL)
		return 0;

	int index = d_find(d, e, comp);

	if (index == -1)
		return 0;

	for (index; index < d->length - 1; index++)
		d->elems[index] = d->elems[index + 1];

	d->length--;

	return 1;
}

void d_print(DynamicArray *arr, void (*_print)(TElement e))
{
	if (arr == NULL)
		return;

	if (arr->elems == NULL)
		return;

	int i;
	for (i = 0; i < arr->length; i++)
		_print(arr->elems[i]);
}

int d_update(DynamicArray *arr, TElement e, int(*comp)(TElement *a, TElement *b))
{
	if (arr == NULL)
		return 0;

	if (arr->elems == NULL)
		return 0;

	int i = d_find(arr, e, comp);
	if (i == -1)
		return 0;

	arr->elems[i] = e;

	return 1;
}


void test_darray()
{
	DynamicArray *test = create_Dynamic_Array(10);
	assert(test != NULL);

	Drug a = create_drug("Test", 1, 10, 15);
	Drug b = create_drug("Ibusinus", 5, 10, 15);
	Drug c = create_drug("Ibusinus", 3, 10, 15);
	d_add(test, a);
	assert(d_find(test, a, compare) == 0);
	assert(test->length == 1);
	d_remove(test, a, compare);

	assert(d_find(test, a, compare) == -1);
	assert(test->length == 0);

	d_add(test, a);
	d_add(test, b);
	d_add(test, c);

	d_print(test, print_drug);

	d_remove(test, c, compare);
	assert(d_find(test, b, compare) == 1);
	assert(d_find(test, c, compare) == -1);

	destroy_Dynamic_Array(test);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
}