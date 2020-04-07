/********************************************************************************
** Form generated from reading UI file 'Ass1112.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASS1112_H
#define UI_ASS1112_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ass1112Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Ass1112Class)
    {
        if (Ass1112Class->objectName().isEmpty())
            Ass1112Class->setObjectName(QString::fromUtf8("Ass1112Class"));
        Ass1112Class->resize(600, 400);
        menuBar = new QMenuBar(Ass1112Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Ass1112Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Ass1112Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Ass1112Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Ass1112Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Ass1112Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Ass1112Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Ass1112Class->setStatusBar(statusBar);

        retranslateUi(Ass1112Class);

        QMetaObject::connectSlotsByName(Ass1112Class);
    } // setupUi

    void retranslateUi(QMainWindow *Ass1112Class)
    {
        Ass1112Class->setWindowTitle(QApplication::translate("Ass1112Class", "Ass1112", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ass1112Class: public Ui_Ass1112Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASS1112_H
