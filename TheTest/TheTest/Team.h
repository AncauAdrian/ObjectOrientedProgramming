#pragma once
#include <string>


class Team
{
	std::string name;
	std::string country;
	int score = 0;
public:
	Team();

	Team(std::string name, std::string country, int score);

	std::string getName();

	std::string getCountry();
	
	int getScore();

	std::string pettyPrint();
};

void testTeam();