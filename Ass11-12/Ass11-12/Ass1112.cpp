#include "Ass1112.h"
#include "UI.h"
#include "Controller.h"
#include "WachlistController.h"
#include "ControllerException.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtCharts/qbarset.h>
#include <QtCharts/qchart.h>
#include <QtCharts/qchartview.h>
#include <QtCharts/qbarseries.h>
#include <QtCharts/qbarset.h>
#include <QtCharts/qbarcategoryaxis.h>
#include <string>
#include <vector>

QT_CHARTS_USE_NAMESPACE


Ass1112::Ass1112(Repository* repo, Repository* wrepo, QWidget *parent) : QMainWindow(parent)
{
	this->repo = repo;
	this->wrepo = wrepo;
	this->cont = new Controller(*repo);
	this->wcont = new WachlistController(*repo, *wrepo);

	this->repo->file_load();
	this->wrepo->file_load();

	ui.setupUi(this);

	this->populate_allList();
	this->populate_wList();

	ui.addtoWbutton->setStyleSheet("* {color: qlineargradient(spread:pad, x1:0 y1:0, x2:1 y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
		"background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 cyan, stop:1 blue);}");

	QObject::connect(ui.addButton, &QPushButton::clicked, this, &Ass1112::add);
	QObject::connect(ui.removeButton, &QPushButton::clicked, this, &Ass1112::remove);
	QObject::connect(ui.updateButton, &QPushButton::clicked, this, &Ass1112::update);
	QObject::connect(ui.filterButton, &QPushButton::clicked, this, &Ass1112::filter_list);
	QObject::connect(ui.addtoWbutton, &QPushButton::clicked, this, &Ass1112::add_to_wlist);
	QObject::connect(ui.wlistRemoveButton, &QPushButton::clicked, this, &Ass1112::remove_from_wlist);
	QObject::connect(ui.saveButton, &QPushButton::clicked, this, &Ass1112::save);
	QObject::connect(ui.AllList, &QListWidget::doubleClicked, this, &Ass1112::view_all);
	QObject::connect(ui.WlistList, &QListWidget::doubleClicked, this, &Ass1112::view_wlist);

	//this->create_stats();
}

Ass1112::~Ass1112()
{
	//delete repo;
	//delete wrepo;
	delete this->cont;
	delete this->wcont;
}

void Ass1112::populate_allList()
{
	ui.AllList->clear();
	int index = 0;

	for (auto t : this->repo->getVector())
	{
		index++;
		new QListWidgetItem((std::to_string(index) + ": " + t.prettyfy()).c_str(), ui.AllList);
	}
}

void Ass1112::populate_wList()
{
	ui.WlistList->clear();
	int index = 0;

	for (auto t : this->wrepo->getVector())
	{
		index++;
		new QListWidgetItem((std::to_string(index) + ": " + t.prettyfy()).c_str(), ui.WlistList);
	}
}

void Ass1112::create_stats()
{
	std::vector<std::string> authors;

	for (auto a : this->repo->getVector())
	{
		int i = 0;
		while (i < authors.size())
		{
			if (authors[i].compare(a.getAuthor()) == 0)
			{
				break;
			}
		}

		if (i == authors.size())
			authors.push_back(a.getAuthor());
	}

	std::vector<QBarSet*> set;
	for (auto a : authors)
	{
		QBarSet *s = new QBarSet(a.c_str());

		int nr = 0;

		for (auto t : this->repo->getVector())
			if (t.getAuthor().compare(a) == 0)
				nr++;
		*s << nr;

		set.push_back(s);
	}

	QBarSeries *series = new QBarSeries();

	for (auto a : set)
		series->append(a);

	QChart *chart = new QChart();
	chart->addSeries(series);
	chart->setTitle("Simple barchart example");
	chart->setAnimationOptions(QChart::SeriesAnimations);

	QStringList categories;
	categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
	QBarCategoryAxis *axis = new QBarCategoryAxis();
	axis->append(categories);
	chart->createDefaultAxes();
	chart->setAxisX(axis, series);

	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);

	QChartView *chartView = new QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);

	ui.statLayout->addWidget(chartView);
}

void Ass1112::add()
{
	std::vector<std::string> args;
	args.push_back("add");
	args.push_back(ui.TitleEdit->text().toStdString());
	args.push_back(ui.AuthorEdit->text().toStdString());
	args.push_back(ui.DurationEdit->text().toStdString());
	args.push_back(ui.LikesEdit->text().toStdString());
	args.push_back(ui.LinkEdit->text().toStdString());

	try {
		this->cont->process_input(args);
		populate_allList();
		ui.errorBox->setText("Tutorial Added!");
	}
	catch (ControllerException& e)
	{
		ui.errorBox->setText(e.what().c_str());
	}
}

