#ifndef EVOLUTIONWIDGET_H
#define EVOLUTIONWIDGET_H

#include <QWidget>
#include "ui_EvolutionWidget.h"

class EvolutionWidget :	public QWidget
{
	Q_OBJECT
public:
	EvolutionWidget(QWidget* parent = Q_NULLPTR);
private:
	Ui::evolutionWidget ui;
};

#endif