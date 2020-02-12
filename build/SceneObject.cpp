#include "SceneObject.h"

SceneObject::SceneObject()
{
}

SceneObject::SceneObject(const SceneObject& other)
{
}

void SceneObject::sendActorToRenderer(int representationId, vtkRenderer* renderer)
{
	if (representationId == 0) {
		renderer->AddActor(this->vertexActor);
	}
	else if (representationId == 1) {
		renderer->AddActor(this->edgeActor);
	}
	else {
		renderer->AddActor(this->surfaceActor);
	}
}

void SceneObject::initMesh()
{
	double center[3] = { -1, 2, 3 };
	this->source->SetCenter(center);
	this->source->Update();

	// vtkNew<vtkPolyDataMapper> vertexMapper;
	vertexMapper->SetInputConnection(source->GetOutputPort());

	// vtkNew<vtkPolyDataMapper> edgeMapper;
	edgeMapper->SetInputConnection(source->GetOutputPort());

	// vtkNew<vtkPolyDataMapper> surfaceMapper;
	surfaceMapper->SetInputConnection(source->GetOutputPort());

	vertexActor->GetProperty()->SetRepresentationToPoints();
	edgeActor->GetProperty()->SetRepresentationToWireframe();
	surfaceActor->GetProperty()->SetRepresentationToSurface();

	// set mappers to actors
	vertexActor->SetMapper(vertexMapper);
	edgeActor->SetMapper(edgeMapper);
	surfaceActor->SetMapper(surfaceMapper);

	edgeActor->GetProperty()->SetAmbient(1.0);
	edgeActor->GetProperty()->SetDiffuse(0.0);
	edgeActor->GetProperty()->SetSpecular(0.0);

	vertexActor->GetProperty()->SetColor(colors->GetColor4d("midnightblue").GetData());
	edgeActor->GetProperty()->SetColor(colors->GetColor4d("midnightblue").GetData());
	surfaceActor->GetProperty()->SetColor(colors->GetColor4d("mintcream").GetData());
}
