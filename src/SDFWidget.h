#ifndef SDFWIDGET_H_
#define SDFWIDGET_H_

#include <QWidget>
#include <QtCore/QObject>

#include "SurfaceEvolverGUI.h"
#include "ui_SDFWidget.h"

class SDFWidget : public QWidget
{
	Q_OBJECT
public:
	SDFWidget(QWidget* parent = Q_NULLPTR);
	void processMesh(std::shared_ptr<MeshObject> object);
private:
	Ui::sdfWidget ui;
};

#endif