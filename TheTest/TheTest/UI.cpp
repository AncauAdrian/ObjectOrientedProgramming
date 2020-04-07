#include "UI.h"
#include "Repository.h"
#include "Controller.h"
#include <iostream>


void UI::initialise(Repository & repo)
{
	repo.add_team(Team("Larvik", "Norway", 0));
	repo.add_team(Team("CSM Bucuresti", "Romania", 0));
	repo.add_team(Team("Buducnost", "Montenegro", 0));
	repo.add_team(Team("Rostov-Don", "Russia", 0));
	repo.add_team(Team("FTC-Rail Cargo Hungaria", "Hungary", 0));
}

void UI::showmenu()
{
	std::cout << "add <name> <country> <score>" << std::endl;
	std::cout << "list" << std::endl;
	std::cout << "pair" << std::endl;
	std::cout << "help" << std::endl;
	std::cout << "exit" << std::endl;

}

void UI::start()
{
	Repository repo;
	Controller cont(repo);

	UI::initialise(repo);


	while (true)
	{
		DynamicVector<std::string> arg;

		std::string s;
		std::cout << ">>";
		std::getline(std::cin, s);

		std::string delimiter = " ";
		size_t pos = 0;
		std::string token;
		while ((pos = s.find(delimiter)) != std::string::npos)
		{
			token = s.substr(0, pos);
			arg.add(token);
			s.erase(0, pos + delimiter.length());
		}
		token = s.substr(0, pos);
		arg.add(token);

		if (arg[0].compare("add") == 0)
		{
			arg.remove_first();
			try
			{
				cont.add(arg);
			}
			catch (...)
			{
				std::cout << "ERROR, cannot add the Team" << std::endl;
			}
		}
		else if (arg[0].compare("list") == 0)
		{
			std::cout << repo.prettyprint() << std::endl;
		}
		else if (arg[0].compare("exit") == 0)
		{
			break;
		}
	}
}
