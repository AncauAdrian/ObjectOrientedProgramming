#pragma once
#include "Team.h"
#include "DynamicVector.h"

class Repository
{
	DynamicVector<Team> v;
public:
	Repository();

	// Adds the team to the list of teams
	void add_team(Team t);

	int find_team(Team t);

	int getLength();

	std::string prettyprint();

	Team operator[](int pos) const;


};

void testRepository();