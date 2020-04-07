#pragma once


class UI
{
public:
	static void showmenu_admin();
	static void showmenu_user();
	static void initialise(Controller& cont);
	static void admin();
	static void user(Repository & repo, Repository & WRepo);
};

