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
    QAction *actionExit;
    QAction *actionPrint;
    QAction *actionHelp;
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QVTKOpenGLNativeWidget *qvtkWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *bgColorButton;
    QLabel *bgColorLabel;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
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
        SurfaceEvolverGUI->resize(991, 641);
        SurfaceEvolverGUI->setMaximumSize(QSize(16777213, 16777215));
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
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);

        // bg color button
        QPixmap pixmap(100, 100);
        pixmap.fill(QColor("black"));
        QIcon bgIcon(pixmap);
        bgColorButton = new QToolButton(centralwidget);
        bgColorButton->setIcon(bgIcon);
        bgColorButton->setObjectName(QString::fromUtf8("bgColorButton"));

        horizontalLayout_2->addWidget(bgColorButton);

        bgColorLabel = new QLabel(centralwidget);
        bgColorLabel->setObjectName(QString::fromUtf8("bgColorLabel"));

        horizontalLayout_2->addWidget(bgColorLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 110));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 20, 90, 76));
        verticalLayout_3 = new QVBoxLayout(horizontalLayoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        checkBoxVertices = new QCheckBox(horizontalLayoutWidget);
        checkBoxVertices->setObjectName(QString::fromUtf8("checkBoxVertices"));

        verticalLayout_3->addWidget(checkBoxVertices);

        checkBoxWireframe = new QCheckBox(horizontalLayoutWidget);
        checkBoxWireframe->setObjectName(QString::fromUtf8("checkBoxWireframe"));
        checkBoxWireframe->setChecked(true);

        verticalLayout_3->addWidget(checkBoxWireframe);

        checkBoxSurface = new QCheckBox(horizontalLayoutWidget);
        checkBoxSurface->setObjectName(QString::fromUtf8("checkBoxSurface"));
        checkBoxSurface->setChecked(true);

        verticalLayout_3->addWidget(checkBoxSurface);


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
        menuBar->setGeometry(QRect(0, 0, 991, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        SurfaceEvolverGUI->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);

        retranslateUi(SurfaceEvolverGUI);
        // file ctrls
        QObject::connect(actionOpen, SIGNAL(triggered()), SurfaceEvolverGUI, SLOT(ActionOpenFile()));
        QObject::connect(actionSave, SIGNAL(triggered()), SurfaceEvolverGUI, SLOT(ActionSaveFile()));

        // render ctrls
        QObject::connect(bgColorButton, SIGNAL(clicked()), SurfaceEvolverGUI, SLOT(ActionRendererBackgroundColor()));
        QObject::connect(checkBoxVertices, SIGNAL(clicked(bool)), SurfaceEvolverGUI, SLOT(ActionRenderVertices()));
        QObject::connect(checkBoxWireframe, SIGNAL(clicked(bool)), SurfaceEvolverGUI, SLOT(ActionRenderWireframe()));
        QObject::connect(checkBoxSurface, SIGNAL(clicked(bool)), SurfaceEvolverGUI, SLOT(ActionRenderSurface()));

        QMetaObject::connectSlotsByName(SurfaceEvolverGUI);
    } // setupUi

    void retranslateUi(QMainWindow *SurfaceEvolverGUI)
    {
        SurfaceEvolverGUI->setWindowTitle(QCoreApplication::translate("SurfaceEvolverGUI", "SurfaceEvolverGUI", nullptr));
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
        bgColorButton->setText(QString());
        bgColorLabel->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Background color", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SurfaceEvolverGUI", "Render mode:", nullptr));
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
