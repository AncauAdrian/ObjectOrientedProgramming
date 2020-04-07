#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt.h"

class Qt : public QMainWindow
{
	Q_OBJECT

public:
	Qt(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtClass ui;
};
