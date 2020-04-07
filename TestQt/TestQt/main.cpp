#include "TestQt.h"
#include "Repository.h"
#include "Controller.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	testCompute();

	QApplication a(argc, argv);

	Repository repo;
	repo.file_load();
	Controller cont(repo);

	TestQt w(&repo, &cont);
	w.show();
	return a.exec();
}
