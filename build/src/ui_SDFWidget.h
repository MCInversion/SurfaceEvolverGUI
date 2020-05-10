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
#include <QtWidgets/QPushButton>
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
    QSpinBox *octreeResolutionSpinBox;
    QSpacerItem *verticalSpacer_3;
    QDoubleSpinBox *offsetFactorSpinBox;
    QLabel *label_8;
    QGroupBox *fastSweepParams;
    QGridLayout *gridLayout_5;
    QLabel *NsweepsLabel;
    QSpinBox *nSweepsSpinBox;
    QLabel *targetObjectLabel;
    QLabel *objectName;
    QSpacerItem *verticalSpacer;
    QGroupBox *meshStatsBox;
    QGridLayout *gridLayout_2;
    QLabel *triCountLabel;
    QLabel *triangleCount;
    QLabel *vertCountLabel;
    QLabel *verticesCount;
    QLabel *polyCountLabel;
    QLabel *bboxMin;
    QLabel *bboxMinLabel;
    QSpacerItem *verticalSpacer_2;
    QLabel *polygonCount;
    QLabel *bboxMaxLabel;
    QLabel *bboxMax;
    QFrame *line_2;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QCheckBox *comuteSignCheckBox;
    QPushButton *computeButton;

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

        octreeResolutionSpinBox = new QSpinBox(groupBox_2);
        octreeResolutionSpinBox->setObjectName(QString::fromUtf8("octreeResolutionSpinBox"));
        octreeResolutionSpinBox->setMinimum(5);
        octreeResolutionSpinBox->setMaximum(1000);
        octreeResolutionSpinBox->setValue(20);

        gridLayout_3->addWidget(octreeResolutionSpinBox, 0, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 2, 0, 1, 1);

        offsetFactorSpinBox = new QDoubleSpinBox(groupBox_2);
        offsetFactorSpinBox->setObjectName(QString::fromUtf8("offsetFactorSpinBox"));
        offsetFactorSpinBox->setDecimals(1);
        offsetFactorSpinBox->setMinimum(0.100000000000000);
        offsetFactorSpinBox->setMaximum(10.000000000000000);
        offsetFactorSpinBox->setSingleStep(0.100000000000000);
        offsetFactorSpinBox->setValue(1.000000000000000);

        gridLayout_3->addWidget(offsetFactorSpinBox, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 2, 1, 1, 1);

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

        targetObjectLabel = new QLabel(sdfWidget);
        targetObjectLabel->setObjectName(QString::fromUtf8("targetObjectLabel"));

        gridLayout->addWidget(targetObjectLabel, 0, 0, 1, 1);

        objectName = new QLabel(sdfWidget);
        objectName->setObjectName(QString::fromUtf8("objectName"));

        gridLayout->addWidget(objectName, 0, 1, 1, 1);

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

        bboxMin = new QLabel(meshStatsBox);
        bboxMin->setObjectName(QString::fromUtf8("bboxMin"));

        gridLayout_2->addWidget(bboxMin, 3, 1, 1, 1);

        bboxMinLabel = new QLabel(meshStatsBox);
        bboxMinLabel->setObjectName(QString::fromUtf8("bboxMinLabel"));

        gridLayout_2->addWidget(bboxMinLabel, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 5, 0, 1, 1);

        polygonCount = new QLabel(meshStatsBox);
        polygonCount->setObjectName(QString::fromUtf8("polygonCount"));

        gridLayout_2->addWidget(polygonCount, 2, 1, 1, 1);

        bboxMaxLabel = new QLabel(meshStatsBox);
        bboxMaxLabel->setObjectName(QString::fromUtf8("bboxMaxLabel"));

        gridLayout_2->addWidget(bboxMaxLabel, 4, 0, 1, 1);

        bboxMax = new QLabel(meshStatsBox);
        bboxMax->setObjectName(QString::fromUtf8("bboxMax"));

        gridLayout_2->addWidget(bboxMax, 4, 1, 1, 1);


        gridLayout->addWidget(meshStatsBox, 2, 0, 1, 1);

        line_2 = new QFrame(sdfWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 4, 1, 1, 1);

        groupBox = new QGroupBox(sdfWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        comuteSignCheckBox = new QCheckBox(groupBox);
        comuteSignCheckBox->setObjectName(QString::fromUtf8("comuteSignCheckBox"));
        comuteSignCheckBox->setChecked(true);

        gridLayout_4->addWidget(comuteSignCheckBox, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 3, 1, 1, 1);

        computeButton = new QPushButton(sdfWidget);
        computeButton->setObjectName(QString::fromUtf8("computeButton"));

        gridLayout->addWidget(computeButton, 5, 1, 1, 1);


        retranslateUi(sdfWidget);
        QObject::connect(computeButton, SIGNAL(clicked()), sdfWidget, SLOT(ActionSDFInit()));

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
        octreeResolutionSpinBox->setToolTip(QCoreApplication::translate("sdfWidget", "grid cell count for geometry's bounding cube for octree construction", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        offsetFactorSpinBox->setToolTip(QCoreApplication::translate("sdfWidget", "a factor by which the geometry's bounding box gets expanded to extend the distance function domain", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        label_8->setToolTip(QCoreApplication::translate("sdfWidget", "a factor by which the geometry's bounding box gets expanded to extend the distance function domain", nullptr));
#endif // QT_CONFIG(tooltip)
        label_8->setText(QCoreApplication::translate("sdfWidget", "grid expansion factor:", nullptr));
        fastSweepParams->setTitle(QCoreApplication::translate("sdfWidget", "Fast-Sweep parameters:", nullptr));
#if QT_CONFIG(tooltip)
        NsweepsLabel->setToolTip(QCoreApplication::translate("sdfWidget", "Number of iterations for fast sweeping algorithm. At least 4 sweeps required to produce decent results.", nullptr));
#endif // QT_CONFIG(tooltip)
        NsweepsLabel->setText(QCoreApplication::translate("sdfWidget", "NSweeps:", nullptr));
#if QT_CONFIG(tooltip)
        nSweepsSpinBox->setToolTip(QCoreApplication::translate("sdfWidget", "Number of iterations for fast sweeping algorithm. At least 4 sweeps required to produce decent results.", nullptr));
#endif // QT_CONFIG(tooltip)
        targetObjectLabel->setText(QCoreApplication::translate("sdfWidget", "target object:", nullptr));
        objectName->setText(QCoreApplication::translate("sdfWidget", "---", nullptr));
        meshStatsBox->setTitle(QCoreApplication::translate("sdfWidget", "Mesh stats:", nullptr));
        triCountLabel->setText(QCoreApplication::translate("sdfWidget", "triangle count:", nullptr));
        triangleCount->setText(QCoreApplication::translate("sdfWidget", "0", nullptr));
        vertCountLabel->setText(QCoreApplication::translate("sdfWidget", "vertices count:", nullptr));
        verticesCount->setText(QCoreApplication::translate("sdfWidget", "0", nullptr));
        polyCountLabel->setText(QCoreApplication::translate("sdfWidget", "polygon count:", nullptr));
        bboxMin->setText(QCoreApplication::translate("sdfWidget", "(0, 0, 0)", nullptr));
        bboxMinLabel->setText(QCoreApplication::translate("sdfWidget", "bounding box min:", nullptr));
        polygonCount->setText(QCoreApplication::translate("sdfWidget", "0", nullptr));
        bboxMaxLabel->setText(QCoreApplication::translate("sdfWidget", "bounding box max:", nullptr));
        bboxMax->setText(QCoreApplication::translate("sdfWidget", "(0, 0, 0)", nullptr));
        groupBox->setTitle(QCoreApplication::translate("sdfWidget", "SDF parameters:", nullptr));
#if QT_CONFIG(tooltip)
        comuteSignCheckBox->setToolTip(QCoreApplication::translate("sdfWidget", "compute sign of distance function (negative for interior grid cells). Only works for closed mesh surfaces.", nullptr));
#endif // QT_CONFIG(tooltip)
        comuteSignCheckBox->setText(QCoreApplication::translate("sdfWidget", "compute sign", nullptr));
        computeButton->setText(QCoreApplication::translate("sdfWidget", "Compute", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sdfWidget: public Ui_sdfWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SDFWIDGET_H
