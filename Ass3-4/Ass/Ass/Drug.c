#include "Drug.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

Drug create_drug(char *name, int conc, int quantity, int price)
{
	Drug a;
	strcpy_s(a.name, sizeof(a.name), name);
	a.conc = conc;
	a.quantity = quantity;
	a.price = price;

	return a;
}

void print_drug(Drug drug)
{
	printf("Name: %s  Concentration: %d  Quantity: %d  Price: %d\n", drug.name, drug.conc, drug.quantity, drug.price);
}

int compare(Drug *a, Drug *b)
{
	if (strcmp(a->name, b->name) == 0 && a->conc == b->conc)
		return 1;
	return 0;
}

void test_drug()
{
	Drug a = create_drug("test", 10, 1, 150);
	Drug b = create_drug("test", 10, 1, 150);
	Drug c = create_drug("test", 16, 1, 150);
	Drug d = create_drug("lol", 10, 1, 150);
	assert(strcmp(a.name, "test") == 0);
	assert(a.conc == 10);
	assert(a.quantity == 1);
	assert(a.price == 150);
	assert(compare(&a, &b));
	assert(compare(&a, &c) == 0);
	assert(compare(&a, &d) == 0);
}