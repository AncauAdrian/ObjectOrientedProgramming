#pragma once
#include "Repository.h"
#include <string>
#include <vector>

class WachlistController
{
	Repository temp;
	Repository & repo;
	Repository & Wrepo;
public:
	WachlistController(Repository & r, Repository & wr);
	void process_input(std::vector<std::string>& args);
	void start_iterating(Repository & repo);
	void add_watchlist(Tutorial t);
	void remove(int index);

};

void testWatchlistController();
