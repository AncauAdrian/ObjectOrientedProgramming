#include "Controller.h"
//#include "Repository.h"
#include "DynamicArray.h"
#include "Undo.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void _undo_update(UndoArray *undo, DynamicArray *repo)
{
	r_remove(undo);
	r_add(undo, repo);
}

int _undo(UndoArray *undo, DynamicArray *repo)
{
	if (undo->cur_index == 0)
		return 0;

	undo->cur_index--;
	hard_copy(repo, undo->elems[undo->cur_index]);
	//d_print(undo->elems[undo->cur_index], print_drug);
	return 1;
}

int _redo(UndoArray *undo, DynamicArray *repo)
{
	if (undo->cur_index == undo->length - 1)
		return 0;

	undo->cur_index++;
	hard_copy(repo, undo->elems[undo->cur_index]);
	return 1;
}

int add_drug(DynamicArray *repo, Drug drug)
{
	if (drug.conc <= 0 || drug.price <= 0 || drug.quantity <= 0)
		return 0;

	if (repo == NULL)
		return 0;

	int i = d_find(repo, drug, compare);
	if (i != -1)
	{
		drug.quantity = drug.quantity + repo->elems[i].quantity;
		return d_update(repo, drug, compare);
	}
	else
	{
		d_add(repo, drug);
		return 1;
	}
}

int remove_drug(DynamicArray *repo, Drug drug)
{
	if (drug.conc <= 0)
		return 0;

	if (repo == NULL)
		return 0;

	return d_remove(repo, drug, compare);
}

int update_drug(DynamicArray *repo, Drug newdrug)
{
	if (newdrug.conc <= 0 || newdrug.price <= 0 || newdrug.quantity <= 0)
		return 0;

	if (repo == NULL)
		return 0;

	return d_update(repo, newdrug, compare);
}

void search(DynamicArray *arr, DynamicArray *res, char s[20])
{
	int i;
	res->length = 0;
	for (i = 0; i < arr->length; i++)
	{
		char *ptr;
		ptr = strstr(arr->elems[i].name, s);
		if (ptr != NULL)
			d_add(res, arr->elems[i]);
	}
}

void search_string(DynamicArray *repo, DynamicArray *res, char s[20])
{
	search(repo, res, s);
	int i, j;
	for (i = 0; i < res->length - 1; i++)
		for (j = i + 1; j < res->length; j++)
		{
			if (strcmp(res->elems[j].name, res->elems[i].name) < 0)
			{
				Drug cache = res->elems[j];
				res->elems[j] = res->elems[i];
				res->elems[i] = cache;
			}
		}
}

void search_string_c(DynamicArray *repo, DynamicArray *res, char s[20])
{
	search(repo, res, s);
	int i, j;
	for (i = 0; i < res->length - 1; i++)
		for (j = i + 1; j < res->length; j++)
		{
			if (res->elems[j].conc > res->elems[i].conc)
			{
				Drug cache = res->elems[j];
				res->elems[j] = res->elems[i];
				res->elems[i] = cache;
			}
		}
}

void print_sorted(DynamicArray *repo, DynamicArray *res)
{
	hard_copy(res, repo);
	int i, j;
	for (i = 0; i < res->length - 1; i++)
		for (j = i + 1; j < res->length; j++)
		{
			if (strcmp(res->elems[j].name, res->elems[i].name) < 0)
			{
				Drug cache = res->elems[j];
				res->elems[j] = res->elems[i];
				res->elems[i] = cache;
			}
		}
}

void short_supply(DynamicArray *repo, DynamicArray *res, int quantity)
{
	res->length = 0;
	int i = 0;
	for (i; i < repo->length; i++)
		if (repo->elems[i].quantity <= quantity)
			d_add(res, repo->elems[i]);
}

void test_controller()
{
	Drug a = create_drug("Paracetamol", 40, 1, 10);
	Drug b = create_drug("Altul", 10, 3, 15);

	DynamicArray *repo = create_Dynamic_Array(50);
	repo->length = 0;
	assert(add_drug(repo, a));
	assert(add_drug(repo, b));
	assert(repo->length == 2);

	assert(remove_drug(repo, b));
	assert(repo->length == 1);

	a = create_drug("Paracetamol", 40, 9999, 10);

	assert(update_drug(repo, a));
	assert(repo->elems[0].quantity == 9999);

	destroy_Dynamic_Array(repo);
}