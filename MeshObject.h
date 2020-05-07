#ifndef MESHOBJECT_H
#define MESHOBJECT_H

#include <QColor>

#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkSmartPointer.h>

#include "./EvolutionCore/Geometry/Geometry.h"

class MeshObject
{
public:
	MeshObject(vtkSmartPointer<vtkPolyData> polyData);
	MeshObject(Geometry& geometryData);

	const vtkSmartPointer<vtkActor>& getModelActor() const;

private:
	vtkSmartPointer<vtkPolyData> m_polyData;
	vtkSmartPointer<vtkPolyDataMapper> m_mapper;
	vtkSmartPointer<vtkActor> m_actor;
};

#endif