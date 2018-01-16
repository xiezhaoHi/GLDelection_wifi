/********************************************************************************
** Form generated from reading UI file 'GLdetection_wifi.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLDETECTION_WIFI_H
#define UI_GLDETECTION_WIFI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GLdetection_wifiClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GLdetection_wifiClass)
    {
        if (GLdetection_wifiClass->objectName().isEmpty())
            GLdetection_wifiClass->setObjectName(QStringLiteral("GLdetection_wifiClass"));
        GLdetection_wifiClass->resize(600, 400);
        menuBar = new QMenuBar(GLdetection_wifiClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        GLdetection_wifiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GLdetection_wifiClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GLdetection_wifiClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GLdetection_wifiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GLdetection_wifiClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GLdetection_wifiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GLdetection_wifiClass->setStatusBar(statusBar);

        retranslateUi(GLdetection_wifiClass);

        QMetaObject::connectSlotsByName(GLdetection_wifiClass);
    } // setupUi

    void retranslateUi(QMainWindow *GLdetection_wifiClass)
    {
        GLdetection_wifiClass->setWindowTitle(QApplication::translate("GLdetection_wifiClass", "GLdetection_wifi", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GLdetection_wifiClass: public Ui_GLdetection_wifiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLDETECTION_WIFI_H
