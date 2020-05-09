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
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
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
    QAction *actionSigned_Distance_Function;
    QAction *actionSurface_Evolution;
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
    QGridLayout *gridLayout_2;
    QToolButton *surfaceColorButton;
    QLabel *vertexLabel;
    QLabel *edgeLabel;
    QLabel *surfaceLabel;
    QToolButton *vertexColorButton;
    QToolButton *edgeColorButton;
    QLabel *opacityLabel;
    QDoubleSpinBox *opacitySpinBox;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QListWidget *libraryListWidget;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *deleteButton;
    QToolButton *clearButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTools;

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
        actionSigned_Distance_Function = new QAction(SurfaceEvolverGUI);
        actionSigned_Distance_Function->setObjectName(QString::fromUtf8("actionSigned_Distance_Function"));
        actionSurface_Evolution = new QAction(SurfaceEvolverGUI);
        actionSurface_Evolution->setObjectName(QString::fromUtf8("actionSurface_Evolution"));
        centralwidget = new QWidget(SurfaceEvolverGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
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

        horizontalLayout_2->addWidget(bgColorButton);

        bgColorLabel = new QLabel(centralwidget);
        bgColorLabel->setObjectName(QString::fromUtf8("bgColorLabel"));

        horizontalLayout_2->addWidget(bgColorLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 170));
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

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        surfaceColorButton = new QToolButton(groupBox);
        surfaceColorButton->setObjectName(QString::fromUtf8("surfaceColorButton"));

        gridLayout_2->addWidget(surfaceColorButton, 2, 1, 1, 1);

        vertexLabel = new QLabel(groupBox);
        vertexLabel->setObjectName(QString::fromUtf8("vertexLabel"));

        gridLayout_2->addWidget(vertexLabel, 0, 0, 1, 1);

        edgeLabel = new QLabel(groupBox);
        edgeLabel->setObjectName(QString::fromUtf8("edgeLabel"));

        gridLayout_2->addWidget(edgeLabel, 1, 0, 1, 1);

        surfaceLabel = new QLabel(groupBox);
        surfaceLabel->setObjectName(QString::fromUtf8("surfaceLabel"));

        gridLayout_2->addWidget(surfaceLabel, 2, 0, 1, 1);

        vertexColorButton = new QToolButton(groupBox);
        vertexColorButton->setObjectName(QString::fromUtf8("vertexColorButton"));

        gridLayout_2->addWidget(vertexColorButton, 0, 1, 1, 1);

        edgeColorButton = new QToolButton(groupBox);
        edgeColorButton->setObjectName(QString::fromUtf8("edgeColorButton"));

        gridLayout_2->addWidget(edgeColorButton, 1, 1, 1, 1);

        opacityLabel = new QLabel(groupBox);
        opacityLabel->setObjectName(QString::fromUtf8("opacityLabel"));

        gridLayout_2->addWidget(opacityLabel, 3, 0, 1, 1);

        opacitySpinBox = new QDoubleSpinBox(groupBox);
        opacitySpinBox->setObjectName(QString::fromUtf8("opacitySpinBox"));
        opacitySpinBox->setMaximum(1.000000000000000);
        opacitySpinBox->setSingleStep(0.010000000000000);
        opacitySpinBox->setValue(1.000000000000000);

        gridLayout_2->addWidget(opacitySpinBox, 3, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(300, 16777215));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        libraryListWidget = new QListWidget(groupBox_2);
        libraryListWidget->setObjectName(QString::fromUtf8("libraryListWidget"));
        libraryListWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        libraryListWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        libraryListWidget->setMovement(QListView::Static);
        libraryListWidget->setSelectionRectVisible(true);

        verticalLayout_5->addWidget(libraryListWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        deleteButton = new QToolButton(groupBox_2);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../trash.ico"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon);

        horizontalLayout_3->addWidget(deleteButton);

        clearButton = new QToolButton(groupBox_2);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../resources/clear.ico"), QSize(), QIcon::Normal, QIcon::Off);
        clearButton->setIcon(icon1);

        horizontalLayout_3->addWidget(clearButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_4->addWidget(groupBox_2);


        verticalLayout->addLayout(verticalLayout_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        SurfaceEvolverGUI->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(SurfaceEvolverGUI);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1185, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        SurfaceEvolverGUI->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuFile->addAction(actionOpen_File);
        menuFile->addAction(actionSave_File);
        menuTools->addAction(actionSigned_Distance_Function);
        menuTools->addAction(actionSurface_Evolution);

        retranslateUi(SurfaceEvolverGUI);
        QObject::connect(bgColorButton, SIGNAL(clicked()), SurfaceEvolverGUI, SLOT(ActionRendererBackgroundColor()));
        QObject::connect(checkBoxVertices, SIGNAL(clicked(bool)), SurfaceEvolverGUI, SLOT(ActionRenderVertices()));
        QObject::connect(checkBoxWireframe, SIGNAL(clicked(bool)), SurfaceEvolverGUI, SLOT(ActionRenderWireframe()));
        QObject::connect(checkBoxSurface, SIGNAL(clicked(bool)), SurfaceEvolverGUI, SLOT(ActionRenderSurface()));
        QObject::connect(vertexColorButton, SIGNAL(clicked()), SurfaceEvolverGUI, SLOT(ActionVertexColor()));
        QObject::connect(edgeColorButton, SIGNAL(clicked()), SurfaceEvolverGUI, SLOT(ActionEdgeColor()));
        QObject::connect(surfaceColorButton, SIGNAL(clicked()), SurfaceEvolverGUI, SLOT(ActionSurfaceColor()));
        QObject::connect(opacitySpinBox, SIGNAL(valueChanged(double)), SurfaceEvolverGUI, SLOT(ActionOpacity()));
        QObject::connect(libraryListWidget, SIGNAL(currentRowChanged(int)), SurfaceEvolverGUI, SLOT(ActionSelectLibraryObject()));
        QObject::connect(deleteButton, SIGNAL(clicked()), SurfaceEvolverGUI, SLOT(ActionRemoveSelectedObjects()));
        QObject::connect(clearButton, SIGNAL(clicked()), SurfaceEvolverGUI, SLOT(ActionClearAllObjects()));

        QMetaObject::connectSlotsByName(SurfaceEvolverGUI);
    } // setupUi

    void retranslateUi(QMainWindow *SurfaceEvolverGUI)
    {
        SurfaceEvolverGUI->setWindowTitle(QCoreApplication::translate("SurfaceEvolverGUI", "SurfaceEvolverGUI", nullptr));
#if QT_CONFIG(tooltip)
        SurfaceEvolverGUI->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
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
        actionSigned_Distance_Function->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Signed Distance Function", nullptr));
        actionSurface_Evolution->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Surface Evolution", nullptr));
        bgColorButton->setText(QString());
        bgColorLabel->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Background color", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SurfaceEvolverGUI", "Mesh render:", nullptr));
        checkBoxVertices->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Vertices", nullptr));
        checkBoxWireframe->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Wireframe", nullptr));
        checkBoxSurface->setText(QCoreApplication::translate("SurfaceEvolverGUI", "Surface", nullptr));
        surfaceColorButton->setText(QString());
        vertexLabel->setText(QCoreApplication::translate("SurfaceEvolverGUI", "vertex color:", nullptr));
        edgeLabel->setText(QCoreApplication::translate("SurfaceEvolverGUI", "edge color:", nullptr));
        surfaceLabel->setText(QCoreApplication::translate("SurfaceEvolverGUI", "surface color:", nullptr));
        vertexColorButton->setText(QString());
        edgeColorButton->setText(QString());
        opacityLabel->setText(QCoreApplication::translate("SurfaceEvolverGUI", "opacity:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SurfaceEvolverGUI", "Scene objects:", nullptr));
#if QT_CONFIG(tooltip)
        deleteButton->setToolTip(QCoreApplication::translate("SurfaceEvolverGUI", "Remove Selected", nullptr));
#endif // QT_CONFIG(tooltip)
        deleteButton->setText(QString());
#if QT_CONFIG(tooltip)
        clearButton->setToolTip(QCoreApplication::translate("SurfaceEvolverGUI", "Clear All", nullptr));
#endif // QT_CONFIG(tooltip)
        clearButton->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("SurfaceEvolverGUI", "File", nullptr));
        menuTools->setTitle(QCoreApplication::translate("SurfaceEvolverGUI", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SurfaceEvolverGUI: public Ui_SurfaceEvolverGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURFACEEVOLVERGUI_H