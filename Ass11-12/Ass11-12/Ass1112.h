#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Ass1112.h"
#include "Repository.h"
#include "Controller.h"
#include "WachlistController.h"
#include "QtDesigner.h"

class Ass1112 : public QMainWindow
{
	Q_OBJECT

	Repository *repo;
	Repository *wrepo;
	Controller *cont;
	WachlistController *wcont;

public:
	Ass1112(Repository* repo, Repository* wrepo, QWidget *parent = Q_NULLPTR);
	~Ass1112();
	Ui::MainWindow ui;

	void populate_allList();
	void populate_wList();
	void create_stats();

private slots:
	void filter_list();
	void add();
	void remove();
	void update();
	void add_to_wlist();
	void remove_from_wlist();
	void save();
	void view_all();
	void view_wlist();

};
