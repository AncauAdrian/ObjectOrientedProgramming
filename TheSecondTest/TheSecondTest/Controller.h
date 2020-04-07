#pragma once
#include "Building.h"
#include <vector>

class Controller
{
	std::vector<Building*> &v;
public:
	Controller(std::vector<Building*> &repo) : v(repo) {};
	void addBuilding(Building* b);
	std::vector<Building*> getAllBuildings();
	std::vector<Building*> getAllToBeRestored();
	std::vector<Building*> getAllToBeDemolished();
	void writeToFile(std::string filename, std::vector<Building> r, std::vector<Building> d);
};

