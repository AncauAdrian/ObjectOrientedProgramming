/********************************************************************************
** Form generated from reading UI file 'Qt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_H
#define UI_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtClass)
    {
        if (QtClass->objectName().isEmpty())
            QtClass->setObjectName(QString::fromUtf8("QtClass"));
        QtClass->resize(600, 400);
        menuBar = new QMenuBar(QtClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtClass->setStatusBar(statusBar);

        retranslateUi(QtClass);

        QMetaObject::connectSlotsByName(QtClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtClass)
    {
        QtClass->setWindowTitle(QApplication::translate("QtClass", "Qt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtClass: public Ui_QtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_H
