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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
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
    QAction *ActionOpenFile;
    QAction *ActionSaveFile;
    QAction *actionOpen_File;
    QAction *actionSave_File;
    QAction *actionDoSomething;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QVTKOpenGLNativeWidget *qvtkWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *bgColorButton;
    QLabel *bgColorLabel;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBoxVertices;
    QCheckBox *checkBoxWireframe;
    QCheckBox *checkBoxSurface;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *SurfaceEvolverGUI)
    {
        if (SurfaceEvolverGUI->objectName().isEmpty())
            SurfaceEvolverGUI->setObjectName(QString::fromUtf8("SurfaceEvolverGUI"));
        SurfaceEvolverGUI->resize(1185, 766);
        SurfaceEvolverGUI->setMaximumSize(QSize(16777213, 16777215));
        actionOpenFile = new QAction(SurfaceEvolverGUI);
        actionOpenFile->setObjectName(QString::fromUtf8("actionOpenFile"));
        actionOpenFile->setEnabled(true);
        actionExit = new QAction(SurfaceEvolverGUI);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionPrint = new QAction(SurfaceEvolverGUI);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        actionHelp = new QAction(SurfaceEvolverGUI);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        ActionOpenFile = new QAction(SurfaceEvolverGUI);
        ActionOpenFile->setObjectName(QString::fromUtf8("ActionOpenFile"));
        ActionSaveFile = new QAction(SurfaceEvolverGUI);
        ActionSaveFile->setObjectName(QString::fromUtf8("ActionSaveFile"));
        actionOpen_File = new QAction(SurfaceEvolverGUI);
        actionOpen_File->setObjectName(QString::fromUtf8("actionOpen_File"));
        actionSave_File = new QAction(SurfaceEvolverGUI);
        actionSave_File->setObjectName(QString::fromUtf8("actionSave_File"));
        actionDoSomething = new QAction(SurfaceEvolverGUI);
        actionDoSomething->setObjectName(QString::fromUtf8("actionDoSomething"));
        centralwidget = new QWidget(SurfaceEvolverGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        qvtkWidget = new QVTKOpenGLNativeWidget(centralwidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));

        verticalLayout_2->addWidget(qvtkWidget);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);

        bgColorButton = new QToolButton(centralwidget);
        bgColorButton->setObjectName(QString::fromUtf8("bgColorButton"));
        // bg color button
        QPixmap pixmap(bgColorButton->size());
        pixmap.fill(QColor("black"));
        QIcon bgIcon(pixmap);

        horizontalLayout_2->addWidget(bgColorButton);

        bgColorLabel = new QLabel(centralwidget);
        bgColorLabel->setObjectName(QString::fromUtf8("bgColorLabel"));

        horizontalLayout_2->addWidget(bgColorLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 110));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        checkBoxVertices = new QCheckBox(groupBox);
        checkBoxVertices->setObjectName(QString::fromUtf8("checkBoxVertices"));

        verticalLayout_3->addWidget(checkBoxVertices);

        checkBoxWireframe = new QCheckBox(groupBox);
        checkBoxWireframe->setObjectName(QString::fromUtf8("checkBoxWireframe"));
        checkBoxWireframe->setChecked(true);

        verticalLayout_3->addWidget(checkBoxWireframe);

        checkBoxSurface = new QCheckBox(groupBox);
        checkBoxSurface->setObjectName(QString::fromUtf8("checkBoxSurface"));
        checkBoxSurface->setChecked(true);

        verticalLayout_3->addWidget(checkBoxSurface);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        // right menu horizontal spacer
        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        SurfaceEvolverGUI->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(SurfaceEvolverGUI);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1185, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        SurfaceEvolverGUI->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen_File);
        menuFile->addAction(actionSave_File);

        retranslateUi(SurfaceEvolverGUI);
        QObject::connect(bgColorButton, SIGNAL(clicked()), SurfaceEvolverGUI, SLOT(ActionRendererBackgroundColor()));
        QObject::connect(checkBoxVertices, SIGNAL(clicked(bool)), SurfaceEvolverGUI, SLOT(ActionRenderVertices()));
        QObject::connect(checkBoxWireframe, SIGNAL(clicked(bool)), SurfaceEvolverGUI, SLOT(ActionRenderWireframe()));
        QObject::connect(checkBoxSurface, SIGNAL(clicked(bool)), SurfaceEvolverGUI, SLOT(ActionRenderSurface()));

        QMetaObject::connectSlotsByName(SurfaceEvolverGUI);
    } // setupUi

    void retranslateUi(QMainWindow *SurfaceEvolverGUI)
    {
        SurfaceEvolverGUI->setWindowTitle(QCoreApplication::translate("SurfaceEvolverGUI", "SurfaceEvolverGUI", nullptr));
        actionOpenFile->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Open File...", nullptr));
        actionExit->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Exit", nullptr));
        actionPrint->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Print", nullptr));
        actionHelp->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Help", nullptr));
        ActionOpenFile->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Open", nullptr));
#if QT_CONFIG(shortcut)
        ActionOpenFile->setShortcut(QCoreApplication::translate("SurfaceEvolverGUI", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionSaveFile->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Save", nullptr));
#if QT_CONFIG(shortcut)
        ActionSaveFile->setShortcut(QCoreApplication::translate("SurfaceEvolverGUI", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen_File->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Open File", nullptr));
        actionSave_File->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Save File", nullptr));
        actionDoSomething->setText(QCoreApplication::translate("SurfaceEvolverGUI", "DoSomething", nullptr));
        bgColorButton->setText(QString());
        bgColorLabel->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Background color", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SurfaceEvolverGUI", "Mesh render mode:", nullptr));
        checkBoxVertices->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Vertices", nullptr));
        checkBoxWireframe->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Wireframe", nullptr));
        checkBoxSurface->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Surface", nullptr));
        menuFile->setTitle(QCoreApplication::translate("SurfaceEvolverGUI", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SurfaceEvolverGUI: public Ui_SurfaceEvolverGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURFACEEVOLVERGUI_H
