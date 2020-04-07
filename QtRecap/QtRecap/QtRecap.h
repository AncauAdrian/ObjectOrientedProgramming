#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtRecap.h"
#include "DialogWindow.h"

class QtRecap : public QMainWindow
{
	Q_OBJECT

public:
	QtRecap(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtRecapClass ui;
	DialogWindow *d;

public slots:
	void showDiag();
};
