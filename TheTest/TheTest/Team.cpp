#include "Team.h"
#include <assert.h>


Team::Team()
{
	this->name = "None";
	this->country = "None";
	this->score = 0;
}

Team::Team(std::string name, std::string country, int score)
{
	this->name = name;
	this->country = country;
	this->score = score;
}

std::string Team::getName()
{
	return this->name;
}

std::string Team::getCountry()
{
	return this->country;
}

int Team::getScore()
{
	return this->score;
}

std::string Team::pettyPrint()
{
	return this->getName() + " | " + this->getCountry() + " | " + std::to_string(this->getScore()) + "\n";
}

void testTeam()
{
	std::string name = "TestName", country = "TestCountry";
	int score = 10;
	Team test(name, country, score);
	assert(name.compare(test.getName()) == 0);
	assert(country.compare(test.getCountry()) == 0);
	assert(score == test.getScore());


}
