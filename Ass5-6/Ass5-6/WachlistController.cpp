#include "WachlistController.h"
#include "Repository.h"
#include "Tutorial.h"
#include "ControllerException.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <assert.h>


WachlistController::WachlistController(Repository & r, Repository & wr) : repo(r), Wrepo(wr)
{

}

void WachlistController::process_input(std::vector<std::string>& args)
{
	if (args.size() == 0)
		throw ControllerException("[ERROR] No command enterred!");

	if (args[0].compare("start") == 0 && args.size() == 1)
	{
		try
		{
			if (repo.isEmpty())
				throw ControllerException("[ERROR] The list of Tutorials is empty!");
			this->temp = this->repo;

			start_iterating(this->temp);
		}
		catch (ControllerException & e)
		{
			throw e;
		}
	}
	else if (args[0].compare("start") == 0 && args.size() == 2)
	{
		try
		{
			if (repo.isEmpty())
				throw ControllerException("[ERROR] The list of Tutorials is empty!");

			this->temp = this->repo.search_a(args[1]);

			start_iterating(this->temp);
		}
		catch (ControllerException & e)
		{
			throw e;
		}
	}
	else if (args[0].compare("delete") == 0 && args.size() == 2)
	{
		try
		{
			int index = std::stoi(args[1]);
			if (index < 0)
				throw ControllerException("[ERROR] Index cannot be negative!");

			if (index >= this->Wrepo.getLength())
				throw ControllerException("[ERROR] Index is out of bounds");

			this->remove(index);
		}
		catch (ControllerException & e)
		{
			throw e;
		}
	}
	else throw ControllerException("[ERROR] Invalid command enterred!");
}

void WachlistController::start_iterating(Repository & repo)
{
	int i = 0;
	while (true)
	{
		std::cout << repo[i].prettyfy() << std::endl;

		std::string cmd = "start chrome " + repo[i].getLink();
		//system(cmd.c_str());

		std::string s;
		std::cout << "usermode@iteration >>";
		std::getline(std::cin, s);

		try
		{
			if (!s.compare("exit"))
				break;
			else if (!s.compare("add"))
			{
				try
				{
					this->add_watchlist(repo[i++]);
					std::cout << "Tutorial added!\n";
				}
				catch (ControllerException & e)
				{
					throw e;
				}
			}
			else if (!s.compare("next"))
				i++;
			else throw ControllerException("[ERROR] Invalid command enterred!");

			if (i == repo.getLength())
				i = 0;
		}
		catch (ControllerException & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

void WachlistController::add_watchlist(Tutorial t)
{
	int i = this->Wrepo.find(t);

	if (i != -1)
		throw ControllerException("[ERROR] Tutorial is already added!");

	this->Wrepo.add_tutorial(t);
}

void WachlistController::remove(int index)
{
	if (index < 0)
		throw "";

	if (index >= this->Wrepo.getLength())
		throw "";

	this->Wrepo.remove_tutorial(index);
}

void testWatchlistController()
{
	Repository repo, Wrepo;
	Tutorial t1{ "TEst1", "Me1", 101, 61, "www1" };
	Tutorial t2{ "TEst2", "Me2", 102, 62, "www2" };
	Tutorial t3{ "TEst3", "Me3", 103, 63, "www3" };
	Tutorial t4{ "TEst4", "Me4", 104, 64, "www4" };

	repo.add_tutorial(t1);
	repo.add_tutorial(t2);
	repo.add_tutorial(t3);
	repo.add_tutorial(t4);
	WachlistController cont(repo, Wrepo);

	std::vector<std::string> cmd;
	
	try
	{
		cont.process_input(cmd);
	}
	catch (...)
	{
		assert(true);
	}

	cont.add_watchlist(t1);
	try
	{
		cont.add_watchlist(t1);
	}
	catch (...)
	{
		assert(true);
	}
	cont.remove(0);

	try
	{
		cont.remove(0);
	}
	catch (...)
	{
		assert(true);
	}
}
