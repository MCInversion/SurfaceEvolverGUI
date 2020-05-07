#ifndef ENGINE_H
#define ENGINE_H


#include <array>
#include <cstdint>
#include <vector>
#include <memory>

#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkPolyData.h>

#include <MeshObject.h>

class Engine
{
private:
	std::vector<std::shared_ptr<MeshObject>> m_objects;
public:
	Engine();
};

#endif