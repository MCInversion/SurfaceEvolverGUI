/********************************************************************************
** Form generated from reading UI file 'EvolutionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVOLUTIONWIDGET_H
#define UI_EVOLUTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_evolutionWidget
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QLabel *label_18;
    QSpinBox *spinBox_4;
    QLabel *label_24;
    QLabel *label_15;
    QSpinBox *spinBox_3;
    QLabel *label_16;
    QLabel *label_19;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_17;
    QCheckBox *checkBox_2;
    QComboBox *comboBox_2;
    QLabel *label_20;
    QCheckBox *checkBox_9;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QGroupBox *targetObjectGroupBox;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_9;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label_28;
    QLabel *label_29;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QFrame *line_5;
    QFrame *line_2;
    QFrame *line_4;
    QLabel *label_11;
    QLabel *label_26;
    QDoubleSpinBox *doubleSpinBox;
    QFrame *line;
    QLabel *label_12;
    QFrame *line_6;
    QSpinBox *spinBox;
    QLabel *label_13;
    QFrame *line_3;
    QCheckBox *checkBox;
    QLabel *label_14;
    QSpacerItem *verticalSpacer_2;
    QSpinBox *spinBox_2;
    QLabel *label_27;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QGroupBox *groupBox_5;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_22;
    QLabel *label_21;
    QLineEdit *lineEdit;
    QSpinBox *spinBox_5;
    QLabel *label_23;
    QLabel *label_25;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_7;
    QLineEdit *lineEdit_4;
    QLabel *label_30;
    QLabel *label_31;
    QLineEdit *lineEdit_5;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QWidget *evolutionWidget)
    {
        if (evolutionWidget->objectName().isEmpty())
            evolutionWidget->setObjectName(QString::fromUtf8("evolutionWidget"));
        evolutionWidget->resize(844, 893);
        gridLayout_3 = new QGridLayout(evolutionWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(evolutionWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 200));
        groupBox_2->setMaximumSize(QSize(450, 16777215));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_4->addWidget(label_18, 2, 2, 1, 1);

        spinBox_4 = new QSpinBox(groupBox_2);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setValue(2);

        gridLayout_4->addWidget(spinBox_4, 1, 1, 1, 1);

        label_24 = new QLabel(groupBox_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_4->addWidget(label_24, 4, 2, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_4->addWidget(label_15, 0, 1, 1, 1);

        spinBox_3 = new QSpinBox(groupBox_2);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setEnabled(false);
        spinBox_3->setMinimum(40);

        gridLayout_4->addWidget(spinBox_3, 0, 2, 1, 1);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_4->addWidget(label_16, 1, 0, 1, 1);

        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_4->addWidget(label_19, 3, 0, 1, 1);

        comboBox = new QComboBox(groupBox_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_4->addWidget(comboBox, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 6, 0, 1, 1);

        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_4->addWidget(label_17, 2, 0, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setChecked(true);

        gridLayout_4->addWidget(checkBox_2, 4, 0, 1, 1);

        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout_4->addWidget(comboBox_2, 4, 1, 1, 1);

        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_4->addWidget(label_20, 3, 2, 1, 1);

        checkBox_9 = new QCheckBox(groupBox_2);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setEnabled(false);

        gridLayout_4->addWidget(checkBox_9, 5, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_6 = new QGroupBox(evolutionWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setMinimumSize(QSize(0, 150));
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        checkBox_3 = new QCheckBox(groupBox_6);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setChecked(true);

        gridLayout_6->addWidget(checkBox_3, 0, 0, 1, 1);

        checkBox_4 = new QCheckBox(groupBox_6);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout_6->addWidget(checkBox_4, 0, 1, 1, 1);

        checkBox_5 = new QCheckBox(groupBox_6);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setChecked(true);

        gridLayout_6->addWidget(checkBox_5, 1, 0, 1, 1);

        checkBox_6 = new QCheckBox(groupBox_6);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));

        gridLayout_6->addWidget(checkBox_6, 2, 0, 1, 1);

        checkBox_7 = new QCheckBox(groupBox_6);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));

        gridLayout_6->addWidget(checkBox_7, 1, 1, 1, 1);

        checkBox_8 = new QCheckBox(groupBox_6);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));

        gridLayout_6->addWidget(checkBox_8, 2, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_6, 3, 0, 1, 1);

        targetObjectGroupBox = new QGroupBox(evolutionWidget);
        targetObjectGroupBox->setObjectName(QString::fromUtf8("targetObjectGroupBox"));
        targetObjectGroupBox->setMinimumSize(QSize(0, 200));
        gridLayout = new QGridLayout(targetObjectGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(targetObjectGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_3 = new QLabel(targetObjectGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label = new QLabel(targetObjectGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_9 = new QLabel(targetObjectGroupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 1);

        label_4 = new QLabel(targetObjectGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        label_8 = new QLabel(targetObjectGroupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        label_2 = new QLabel(targetObjectGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_7 = new QLabel(targetObjectGroupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        label_10 = new QLabel(targetObjectGroupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 4, 1, 1, 1);

        label_6 = new QLabel(targetObjectGroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 1, 1, 1);

        label_28 = new QLabel(targetObjectGroupBox);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout->addWidget(label_28, 5, 0, 1, 1);

        label_29 = new QLabel(targetObjectGroupBox);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout->addWidget(label_29, 5, 1, 1, 1);


        gridLayout_3->addWidget(targetObjectGroupBox, 0, 0, 1, 1);

        groupBox = new QGroupBox(evolutionWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(320, 250));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        line_5 = new QFrame(groupBox);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_5, 6, 0, 1, 1);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 2, 1, 1, 1);

        line_4 = new QFrame(groupBox);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_4, 4, 1, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 0, 0, 1, 1);

        label_26 = new QLabel(groupBox);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_2->addWidget(label_26, 7, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMinimum(0.100000000000000);
        doubleSpinBox->setMaximum(10.000000000000000);
        doubleSpinBox->setSingleStep(0.100000000000000);
        doubleSpinBox->setValue(1.000000000000000);

        gridLayout_2->addWidget(doubleSpinBox, 1, 1, 1, 1);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 2, 0, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 1, 0, 1, 1);

        line_6 = new QFrame(groupBox);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_6, 6, 1, 1, 1);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(5);
        spinBox->setMaximum(200);
        spinBox->setValue(30);

        gridLayout_2->addWidget(spinBox, 0, 1, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 3, 0, 1, 1);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 4, 0, 1, 1);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);

        gridLayout_2->addWidget(checkBox, 5, 1, 1, 1);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 5, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 9, 0, 1, 1);

        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(8);
        spinBox_2->setValue(8);

        gridLayout_2->addWidget(spinBox_2, 3, 1, 1, 1);

        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_2->addWidget(label_27, 8, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(lineEdit_2, 7, 1, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(lineEdit_3, 8, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_5 = new QGroupBox(evolutionWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));

        gridLayout_3->addWidget(groupBox_5, 2, 1, 1, 1);

        groupBox_3 = new QGroupBox(evolutionWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(300, 16777215));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_4, 3, 0, 1, 1);

        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_5->addWidget(label_22, 0, 0, 1, 1);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_5->addWidget(label_21, 1, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaximumSize(QSize(100, 16777215));

        gridLayout_5->addWidget(lineEdit, 0, 1, 1, 1);

        spinBox_5 = new QSpinBox(groupBox_3);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setMinimum(1);
        spinBox_5->setMaximum(2000);
        spinBox_5->setValue(50);

        gridLayout_5->addWidget(spinBox_5, 1, 1, 1, 1);

        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_5->addWidget(label_23, 2, 0, 1, 1);

        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_5->addWidget(label_25, 2, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        pushButton = new QPushButton(evolutionWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout_3->addLayout(verticalLayout, 3, 1, 1, 1);

        groupBox_4 = new QGroupBox(evolutionWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(0, 250));
        gridLayout_7 = new QGridLayout(groupBox_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        lineEdit_4 = new QLineEdit(groupBox_4);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setMaximumSize(QSize(100, 16777215));

        gridLayout_7->addWidget(lineEdit_4, 0, 1, 1, 1);

        label_30 = new QLabel(groupBox_4);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_7->addWidget(label_30, 0, 0, 1, 1);

        label_31 = new QLabel(groupBox_4);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_7->addWidget(label_31, 1, 0, 1, 1);

        lineEdit_5 = new QLineEdit(groupBox_4);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setMaximumSize(QSize(100, 16777215));

        gridLayout_7->addWidget(lineEdit_5, 1, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_6, 2, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_4, 2, 0, 1, 1);


        retranslateUi(evolutionWidget);

        QMetaObject::connectSlotsByName(evolutionWidget);
    } // setupUi

    void retranslateUi(QWidget *evolutionWidget)
    {
        evolutionWidget->setWindowTitle(QCoreApplication::translate("evolutionWidget", "Surface Evolution", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("evolutionWidget", "Initial surface:", nullptr));
        label_18->setText(QCoreApplication::translate("evolutionWidget", "162", nullptr));
#if QT_CONFIG(tooltip)
        spinBox_4->setToolTip(QCoreApplication::translate("evolutionWidget", "surface subdivision detail for IcoSphere and CubeSphere. Note that IcoSphere detail is recursive (exponential) while CubeSphere is linear.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        label_24->setToolTip(QCoreApplication::translate("evolutionWidget", "mesh element type for IcoSphere and CubeSphere", nullptr));
#endif // QT_CONFIG(tooltip)
        label_24->setText(QCoreApplication::translate("evolutionWidget", "(surface elems)", nullptr));
#if QT_CONFIG(tooltip)
        label_15->setToolTip(QCoreApplication::translate("evolutionWidget", "a percentage of an offset from SDF's zero level for inward evolution through Marching cubes iso contour.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_15->setText(QCoreApplication::translate("evolutionWidget", "contour offset dist %:", nullptr));
#if QT_CONFIG(tooltip)
        spinBox_3->setToolTip(QCoreApplication::translate("evolutionWidget", "a percentage of an offset from SDF's zero level for inward evolution through Marching cubes iso contour.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        label_16->setToolTip(QCoreApplication::translate("evolutionWidget", "surface subdivision detail for IcoSphere and CubeSphere. Note that IcoSphere detail is recursive (exponential) while CubeSphere is linear.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_16->setText(QCoreApplication::translate("evolutionWidget", "surface detail:", nullptr));
        label_19->setText(QCoreApplication::translate("evolutionWidget", "NPolys:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("evolutionWidget", "IcoSphere", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("evolutionWidget", "CubeSphere", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("evolutionWidget", "Marching cubes contour", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("evolutionWidget", "Choose from file", nullptr));

        label_17->setText(QCoreApplication::translate("evolutionWidget", "NVerts:", nullptr));
        checkBox_2->setText(QCoreApplication::translate("evolutionWidget", "show wireframe outline", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("evolutionWidget", "triangles", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("evolutionWidget", "quads", nullptr));

#if QT_CONFIG(tooltip)
        comboBox_2->setToolTip(QCoreApplication::translate("evolutionWidget", "mesh element type for IcoSphere and CubeSphere", nullptr));
#endif // QT_CONFIG(tooltip)
        label_20->setText(QCoreApplication::translate("evolutionWidget", "320", nullptr));
        checkBox_9->setText(QCoreApplication::translate("evolutionWidget", "fixed Dirichlet", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("evolutionWidget", "Output:", nullptr));
#if QT_CONFIG(tooltip)
        checkBox_3->setToolTip(QCoreApplication::translate("evolutionWidget", "store time states as a library object", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBox_3->setText(QCoreApplication::translate("evolutionWidget", "store time states", nullptr));
#if QT_CONFIG(tooltip)
        checkBox_4->setToolTip(QCoreApplication::translate("evolutionWidget", "automatically save time states as VTK polydata", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBox_4->setText(QCoreApplication::translate("evolutionWidget", "save time states to .vtk", nullptr));
#if QT_CONFIG(tooltip)
        checkBox_5->setToolTip(QCoreApplication::translate("evolutionWidget", "store and save unsmoothed evolution result from before applying final smoothing", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBox_5->setText(QCoreApplication::translate("evolutionWidget", "store and save (unsmoothed) result", nullptr));
#if QT_CONFIG(tooltip)
        checkBox_6->setToolTip(QCoreApplication::translate("evolutionWidget", "generic log contains time step information as well as general evolution properties", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBox_6->setText(QCoreApplication::translate("evolutionWidget", "save generic log", nullptr));
#if QT_CONFIG(tooltip)
        checkBox_7->setToolTip(QCoreApplication::translate("evolutionWidget", "automatically save results as VTK polydata", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBox_7->setText(QCoreApplication::translate("evolutionWidget", "save result to .vtk", nullptr));
#if QT_CONFIG(tooltip)
        checkBox_8->setToolTip(QCoreApplication::translate("evolutionWidget", "time log stores computation times for individual processes", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBox_8->setText(QCoreApplication::translate("evolutionWidget", "save time log", nullptr));
        targetObjectGroupBox->setTitle(QCoreApplication::translate("evolutionWidget", "Mesh object properties:", nullptr));
        label_5->setText(QCoreApplication::translate("evolutionWidget", "polygon count:", nullptr));
        label_3->setText(QCoreApplication::translate("evolutionWidget", "triangle count:", nullptr));
        label->setText(QCoreApplication::translate("evolutionWidget", "vertices count:", nullptr));
        label_9->setText(QCoreApplication::translate("evolutionWidget", "(0, 0, 0)", nullptr));
        label_4->setText(QCoreApplication::translate("evolutionWidget", "0", nullptr));
        label_8->setText(QCoreApplication::translate("evolutionWidget", "bounding box max:", nullptr));
        label_2->setText(QCoreApplication::translate("evolutionWidget", "0", nullptr));
        label_7->setText(QCoreApplication::translate("evolutionWidget", "bounding box min:", nullptr));
        label_10->setText(QCoreApplication::translate("evolutionWidget", "(0, 0, 0)", nullptr));
        label_6->setText(QCoreApplication::translate("evolutionWidget", "0", nullptr));
        label_28->setText(QCoreApplication::translate("evolutionWidget", "open surface?", nullptr));
        label_29->setText(QCoreApplication::translate("evolutionWidget", "N/A", nullptr));
        groupBox->setTitle(QCoreApplication::translate("evolutionWidget", "Signed distance function (SDF) parameters:", nullptr));
#if QT_CONFIG(tooltip)
        label_11->setToolTip(QCoreApplication::translate("evolutionWidget", "grid cell count for geometry's bounding cube for octree construction", nullptr));
#endif // QT_CONFIG(tooltip)
        label_11->setText(QCoreApplication::translate("evolutionWidget", "octree resolution:", nullptr));
#if QT_CONFIG(tooltip)
        label_26->setToolTip(QCoreApplication::translate("evolutionWidget", "this constant weighs a control function which affects the surface advection rate given by the gradient field of SDF", nullptr));
#endif // QT_CONFIG(tooltip)
        label_26->setText(QCoreApplication::translate("evolutionWidget", "overall weight constant:", nullptr));
#if QT_CONFIG(tooltip)
        doubleSpinBox->setToolTip(QCoreApplication::translate("evolutionWidget", "a factor by which the geometry's bounding box gets expanded to extend the distance function domain", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        label_12->setToolTip(QCoreApplication::translate("evolutionWidget", "a factor by which the geometry's bounding box gets expanded to extend the distance function domain", nullptr));
#endif // QT_CONFIG(tooltip)
        label_12->setText(QCoreApplication::translate("evolutionWidget", "grid expansion factor:", nullptr));
#if QT_CONFIG(tooltip)
        spinBox->setToolTip(QCoreApplication::translate("evolutionWidget", "grid cell count for geometry's bounding cube for octree construction", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        label_13->setToolTip(QCoreApplication::translate("evolutionWidget", "Number of iterations for fast sweeping algorithm. At least 4 sweeps required to produce decent results.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_13->setText(QCoreApplication::translate("evolutionWidget", "NSweeps (Fast Sweeping):", nullptr));
#if QT_CONFIG(tooltip)
        checkBox->setToolTip(QCoreApplication::translate("evolutionWidget", "compute sign of distance function (negative for interior grid cells). Only works for closed mesh surfaces.", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBox->setText(QCoreApplication::translate("evolutionWidget", "compute sign", nullptr));
        label_14->setText(QString());
#if QT_CONFIG(tooltip)
        spinBox_2->setToolTip(QCoreApplication::translate("evolutionWidget", "Number of iterations for fast sweeping algorithm. At least 4 sweeps required to produce decent results.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        label_27->setToolTip(QCoreApplication::translate("evolutionWidget", "this constant weighs the projection of the negative gradient of SDF onto the tangential plane of the surface.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_27->setText(QCoreApplication::translate("evolutionWidget", "grad(SDF) projection weight:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_2->setToolTip(QCoreApplication::translate("evolutionWidget", "this constant weighs a control function which affects the surface advection rate given by the gradient field of SDF", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_2->setText(QCoreApplication::translate("evolutionWidget", "1.0", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_3->setToolTip(QCoreApplication::translate("evolutionWidget", "this constant weighs the projection of the negative gradient of SDF onto the tangential plane of the surface.", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_3->setText(QCoreApplication::translate("evolutionWidget", "0.0", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("evolutionWidget", "Tangential redistribution (TR) parameters:", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("evolutionWidget", "Evolution properties:", nullptr));
#if QT_CONFIG(tooltip)
        label_22->setToolTip(QCoreApplication::translate("evolutionWidget", "evolution time step (double)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_22->setText(QCoreApplication::translate("evolutionWidget", "dt:", nullptr));
#if QT_CONFIG(tooltip)
        label_21->setToolTip(QCoreApplication::translate("evolutionWidget", "number of evolution steps (uint)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_21->setText(QCoreApplication::translate("evolutionWidget", "NSteps:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit->setToolTip(QCoreApplication::translate("evolutionWidget", "evolution time step (double)", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit->setText(QCoreApplication::translate("evolutionWidget", "0.03", nullptr));
#if QT_CONFIG(tooltip)
        spinBox_5->setToolTip(QCoreApplication::translate("evolutionWidget", "number of evolution steps (uint)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        label_23->setToolTip(QCoreApplication::translate("evolutionWidget", "stopping time for evolution (double)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_23->setText(QCoreApplication::translate("evolutionWidget", "tStop:", nullptr));
#if QT_CONFIG(tooltip)
        label_25->setToolTip(QCoreApplication::translate("evolutionWidget", "stopping time for evolution (double)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_25->setText(QCoreApplication::translate("evolutionWidget", "1.5", nullptr));
        pushButton->setText(QCoreApplication::translate("evolutionWidget", "Evolve", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("evolutionWidget", "Mean curvature flow (MCF) parameters:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_4->setToolTip(QCoreApplication::translate("evolutionWidget", "a constant that weighs a control function which affects the mean curvature operator of the evolving surface. Setting to zero disables mean curvature effect", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_4->setText(QCoreApplication::translate("evolutionWidget", "1.0", nullptr));
#if QT_CONFIG(tooltip)
        label_30->setToolTip(QCoreApplication::translate("evolutionWidget", "a constant that weighs a control function which affects the mean curvature operator of the evolving surface. Setting to zero disables mean curvature effect", nullptr));
#endif // QT_CONFIG(tooltip)
        label_30->setText(QCoreApplication::translate("evolutionWidget", "overall weight constant:", nullptr));
#if QT_CONFIG(tooltip)
        label_31->setToolTip(QCoreApplication::translate("evolutionWidget", "a decay radius for exponential weight function on mean curvature operator. Lable \"automatic\" takes the 80% of the object's bounding box radius.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_31->setText(QCoreApplication::translate("evolutionWidget", "exponential decay radius:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_5->setToolTip(QCoreApplication::translate("evolutionWidget", "a decay radius for exponential weight function on mean curvature operator. Lable \"automatic\" takes the 80% of the object's bounding box radius.", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_5->setText(QCoreApplication::translate("evolutionWidget", "automatic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class evolutionWidget: public Ui_evolutionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVOLUTIONWIDGET_H
