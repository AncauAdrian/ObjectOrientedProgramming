#include "QtRecap.h"

QtRecap::QtRecap(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QObject::connect(ui.openButton, &QPushButton::clicked, this, &QtRecap::showDiag);
}

void QtRecap::showDiag()
{
	d = new DialogWindow();
	d->show();
}
