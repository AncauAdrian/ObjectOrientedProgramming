#pragma once
#include "Repository.h"
#include "Comparator.h"
#include <vector>

class Controller
{
	Repository& repo;
public:
	Controller(Repository& r);

	void process_input(std::vector<std::string>& args);

	void add(std::string title, std::string author, int likes, int minutes, int seconds, std::string link);

	void update(std::string title, std::string author, int likes, int minutes, int seconds, std::string link);

	void remove(std::string title, std::string author);

	Repository& getRepo();
};

std::string sort(std::vector<Tutorial> v, Comparator<Tutorial>& c);

void testController();