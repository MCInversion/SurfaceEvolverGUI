#include "SDFWidget.h"

SDFWidget::SDFWidget(QWidget* parent) {
	ui.setupUi(this);
}

void SDFWidget::processMeshInfo(std::shared_ptr<MeshObject> object)
{
	ui.objectName->setText(object->name());
	ui.verticesCount->setText(QString::number(object->vertexCount()));
	ui.triangleCount->setText(QString::number(object->triangleCount()));
	ui.polygonCount->setText(QString::number(object->polyCount()));
	ui.bboxMin->setText(object->getBoxMinOutput());
	ui.bboxMax->setText(object->getBoxMaxOutput());
	
}

void SDFWidget::closeEvent(QCloseEvent* event)
{
	emit closeSDF();
}
