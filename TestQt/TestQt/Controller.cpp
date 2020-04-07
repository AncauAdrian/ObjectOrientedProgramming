#include "Controller.h"
#include <assert.h>


Controller::Controller(Repository& repo) :repo(repo)
{
}

std::vector<WeatherInfo> Controller::filter(double prob)
{
	std::vector<WeatherInfo> v;

	for (auto a : this->repo.getVector())
	{
		if (a.getProbability() < prob)
			v.push_back(a);
	}

	return v;
}

int Controller::compute(std::string desc)
{
	int n = 0;

	for (auto a : this->repo.getVector())
	{
		if (a.getDescription().compare(desc) == 0)
		{
			n += a.getEndTime() - a.getStartTime();
		}
	}

	return n;
}

void testCompute()
{
	Repository repo;
	Controller cont(repo);

	repo.add(5, 7, 1, 1, "test");
	repo.add(7, 9, 1, 1, "test");
	repo.add(5, 7, 1, 1, "not");
	repo.add(5, 7, 1, 1, "not");
	repo.add(19, 23, 1, 1, "test");

	assert(cont.compute("test") == 8);

}
