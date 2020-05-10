#ifndef SDFWIDGET_H_
#define SDFWIDGET_H_

#include <QWidget>
#include <QtCore/QObject>
#include <QCloseEvent>

#include "SurfaceEvolverGUI.h"
#include "ui_SDFWidget.h"
#include "Parameters.h"

class SDFWidget : public QWidget
{
	Q_OBJECT
public:
	SDFWidget(QWidget* parent = Q_NULLPTR);

	// processes mesh object
	void processMeshInfo(SceneObject* object);
	void closeEvent(QCloseEvent* event);

	SDFParams getSDFParams();
public slots:
	void ActionSDFInit();
signals:
	bool closeSDF();
	bool sdfInit();
private:
	Ui::sdfWidget ui;
};

#endif