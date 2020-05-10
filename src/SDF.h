#ifndef SDF_H_
#define SDF_H_

#include "Grid.h"
#include "FastSweep3D.h"
#include "Octree.h"
#include "VTKExporter.h"
#include "Parameters.h"

enum class SDF_Method {
	fast_sweeping = 0,
	aabb_dist = 1,
	brute_force = 2,
};

class SDF
{
public:
	Geometry* geom = nullptr;
	AABBTree* tri_aabb = nullptr;
	AABBTree* edge_aabb = nullptr;
	AABBTree* vert_aabb = nullptr;
	Octree* octree = nullptr;
	Grid* grid = nullptr; // contains scalar field (& its gradient)
	FastSweep3D* fastSweep = nullptr;

	uint resolution;
	SDF_Method method = SDF_Method::fast_sweeping;

	std::string geom_properties = "";
	std::string time_log = "";
	std::string last_transform = "";
	std::string grid_export_name = "";

	SDF();
	SDF(const SDF& other);
	SDF(SDFParams* sdfParams);
	SDF(Geometry* geom, uint resolution, bool computeSign = false, bool computeGradient = true,
		bool saveGridStates = false, bool scaleAndInterpolate = false, SDF_Method method = SDF_Method::fast_sweeping);

	void exportGrid(VTKExporter* e, std::string export_name = "");
	void exportGrid(std::string export_name = "", std::string path = "");
	void exportGradientField(VTKExporter* e, std::string export_name = "");
	std::string getComputationProperties();

	void applyMatrix(Matrix4& m);
public:
	uint resolution_limit = 20;
};

#endif