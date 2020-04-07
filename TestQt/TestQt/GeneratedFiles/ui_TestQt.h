/********************************************************************************
** Form generated from reading UI file 'TestQt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQT_H
#define UI_TESTQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestQtClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *listLayout;
    QListWidget *weatherList;
    QWidget *formLayoutWidget;
    QFormLayout *buttonLayout;
    QPushButton *filterButton;
    QLineEdit *filterEdit;
    QPushButton *computeButton;
    QLineEdit *computeEdit;
    QTextEdit *resEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestQtClass)
    {
        if (TestQtClass->objectName().isEmpty())
            TestQtClass->setObjectName(QString::fromUtf8("TestQtClass"));
        TestQtClass->resize(730, 490);
        centralWidget = new QWidget(TestQtClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(19, 9, 691, 321));
        listLayout = new QVBoxLayout(verticalLayoutWidget);
        listLayout->setSpacing(6);
        listLayout->setContentsMargins(11, 11, 11, 11);
        listLayout->setObjectName(QString::fromUtf8("listLayout"));
        listLayout->setContentsMargins(0, 0, 0, 0);
        weatherList = new QListWidget(verticalLayoutWidget);
        weatherList->setObjectName(QString::fromUtf8("weatherList"));

        listLayout->addWidget(weatherList);

        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(19, 359, 691, 71));
        buttonLayout = new QFormLayout(formLayoutWidget);
        buttonLayout->setSpacing(6);
        buttonLayout->setContentsMargins(11, 11, 11, 11);
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        buttonLayout->setContentsMargins(0, 0, 0, 0);
        filterButton = new QPushButton(formLayoutWidget);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));

        buttonLayout->setWidget(0, QFormLayout::LabelRole, filterButton);

        filterEdit = new QLineEdit(formLayoutWidget);
        filterEdit->setObjectName(QString::fromUtf8("filterEdit"));

        buttonLayout->setWidget(0, QFormLayout::FieldRole, filterEdit);

        computeButton = new QPushButton(formLayoutWidget);
        computeButton->setObjectName(QString::fromUtf8("computeButton"));

        buttonLayout->setWidget(1, QFormLayout::LabelRole, computeButton);

        computeEdit = new QLineEdit(formLayoutWidget);
        computeEdit->setObjectName(QString::fromUtf8("computeEdit"));

        buttonLayout->setWidget(1, QFormLayout::FieldRole, computeEdit);

        resEdit = new QTextEdit(formLayoutWidget);
        resEdit->setObjectName(QString::fromUtf8("resEdit"));
        resEdit->setReadOnly(true);

        buttonLayout->setWidget(2, QFormLayout::FieldRole, resEdit);

        TestQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TestQtClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 730, 21));
        TestQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestQtClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TestQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TestQtClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TestQtClass->setStatusBar(statusBar);

        retranslateUi(TestQtClass);

        QMetaObject::connectSlotsByName(TestQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestQtClass)
    {
        TestQtClass->setWindowTitle(QApplication::translate("TestQtClass", "TestQt", nullptr));
        filterButton->setText(QApplication::translate("TestQtClass", "Filter", nullptr));
        computeButton->setText(QApplication::translate("TestQtClass", "Compute", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestQtClass: public Ui_TestQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQT_H