void Ass1112::remove()
{
	QListWidgetItem *i = ui.AllList->currentItem();

	if (i == Q_NULLPTR)
	{
		ui.errorBox->setText("[ERROR] No tutorial selected!");
		return;
	}

	std::string n = i->text().toStdString();

	int pos = n.find(':');
	int index = std::stoi(n.substr(0, pos));
	repo->remove_tutorial(index - 1);
	populate_allList();

	ui.errorBox->setText((std::string("Removed Tutorial with position: ") + std::to_string(index)).c_str());
}

void Ass1112::update()
{
	std::vector<std::string> args;
	args.push_back("update");
	args.push_back(ui.TitleEdit->text().toStdString());
	args.push_back(ui.AuthorEdit->text().toStdString());
	args.push_back(ui.DurationEdit->text().toStdString());
	args.push_back(ui.LikesEdit->text().toStdString());
	args.push_back(ui.LinkEdit->text().toStdString());

	try {
		this->cont->process_input(args);
		populate_allList();
		ui.errorBox->setText("Tutorial Updated!");
	}
	catch (ControllerException& e)
	{
		ui.errorBox->setText(e.what().c_str());
	}
}

void Ass1112::add_to_wlist()
{
	QListWidgetItem *i = ui.AllList->currentItem();

	if (i == Q_NULLPTR)
	{
		ui.errorBox->setText("[ERROR] No tutorial selected!");
		return;
	}

	std::string n = i->text().toStdString();

	int pos = n.find(':');
	int index = std::stoi(n.substr(0, pos));
	Tutorial t = repo->getVector()[index - 1];
	
	try
	{
		this->wcont->add_watchlist(t);
		populate_wList();
		ui.errorBox->setText("Tutorial Added to the Watchlist!");
	}
	catch (ControllerException& e)
	{
		ui.errorBox->setText(e.what().c_str());
	}
}

void Ass1112::remove_from_wlist()
{
	QListWidgetItem *i = ui.WlistList->currentItem();

	if (i == Q_NULLPTR)
	{
		ui.errorBox->setText("[ERROR] No tutorial selected!");
		return;
	}

	std::string n = i->text().toStdString();

	int pos = n.find(':');
	int index = std::stoi(n.substr(0, pos));
	wrepo->remove_tutorial(index - 1);
	populate_wList();

	ui.errorBox->setText((std::string("Removed Tutorial with position: ") + std::to_string(index)).c_str());
}

void Ass1112::save()
{
	repo->file_save();
	wrepo->file_save();

	ui.errorBox->setText("All lists were saved!");
}

void Ass1112::view_all()
{
	this->repo->display();
}

void Ass1112::view_wlist()
{
	this->wrepo->display();
}

void Ass1112::filter_list()
{
	ui.AllList->clear();
	std::string title = ui.TitleEdit->text().toStdString();
	std::string author = ui.AuthorEdit->text().toStdString();

	int index = 0;

	for (Tutorial a : repo->getVector())
	{
		index++;
		if (strstr(a.getTitle().c_str(), title.c_str()) != nullptr && strstr(a.getAuthor().c_str(), author.c_str()) != nullptr)
			new QListWidgetItem((std::to_string(index) + ": " + a.prettyfy()).c_str(), ui.AllList);
	}

	ui.errorBox->setText("List Filtered!");
}

//Ass1112::Ass1112(QWidget *parent) : QMainWindow(parent)
//{
//
//	QWidget *wnd = new QWidget{ };
//	QVBoxLayout *vLay = new QVBoxLayout{ this };
//
//	repo = new RepositoryCSV(CSV_REPO_FILE);
//
//	repo->file_load();
//
//	input = new QLineEdit(this);
//
//	list = new QListWidget;
//
//	for (auto a : repo->getVector())
//		new QListWidgetItem(a.prettyfy().c_str(), list);
//
//
//	vLay->addWidget(input);
//	//vLay->addWidget(new QLabel("List of Tutorials"));
//	vLay->addWidget(list);
//	wnd->setLayout(vLay);
//	wnd->show();
//	wnd->setWindowTitle("Tutorials");
//
//	QObject::connect(input, &QLineEdit::textChanged, this, &Ass1112::filter_list);
//}
//
//Ass1112::~Ass1112()
//{
//	delete input;
//	delete list;
//	delete repo;
//}
//
