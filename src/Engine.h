#ifndef ENGINE_H
#define ENGINE_H


#include <array>
#include <cstdint>
#include <vector>
#include <memory>

#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>

#include <QVTKOpenGLNativeWidget.h>
#include <vtksys/SystemTools.hxx>
#include <vtkIndent.h>

#include "SceneObject.h"

class Engine
{
private:
	QVTKOpenGLNativeWidget* m_parentWidget = nullptr;

	QColor m_bgColor = QColor("black");

	QColor m_vertexColor = QColor(13, 18, 56);
	QColor m_edgeColor = QColor(0, 74, 194);
	QColor m_surfaceColor = QColor(237, 224, 206);

	double m_opacity = 1.0;
	double m_isoLevelVal = 0.0;

	std::vector<SceneObject> m_libObjects;
	std::vector<SceneObject> m_helperObjects;

	int m_objId = 0;

	// render style
	bool m_vertex = false;
	bool m_wireframe = true;
	bool m_surface = true;

	// === vtk ====
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> m_renderWindow;
	vtkSmartPointer<vtkRenderer> m_renderer;
public:
	Engine(QVTKOpenGLNativeWidget* parent);

	void updateRenderedObjects();
	void setBackgroundColor(QColor color = QColor("black"));
	void setVertexColorToObjects(QColor color, std::vector<int> selectedIds = {});
	void setEdgeColorToObjects(QColor color, std::vector<int> selectedIds = {});
	void setSurfaceColorToObjects(QColor color, std::vector<int> selectedIds = {});

	void setOpacityToObjects(double opacity, std::vector<int> selectedIds = {});
	void setSingleContourToObjects(bool singleContour, std::vector<int> selectedIds = {});
	void setNContoursToObjects(int nContours, std::vector<int> selectedIds = {});
	void setIsoLevelToObjects(double isoLevel, std::vector<int> selectedIds = {});
	void setDIsoToObjects(double dIso, std::vector<int> selectedIds = {});

	void addPolyDataObjectToScene(vtkSmartPointer<vtkPolyData> model, QString filename);
	void addImageDataObjectToScene(vtkSmartPointer<vtkImageData> img, QString filename);
	void addGridDataObjectToScene(Grid* grid, QString name);
	void removeObjectFromLibrary(int id);
	void clearObjectLibrary();

	SceneObject* getLibraryObject(int id);

	void addHelperObjectToScene(SceneObject helper, QColor helper_color = QColor(52, 235, 180));
	void clearHelperObjects();

	void setVertexRepresentationOfObjects(bool representation, std::vector<int> selectedIds = {});
	void setWireframeRepresentationOfObjects(bool representation, std::vector<int> selectedIds = {});
	void setSurfaceRepresentationOfObjects(bool representation, std::vector<int> selectedIds = {});

	void setSelectedObjectId(int id);
	void setVisibilityOfObject(bool visible, int id);
	void setVertexRepresentationOfObject(bool representation, int id);
	void setWireframeRepresentationOfObject(bool representation, int id);
	void setSurfaceRepresentationOfObject(bool representation, int id);

	inline bool libraryEmpty() { return m_libObjects.empty(); };

	inline bool vertexRender() { return m_vertex; };
	inline bool edgeRender() { return m_wireframe; };
	inline bool surfaceRender() { return m_surface; };	

	inline QColor bgColor() { return m_bgColor; };
	inline QColor vertexColor() { return m_vertexColor; };
	inline QColor edgeColor() { return m_edgeColor; };
	inline QColor surfaceColor() { return m_surfaceColor; };

	inline double opacity() { return m_opacity; };
	inline double currentIsoLevel() { return m_isoLevelVal; };

	inline int selectedId() { return m_objId; };
};

#endif