#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyDataAlgorithm.h>
#include <vtkSphereSource.h>
#include <vtkVersion.h>

class SceneObject
{
public:
	// actors
	vtkNew<vtkActor> vertexActor;
	vtkNew<vtkActor> edgeActor;
	vtkNew<vtkActor> surfaceActor;
	// mappers
	vtkNew<vtkPolyDataMapper> vertexMapper;
	vtkNew<vtkPolyDataMapper> edgeMapper;
	vtkNew<vtkPolyDataMapper> surfaceMapper;
	// color
	vtkNew<vtkNamedColors> colors;
	// source
	vtkNew<vtkSphereSource> source;

	SceneObject();
	SceneObject(const SceneObject& other);
	~SceneObject() = default;
};

#endif

