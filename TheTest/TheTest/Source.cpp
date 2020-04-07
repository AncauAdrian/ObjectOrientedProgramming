#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include "DynamicVector.h"
#include "Team.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"
#include <stdlib.h>
#include <crtdbg.h>


int main()
{
	testTeam();
	testRepository();
	testController();

	UI::start();
	
	_CrtDumpMemoryLeaks();
	return 0;
}