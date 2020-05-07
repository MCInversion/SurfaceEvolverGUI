#include "MeshObject.h"

MeshObject::MeshObject(vtkSmartPointer<vtkPolyData> polyData) : m_polyData{ polyData }
{
}

MeshObject::MeshObject(Geometry& geometryData)
{

}

const vtkSmartPointer<vtkActor>& MeshObject::getModelActor() const
{
	return m_actor;
}
