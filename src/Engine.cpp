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

	for (SceneObject obj : m_libObjects) {
		if (obj.isVisible()) {
			if (obj.vertexRender()) m_renderer->AddActor(obj.getVertexActor());
			if (obj.edgeRender()) m_renderer->AddActor(obj.getEdgeActor());
			if (obj.surfaceRender()) m_renderer->AddActor(obj.getSurfaceActor());
		}
	}

	for (SceneObject help : m_helperObjects) {
		m_renderer->AddActor(help.getEdgeActor());
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
		for (SceneObject obj : m_libObjects) {
			obj.setVertexColor(color);
		}
	}
	else {
		for (int id : selectedIds) {
			m_libObjects[id].setVertexColor(color);
		}
	}

	m_renderWindow->Render();
}

void Engine::setEdgeColorToObjects(QColor color, std::vector<int> selectedIds)
{
	if (selectedIds.empty()) {
		for (SceneObject obj : m_libObjects) {
			obj.setEdgeColor(color);
		}
	}
	else {
		for (int id : selectedIds) {
			m_libObjects[id].setEdgeColor(color);
		}
	}

	m_renderWindow->Render();
}

void Engine::setSurfaceColorToObjects(QColor color, std::vector<int> selectedIds)
{
	if (selectedIds.empty()) {
		for (SceneObject obj : m_libObjects) {
			obj.setSurfaceColor(color);
		}
	}
	else {
		for (int id : selectedIds) {
			m_libObjects[id].setSurfaceColor(color);
		}
	}

	m_renderWindow->Render();
}

void Engine::setOpacityToObjects(double opacity, std::vector<int> selectedIds)
{
	if (selectedIds.empty()) {
		for (SceneObject obj : m_libObjects) {
			obj.setOpacity(opacity);
		}
	}
	else {
		for (int id : selectedIds) {
			m_libObjects[id].setOpacity(opacity);
		}
	}

	m_renderWindow->Render();
}

void Engine::setSingleContourToObjects(bool singleContour, std::vector<int> selectedIds)
{
	if (!selectedIds.empty()) {
		for (int id : selectedIds) {
			if (m_libObjects[id].type() == ObjectType::SGrid) {
				m_libObjects[id].setSingleContour(singleContour);
			}
		}
	}
	updateRenderedObjects();
}

void Engine::setNContoursToObjects(int nContours, std::vector<int> selectedIds)
{
	if (!selectedIds.empty()) {
		for (int id : selectedIds) {
			if (m_libObjects[id].type() == ObjectType::SGrid) {
				m_libObjects[id].setNContours(nContours);
			}
		}
	}
	updateRenderedObjects();
}

void Engine::setIsoLevelToObjects(double isoLevel, std::vector<int> selectedIds)
{
	if (!selectedIds.empty()) {
		for (int id : selectedIds) {
			if (m_libObjects[id].type() == ObjectType::SGrid) {
				m_libObjects[id].setIsoLevel(isoLevel);
				m_isoLevelVal = m_libObjects[id].isoLevel();
			}
		}
	}
	updateRenderedObjects();
}

void Engine::setDIsoToObjects(double dIso, std::vector<int> selectedIds)
{
	if (!selectedIds.empty()) {
		for (int id : selectedIds) {
			if (m_libObjects[id].type() == ObjectType::SGrid) {
				m_libObjects[id].setDIso(dIso);
			}
		}
	}
	updateRenderedObjects();
}

void Engine::addPolyDataObjectToScene(vtkSmartPointer<vtkPolyData> model, QString filename)
{
	m_libObjects.push_back(SceneObject(model, filename));
}

void Engine::addImageDataObjectToScene(vtkSmartPointer<vtkImageData> img, QString filename)
{
	m_libObjects.push_back(SceneObject(img, filename, true, true));
}

void Engine::addGridDataObjectToScene(Grid* grid, QString name)
{
	m_libObjects.push_back(SceneObject(grid, name));
}

void Engine::removeObjectFromLibrary(int id)
{
	if (id < 0 || id >= m_libObjects.size()) return;

	m_libObjects.erase(m_libObjects.begin() + id);
	updateRenderedObjects();
}

void Engine::clearObjectLibrary()
{
	m_libObjects.clear();
	updateRenderedObjects();
}

SceneObject* Engine::getLibraryObject(int id)
{
	if (id < 0 || id >= m_libObjects.size()) return nullptr;

	return &m_libObjects[id];
}

void Engine::addHelperObjectToScene(SceneObject helper, QColor helper_color)
{
	helper.setEdgeColor(helper_color);
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
		for (SceneObject obj : m_libObjects) {
			obj.setVertexRepresentation(representation);
		}
	}
	else {
		for (int id : selectedIds) {
			m_libObjects[id].setVertexRepresentation(representation);
		}
	}
}

void Engine::setWireframeRepresentationOfObjects(bool representation, std::vector<int> selectedIds)
{
	if (selectedIds.empty()) {
		for (SceneObject obj : m_libObjects) {
			obj.setWireframeRepresentation(representation);
		}
	}
	else {
		for (int id : selectedIds) {
			m_libObjects[id].setWireframeRepresentation(representation);
		}
	}
}

void Engine::setSurfaceRepresentationOfObjects(bool representation, std::vector<int> selectedIds)
{
	if (selectedIds.empty()) {
		for (SceneObject obj : m_libObjects) {
			obj.setSurfaceRepresentation(representation);
		}
	}
	else {
		for (int id : selectedIds) {
			m_libObjects[id].setSurfaceRepresentation(representation);
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

	m_libObjects.at(id).setVisible(visible);
	updateRenderedObjects();
}

void Engine::setVertexRepresentationOfObject(bool representation, int id)
{
	if (id < 0 || id >= m_libObjects.size()) return;

	m_libObjects[id].setVertexRepresentation(representation);
}

void Engine::setWireframeRepresentationOfObject(bool representation, int id)
{
	if (id < 0 || id >= m_libObjects.size()) return;

	m_libObjects[id].setWireframeRepresentation(representation);
}

void Engine::setSurfaceRepresentationOfObject(bool representation, int id)
{
	if (id < 0 || id >= m_libObjects.size()) return;

	m_libObjects[id].setSurfaceRepresentation(representation);
}
