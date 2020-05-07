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

#include <MeshObject.h>

class Engine
{
private:
	QVTKOpenGLNativeWidget* m_parentWidget = nullptr;

	QColor m_bgColor = QColor("black");

	std::vector<std::shared_ptr<MeshObject>> m_objects;

	// render style
	bool m_vertex = false;
	bool m_wireframe = true;
	bool m_surface = true;
public:
	Engine(QVTKOpenGLNativeWidget* parent);

	void updateRenderedObjects();
	void setBackgroundColor(QColor color = QColor("black"));

	void addPolyDataObjectToScene(vtkSmartPointer<vtkPolyData> model);
	void removeMeshObjectFromLibrary(int id);

	void setVertexRepresentationOfAllObjects(bool representation);
	void setWireframeRepresentationOfAllObjects(bool representation);
	void setSurfaceRepresentationOfAllObjects(bool representation);

	void setVisibilityOfObject(bool visible, int id);
	void setVertexRepresentationOfObject(bool representation, int id);
	void setWireframeRepresentationOfObject(bool representation, int id);
	void setSurfaceRepresentationOfObject(bool representation, int id);

	inline QColor bgColor() { return m_bgColor; };

	// === vtk ====
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> m_renderWindow;
	vtkSmartPointer<vtkRenderer> m_renderer;

	// vtkSmartPointer<vtkNamedColors> m_colors;
};

#endif