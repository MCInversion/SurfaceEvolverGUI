#ifndef SDFWIDGET_H_
#define SDFWIDGET_H_

#include <QWidget>
#include <QtCore/QObject>
#include <QCloseEvent>

#include "SurfaceEvolverGUI.h"
#include "ui_SDFWidget.h"

class SDFWidget : public QWidget
{
	Q_OBJECT
public:
	SDFWidget(QWidget* parent = Q_NULLPTR);

	// processes raw polydata object
	void processMeshInfo(std::shared_ptr<MeshObject> object);
	void closeEvent(QCloseEvent* event);
signals:
	bool closeSDF();
private:
	Ui::sdfWidget ui;
};

#endif