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

#include "Geometry.h"

class MeshObject
{
public:
	MeshObject(vtkSmartPointer<vtkPolyData> polyData);
	MeshObject(Geometry& geometryData);

	const vtkSmartPointer<vtkActor>& getVertexActor() const;
	const vtkSmartPointer<vtkActor>& getEdgeActor() const;
	const vtkSmartPointer<vtkActor>& getSurfaceActor() const;

	inline const QColor& vertexColor() const { return m_vertexColor; };
	inline const QColor& edgeColor() const { return m_edgeColor; };
	inline const QColor& surfaceColor() const { return m_surfaceColor; };

	inline const double opacity() const { return m_opacity; };

	void setVertexColor(QColor& color);
	void setEdgeColor(QColor& color);
	void setSurfaceColor(QColor& color);

	void setOpacity(double opacity);

	inline void setVisible(bool visible) { m_visible = visible; };
	inline void setVertexRepresentation(bool representation) { m_vertex = representation; };
	inline void setWireframeRepresentation(bool representation) { m_wireframe = representation; };
	inline void setSurfaceRepresentation(bool representation) { m_surface = representation; };

	inline bool isVisible() { return m_visible; };

	inline bool vertexRender() { return m_vertex; };
	inline bool edgeRender() { return m_wireframe; };
	inline bool surfaceRender() { return m_surface; };
private:
	vtkSmartPointer<vtkPolyData> m_polyData;

	// visibility
	bool m_visible = true;

	// render style
	bool m_vertex = false;
	bool m_wireframe = true;
	bool m_surface = true;

	double m_opacity = 1.0;

	// mesh mappers
	vtkSmartPointer<vtkPolyDataMapper> m_vertexMapper;
	vtkSmartPointer<vtkPolyDataMapper> m_edgeMapper;
	vtkSmartPointer<vtkPolyDataMapper> m_surfaceMapper;

	// mesh actors
	vtkSmartPointer<vtkActor> m_vertexActor;
	vtkSmartPointer<vtkActor> m_edgeActor;
	vtkSmartPointer<vtkActor> m_surfaceActor;

	// representation colors
	QColor m_vertexColor = QColor(13, 18, 56);
	QColor m_edgeColor = QColor(0, 74, 194);
	QColor m_surfaceColor = QColor(237, 224, 206);

	// transformation
	Vector3 m_position = Vector3();
	Quaternion m_orientation = Quaternion();
	Vector3 m_scale = Vector3(1.0, 1.0, 1.0);
	
	void initProperties();
};

#endif