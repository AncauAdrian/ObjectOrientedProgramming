#include "Controller.h"
#include <assert.h>



Controller::Controller(Repository & r) : repo(r)
{

}

void Controller::add(DynamicVector<std::string> args)
{
	if (args.getSize() != 3)
		throw "";

	std::string name = args[0], country = args[1];
	int score;
	try
	{
		score = std::stoi(args[2]);
	}
	catch (...)
	{
		throw "";
	}

	Team t(name, country, score);

	if (repo.find_team(t) != -1)
		throw "";

	this->repo.add_team(t);

}

void testController()
{
	Repository repo;
	Controller cont(repo);

	assert(repo.getLength() == 0);

	DynamicVector<std::string> args;
	args.add("Name1");
	args.add("Country1");
	args.add("100");
	cont.add(args);

	assert(repo.getLength() == 1);

	args = DynamicVector<std::string>();

	args.add("Name2");
	args.add("Country2");
	args.add("100");
	cont.add(args);

	assert(repo.getLength() == 2);

	args.add("Name2");
	args.add("Country2");
	args.add("100");
	try
	{
		cont.add(args);
		assert(false);
	}
	catch (...)
	{
		assert(true);
		assert(repo.getLength() == 2);
	}
}
