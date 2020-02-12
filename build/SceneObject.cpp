#include "SceneObject.h"

SceneObject::SceneObject()
{
	this->source->Update();

	this->vertexMapper->SetInputConnection(this->source->GetOutputPort());
	this->edgeMapper->SetInputConnection(this->source->GetOutputPort());
	this->surfaceMapper->SetInputConnection(this->source->GetOutputPort());

	this->vertexActor->GetProperty()->SetRepresentationToPoints();
	this->edgeActor->GetProperty()->SetRepresentationToWireframe();
	this->surfaceActor->GetProperty()->SetRepresentationToSurface();

	this->surfaceMapper->SetResolveCoincidentTopologyPolygonOffsetParameters(0, 1);
	this->surfaceMapper->SetResolveCoincidentTopologyToPolygonOffset();
	this->edgeMapper->SetResolveCoincidentTopologyPolygonOffsetParameters(1, 1);
	this->edgeMapper->SetResolveCoincidentTopologyToPolygonOffset();
	this->vertexMapper->SetResolveCoincidentTopologyPolygonOffsetParameters(2, 1);
	this->vertexMapper->SetResolveCoincidentTopologyToPolygonOffset();

	this->edgeMapper->ScalarVisibilityOff();

	// set mappers to actors
	this->vertexActor->SetMapper(this->vertexMapper);
	this->edgeActor->SetMapper(this->edgeMapper);
	this->surfaceActor->SetMapper(this->surfaceMapper);
	
	this->edgeActor->GetProperty()->SetAmbient(1.0);
	this->edgeActor->GetProperty()->SetDiffuse(0.0);
	this->edgeActor->GetProperty()->SetSpecular(0.0);

	this->vertexActor->GetProperty()->SetColor(colors->GetColor4d("midnightblue").GetData());
	this->edgeActor->GetProperty()->SetColor(colors->GetColor4d("midnightblue").GetData());
	this->surfaceActor->GetProperty()->SetColor(colors->GetColor4d("mintcream").GetData());
}

SceneObject::SceneObject(const SceneObject& other)
{
}
