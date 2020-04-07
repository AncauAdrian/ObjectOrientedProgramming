/********************************************************************************
** Form generated from reading UI file 'QtRecap.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTRECAP_H
#define UI_QTRECAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtRecapClass
{
public:
    QWidget *centralWidget;
    QPushButton *openButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtRecapClass)
    {
        if (QtRecapClass->objectName().isEmpty())
            QtRecapClass->setObjectName(QString::fromUtf8("QtRecapClass"));
        QtRecapClass->resize(600, 400);
        centralWidget = new QWidget(QtRecapClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(150, 130, 75, 23));
        QtRecapClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtRecapClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        QtRecapClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtRecapClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtRecapClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtRecapClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtRecapClass->setStatusBar(statusBar);

        retranslateUi(QtRecapClass);

        QMetaObject::connectSlotsByName(QtRecapClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtRecapClass)
    {
        QtRecapClass->setWindowTitle(QApplication::translate("QtRecapClass", "QtRecap", nullptr));
        openButton->setText(QApplication::translate("QtRecapClass", "open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtRecapClass: public Ui_QtRecapClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTRECAP_H
