#define _CRTDBG_MAP_ALLOC
//#include "DynamicVector.h"
#include "Tutorial.h"
#include "Repository.h"
#include "Controller.h"
#include "WachlistController.h"
#include "UI.h"
#include <stdlib.h>
#include <crtdbg.h>


int main()
{
	//testDynamicVector();
	testTutorial();
	testRepository();
	testController();
	testWatchlistController();
	//test_html();


	UI::admin();

	_CrtDumpMemoryLeaks();

	return 0;
}