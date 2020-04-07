#include "Repository.h"
#include <assert.h>
#include <iostream>

Repository::Repository()
{
}

void Repository::add_team(Team t)
{
	this->v.add(t);
}

int Repository::find_team(Team t)
{
	for (int i = 0; i < this->v.getSize(); i++)
		if (this->v[i].getName().compare(t.getName()) == 0)
			return i;

	return -1;
}

int Repository::getLength()
{
	return this->v.getSize();
}

std::string Repository::prettyprint()
{
	std::string a;
	for (int i = 0; i < this->getLength(); i++)
	{
		a += this->v[i].pettyPrint();
		//std::cout << this->v[i].pettyPrint();
	}
	return a;
}

Team Repository::operator[](int pos) const
{
	return this->v[pos];
}

void testRepository()
{
	Team a1("Name1", "Country1", 100);
	Team a2("Name2", "Country2", 100);
	Team a3("Name2", "Country2", 100);

	Repository repo;
	assert(repo.getLength() == 0);
	repo.add_team(a1);
	assert(repo.getLength() == 1);
	repo.add_team(a2);
	assert(repo.getLength() == 2);

	assert(repo.find_team(a1) == 0);
	assert(repo.find_team(a2) == 1);
	assert(repo.find_team(Team("Aaa", "A", 1)) == -1);
}
