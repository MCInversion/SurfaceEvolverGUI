#include "Engine.h"

Engine::Engine(QVTKOpenGLNativeWidget* parent)
{
	m_parentWidget = parent;

	m_renderer = vtkSmartPointer<vtkRenderer>::New();
	m_renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();

	m_renderWindow->AddRenderer(m_renderer);
	m_renderWindow->SetWindowName("SurfaceEvolverGUI");
	m_parentWidget->SetRenderWindow(m_renderWindow);

	setBackgroundColor();
}

void Engine::updateRenderedObjects()
{
	m_renderer->RemoveAllViewProps();

	for (const std::shared_ptr<MeshObject>& obj : m_objects) {
		if (obj->isVisible()) {
			if (obj->vertexRender()) m_renderer->AddActor(obj->getVertexActor());
			if (obj->edgeRender()) m_renderer->AddActor(obj->getEdgeActor());
			if (obj->surfaceRender()) m_renderer->AddActor(obj->getSurfaceActor());
		}
	}

	m_renderer->ResetCamera();
	m_renderWindow->Render();
}

void Engine::setBackgroundColor(QColor color)
{
	m_bgColor = color;

	double r = (double)m_bgColor.red() / 255.;
	double g = (double)m_bgColor.green() / 255.;
	double b = (double)m_bgColor.blue() / 255.;
	m_renderer->SetBackground(r, g, b);
	m_renderWindow->Render();
}

void Engine::setVertexColorToObjects(QColor color, std::vector<int> selectedIds)
{
	if (selectedIds.empty()) {
		for (const std::shared_ptr<MeshObject>& obj : m_objects) {
			obj->setVertexColor(color);
		}
	}

	m_renderWindow->Render();
}

void Engine::setEdgeColorToObjects(QColor color, std::vector<int> selectedIds)
{
	if (selectedIds.empty()) {
		for (const std::shared_ptr<MeshObject>& obj : m_objects) {
			obj->setEdgeColor(color);
		}
	}

	m_renderWindow->Render();
}

void Engine::setSurfaceColorToObjects(QColor color, std::vector<int> selectedIds)
{
	if (selectedIds.empty()) {
		for (const std::shared_ptr<MeshObject>& obj : m_objects) {
			obj->setSurfaceColor(color);
		}
	}

	m_renderWindow->Render();
}

void Engine::setOpacityToObjects(double opacity, std::vector<int> selectedIds)
{
	if (selectedIds.empty()) {
		for (const std::shared_ptr<MeshObject>& obj : m_objects) {
			obj->setOpacity(opacity);
		}
	}

	m_renderWindow->Render();
}

void Engine::addPolyDataObjectToScene(vtkSmartPointer<vtkPolyData> model)
{
	std::shared_ptr<MeshObject> mObj = std::make_shared<MeshObject>(MeshObject(model));
	m_objects.push_back(mObj);
}

void Engine::removeMeshObjectFromLibrary(int id)
{
	if (id < 0 || id >= m_objects.size()) return;

	m_objects.erase(m_objects.begin() + id);
	updateRenderedObjects();
}

void Engine::clearMeshObjectLibrary()
{
	m_objects.clear();
	updateRenderedObjects();
}

std::shared_ptr<MeshObject> Engine::getLibraryObject(int id)
{
	if (id < 0 || id >= m_objects.size()) return nullptr;

	return m_objects[id];
}

void Engine::setVertexRepresentationOfAllObjects(bool representation)
{
	for (const std::shared_ptr<MeshObject>& obj : m_objects) {
		obj->setVertexRepresentation(representation);
	}
}

void Engine::setWireframeRepresentationOfAllObjects(bool representation)
{
	for (const std::shared_ptr<MeshObject>& obj : m_objects) {
		obj->setWireframeRepresentation(representation);
	}
}

void Engine::setSurfaceRepresentationOfAllObjects(bool representation)
{
	for (const std::shared_ptr<MeshObject>& obj : m_objects) {
		obj->setSurfaceRepresentation(representation);
	}
}

void Engine::setSelectedObjectId(int id)
{
	m_objId = id;
}

void Engine::setVisibilityOfObject(bool visible, int id)
{
	if (id < 0 || id >= m_objects.size()) return;

	m_objects.at(id)->setVisible(visible);
}

void Engine::setVertexRepresentationOfObject(bool representation, int id)
{
	if (id < 0 || id >= m_objects.size()) return;

	m_objects.at(id)->setVertexRepresentation(representation);
}

void Engine::setWireframeRepresentationOfObject(bool representation, int id)
{
	if (id < 0 || id >= m_objects.size()) return;

	m_objects.at(id)->setWireframeRepresentation(representation);
}

void Engine::setSurfaceRepresentationOfObject(bool representation, int id)
{
	if (id < 0 || id >= m_objects.size()) return;

	m_objects.at(id)->setSurfaceRepresentation(representation);
}
