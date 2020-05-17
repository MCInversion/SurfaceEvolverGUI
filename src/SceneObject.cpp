#include "SceneObject.h"

// ========== CONSTRUCTORS - Basic =======================

SceneObject::SceneObject()
{
}

SceneObject::SceneObject(QString name)
{
	m_name = name;
}

// ======================================================
// =========== CONSTRUCTORS - Mesh ======================

SceneObject::SceneObject(vtkSmartPointer<vtkPolyData> polyData, QString name, bool clip_file_extension)
{
	m_name = (clip_file_extension ? name.split(".").first() : name);
	m_type = ObjectType::Mesh;
	m_polyData = polyData;

	initMappersFromPolyData();
	initMeshProperties();
}

SceneObject::SceneObject(Geometry& geometryData)
{
	m_name = QString(geometryData.name.c_str());
	m_type = ObjectType::Mesh;
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

	initMappersFromPolyData();
	initMeshProperties();
}

// ======================================================
// =========== CONSTRUCTORS - Scalar Grid ===============

SceneObject::SceneObject(vtkSmartPointer<vtkImageData> imgData, QString name, bool clip_file_extension, bool img_data)
{
	m_name = (clip_file_extension ? name.split(".").first() : name);
	m_type = ObjectType::SGrid;
	m_imgData = imgData;
	initVolumeProperties();
}

SceneObject::SceneObject(Grid* grid, QString name)
{
	m_name = name;
	m_type = ObjectType::SGrid;
	initFromGrid(grid);
	initVolumeProperties(grid);
}

// ======================================================

void SceneObject::setOpacity(double opacity)
{
	m_opacity = opacity;

	m_vertexActor->GetProperty()->SetOpacity(m_opacity);
	m_edgeActor->GetProperty()->SetOpacity(m_opacity);
	m_surfaceActor->GetProperty()->SetOpacity(m_opacity);
}

void SceneObject::setVertexColor(QColor& color)
{
	m_vertexColor = color;
	m_vertexActor->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
}

void SceneObject::setEdgeColor(QColor& color)
{
	m_edgeColor = color;
	m_edgeActor->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
}

void SceneObject::setSurfaceColor(QColor& color)
{
	m_surfaceColor = color;
	m_surfaceActor->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
}

void SceneObject::updateContours()
{
	double range[2] = { m_valMin, m_valMax };
	sampleIsoSurfaces(range, m_nContours);
}

void SceneObject::setIsoLevel(double isoLevel)
{
	double isoInRange = m_valMin + isoLevel / 100 * (m_valMax - m_valMin);
	m_isoLevel = isoInRange;
	updateContours();
}

void SceneObject::initMappersFromPolyData()
{
	m_vertexMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	m_vertexMapper->SetInputData(m_polyData);

	m_edgeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	m_edgeMapper->SetInputData(m_polyData);

	m_surfaceMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	m_surfaceMapper->SetInputData(m_polyData);
}

void SceneObject::initMappersFromOutput(vtkSmartPointer<vtkAlgorithmOutput> out, bool scalar_visibility)
{
	m_vertexMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	m_vertexMapper->SetInputConnection(out);
	if (!scalar_visibility) m_vertexMapper->ScalarVisibilityOff();

	m_edgeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	m_edgeMapper->SetInputConnection(out);
	if (!scalar_visibility) m_edgeMapper->ScalarVisibilityOff();

	m_surfaceMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	m_surfaceMapper->SetInputConnection(out);
	if (!scalar_visibility) m_surfaceMapper->ScalarVisibilityOff();
}

void SceneObject::initMeshProperties()
{
	m_vertexActor = vtkSmartPointer<vtkActor>::New();
	m_vertexActor->SetMapper(m_vertexMapper);

	setVertexColor(m_vertexColor);

	m_vertexActor->GetProperty()->SetRepresentationToPoints();

	m_vertexActor->GetProperty()->SetAmbient(1.0);
	m_vertexActor->GetProperty()->SetDiffuse(0.0);
	m_vertexActor->GetProperty()->SetSpecular(0.0);
	m_vertexActor->GetProperty()->SetPointSize(4.0);
	m_vertexActor->GetProperty()->SetOpacity(m_opacity);

	m_edgeActor = vtkSmartPointer<vtkActor>::New();
	m_edgeActor->SetMapper(m_edgeMapper);
	setEdgeColor(m_edgeColor);

	m_edgeActor->GetProperty()->SetRepresentationToWireframe();

	m_edgeActor->GetProperty()->SetAmbient(1.0);
	m_edgeActor->GetProperty()->SetDiffuse(0.0);
	m_edgeActor->GetProperty()->SetSpecular(0.0);
	m_edgeActor->GetProperty()->SetLineWidth(2.0);
	m_edgeActor->GetProperty()->SetOpacity(m_opacity);
	
	m_surfaceActor = vtkSmartPointer<vtkActor>::New();
	m_surfaceActor->SetMapper(m_surfaceMapper);	
	setSurfaceColor(m_surfaceColor);

	m_surfaceActor->GetProperty()->SetRepresentationToSurface();
	m_surfaceActor->GetProperty()->SetInterpolationToFlat();
	m_surfaceActor->GetProperty()->SetOpacity(m_opacity);
}

