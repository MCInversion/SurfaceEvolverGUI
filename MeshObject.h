#ifndef MESHOBJECT_H
#define MESHOBJECT_H

#include <QObject>
#include <QColor>

#include <vtkPolyDataMapper.h>
#include <vtkCellArray.h>
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkTriangle.h>
#include <vtkPolygon.h>
#include <vtkActor.h>
#include <vtkProperty.h>

#include "./EvolutionCore/Geometry/Geometry.h"

class MeshObject
{
public:
	MeshObject(vtkSmartPointer<vtkPolyData> polyData);
	MeshObject(Geometry& geometryData);

	const vtkSmartPointer<vtkActor>& getVertexActor() const;
	const vtkSmartPointer<vtkActor>& getEdgeActor() const;
	const vtkSmartPointer<vtkActor>& getSurfaceActor() const;

	void setVertexColor(const QColor& color);
	void setEdgeColor(const QColor& color);
	void setSurfaceColor(const QColor& color);

private:
	vtkSmartPointer<vtkPolyData> m_polyData;

	// mesh mappers
	vtkSmartPointer<vtkPolyDataMapper> m_vertexMapper;
	vtkSmartPointer<vtkPolyDataMapper> m_edgeMapper;
	vtkSmartPointer<vtkPolyDataMapper> m_surfaceMapper;

	// mesh actors
	vtkSmartPointer<vtkActor> m_vertexActor;
	vtkSmartPointer<vtkActor> m_edgeActor;
	vtkSmartPointer<vtkActor> m_surfaceActor;

	QColor m_defaultVertexColor;
	QColor m_defaultEdgeColor;
	QColor m_defaultSurfaceColor;
};

#endif