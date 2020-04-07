#pragma once

#include <string>

class WeatherInfo
{
	int startTime, endTime;
	double temperature, prob;
	std::string description;

public:
	WeatherInfo(int startTime, int endTime, double temperature, double prob, std::string desc);
	~WeatherInfo();

	int getStartTime();
	int getEndTime();
	double getProbability();
	std::string getDescription();
	std::string prettyprint();
};

