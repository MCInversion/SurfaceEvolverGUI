#include "SDFWidget.h"

SDFWidget::SDFWidget(QWidget* parent) {
	ui.setupUi(this);
}

void SDFWidget::processMeshInfo(SceneObject* object)
{
	ui.objectName->setText(object->name());
	ui.verticesCount->setText(QString::number(object->vertexCount()));
	ui.triangleCount->setText(QString::number(object->triangleCount()));
	ui.polygonCount->setText(QString::number(object->polyCount()));
	ui.bboxMin->setText(object->getBoxMinOutput());
	ui.bboxMax->setText(object->getBoxMaxOutput());
}

void SDFWidget::ActionSDFInit()
{
	emit sdfInit();
	close();
}

void SDFWidget::closeEvent(QCloseEvent* event)
{
	emit closeSDF();
}

SDFParams SDFWidget::getSDFParams()
{
	SDFParams params;
	params.octree_resolution = ui.octreeResolutionSpinBox->value();
	params.NSweeps = ui.nSweepsSpinBox->value();
	params.grid_expansion_factor = ui.offsetFactorSpinBox->value();
	params.compute_sign = ui.comuteSignCheckBox->isChecked();
	return params;
}
