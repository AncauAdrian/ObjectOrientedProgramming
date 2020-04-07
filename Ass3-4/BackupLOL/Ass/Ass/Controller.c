#include "Controller.h"
#include "Repository.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int add_drug(Array *repo, Drug drug)
{
	if (drug.conc <= 0 || drug.price <= 0 || drug.quantity <= 0)
		return 0;

	if (repo == NULL)
		return 0;

	int i = find_element(repo, drug);
	if (i != -1)
	{
		drug.quantity = drug.quantity + repo->elems[i].quantity;
		return modify_element(repo, repo->elems[i], drug);
	}
	else
	{
		add_element(repo, drug);
		return 1;
	}
}

int remove_drug(Array *repo, Drug drug)
{
	if (drug.conc <= 0)
		return 0;

	if (repo == NULL)
		return 0;

	return delete_element(repo, drug);
}

int update_drug(Array *repo, Drug newdrug)
{
	if (newdrug.conc <= 0 || newdrug.price <= 0 || newdrug.quantity <= 0)
		return 0;

	if (repo == NULL)
		return 0;

	return modify_element(repo, newdrug, newdrug);
}

Array search_string(Array *repo, char s[20])
{
	Array a = search_elements(repo, s);
	int i, j;
	for(i = 0; i < a.length - 1; i++)
		for (j = i + 1; j < a.length; j++)
		{
			if (strcmp(a.elems[j].name, a.elems[i].name) < 0)
			{
				TElement cache = a.elems[j];
				a.elems[j] = a.elems[i];
				a.elems[i] = cache;
			}
		}

	return a;
}

Array search_string_c(Array *repo, char s[20])
{
	Array a = search_elements(repo, s);
	int i, j;
	for (i = 0; i < a.length - 1; i++)
		for (j = i + 1; j < a.length; j++)
		{
			if (a.elems[j].conc > a.elems[i].conc)
			{
				TElement cache = a.elems[j];
				a.elems[j] = a.elems[i];
				a.elems[i] = cache;
			}
		}

	return a;
}

Array print_sorted(Array *repo)
{
	Array a = *repo;
	int i, j;
	for (i = 0; i < a.length - 1; i++)
		for (j = i + 1; j < a.length; j++)
		{
			if (strcmp(a.elems[j].name, a.elems[i].name) < 0)
			{
				TElement cache = a.elems[j];
				a.elems[j] = a.elems[i];
				a.elems[i] = cache;
			}
		}

	return a;
}

void test_controller()
{
	Drug a = create_drug("Paracetamol", 40, 1, 10);
	Drug b = create_drug("Altul", 10, 3, 15);

	Array repo;
	repo.length = 0;
	assert(add_drug(&repo, a));
	assert(add_drug(&repo, b));
	assert(repo.length == 2);

	assert(remove_drug(&repo, b));
	assert(repo.length == 1);

	a = create_drug("Paracetamol", 40, 9999, 10);

	assert(update_drug(&repo, a));
	assert(repo.elems[0].quantity == 9999);
}