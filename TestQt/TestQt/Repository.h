#pragma once
#include "WeatherInfo.h"
#include <vector>

class Repository
{
	std::vector<WeatherInfo> v;
public:
	Repository();
	~Repository();

	void add(int start, int end, double temp, double prob, std::string desc);
	void file_load();
	std::vector<WeatherInfo>& getVector();
};

std::vector<std::string> tokenize(std::string str, char delimiter);
