#include "Repository.h"
#include <assert.h>
#include <string.h>

void add_element(Array *arr, TElement e)
{
	arr->elems[arr->length] = e;
	arr->length++;
}

int find_element(Array *arr, TElement e)
{
	int i;
	for (i = 0; i < arr->length; i++)
	{
		if (compare(&e, &(arr->elems[i])))
			return i;
	}
	return -1;
}

int delete_element(Array *arr, TElement e)
{
	int i = find_element(arr, e);
	if (i == -1)
		return 0;

	int j;
	for (j = i; j < arr->length - 1; j++)
	{
		arr->elems[j] = arr->elems[j + 1];
	}
	arr->length--;

	return 1;
}

int modify_element(Array *arr, TElement olde, TElement newe)
{
	int i = find_element(arr, olde);
	if (i == -1)
		return 0;

	arr->elems[i] = newe;

	return 1;
}

void print_elems(Array *arr)
{
	int i;
	for (i = 0; i < arr->length; i++)
	{
		print_drug(arr->elems[i]);
	}
}

Array search_elements(Array *arr, char s[20])
{
	int i;
	Array a;
	a.length = 0;
	for (i = 0; i < arr->length; i++)
	{
		char *ptr;
		ptr = strstr(arr->elems[i].name, s);
		if (ptr != NULL)
			add_element(&a, arr->elems[i]);
	}

	return a;
}

void test_repo()
{
	Drug a = create_drug("Paracetamol", 100, 2, 15);
	Drug b = create_drug("Ibusinus", 150, 1, 10);
	Drug c = create_drug("Aspirin", 100, 2, 15);
	Array arr;
	arr.length = 0;
	add_element(&arr, a);
	add_element(&arr, b);
	add_element(&arr, c);
	
	assert(find_element(&arr, a) == 0);
	assert(find_element(&arr, b) == 1);
	assert(find_element(&arr, c) == 2);
	assert(arr.length == 3);

	assert(delete_element(&arr, c));
	assert(find_element(&arr, c) == -1);
	assert(arr.length == 2);

	c = create_drug("Paracetamol", 150, 5, 20);
	add_element(&arr, c);
	assert(find_element(&arr, a) != find_element(&arr, c));

	assert(modify_element(&arr, create_drug("te", 0, 0, 0), c) == 0);

	Drug d = create_drug("Nurofen", 1000, 9999, -1);
	assert(modify_element(&arr, c, d));
	assert(find_element(&arr, d));
}