void SceneObject::initFromGrid(Grid* grid)
{
	if (m_type != ObjectType::SGrid) return;

	vtkSmartPointer<vtkDoubleArray> dataArray = vtkSmartPointer<vtkDoubleArray>::New();
	unsigned int NCells = grid->gridExtent;
	for (vtkIdType id = 0; id < NCells; id++) {
		double value = grid->field[id];
		dataArray->InsertNextValue(value);
	}
	double dataRange[2];
	dataArray->GetRange(dataRange);
	double rangeExtent = dataRange[1] - dataRange[0];

	m_imgData = vtkSmartPointer<vtkImageData>::New();

	m_imgData->SetExtent(0, grid->Nx - 1, 0, grid->Ny - 1, 0, grid->Nz - 1);

	Vector3 boxMin = grid->bbox.min;
	double dx = grid->scale.x / grid->Nx;
	double dy = grid->scale.y / grid->Ny;
	double dz = grid->scale.z / grid->Nz;
	double orig[3] = { 
		boxMin.x + dx /*0.5 * */,
		boxMin.y + dy /* 0.5 * */,
		boxMin.z + dz /*0.5 * */
	};
	m_imgData->SetOrigin(orig);
	double spacing[3] = { dx, dy, dz };
	m_imgData->SetSpacing(spacing);

	m_imgData->GetPointData()->SetScalars(dataArray);
}

void SceneObject::initVolumeProperties(Grid* grid)
{
	if (m_type != ObjectType::SGrid) return;

	double valuesRange[2];
	m_imgData->Modified();
	m_imgData->GetPointData()->GetScalars()->Modified();
	m_imgData->GetScalarRange(valuesRange);
	m_valMin = valuesRange[0], m_valMax = valuesRange[1];
	double valRangeLength = m_valMax - m_valMin;

	if (!grid) {
		m_isoLevel = 0.5 * (m_valMin + m_valMax);
	}
	else {
		m_isoLevel = 0.5 * grid->max_unclipped_isolevel;
	}

	// default dIso
	m_dIso = valRangeLength * 0.05;

	// defaults:
	m_opacity = 0.3;
	m_vertex = false;
	m_wireframe = false;
	m_surface = true;

	m_vertexColor = QColor(255, 255, 255);
	m_edgeColor = QColor(255, 255, 255);
	m_surfaceColor = QColor(9, 171, 105);

	// printf("minVal = %lf, maxVal = %lf", valuesRange[0], valuesRange[1]);
	/*
	vtkSmartPointer<vtkSmartVolumeMapper> volumeMapper = vtkSmartPointer<vtkSmartVolumeMapper>::New();
	volumeMapper->SetBlendModeToComposite();

	// input data
	volumeMapper->SetInputData(m_imgData);

	// default volume property
	vtkSmartPointer<vtkVolumeProperty> volumeProperty = vtkSmartPointer<vtkVolumeProperty>::New();
	volumeProperty->ShadeOff();
	volumeProperty->SetInterpolationType(VTK_LINEAR_INTERPOLATION);

	// composite opacity
	vtkSmartPointer<vtkPiecewiseFunction> compositeOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
	compositeOpacity->AddPoint(valMin, 0.9);
	compositeOpacity->AddPoint(valMin + 1. / 4. * valRangeLength, 0.1);
	compositeOpacity->AddPoint(valMin + 1. / 2. * valRangeLength, 0.0);
	compositeOpacity->AddPoint(valMax, 0.0);
	volumeProperty->SetScalarOpacity(compositeOpacity);

	// color transfer function
	vtkSmartPointer<vtkColorTransferFunction> color = vtkSmartPointer<vtkColorTransferFunction>::New();
	color->SetColorSpaceToHSV();
	color->AddHSVPoint(valMin, 1.0, 1.0, 1.0);
	color->AddHSVPoint(valMin + 1. / 4. * valRangeLength, 0.75, 1.0, 1.0);
	color->AddHSVPoint(valMax, 0.0, 1.0, 1.0);
	volumeProperty->SetColor(color);

	volumeMapper->SetRequestedRenderModeToRayCast();
	m_volume = vtkSmartPointer<vtkVolume>::New();
	m_volume->SetMapper(volumeMapper);
	m_volume->SetProperty(volumeProperty);*/

	sampleIsoSurfaces(valuesRange, m_nContours);
}

