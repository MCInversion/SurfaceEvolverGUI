/********************************************************************************
** Form generated from reading UI file 'SurfaceEvolverGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURFACEEVOLVERGUI_H
#define UI_SURFACEEVOLVERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>
#include "QVTKOpenGLNativeWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SurfaceEvolverGUI
{
public:
    QAction *actionOpenFile;
    QAction *actionExit;
    QAction *actionPrint;
    QAction *actionHelp;
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVTKOpenGLNativeWidget *qvtkWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *SurfaceEvolverGUI)
    {
        if (SurfaceEvolverGUI->objectName().isEmpty())
            SurfaceEvolverGUI->setObjectName(QString::fromUtf8("SurfaceEvolverGUI"));
        SurfaceEvolverGUI->resize(637, 641);
        actionOpenFile = new QAction(SurfaceEvolverGUI);
        actionOpenFile->setObjectName(QString::fromUtf8("actionOpenFile"));
        actionOpenFile->setEnabled(true);
        actionExit = new QAction(SurfaceEvolverGUI);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionPrint = new QAction(SurfaceEvolverGUI);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        actionHelp = new QAction(SurfaceEvolverGUI);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionOpen = new QAction(SurfaceEvolverGUI);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(SurfaceEvolverGUI);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        centralwidget = new QWidget(SurfaceEvolverGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        qvtkWidget = new QVTKOpenGLNativeWidget(centralwidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));

        horizontalLayout->addWidget(qvtkWidget);

        SurfaceEvolverGUI->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(SurfaceEvolverGUI);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 637, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        SurfaceEvolverGUI->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);

        retranslateUi(SurfaceEvolverGUI);

        QMetaObject::connectSlotsByName(SurfaceEvolverGUI);
    } // setupUi

    void retranslateUi(QMainWindow *SurfaceEvolverGUI)
    {
        SurfaceEvolverGUI->setWindowTitle(QCoreApplication::translate("SurfaceEvolverGUI", "SurfaceEvolverGUI", nullptr));
        actionOpenFile->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Open File...", nullptr));
        actionExit->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Exit", nullptr));
        actionPrint->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Print", nullptr));
        actionHelp->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Help", nullptr));
        actionOpen->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("SurfaceEvolverGUI", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("SurfaceEvolverGUI", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        menuFile->setTitle(QCoreApplication::translate("SurfaceEvolverGUI", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SurfaceEvolverGUI: public Ui_SurfaceEvolverGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURFACEEVOLVERGUI_H
