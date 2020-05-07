#include <QApplication>
#include <QSurfaceFormat>
#include <QVTKOpenGLNativeWidget.h>

#include "SurfaceEvolverGUI.h"

//   DONE:
//
// - Add an AABBTree structure
// - Add an Octree for activating intersected grid cells
// - Make a "fast" cell intersection query
// - Set intersected cell values to 0 and INFINITY everywhere else
// - Apply Fast Sweeping Method
// - SDF
// - Optimize initial condition for FastSweep3D by actual distance computation for Octree leaves
// - Get exact octree centroid to closest triangle dist
// - Unite AABB, Octree and FastSweep3D into a single class
// - debug and optimize FastSweep3D
// - interpolate distance field for higher resolutions (not much improvement)
// - perform simple DF tests for geom primitives like sphere, icosphere, cubesphere
// - optimize Box-Triangle intersection
// - add Quaternion class and TRS decomposition of Matrix4
// - adaptive resampling of split cost function (done for 2 * 4 samples - 265-bit registers)
// - minimize split cost function using a piecewise-quadratic interpolation to find the minimum (20% slower than simple cost(x) < minCost comparison)
// - matrix multiplication for Matrix4
// - flood fill for sign computation of SDF
// - Test mesh angle weighted pseudonormals
// - test if grid gradient is computed correctly by exporting to a vtk vector file.
// - finite volume normal derivatives (Laplace-Beltrami)
// - compose a linear system for evolution from CubeSphere to PrimitiveBox of the same subdivision level
// - mean curvature flow for sphere test (cotan scheme)
// - fix lagging numerical solution for sphere test
// - test evolution without tangential redistribution on different objects
// - compute mean area for finite volumes in each time step
// - test a non-convex model (e.g.: bunny)
// - make separate outputs for mean co-volume measure
// - implement cutoff offset for the bounding cube to compute the field on minimum necessary subset (box)
// - visualize angle-weighted pseudo-normals with interpolated -grad(SDF) vectors
// - add scalar data (fvAreas, distances, curvatures) to mesh vertices
// - Special types: SEvolverParams, SDFParams,...
// - SurfaceEvolutionSolver -> Evolver, LinearSolver
// - refactor and separate console and log outputs for specific situations
// - catch all NaNs as exceptions (breaks)
// - test evolution for extremal cases: MCF dominant (eta = 0.01, eps = 1.0) and SDF dominant (eta = 1, eps = 0.01)
// - previous step mean curvature values H => H N = h (mean curvature vector)
// - previous step normal velocity term: v_N = eps(d) * h + eta(d) * N
// - tangential redist. lin. system: Laplace-Beltrami(psi) = dot( v_N, h ) - mean(dot( v_N , h) + omega * (A/G - 1)
// - Evolution from an input geometry
// - Sphere test with tangential redistribution TR (exceptionally slow for the last icosphere subdiv)
// - MCF-TR sphere test with an inhomogeneous distribution of vertices
// - MCF-TR(& w\o TR) evolution test on an ellipsoid
// - Angle-Based Tangential redistribution
// - polygon adjacency for boundary vertices

//  POSTPONED:
//
// - co-volume measure-driven time step: dt ~ m(V)
// - implement a method/class to get CPU instruction set, mainly whether it supports AVX, an alternate resampling method has to be implemented for CPU's that do not support AVX
// - implement sort order function of a 256-bit AVX vector (needs a proper lookup hash)
// - AABB update for transformations + Timing test
// - Inverse transform grid upon transforming mesh
// - implement adaptive resampling for 512-bit registers - 2 * 8 sampling positions (if possible)
// - compare results with CGAL distance query implementation
// - sign computation \w (arbitrary)ray-mesh intersection (even # of intersections = 1, odd # of intersections = -1)
//   Important notes:
//		- split position matters, yet sometimes a less precise estimate yields better result than quad min. Trying 8 sample positions could help
//		- still no idea why the near/far cycle's written this way. Sometimes it leads the traversal to only one intersection, ignoring the rest, because they're "far"
// - flat AABB and Octree (we can try, but this would require dynamic arrays (i.e.: std::vectors) which would be slower than allocation)
// - fix apparent interpolation bug for SDF values and gradients (is there one?)

//   DONE, BUT MIGHT BE IMPROVED:
//
// - AABB and Octree have to take as little space as possible
// - implement generic triangle/quad centroid co-volume procedure (centroid on triangulated polygon)

//   WIP:
// 
//

//   TODO:
//
// - fix cotan scheme for boundary vertices
// - fix finite volume computation for obtuse angles according to Desbrun
// - impose Dirichlet boundary conditions on Evolver
// - Debug volume-based TR - psi rhs has to have a zero sum
//
// - fix SDF coordinates (use global grid indexing)
// - implement global grid and cellSize-based Octree & SDF (just like in Vctr Engine Meta Object)
// - finish class EvolutionRemesher with all params
//
// - quad co-volume scheme
// - mean curvature flow for sphere test (quad scheme)
// - mean curvature flow for sphere test (tri interp scheme)
 
int main( int argc, char** argv )
{
  // needed to ensure appropriate OpenGL context is created for VTK rendering.
  QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());

  // QT Stuff
  QApplication app( argc, argv );
 
  SurfaceEvolverGUI surfaceEvolverGUI;
  surfaceEvolverGUI.show();
 
  return app.exec();
}
