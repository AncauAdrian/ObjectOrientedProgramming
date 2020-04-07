#pragma once
#include <QtWidgets/qdialog.h>
#include "ui_SecondWindow.h"

class DialogWindow : public QDialog
{
	Q_OBJECT

public:
	DialogWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::Dialog ui;
};

