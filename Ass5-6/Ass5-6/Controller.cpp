#include "Controller.h"
#include "ControllerException.h"
#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
#include <sstream>

Controller::Controller(Repository & r) : repo(r)
{
}

void Controller::process_input(std::vector<std::string>& args)
{
	if (args.empty())
		throw ControllerException("[ERROR] Arguments list empty!");

	if (args[0].compare("add") == 0 && args.size() == 6)
	{
		try
		{
			int likes, minutes, seconds;
			likes = std::stoi(args[4]);
			int index = args[3].find(':');
			if (index == std::string::npos)
				throw ControllerException("[ERROR] Duration should be of format MM:SS");

			minutes = std::stoi(args[3].substr(0, index));
			seconds = std::stoi(args[3].substr(index + 1, args[3].length()));

			if (likes < 0 || minutes < 0 || seconds < 0)
				throw ControllerException("[ERROR] Duration and Seconds may not be negative");

			
			this->add(args[1], args[2], likes, minutes, seconds, args[5]);
		}
		catch (ControllerException& e)
		{
			throw e;
		}
	}
	else if (args[0].compare("update") == 0 && args.size() == 6)
	{
		try
		{
			int likes, minutes, seconds;
			likes = std::stoi(args[4]);
			int index = args[3].find(':');
			if (index == std::string::npos)
				throw ControllerException("[ERROR] Duration should be of format MM:SS");

			minutes = std::stoi(args[3].substr(0, index));
			seconds = std::stoi(args[3].substr(index + 1, args[3].length()));

			if (likes < 0 || minutes < 0 || seconds < 0)
				throw ControllerException("[ERROR] Duration and Seconds may not be negative");

			this->update(args[1], args[2], likes, minutes, seconds, args[5]);
		}
		catch (ControllerException & e)
		{
			throw e;
		}
	}
	else if (args[0].compare("remove") == 0 && args.size() == 3)
	{
		try
		{
			this->remove(args[1], args[2]);
		}
		catch (ControllerException & e)
		{
			throw e;
		}
	}
	else throw ControllerException("[ERROR] Invalid command enterred or invalid number of arguments!");
}

void Controller::add(std::string title, std::string author, int likes, int minutes, int seconds, std::string link)
{
	Tutorial t(title, author, likes, minutes * 60 + seconds, link);

	int i = this->repo.find(t);

	if (i != -1)
		throw ControllerException("[ERROR] Tutorial already exists in the list!");

	this->repo.add_tutorial(t);
}

void Controller::update(std::string title, std::string author, int likes, int minutes, int seconds, std::string link)
{
	Tutorial t(title, author, likes, minutes * 60 + seconds, link);

	int i = this->repo.find(t);

	if (i == -1)
		throw ControllerException("[ERROR] Tutorial doesn't exist!");

	this->repo.update_tutorial(t);
}

void Controller::remove(std::string title, std::string author)
{
	Tutorial t(title, author, 0, 0, "");

	int i = this->repo.find(t);

	if (i == -1)
		throw ControllerException("[ERROR] Tutorial doesn't exist!");

	this->repo.remove_tutorial(t);
}

Repository & Controller::getRepo()
{
	return this->repo;
}


std::string sort(std::vector<Tutorial> v, Comparator<Tutorial> & c)
{
	Tutorial temp;
	for (auto i = v.begin(); i != v.end(); i++)
	{
		for (auto j = i + 1; j != v.end(); j++)
		{
			if (!c.compare(*i, *j))
			{
				temp = *i;
				*i = *j;
				*j = temp;
			}
		}
	}
	
	std::string s;

	for (auto a : v)
		s += a.prettyfy() + "\n";

	return s;
}

void testController()
{
	using namespace std;
	Repository repo;
	Controller cont(repo);


	cont.add("TestT", "TestA", 100, 60, 23, "www");
	cont.add("TestT1", "TestA1", 101, 60, 24, "www1");
	cont.add("TestT2", "TestA2", 101, 60, 25, "www2");
	cont.add("TestT3", "TestA3", 101, 60, 26, "www3");

	cont.remove("TestT3", "TestA3");
	try
	{
		cont.remove("Test3", "TestA3");
	}
	catch (...)
	{
		assert(true);
	}

	vector<std::string> cmd;
	try
	{
		cont.process_input(cmd);
	}
	catch (...)
	{
		assert(true);
	}

	cmd.push_back(std::string("add"));
	cmd.push_back(std::string("Test"));
	cmd.push_back(std::string("Test"));
	cmd.push_back(std::string("10:15"));
	cmd.push_back(std::string("222"));
	try
	{
		cont.process_input(cmd);
	}
	catch (...)
	{
		assert(true);
	}

	cmd.push_back(std::string("www"));
	cont.process_input(cmd);

	cmd.clear();

	cmd.push_back(std::string("update"));
	cmd.push_back(std::string("Test"));
	cmd.push_back(std::string("Test"));
	cmd.push_back(std::string("10:5"));
	cmd.push_back(std::string("1111"));
	cmd.push_back(std::string("wwww"));
	cont.process_input(cmd);

	cmd.clear();

	cmd.push_back(std::string("remove"));

	cont.getRepo();
	try
	{
		cont.process_input(cmd);
	}
	catch (...)
	{
		assert(true);
	}
	cmd.push_back(std::string("Test"));
	try
	{
		cont.process_input(cmd);
	}
	catch (...)
	{
		assert(true);
	}
	cmd.push_back(std::string("Test"));
	cont.process_input(cmd);

	try {
		cont.add("TestT", "TestA", 100, 60, 23, "www");
	}
	catch (...)
	{
		assert(true);
	}
	
}
