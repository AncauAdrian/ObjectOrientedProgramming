#pragma once
#include "Repository.h"
#include "DynamicVector.h"

class Controller
{
	Repository & repo;
public:
	Controller(Repository & r);

	// Takes the vector of arguments and converts them into a team, after which it adds that team to the list
	void add(DynamicVector<std::string> args);
};

void testController();

