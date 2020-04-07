#include "TestQt.h"

TestQt::TestQt(Repository* repo, Controller* cont, QWidget *parent)
	: QMainWindow(parent)
{
	this->repo = repo;
	this->cont = cont;
	ui.setupUi(this);

	this->populate_list(repo->getVector());

	QObject::connect(ui.filterButton, &QPushButton::clicked, this, &TestQt::filter);
	QObject::connect(ui.computeButton, &QPushButton::clicked, this, &TestQt::compute);
}

void TestQt::populate_list(std::vector<WeatherInfo>& v)
{
	ui.weatherList->clear();

	for (auto a : v)
	{
		new QListWidgetItem(a.prettyprint().c_str(), ui.weatherList);
	}
}

void TestQt::compute()
{
	std::string val = ui.computeEdit->text().toStdString();

	int n = cont->compute(val);

	ui.resEdit->setText(std::to_string(n).c_str());
}

void TestQt::filter()
{
	std::string val = ui.filterEdit->text().toStdString();
	
	if (val.length() == 0)
		populate_list(this->repo->getVector());
	else
		this->populate_list(this->cont->filter(std::stod(val)));
}
