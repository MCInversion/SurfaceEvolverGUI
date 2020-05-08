#include "MeshObject.h"

MeshObject::MeshObject(vtkSmartPointer<vtkPolyData> polyData) : m_polyData{ polyData }
{
	initProperties();
}

MeshObject::MeshObject(Geometry& geometryData)
{
	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
	vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();

	// vertices
	for (int i = 0; i < geometryData.uniqueVertices.size(); i++) {
		//Declare a variable to store the index of the point that gets added. This behaves just like an unsigned int.
		vtkIdType pid[1];

		//Add a point to the polydata and save its index, which we will use to create the vertex on that point.
		pid[0] = points->InsertNextPoint(
			geometryData.uniqueVertices[i].x,
			geometryData.uniqueVertices[i].y,
			geometryData.uniqueVertices[i].z
		);
	}

	bool polygonalCells = geometryData.hasTriangulations();

	if (geometryData.hasTriangulations()) {
		for (int t = 0; t < geometryData.triangulations.size(); t++) {
			vtkSmartPointer<vtkPolygon> polygon = vtkSmartPointer<vtkPolygon>::New();

			std::vector<unsigned int> polygonIds = geometryData.getPolygonIndicesFromTriangulation(geometryData.triangulations[t]);
			polygon->GetPointIds()->SetNumberOfIds(polygonIds.size());

			for (unsigned int k = 0; k < polygonIds.size(); k++) {
				polygon->GetPointIds()->SetId(k, polygonIds[k]);
			}

			cells->InsertNextCell(polygon);
		}
	}

	/*
	// TODO: map scalars to colors
	if (geometryData.hasScalarData()) {
		size_t NTables = geometryData.scalarTables.size();
	}*/

	//set the points and vertices we created as the geometry and topology of the polydata
	m_polyData = vtkSmartPointer<vtkPolyData>::New();
	m_polyData->SetPoints(points);
	m_polyData->SetPolys(cells);

	initProperties();
}

const vtkSmartPointer<vtkActor>& MeshObject::getVertexActor() const
{
	return m_vertexActor;
}

const vtkSmartPointer<vtkActor>& MeshObject::getEdgeActor() const
{
	return m_edgeActor;
}

const vtkSmartPointer<vtkActor>& MeshObject::getSurfaceActor() const
{
	return m_surfaceActor;
}

void MeshObject::setVertexColor(QColor& color)
{
	m_vertexActor->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
}

void MeshObject::setEdgeColor(QColor& color)
{
	m_edgeActor->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
}

void MeshObject::setSurfaceColor(QColor& color)
{
	m_surfaceActor->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
}

void MeshObject::setOpacity(double opacity)
{
	m_opacity = opacity;
	m_vertexActor->GetProperty()->SetOpacity(m_opacity);
	m_surfaceActor->GetProperty()->SetOpacity(m_opacity);
	m_surfaceActor->GetProperty()->SetOpacity(m_opacity);
}

void MeshObject::initProperties()
{
	m_vertexMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	m_edgeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	m_surfaceMapper = vtkSmartPointer<vtkPolyDataMapper>::New();

	m_vertexActor = vtkSmartPointer<vtkActor>::New();
	m_edgeActor = vtkSmartPointer<vtkActor>::New();
	m_surfaceActor = vtkSmartPointer<vtkActor>::New();

	m_vertexMapper->SetInputData(m_polyData);
	m_edgeMapper->SetInputData(m_polyData);
	m_surfaceMapper->SetInputData(m_polyData);

	m_vertexActor->SetMapper(m_vertexMapper);
	m_edgeActor->SetMapper(m_edgeMapper);
	m_surfaceActor->SetMapper(m_surfaceMapper);
	setVertexColor(m_defaultVertexColor);
	setEdgeColor(m_defaultEdgeColor);
	setSurfaceColor(m_defaultSurfaceColor);

	m_vertexActor->GetProperty()->SetRepresentationToPoints();

	m_vertexActor->GetProperty()->SetAmbient(1.0);
	m_vertexActor->GetProperty()->SetDiffuse(0.0);
	m_vertexActor->GetProperty()->SetSpecular(0.0);
	m_vertexActor->GetProperty()->SetPointSize(4.0);
	m_vertexActor->GetProperty()->SetOpacity(m_opacity);

	m_edgeActor->GetProperty()->SetRepresentationToWireframe();

	m_edgeActor->GetProperty()->SetAmbient(1.0);
	m_edgeActor->GetProperty()->SetDiffuse(0.0);
	m_edgeActor->GetProperty()->SetSpecular(0.0);
	m_edgeActor->GetProperty()->SetLineWidth(2.0);
	m_surfaceActor->GetProperty()->SetOpacity(m_opacity);

	m_surfaceActor->GetProperty()->SetRepresentationToSurface();
	m_surfaceActor->GetProperty()->SetInterpolationToFlat();
	m_surfaceActor->GetProperty()->SetOpacity(m_opacity);
}
