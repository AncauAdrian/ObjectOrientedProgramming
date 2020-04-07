#include "WeatherInfo.h"



WeatherInfo::WeatherInfo(int startTime, int endTime, double temperature, double prob, std::string desc)
{
	this->startTime = startTime;
	this->endTime = endTime;
	this->temperature = temperature;
	this->prob = prob;
	this->description = desc;
}

WeatherInfo::~WeatherInfo()
{
}

int WeatherInfo::getStartTime()
{
	return this->startTime;
}

int WeatherInfo::getEndTime()
{
	return this->endTime;
}

double WeatherInfo::getProbability()
{
	return this->prob;
}

std::string WeatherInfo::getDescription()
{
	return this->description;
}

std::string WeatherInfo::prettyprint()
{
	using namespace std;

	return "Start Time: " + to_string(this->startTime) + " -- End Time: " + to_string(this->endTime) 
		+ " -- Temperature: " + to_string(this->temperature) + " -- Probability: " + to_string(this->prob) 
		+ " -- Description: "+ description;
}
