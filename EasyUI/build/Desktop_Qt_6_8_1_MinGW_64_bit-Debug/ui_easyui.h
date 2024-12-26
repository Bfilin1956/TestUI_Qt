/********************************************************************************
** Form generated from reading UI file 'easyui.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EASYUI_H
#define UI_EASYUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EasyUI
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EasyUI)
    {
        if (EasyUI->objectName().isEmpty())
            EasyUI->setObjectName("EasyUI");
        EasyUI->resize(800, 600);
        centralwidget = new QWidget(EasyUI);
        centralwidget->setObjectName("centralwidget");
        EasyUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EasyUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        EasyUI->setMenuBar(menubar);
        statusbar = new QStatusBar(EasyUI);
        statusbar->setObjectName("statusbar");
        EasyUI->setStatusBar(statusbar);

        retranslateUi(EasyUI);

        QMetaObject::connectSlotsByName(EasyUI);
    } // setupUi

    void retranslateUi(QMainWindow *EasyUI)
    {
        EasyUI->setWindowTitle(QCoreApplication::translate("EasyUI", "EasyUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EasyUI: public Ui_EasyUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EASYUI_H
