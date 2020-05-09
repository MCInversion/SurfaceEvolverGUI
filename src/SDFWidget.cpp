#include "SDFWidget.h"

SDFWidget::SDFWidget(QWidget* parent) {
	ui.setupUi(this);
}

void SDFWidget::processMesh(std::shared_ptr<MeshObject> object)
{
	ui.verticesCount->setText(QString::number(object->vertexCount()));
	ui.polygonCount->setText(QString::number(object->polyCount()));
}
