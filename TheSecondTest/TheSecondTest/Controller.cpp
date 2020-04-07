#include "Controller.h"
#include "Building.h"

void Controller::addBuilding(Building * b)
{
	this->v.push_back(b);
}

std::vector<Building*> Controller::getAllBuildings()
{
	return this->v;
}

std::vector<Building*> Controller::getAllToBeRestored()
{
	std::vector<Building*> r;
	for (auto i : this->v)
		if (i->mustBeRestored())
			r.push_back(i);

	return r;
}

std::vector<Building*> Controller::getAllToBeDemolished()
{
	std::vector<Building*> r;
	for (auto i : this->v)
		if (i->canBeDemolished())
			r.push_back(i);

	return r;
}
