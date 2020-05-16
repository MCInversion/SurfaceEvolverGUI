#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include <string>
#include "Geometry.h"
#include "Grid.h"

struct SDFParams {
	unsigned int octree_resolution = 40;
	unsigned int NSweeps = 8;
	double grid_expansion_factor = 1.0;

	Geometry* targetGeom = nullptr;

	bool compute_sign = true;

	// other params are merely for testing on Develop
};

enum class ElementType {
	tri = 0,
	quad = 1
};

struct EvolutionParams {
	double dt = 0.01;
	double tStop = 1.0;
	int NSteps = 10;
	unsigned int subdiv = 2;
	ElementType elType = ElementType::tri;

	std::string name = "Sphere";

	Geometry* sourceGeometry = nullptr;

	// ===== output flags ==========
	bool saveStates = false;
	bool saveResult = true;
	bool printHappenings = false;
	bool printStepOutput = false;
	bool printSolution = false;

	bool writeGenericLog = true;
	bool writeTimeLog = false;
	// =============================
};

struct SphereTestParams {
	double r0 = 1.0;
	int testId = -1;

	// ===== output flags ==========
	bool writeErrorLog = false;
	// =============================
};

struct MeanCurvatureParams {
	// Laplace-Beltrami ctrl constants:
	double rDecay = 1.0;
	double C1 = 1.0;
	double C2 = rDecay;

	bool constant = false;

	// ===== output flags ==========
	bool saveAreaStates = false;
	bool saveCurvatureStates = false;
	bool saveNormalVelocityStates = false;
	bool saveCurvatureVectors = false;

	bool writeMeanAreaLog = false;
	// =============================

	int smoothSteps = -1; // -1 - no smooth steps
	double initSmoothRate = 0.05;
	double smoothDecay = 0.1;
};

struct GradDistanceParams {
	Geometry* targetGeom = nullptr;
	Grid* sdfGrid = nullptr;

	// grad SDF ctrl constants:
	double C = 1.0;
	double D = 0.0;

	bool constant = false;

	// ===== output flags ==========
	bool saveDistanceStates = false;
	bool saveGradientStates = false;
	// =============================
};

struct TangentialRedistParams {
	// ctrl params
	double omega_volume = 100.0;
	double omega_angle = 2.0;

	// ===== Redistribution type =======
	int type = 0; // -1 - none, 0 - angle-based, 1 - volume-based, 2 - length-based

	// ===== output flags ======
	bool saveTangentialVelocityStates = false;
	// ================
};

#endif
