#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <array>
#include <cstdint>
#include <vector>
#include <memory>

#include <QObject>
#include <QColor>

#include <vtkActor.h>
#include <vtkDataObject.h>
#include <vtkAlgorithm.h>
#include <vtkAlgorithmOutput.h>
#include <vtkSmartPointer.h>

#include <vtkPolyDataMapper.h>
#include <vtkCellArray.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkTriangle.h>
#include <vtkTriangleFilter.h>
#include <vtkPolygon.h>
#include <vtkProperty.h>
#include <vtkPoints.h>

#include <vtkSampleFunction.h>
#include <vtkSmartVolumeMapper.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include <vtkVolumeProperty.h>
#include <vtkImageData.h>
#include <vtkDataArray.h>
#include <vtkDoubleArray.h>
#include <vtkFieldData.h>
#include <vtkVolume.h>
#include <vtkPointData.h>
#include <vtkMarchingCubes.h>

#include "Geometry.h"
#include "Grid.h"

enum ObjectType {
	Misc = -1,
	Mesh = 0,
	SGrid = 1
};

class SceneObject
{
public:
	// --- basic constructors ---------------
	SceneObject();
	SceneObject(QString name);
	// ---- mesh constructors ---------------
	SceneObject(vtkSmartPointer<vtkPolyData> polyData, QString name, bool clip_file_extension = true);
	SceneObject(Geometry& geometryData);
	// ---- grid constructors ---------------
	SceneObject(vtkSmartPointer<vtkImageData> imgData, QString name, bool clip_file_extension = true, bool img_data = true);
	SceneObject(Grid* grid, QString name);

	// ------- basic public methods ---------
	inline void setVisible(bool visible) { m_visible = visible; };
	void setOpacity(double opacity);
	inline ObjectType type() { return m_type; };

	inline QString name() { return m_name; };
	inline bool isVisible() { return m_visible; };

	inline const double opacity() const { return m_opacity; };
	// ------ mesh public methods -----------
	inline const vtkSmartPointer<vtkActor>& getVertexActor() const { return m_vertexActor; };
	inline const vtkSmartPointer<vtkActor>& getEdgeActor() const { return m_edgeActor; };
	inline const vtkSmartPointer<vtkActor>& getSurfaceActor() const { return m_surfaceActor; };

	inline const QColor& vertexColor() const { return m_vertexColor; };
	inline const QColor& edgeColor() const { return m_edgeColor; };
	inline const QColor& surfaceColor() const { return m_surfaceColor; };

	void setVertexColor(QColor& color);
	void setEdgeColor(QColor& color);
	void setSurfaceColor(QColor& color);

	inline void setVertexRepresentation(bool representation) { m_vertex = representation; };
	inline void setWireframeRepresentation(bool representation) { m_wireframe = representation; };
	inline void setSurfaceRepresentation(bool representation) { m_surface = representation; };

	inline bool vertexRender() { return m_vertex; };
	inline bool edgeRender() { return m_wireframe; };
	inline bool surfaceRender() { return m_surface; };

	void updateContours();
	inline void setSingleContour(bool singleContour) { m_singleContour = singleContour; updateContours(); };
	inline void setNContours(int nContours) { m_nContours = nContours; updateContours(); };
	void setIsoLevel(double isoLevel);
	inline void setDIso(double dIso) { m_dIso = dIso; updateContours();	};

	inline bool singleContour() { return m_singleContour; };
	inline int nContours() { return m_nContours; };
	inline double isoLevel() { return m_isoLevel; };
	inline double dIso() { return m_dIso; };
	inline double valMax() { return m_valMax; };
	inline double valMin() { return m_valMin; };

	int vertexCount();
	int triangleCount();
	int polyCount();
	Vector3 getBoxMin();
	Vector3 getBoxMax();

	QString getBoxMinOutput();
	QString getBoxMaxOutput();

	inline vtkSmartPointer<vtkPolyData> getPolyData() { return m_polyData; };

	Geometry translatePolyDataToGeometry();
	// ------- scalar grid public methods ----------------
	inline const vtkSmartPointer<vtkVolume>& getVolume() const { return m_volume; };
	const vtkSmartPointer<vtkActor>& getIsoSurfaceActor() const { return m_isoSurfaceActor; };

	vtkSmartPointer<vtkPolyData> getPolyDataFromSurfaces();
	//
private:

	// ====== Basic object params ==========
	QString m_name = "EmptyObject";
	ObjectType m_type = ObjectType::Misc;

	bool m_visible = true;

	double m_opacity = 1.0;

	// ====== Mesh Object params ===========
	vtkSmartPointer<vtkPolyData> m_polyData;

	// render style
	bool m_vertex = false;
	bool m_wireframe = true;
	bool m_surface = true;

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

	void initMappersFromPolyData();
	void initMappersFromOutput(vtkSmartPointer<vtkAlgorithmOutput> out, bool scalar_visibility = true);

	void initMeshProperties();
	// void initMarchingCubesProperties(vtkSmartPointer<vtkMarchingCubes> mc);

	// ======= Scalar Grid Object params ========
	vtkSmartPointer<vtkImageData> m_imgData;
	vtkSmartPointer<vtkVolume> m_volume;
	vtkSmartPointer<vtkActor> m_isoSurfaceActor;

	bool m_singleContour = false;
	int m_nContours = 6;
	double m_valMin = 0.; double m_valMax = 100.;
	double m_isoLevel = 0.;
	double m_dIso = 5.0;

	void initFromGrid(Grid* grid);
	void initVolumeProperties(Grid* grid = nullptr);
	void sampleIsoSurfaces(double* range, int nSamples);
};

#endif