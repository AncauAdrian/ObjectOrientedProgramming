#include <string>
#include <iostream>
#include <sstream>
#include "Building.h"
#include "Controller.h"


void showmenu()
{
	using namespace std;

	cout << "1. Add Building" << endl;
	cout << "2. Show All Buildings" << endl;
	cout << "3. Show All Buildings that must be restored" << endl;
	cout << "4. Save to File" << endl;
}


int main()
{
	std::cout << "BUILDING MANAGEMENT" << std::endl;
	showmenu();

	std::vector<Building*> repo;
	Controller cont(repo);
	std::string read;
	int option;
	while (true)
	{
		std::getline(std::cin, read);
		
		try
		{
			option = std::stoi(read);
		}
		catch (...)
		{
			std::cout << "Enter a number please!" << std::endl;
			continue;
		}

		if (option == 1)
		{
			std::cout << "Address: ";
			std::getline(std::cin, read);
			std::string addr = read;

			std::cout << "Construction Year: ";
			std::getline(std::cin, read);

			int year;

			try
			{
				year = std::stoi(read);
			}
			catch (...)
			{
				std::cout << "Enter a number please!" << std::endl;
				continue;
			}

			std::cout << "Enter B for block and H for house:";
			std::getline(std::cin, read);

			if (read.compare("b") == 0)
			{
				std::cout << "Total Apartments: ";
				std::getline(std::cin, read);
				int totalAp;

				try
				{
					totalAp = std::stoi(read);
				}
				catch (...)
				{
					std::cout << "Enter a number please!" << std::endl;
					continue;
				}

				std::cout << "Occupied Apartments: ";
				std::getline(std::cin, read);
				int ocAp;

				try
				{
					ocAp = std::stoi(read);
				}
				catch (...)
				{
					std::cout << "Enter a number please!" << std::endl;
					continue;
				}

				Block bl(addr, year, totalAp, ocAp);
				Building &b = bl;
				cont.addBuilding(&b);
			}
			else if (read.compare("h") == 0)
			{
				std::cout << "Type: ";
				std::getline(std::cin, read);
				std::string type = read;

				std::cout << "Is Historical? y for yes anything else for no ";
				std::getline(std::cin, read);

				bool isHist = false;

				if (read.compare("y"))
					isHist = true;

				House ho(addr, year, type, isHist);
				Building &b = ho;
				cont.addBuilding(&b);
			}
			else
			{
				std::cout << "Invalid! \n";
				continue;
			}

		}
		else if (option == 2)
		{

		}
	}

	return 0;
}