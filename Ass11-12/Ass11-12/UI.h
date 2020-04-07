#pragma once
#define CSV_REPO_FILE "list.txt"
#define CSV_WREPO_FILE "wlist.txt"

#define HTML_REPO_FILE "list.html"
#define HTML_WREPO_FILE "wlist.html"

#include "Repository.h"
#include "Controller.h"

class UI
{
public:
	static void showmenu_admin();
	static void showmenu_user();
	static void initialise(Controller& cont);
	static int admin(int argc, char *argv[]);
	static void user(Repository & repo, Repository & WRepo);
};

