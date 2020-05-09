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

	for (const std::shared_ptr<MeshObject>& obj : m_libObjects) {
		if (obj->isVisible()) {
			if (obj->vertexRender()) m_renderer->AddActor(obj->getVertexActor());
			if (obj->edgeRender()) m_renderer->AddActor(obj->getEdgeActor());
			if (obj->surfaceRender()) m_renderer->AddActor(obj->getSurfaceActor());
		}
	}

	for (const std::shared_ptr<MeshObject>& help : m_helperObjects) {
		m_renderer->AddActor(help->getEdgeActor());
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
		for (const std::shared_ptr<MeshObject>& obj : m_libObjects) {
			obj->setVertexColor(color);
		}
	}
	else {
		for (int id : selectedIds) {
			m_libObjects[id]->setVertexColor(color);
		}
	}

	m_renderWindow->Render();
}

void Engine::setEdgeColorToObjects(QColor color, std::vector<int> selectedIds)
{
	if (selectedIds.empty()) {
		for (const std::shared_ptr<MeshObject>& obj : m_libObjects) {
			obj->setEdgeColor(color);
		}
	}
	else {
		for (int id : selectedIds) {
			m_libObjects[id]->setEdgeColor(color);
		}
	}

	m_renderWindow->Render();
}

void Engine::setSurfaceColorToObjects(QColor color, std::vector<int> selectedIds)
{
	if (selectedIds.empty()) {
		for (const std::shared_ptr<MeshObject>& obj : m_libObjects) {
			obj->setSurfaceColor(color);
		}
	}
	else {
		for (int id : selectedIds) {
			m_libObjects[id]->setSurfaceColor(color);
		}
	}

	m_renderWindow->Render();
}

void Engine::setOpacityToObjects(double opacity, std::vector<int> selectedIds)
{
	if (selectedIds.empty()) {
		for (const std::shared_ptr<MeshObject>& obj : m_libObjects) {
			obj->setOpacity(opacity);
		}
	}
	else {
		for (int id : selectedIds) {
			m_libObjects[id]->setOpacity(opacity);
		}
	}

	m_renderWindow->Render();
}

void Engine::addPolyDataObjectToScene(vtkSmartPointer<vtkPolyData> model, QString filename)
{
	std::shared_ptr<MeshObject> mObj = std::make_shared<MeshObject>(MeshObject(model, filename));
	m_libObjects.push_back(mObj);
}

void Engine::removeMeshObjectFromLibrary(int id)
{
	if (id < 0 || id >= m_libObjects.size()) return;

	m_libObjects.erase(m_libObjects.begin() + id);
	updateRenderedObjects();
}

void Engine::clearMeshObjectLibrary()
{
	m_libObjects.clear();
	updateRenderedObjects();
}

std::shared_ptr<MeshObject> Engine::getLibraryObject(int id)
{
	if (id < 0 || id >= m_libObjects.size()) return nullptr;

	return m_libObjects[id];
}

void Engine::addHelperObjectToScene(std::shared_ptr<MeshObject> helper, QColor helper_color)
{
	helper->setEdgeColor(helper_color);
	m_helperObjects.push_back(helper);
}

void Engine::clearHelperObjects()
{
	m_helperObjects.clear();
	updateRenderedObjects();
}

void Engine::setVertexRepresentationOfObjects(bool representation, std::vector<int> selectedIds)
{
	if (selectedIds.empty()) {
		for (const std::shared_ptr<MeshObject>& obj : m_libObjects) {
			obj->setVertexRepresentation(representation);
		}
	}
	else {
		for (int id : selectedIds) {
			m_libObjects[id]->setVertexRepresentation(representation);
		}
	}

}

void Engine::setWireframeRepresentationOfObjects(bool representation, std::vector<int> selectedIds)
{
	if (selectedIds.empty()) {
		for (const std::shared_ptr<MeshObject>& obj : m_libObjects) {
			obj->setWireframeRepresentation(representation);
		}
	}
	else {
		for (int id : selectedIds) {
			m_libObjects[id]->setWireframeRepresentation(representation);
		}
	}
}

void Engine::setSurfaceRepresentationOfObjects(bool representation, std::vector<int> selectedIds)
{
	if (selectedIds.empty()) {
		for (const std::shared_ptr<MeshObject>& obj : m_libObjects) {
			obj->setSurfaceRepresentation(representation);
		}
	}
	else {
		for (int id : selectedIds) {
			m_libObjects[id]->setSurfaceRepresentation(representation);
		}
	}
}

void Engine::setSelectedObjectId(int id)
{
	m_objId = id;
}

void Engine::setVisibilityOfObject(bool visible, int id)
{
	if (id < 0 || id >= m_libObjects.size()) return;

	m_libObjects.at(id)->setVisible(visible);
	updateRenderedObjects();
}

void Engine::setVertexRepresentationOfObject(bool representation, int id)
{
	if (id < 0 || id >= m_libObjects.size()) return;

	m_libObjects.at(id)->setVertexRepresentation(representation);
}

void Engine::setWireframeRepresentationOfObject(bool representation, int id)
{
	if (id < 0 || id >= m_libObjects.size()) return;

	m_libObjects.at(id)->setWireframeRepresentation(representation);
}

void Engine::setSurfaceRepresentationOfObject(bool representation, int id)
{
	if (id < 0 || id >= m_libObjects.size()) return;

	m_libObjects.at(id)->setSurfaceRepresentation(representation);
}
