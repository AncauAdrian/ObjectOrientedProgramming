#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestQt.h"
#include "Repository.h"
#include "Controller.h"

class TestQt : public QMainWindow
{
	Q_OBJECT

	Repository* repo;
	Controller* cont;

public:
	TestQt(Repository* repo, Controller* cont, QWidget *parent = Q_NULLPTR);

private:
	Ui::TestQtClass ui;

	void populate_list(std::vector<WeatherInfo>& v);

private slots:
	void filter();
	void compute();
};
