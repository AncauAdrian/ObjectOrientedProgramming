#include "Drug.h"
#include <assert.h>
#include <string.h>

void tests()
{
	Drug a = create_drug("test", 10, 1, 150);
	assert(strcmp(a.name, "test") == 0);
	assert(a.conc == 10);
	assert(a.quantity == 1);
	assert(a.price == 150);
}