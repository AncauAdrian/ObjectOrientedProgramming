/********************************************************************************
** Form generated from reading UI file 'assbyvVHE.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ASSBYVVHE_H
#define ASSBYVVHE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
	QWidget *centralwidget;
	QTabWidget *tabWidget;
	QWidget *TabMan;
	QWidget *verticalLayoutWidget_4;
	QVBoxLayout *CenterRightLayout;
	QLabel *errorLabel;
	QTextBrowser *errorBox;
	QPushButton *addtoWbutton;
	QPushButton *wlistRemoveButton;
	QPushButton *saveButton;
	QWidget *verticalLayoutWidget;
	QVBoxLayout *TopVLayout;
	QLabel *AllLabel;
	QListWidget *AllList;
	QWidget *verticalLayoutWidget_3;
	QVBoxLayout *CenterLeftLayout;
	QFormLayout *formLayout;
	QLabel *TitleLabel;
	QLineEdit *TitleEdit;
	QLabel *AuthorLabel;
	QLineEdit *AuthorEdit;
	QLabel *DurationLabel;
	QLineEdit *DurationEdit;
	QLabel *LikesLabel;
	QLineEdit *LikesEdit;
	QLabel *LinksLabel;
	QLineEdit *LinkEdit;
	QGridLayout *gridLayout;
	QPushButton *updateButton;
	QPushButton *filterButton;
	QPushButton *addButton;
	QPushButton *removeButton;
	QWidget *verticalLayoutWidget_2;
	QVBoxLayout *BottomVlayout;
	QLabel *WlistLabel;
	QListWidget *WlistList;
	QWidget *TabStat;
	QWidget *verticalLayoutWidget_5;
	QVBoxLayout *statLayout;
	QStatusBar *statusbar;

	void setupUi(QMainWindow *MainWindow)
	{
		if (MainWindow->objectName().isEmpty())
			MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
		MainWindow->resize(856, 752);
		centralwidget = new QWidget(MainWindow);
		centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
		tabWidget = new QTabWidget(centralwidget);
		tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
		tabWidget->setGeometry(QRect(10, 0, 841, 751));
		TabMan = new QWidget();
		TabMan->setObjectName(QString::fromUtf8("TabMan"));
		verticalLayoutWidget_4 = new QWidget(TabMan);
		verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
		verticalLayoutWidget_4->setGeometry(QRect(540, 238, 271, 201));
		CenterRightLayout = new QVBoxLayout(verticalLayoutWidget_4);
		CenterRightLayout->setObjectName(QString::fromUtf8("CenterRightLayout"));
		CenterRightLayout->setContentsMargins(0, 0, 0, 0);
		errorLabel = new QLabel(verticalLayoutWidget_4);
		errorLabel->setObjectName(QString::fromUtf8("errorLabel"));

		CenterRightLayout->addWidget(errorLabel);

		errorBox = new QTextBrowser(verticalLayoutWidget_4);
		errorBox->setObjectName(QString::fromUtf8("errorBox"));

		CenterRightLayout->addWidget(errorBox);

		addtoWbutton = new QPushButton(verticalLayoutWidget_4);
		addtoWbutton->setObjectName(QString::fromUtf8("addtoWbutton"));

		CenterRightLayout->addWidget(addtoWbutton);

		wlistRemoveButton = new QPushButton(verticalLayoutWidget_4);
		wlistRemoveButton->setObjectName(QString::fromUtf8("wlistRemoveButton"));

		CenterRightLayout->addWidget(wlistRemoveButton);

		saveButton = new QPushButton(verticalLayoutWidget_4);
		saveButton->setObjectName(QString::fromUtf8("saveButton"));

		CenterRightLayout->addWidget(saveButton);

		verticalLayoutWidget = new QWidget(TabMan);
		verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
		verticalLayoutWidget->setGeometry(QRect(0, 0, 821, 221));
		TopVLayout = new QVBoxLayout(verticalLayoutWidget);
		TopVLayout->setObjectName(QString::fromUtf8("TopVLayout"));
		TopVLayout->setContentsMargins(0, 0, 0, 0);
		AllLabel = new QLabel(verticalLayoutWidget);
		AllLabel->setObjectName(QString::fromUtf8("AllLabel"));

		TopVLayout->addWidget(AllLabel);

		AllList = new QListWidget(verticalLayoutWidget);
		AllList->setObjectName(QString::fromUtf8("AllList"));

		TopVLayout->addWidget(AllList);

		verticalLayoutWidget_3 = new QWidget(TabMan);
		verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
		verticalLayoutWidget_3->setGeometry(QRect(0, 240, 511, 201));
		CenterLeftLayout = new QVBoxLayout(verticalLayoutWidget_3);
		CenterLeftLayout->setObjectName(QString::fromUtf8("CenterLeftLayout"));
		CenterLeftLayout->setContentsMargins(0, 0, 0, 0);
		formLayout = new QFormLayout();
		formLayout->setObjectName(QString::fromUtf8("formLayout"));
		TitleLabel = new QLabel(verticalLayoutWidget_3);
		TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));

		formLayout->setWidget(0, QFormLayout::LabelRole, TitleLabel);

		TitleEdit = new QLineEdit(verticalLayoutWidget_3);
		TitleEdit->setObjectName(QString::fromUtf8("TitleEdit"));

		formLayout->setWidget(0, QFormLayout::FieldRole, TitleEdit);

		AuthorLabel = new QLabel(verticalLayoutWidget_3);
		AuthorLabel->setObjectName(QString::fromUtf8("AuthorLabel"));

		formLayout->setWidget(1, QFormLayout::LabelRole, AuthorLabel);

		AuthorEdit = new QLineEdit(verticalLayoutWidget_3);
		AuthorEdit->setObjectName(QString::fromUtf8("AuthorEdit"));

		formLayout->setWidget(1, QFormLayout::FieldRole, AuthorEdit);

		DurationLabel = new QLabel(verticalLayoutWidget_3);
		DurationLabel->setObjectName(QString::fromUtf8("DurationLabel"));

		formLayout->setWidget(2, QFormLayout::LabelRole, DurationLabel);

		DurationEdit = new QLineEdit(verticalLayoutWidget_3);
		DurationEdit->setObjectName(QString::fromUtf8("DurationEdit"));

		formLayout->setWidget(2, QFormLayout::FieldRole, DurationEdit);

		LikesLabel = new QLabel(verticalLayoutWidget_3);
		LikesLabel->setObjectName(QString::fromUtf8("LikesLabel"));

		formLayout->setWidget(3, QFormLayout::LabelRole, LikesLabel);

		LikesEdit = new QLineEdit(verticalLayoutWidget_3);
		LikesEdit->setObjectName(QString::fromUtf8("LikesEdit"));

		formLayout->setWidget(3, QFormLayout::FieldRole, LikesEdit);

		LinksLabel = new QLabel(verticalLayoutWidget_3);
		LinksLabel->setObjectName(QString::fromUtf8("LinksLabel"));

		formLayout->setWidget(4, QFormLayout::LabelRole, LinksLabel);

		LinkEdit = new QLineEdit(verticalLayoutWidget_3);
		LinkEdit->setObjectName(QString::fromUtf8("LinkEdit"));

		formLayout->setWidget(4, QFormLayout::FieldRole, LinkEdit);


		CenterLeftLayout->addLayout(formLayout);

		gridLayout = new QGridLayout();
		gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
		updateButton = new QPushButton(verticalLayoutWidget_3);
		updateButton->setObjectName(QString::fromUtf8("updateButton"));

		gridLayout->addWidget(updateButton, 0, 1, 1, 1);

		filterButton = new QPushButton(verticalLayoutWidget_3);
		filterButton->setObjectName(QString::fromUtf8("filterButton"));

		gridLayout->addWidget(filterButton, 1, 1, 1, 1);

		addButton = new QPushButton(verticalLayoutWidget_3);
		addButton->setObjectName(QString::fromUtf8("addButton"));

		gridLayout->addWidget(addButton, 0, 0, 1, 1);

		removeButton = new QPushButton(verticalLayoutWidget_3);
		removeButton->setObjectName(QString::fromUtf8("removeButton"));

		gridLayout->addWidget(removeButton, 0, 2, 1, 1);


		CenterLeftLayout->addLayout(gridLayout);

		verticalLayoutWidget_2 = new QWidget(TabMan);
		verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
		verticalLayoutWidget_2->setGeometry(QRect(0, 450, 821, 251));
		BottomVlayout = new QVBoxLayout(verticalLayoutWidget_2);
		BottomVlayout->setObjectName(QString::fromUtf8("BottomVlayout"));
		BottomVlayout->setContentsMargins(0, 0, 0, 0);
		WlistLabel = new QLabel(verticalLayoutWidget_2);
		WlistLabel->setObjectName(QString::fromUtf8("WlistLabel"));

		BottomVlayout->addWidget(WlistLabel);

		WlistList = new QListWidget(verticalLayoutWidget_2);
		WlistList->setObjectName(QString::fromUtf8("WlistList"));

		BottomVlayout->addWidget(WlistList);

		tabWidget->addTab(TabMan, QString());
		TabStat = new QWidget();
		TabStat->setObjectName(QString::fromUtf8("TabStat"));
		verticalLayoutWidget_5 = new QWidget(TabStat);
		verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
		verticalLayoutWidget_5->setGeometry(QRect(9, 9, 811, 701));
		statLayout = new QVBoxLayout(verticalLayoutWidget_5);
		statLayout->setObjectName(QString::fromUtf8("statLayout"));
		statLayout->setContentsMargins(0, 0, 0, 0);
		tabWidget->addTab(TabStat, QString());
		MainWindow->setCentralWidget(centralwidget);
		statusbar = new QStatusBar(MainWindow);
		statusbar->setObjectName(QString::fromUtf8("statusbar"));
		MainWindow->setStatusBar(statusbar);

		retranslateUi(MainWindow);

		tabWidget->setCurrentIndex(1);


		QMetaObject::connectSlotsByName(MainWindow);
	} // setupUi

	void retranslateUi(QMainWindow *MainWindow)
	{
		MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Tutorial Manager", nullptr));
		errorLabel->setText(QApplication::translate("MainWindow", "Last Command Output:", nullptr));
		addtoWbutton->setText(QApplication::translate("MainWindow", "Add to Watchlist \\|/", nullptr));
		wlistRemoveButton->setText(QApplication::translate("MainWindow", "Remove from Watchlist", nullptr));
		saveButton->setText(QApplication::translate("MainWindow", "Save", nullptr));
		AllLabel->setText(QApplication::translate("MainWindow", "All Tutorials", nullptr));
		TitleLabel->setText(QApplication::translate("MainWindow", "Title", nullptr));
		AuthorLabel->setText(QApplication::translate("MainWindow", "Author", nullptr));
		DurationLabel->setText(QApplication::translate("MainWindow", "Duration", nullptr));
		LikesLabel->setText(QApplication::translate("MainWindow", "Likes", nullptr));
		LinksLabel->setText(QApplication::translate("MainWindow", "Link", nullptr));
		updateButton->setText(QApplication::translate("MainWindow", "update", nullptr));
		filterButton->setText(QApplication::translate("MainWindow", "filter", nullptr));
		addButton->setText(QApplication::translate("MainWindow", "add", nullptr));
		removeButton->setText(QApplication::translate("MainWindow", "remove", nullptr));
		WlistLabel->setText(QApplication::translate("MainWindow", "Tutorial Watchlist", nullptr));
		tabWidget->setTabText(tabWidget->indexOf(TabMan), QApplication::translate("MainWindow", "Tab Manager", nullptr));
		tabWidget->setTabText(tabWidget->indexOf(TabStat), QApplication::translate("MainWindow", "Statistics", nullptr));
	} // retranslateUi

};

namespace Ui {
	class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ASSBYVVHE_H
