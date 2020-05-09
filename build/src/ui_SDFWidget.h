/********************************************************************************
** Form generated from reading UI file 'SDFWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SDFWIDGET_H
#define UI_SDFWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sdfWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *line;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QSpinBox *spinBox;
    QSpacerItem *verticalSpacer_3;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QGroupBox *meshStatsBox;
    QGridLayout *gridLayout_2;
    QLabel *triCountLabel;
    QLabel *triangleCount;
    QLabel *vertCountLabel;
    QLabel *verticesCount;
    QLabel *polyCountLabel;
    QLabel *label_4;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *polygonCount;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *line_2;
    QGroupBox *fastSweepParams;
    QGridLayout *gridLayout_5;
    QLabel *NsweepsLabel;
    QSpinBox *nSweepsSpinBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QCheckBox *comuteSignCheckBox;

    void setupUi(QWidget *sdfWidget)
    {
        if (sdfWidget->objectName().isEmpty())
            sdfWidget->setObjectName(QString::fromUtf8("sdfWidget"));
        sdfWidget->resize(604, 499);
        gridLayout = new QGridLayout(sdfWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        line = new QFrame(sdfWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(sdfWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(5);
        spinBox->setMaximum(1000);
        spinBox->setValue(40);

        gridLayout_3->addWidget(spinBox, 0, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 3, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMinimum(0.100000000000000);
        doubleSpinBox->setMaximum(10.000000000000000);
        doubleSpinBox->setSingleStep(0.100000000000000);
        doubleSpinBox->setValue(1.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 2, 0, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox_2, 2, 1, 1, 1);

        label = new QLabel(sdfWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(sdfWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        meshStatsBox = new QGroupBox(sdfWidget);
        meshStatsBox->setObjectName(QString::fromUtf8("meshStatsBox"));
        meshStatsBox->setMinimumSize(QSize(0, 200));
        gridLayout_2 = new QGridLayout(meshStatsBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        triCountLabel = new QLabel(meshStatsBox);
        triCountLabel->setObjectName(QString::fromUtf8("triCountLabel"));

        gridLayout_2->addWidget(triCountLabel, 1, 0, 1, 1);

        triangleCount = new QLabel(meshStatsBox);
        triangleCount->setObjectName(QString::fromUtf8("triangleCount"));

        gridLayout_2->addWidget(triangleCount, 1, 1, 1, 1);

        vertCountLabel = new QLabel(meshStatsBox);
        vertCountLabel->setObjectName(QString::fromUtf8("vertCountLabel"));

        gridLayout_2->addWidget(vertCountLabel, 0, 0, 1, 1);

        verticesCount = new QLabel(meshStatsBox);
        verticesCount->setObjectName(QString::fromUtf8("verticesCount"));

        gridLayout_2->addWidget(verticesCount, 0, 1, 1, 1);

        polyCountLabel = new QLabel(meshStatsBox);
        polyCountLabel->setObjectName(QString::fromUtf8("polyCountLabel"));

        gridLayout_2->addWidget(polyCountLabel, 2, 0, 1, 1);

        label_4 = new QLabel(meshStatsBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 1, 1, 1);

        label_3 = new QLabel(meshStatsBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 5, 0, 1, 1);

        polygonCount = new QLabel(meshStatsBox);
        polygonCount->setObjectName(QString::fromUtf8("polygonCount"));

        gridLayout_2->addWidget(polygonCount, 2, 1, 1, 1);

        label_6 = new QLabel(meshStatsBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 4, 0, 1, 1);

        label_7 = new QLabel(meshStatsBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 4, 1, 1, 1);


        gridLayout->addWidget(meshStatsBox, 2, 0, 1, 1);

        line_2 = new QFrame(sdfWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 1, 1, 1, 1);

        fastSweepParams = new QGroupBox(sdfWidget);
        fastSweepParams->setObjectName(QString::fromUtf8("fastSweepParams"));
        fastSweepParams->setMinimumSize(QSize(0, 50));
        gridLayout_5 = new QGridLayout(fastSweepParams);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        NsweepsLabel = new QLabel(fastSweepParams);
        NsweepsLabel->setObjectName(QString::fromUtf8("NsweepsLabel"));

        gridLayout_5->addWidget(NsweepsLabel, 0, 0, 1, 1);

        nSweepsSpinBox = new QSpinBox(fastSweepParams);
        nSweepsSpinBox->setObjectName(QString::fromUtf8("nSweepsSpinBox"));
        nSweepsSpinBox->setMinimum(1);
        nSweepsSpinBox->setMaximum(8);
        nSweepsSpinBox->setValue(8);

        gridLayout_5->addWidget(nSweepsSpinBox, 0, 1, 1, 1);


        gridLayout->addWidget(fastSweepParams, 3, 0, 1, 1);

        groupBox = new QGroupBox(sdfWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        comuteSignCheckBox = new QCheckBox(groupBox);
        comuteSignCheckBox->setObjectName(QString::fromUtf8("comuteSignCheckBox"));
        comuteSignCheckBox->setChecked(true);

        gridLayout_4->addWidget(comuteSignCheckBox, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 3, 1, 1, 1);


        retranslateUi(sdfWidget);

        QMetaObject::connectSlotsByName(sdfWidget);
    } // setupUi

    void retranslateUi(QWidget *sdfWidget)
    {
        sdfWidget->setWindowTitle(QCoreApplication::translate("sdfWidget", "Signed Distance Function (SDF)", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("sdfWidget", "Grid parameters:", nullptr));
#if QT_CONFIG(tooltip)
        label_5->setToolTip(QCoreApplication::translate("sdfWidget", "grid cell count for geometry's bounding cube for octree construction", nullptr));
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("sdfWidget", "octree resolution:", nullptr));
#if QT_CONFIG(tooltip)
        spinBox->setToolTip(QCoreApplication::translate("sdfWidget", "grid cell count for geometry's bounding cube for octree construction", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        doubleSpinBox->setToolTip(QCoreApplication::translate("sdfWidget", "a factor by which the geometry's bounding box gets expanded to extend the distance function domain", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        label_8->setToolTip(QCoreApplication::translate("sdfWidget", "a factor by which the geometry's bounding box gets expanded to extend the distance function domain", nullptr));
#endif // QT_CONFIG(tooltip)
        label_8->setText(QCoreApplication::translate("sdfWidget", "grid expansion factor:", nullptr));
        label_9->setText(QCoreApplication::translate("sdfWidget", "total grid resolution:", nullptr));
        label_10->setText(QCoreApplication::translate("sdfWidget", "80 x 80 x 80", nullptr));
        label->setText(QCoreApplication::translate("sdfWidget", "target object:", nullptr));
        label_2->setText(QCoreApplication::translate("sdfWidget", "---", nullptr));
        meshStatsBox->setTitle(QCoreApplication::translate("sdfWidget", "Mesh stats:", nullptr));
        triCountLabel->setText(QCoreApplication::translate("sdfWidget", "triangle count:", nullptr));
        triangleCount->setText(QCoreApplication::translate("sdfWidget", "0", nullptr));
        vertCountLabel->setText(QCoreApplication::translate("sdfWidget", "vertices count:", nullptr));
        verticesCount->setText(QCoreApplication::translate("sdfWidget", "0", nullptr));
        polyCountLabel->setText(QCoreApplication::translate("sdfWidget", "polygon count:", nullptr));
        label_4->setText(QCoreApplication::translate("sdfWidget", "(0, 0, 0)", nullptr));
        label_3->setText(QCoreApplication::translate("sdfWidget", "bounding box min:", nullptr));
        polygonCount->setText(QCoreApplication::translate("sdfWidget", "0", nullptr));
        label_6->setText(QCoreApplication::translate("sdfWidget", "bounding box max:", nullptr));
        label_7->setText(QCoreApplication::translate("sdfWidget", "(0, 0, 0)", nullptr));
        fastSweepParams->setTitle(QCoreApplication::translate("sdfWidget", "Fast-Sweep parameters:", nullptr));
#if QT_CONFIG(tooltip)
        NsweepsLabel->setToolTip(QCoreApplication::translate("sdfWidget", "Number of iterations for fast sweeping algorithm. At least 4 sweeps required to produce decent results.", nullptr));
#endif // QT_CONFIG(tooltip)
        NsweepsLabel->setText(QCoreApplication::translate("sdfWidget", "NSweeps:", nullptr));
#if QT_CONFIG(tooltip)
        nSweepsSpinBox->setToolTip(QCoreApplication::translate("sdfWidget", "Number of iterations for fast sweeping algorithm. At least 4 sweeps required to produce decent results.", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox->setTitle(QCoreApplication::translate("sdfWidget", "SDF parameters:", nullptr));
#if QT_CONFIG(tooltip)
        comuteSignCheckBox->setToolTip(QCoreApplication::translate("sdfWidget", "compute sign of distance function (negative for interior grid cells). Only works for closed mesh surfaces.", nullptr));
#endif // QT_CONFIG(tooltip)
        comuteSignCheckBox->setText(QCoreApplication::translate("sdfWidget", "compute sign", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sdfWidget: public Ui_sdfWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SDFWIDGET_H
