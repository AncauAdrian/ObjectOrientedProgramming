#include "Comparator.h"

bool ComparatorAscendingByTitle::compare(const Tutorial& a, const Tutorial& b) const
{
	if (a.getTitle().compare(b.getTitle()) <= 0)
		return true;

	return false;
}

bool ComparatorAscendingByAuthor::compare(const Tutorial& a, const Tutorial& b) const
{
	if (a.getAuthor().compare(b.getAuthor()) <= 0)
		return true;

	return false;
}
