#pragma once
#include "Repository.h"
#include <vector>

class Controller
{
	Repository& repo;
public:
	Controller(Repository& repo);
	std::vector<WeatherInfo> filter(double prob);

	// Takes a given description and calculates the total number of hours that have that description
	int compute(std::string desc);
};

void testCompute();

