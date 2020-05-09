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

#include "MeshObject.h"

class Engine
{
private:
	QVTKOpenGLNativeWidget* m_parentWidget = nullptr;

	QColor m_bgColor = QColor("black");

	QColor m_vertexColor = QColor(13, 18, 56);
	QColor m_edgeColor = QColor(0, 74, 194);
	QColor m_surfaceColor = QColor(237, 224, 206);

	double m_opacity = 1.0;

	std::vector<std::shared_ptr<MeshObject>> m_objects;

	int m_objId = 0;

	// render style
	bool m_vertex = false;
	bool m_wireframe = true;
	bool m_surface = true;
public:
	Engine(QVTKOpenGLNativeWidget* parent);


	void updateRenderedObjects();
	void setBackgroundColor(QColor color = QColor("black"));
	void setVertexColorToObjects(QColor color, std::vector<int> selectedIds = {});
	void setEdgeColorToObjects(QColor color, std::vector<int> selectedIds = {});
	void setSurfaceColorToObjects(QColor color, std::vector<int> selectedIds = {});

	void setOpacityToObjects(double opacity, std::vector<int> selectedIds = {});

	void addPolyDataObjectToScene(vtkSmartPointer<vtkPolyData> model);
	void removeMeshObjectFromLibrary(int id);
	void clearMeshObjectLibrary();

	std::shared_ptr<MeshObject> getLibraryObject(int id);

	void setVertexRepresentationOfObjects(bool representation, std::vector<int> selectedIds = {});
	void setWireframeRepresentationOfObjects(bool representation, std::vector<int> selectedIds = {});
	void setSurfaceRepresentationOfObjects(bool representation, std::vector<int> selectedIds = {});

	void setSelectedObjectId(int id);
	void setVisibilityOfObject(bool visible, int id);
	void setVertexRepresentationOfObject(bool representation, int id);
	void setWireframeRepresentationOfObject(bool representation, int id);
	void setSurfaceRepresentationOfObject(bool representation, int id);

	inline bool vertexRender() { return m_vertex; };
	inline bool edgeRender() { return m_wireframe; };
	inline bool surfaceRender() { return m_surface; };

	inline QColor bgColor() { return m_bgColor; };
	inline QColor vertexColor() { return m_vertexColor; };
	inline QColor edgeColor() { return m_edgeColor; };
	inline QColor surfaceColor() { return m_surfaceColor; };

	inline double opacity() { return m_opacity; };

	// === vtk ====
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> m_renderWindow;
	vtkSmartPointer<vtkRenderer> m_renderer;
};

#endif