void SceneObject::sampleIsoSurfaces(double* range, int nSamples)
{
	if (m_type != ObjectType::SGrid) return;

	// ======================================================

	vtkSmartPointer<vtkMarchingCubes> surface = vtkSmartPointer<vtkMarchingCubes>::New();
	surface->SetInputData(m_imgData);
	surface->ComputeNormalsOn();

	if (m_singleContour) {
		surface->SetNumberOfContours(1);
		surface->SetValue(0, m_isoLevel);
	}
	else {
		surface->SetNumberOfContours(nSamples);

		vtkIdType contourId = 0;
		
		for (vtkIdType id = nSamples / 2; id != 0; id--) {
			double isoValue;
			isoValue = m_isoLevel - std::floor((double)id / (double)2) * m_dIso;

			if (isoValue > range[1] || isoValue < range[0]) continue;
			surface->SetValue(contourId++, isoValue);
		}

		for (vtkIdType id = 0; id < nSamples / 2; id++) {
			double isoValue;
			isoValue = m_isoLevel + std::floor((double)id / (double)2) * m_dIso;
		
			if (isoValue > range[1] || isoValue < range[0]) continue;
			surface->SetValue(contourId++, isoValue);
		}
	}

	// === isosurf sampled ====================================
	
	initMappersFromOutput(surface->GetOutputPort(), false);
	initMeshProperties();
}

int SceneObject::vertexCount()
{
	if (m_type != ObjectType::Mesh) return 0;

	return m_polyData->GetNumberOfPoints();
}

int SceneObject::triangleCount()
{
	if (m_type != ObjectType::Mesh) return 0;

	vtkSmartPointer<vtkTriangleFilter> triFilter = vtkSmartPointer<vtkTriangleFilter>::New();
	triFilter->SetInputData(m_polyData);
	triFilter->Update();
	return triFilter->GetOutput()->GetNumberOfPolys();
}

int SceneObject::polyCount()
{
	if (m_type != ObjectType::Mesh) return 0;

	return m_polyData->GetNumberOfPolys();
}

Vector3 SceneObject::getBoxMin()
{
	if (m_type == ObjectType::Misc) return Vector3();

	double* bounds = new double[6];
	if (m_type == ObjectType::Mesh) {
		bounds = m_polyData->GetBounds();
	}
	else if (m_type == ObjectType::SGrid) {
		bounds = m_imgData->GetBounds();
	}
	
	return Vector3(bounds[0], bounds[2], bounds[4]);
}

Vector3 SceneObject::getBoxMax()
{
	if (m_type == ObjectType::Misc) return Vector3();

	double* bounds = new double[6];
	if (m_type == ObjectType::Mesh) {
		bounds = m_polyData->GetBounds();
	}
	else if (m_type == ObjectType::SGrid) {
		bounds = m_imgData->GetBounds();
	}

	return Vector3(bounds[1], bounds[3], bounds[5]);
}

QString SceneObject::getBoxMinOutput()
{
	if (m_type == ObjectType::Misc) return QString();

	double* bounds = new double[6];
	if (m_type == ObjectType::Mesh) {
		bounds = m_polyData->GetBounds();
	}
	else if (m_type == ObjectType::SGrid) {
		bounds = m_imgData->GetBounds();
	}

	QString result = "(" + QString::number(bounds[0]) + ", " + QString::number(bounds[2]) + ", " + QString::number(bounds[4]) + ")";
	return result;
}

QString SceneObject::getBoxMaxOutput()
{
	if (m_type == ObjectType::Misc) return QString();

	double* bounds = new double[6];
	if (m_type == ObjectType::Mesh) {
		bounds = m_polyData->GetBounds();
	}
	else if (m_type == ObjectType::SGrid) {
		bounds = m_imgData->GetBounds();
	}

	QString result = "(" + QString::number(bounds[1]) + ", " + QString::number(bounds[3]) + ", " + QString::number(bounds[5]) + ")";
	return result;
}

Geometry SceneObject::translatePolyDataToGeometry()
{
	Geometry result = Geometry();
	result.name = m_name.toStdString();

	if (m_type != ObjectType::Mesh) {
		return result;
	}

	int NPoints = m_polyData->GetNumberOfPoints();
	result.uniqueVertices = std::vector<Vector3>(NPoints);

	double pt[3];
	for (vtkIdType n = 0; n < NPoints; n++) {
		m_polyData->GetPoint(n, pt);
		result.uniqueVertices[(int)n] = Vector3(pt[0], pt[1], pt[2]);
	}

	vtkSmartPointer<vtkTriangleFilter> triFilter = vtkSmartPointer<vtkTriangleFilter>::New();
	triFilter->SetInputData(m_polyData);
	triFilter->Update();

	int NTriangles = triFilter->GetOutput()->GetNumberOfPolys();
	result.vertexIndices = std::vector<unsigned int>(3 * NTriangles);

	vtkSmartPointer<vtkCellArray> polys = triFilter->GetOutput()->GetPolys();
	polys->InitTraversal();
	vtkSmartPointer<vtkIdList> idList = vtkSmartPointer<vtkIdList>::New();
	for (int i = 0; i < NTriangles; i++) {
		polys->GetNextCell(idList);
		result.vertexIndices[3 * i] = idList->GetId(0);
		result.vertexIndices[3 * i + 1] = idList->GetId(1);
		result.vertexIndices[3 * i + 2] = idList->GetId(2);
	}

	result.computeTriangulations();
	result.fillVerticesFromUniqueVertices();
	result.computeNormals();

	return result;
}
