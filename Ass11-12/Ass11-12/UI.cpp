#define CSV_REPO_FILE "list.txt"
#define CSV_WREPO_FILE "wlist.txt"

#define HTML_REPO_FILE "list.html"
#define HTML_WREPO_FILE "wlist.html"

#include "Tutorial.h"
#include "Repository.h"
#include "Controller.h"
#include "WachlistController.h"
#include "UI.h"
#include "ControllerException.h"
#include <string>
#include <iostream>
#include <exception>
#include "Ass1112.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qlineedit.h>


void UI::showmenu_admin()
{
	std::cout << "\n\n>>>> ADMINISTRATOR MODE <<<<" << std::endl;
	std::cout << "add <title> <author> <duration(mm:ss)> <likes> <link>" << std::endl;
	std::cout << "update <title> <author> <duration(mm:ss)> <likes> <link>" << std::endl;
	std::cout << "remove <title> <author>" << std::endl;
	std::cout << "list" << std::endl;
	std::cout << "usermode" << std::endl;
	std::cout << "display" << std::endl;
	std::cout << "exit" << std::endl;
}

void UI::showmenu_user()
{
	std::cout << "\n\n>>>>>>>>> USER MODE <<<<<<<<" << std::endl;
	std::cout << "list -- list the entire watchlist" << std::endl;
	std::cout << "start <author=""> -- iterate over the tutorials that have the specified author" << std::endl;
	std::cout << "add -- while iterating, add the current tutorial to the watchlist" << std::endl;
	std::cout << "next -- while iterating, skip to the next tutorial" << std::endl;
	std::cout << "delete <index>" << std::endl;
	std::cout << "display" << std::endl;
	std::cout << "exit -- if iterating exit to usermode, if in usermode exit to admin mode" << std::endl;
}

void UI::initialise(Controller& cont)
{
	cont.add("Types", "Adrian", 11, 12, 7, "https://www.youtube.com/watch?v=dUUap90oiPA");
	cont.add("Functions", "Dan", 151, 22, 5, "https://www.youtube.com/watch?v=dUUap90oiPA");
	cont.add("Classes", "Adrian", 51, 3, 11, "https://www.youtube.com/watch?v=dUUap90oiPA");
	cont.add("Templates", "Adrian", 111, 13, 27, "https://www.youtube.com/watch?v=dUUap90oiPA");
	cont.add("Pointers", "Dan", 121, 5, 35, "https://www.youtube.com/watch?v=dUUap90oiPA");
	cont.add("Libraries", "Dan", 12, 12, 59, "https://www.youtube.com/watch?v=dUUap90oiPA");
	cont.add("GeneralKnowledge", "Adrian", 205, 18, 33, "https://www.youtube.com/watch?v=dUUap90oiPA");
	cont.add("Miscellanious", "Alex", 113, 25, 25, "https://www.youtube.com/watch?v=dUUap90oiPA");
	cont.add("Includes", "Alex", 341, 11, 53, "https://www.youtube.com/watch?v=dUUap90oiPA");
	cont.add("Scopes", "Alex", 123, 12, 5, "https://www.youtube.com/watch?v=dUUap90oiPA");
}

int UI::admin(int argc, char *argv[])
{
	QApplication a(argc, argv);

	RepositoryCSV repo(CSV_REPO_FILE);
	RepositoryCSV wrepo(CSV_WREPO_FILE);

	Ass1112 w(&repo, &wrepo);
	w.show();
	return a.exec();
}

void UI::user(Repository & repo, Repository & Wrepo)
{

}

//void UI::admin()
//{
//
//	std::cout << "Use CSV instead of HTML? y/n" << std:: endl;
//
//	std::string in;
//	std::cout << "admin >>";
//	//std::getline(std::cin, in);
//	std::cin >> in;
//
//	RepositoryHTML a(HTML_REPO_FILE);
//	RepositoryHTML b(HTML_WREPO_FILE);
//
//	Repository& repo{ a };
//	Repository& Wrepo{ b };
//
//	if (in.compare("y") == 0)
//	{
//		repo = { RepositoryCSV(CSV_REPO_FILE) };
//		Wrepo = { RepositoryCSV(CSV_WREPO_FILE) };
//		std::cout << "CSV REPOSITORY CHOSEN" << std::endl;
//	} else std::cout << "HTML REPOSITORY CHOSEN" << std::endl;
//
//	UI::showmenu_admin();
//
//	Controller cont(repo);
//	//UI::initialise(cont);
//
//	repo.file_load();
//
//	while (true)
//	{
//		std::vector<std::string> arg;
//
//		std::string s;
//		std::cout << "admin >>";
//		std::getline(std::cin, s);
//
//		std::string delimiter = " ";
//
//		size_t pos = 0;
//		std::string token;
//		while ((pos = s.find(delimiter)) != std::string::npos)
//		{
//			token = s.substr(0, pos);
//			arg.push_back(token);
//			s.erase(0, pos + delimiter.length());
//		}
//		token = s.substr(0, pos);
//		arg.push_back(token);
//
//		if (arg[0].compare("exit") == 0)
//		{
//			repo.file_save();
//			break;
//		}
//
//		if (arg[0].compare("list") == 0)
//		{
//			//std::cout << cont.getRepo().pretty_print();
//			ComparatorAscendingByTitle t;
//			std::cout << sort(repo.getVector(), t) << std::endl;
//			ComparatorAscendingByAuthor a;
//			std::cout << sort(repo.getVector(), a);
//
//			continue;
//		}
//
//		if (arg[0].compare("usermode") == 0)
//		{
//			UI::user(repo, Wrepo);
//			continue;
//		}
//
//		if (arg[0].compare("display") == 0)
//		{
//			repo.display();
//			continue;
//		}
//
//		try
//		{
//			cont.process_input(arg);
//			repo.file_save();
//		}
//		catch (ControllerException & e)
//		{
//			std::cout << e.what() << std::endl;
//		}
//	}
//}
//
//void UI::user(Repository & repo, Repository & Wrepo)
//{
//
//	UI::showmenu_user();
//
//	Wrepo.file_load();
//
//	Repository temp;
//	WachlistController cont(repo, Wrepo);
//
//	while (true)
//	{
//		std::vector<std::string> arg;
//
//		std::string s;
//		std::cout << "usermode >>";
//		std::getline(std::cin, s);
//
//		std::string delimiter = " ";
//
//		size_t pos = 0;
//		std::string token;
//		while ((pos = s.find(delimiter)) != std::string::npos)
//		{
//			token = s.substr(0, pos);
//			arg.push_back(token);
//			s.erase(0, pos + delimiter.length());
//		}
//		token = s.substr(0, pos);
//		arg.push_back(token);
//
//		if (arg[0].compare("exit") == 0)
//		{
//			Wrepo.file_save();
//			break;
//		}
//
//		if (arg[0].compare("help") == 0)
//		{
//			UI::showmenu_user();
//			continue;
//		}
//
//		if (arg[0].compare("list") == 0)
//		{
//			std::cout << Wrepo.pretty_print();
//			continue;
//		}
//
//		if (arg[0].compare("display") == 0)
//		{
//			Wrepo.display();
//			continue;
//		}
//
//		try
//		{
//			cont.process_input(arg);
//			Wrepo.file_save();
//		}
//		catch (ControllerException & e)
//		{
//			std::cout << e.what() << std::endl;
//		}
//	}
//}
