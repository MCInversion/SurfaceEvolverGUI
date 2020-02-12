#ifndef SurfaceEvolverGUI_H
#define SurfaceEvolverGUI_H

#include "SceneObject.h"
#include <set>
#include <string>

#include <vtkSmartPointer.h>

#include <QMainWindow>
#include <QColorDialog>

#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSphereSource.h>
#include <vtkVersion.h>

// Forward Qt class declarations
class Ui_SurfaceEvolverGUI;

class SurfaceEvolverGUI : public QMainWindow
{
  Q_OBJECT
public:
  // Constructor/Destructor
  SurfaceEvolverGUI();
  ~SurfaceEvolverGUI() = default;
  QColor bgColor = QColor("black");

  void updateRenderedObjects();

public slots:

  void slotExit();
  void ActionRendererBackgroundColor();
  void ActionRenderVertices();
  void ActionRenderWireframe();
  void ActionRenderSurface();

private:
   // render style
    bool _vertex = false;
    bool _wireframe = true;
    bool _surface = true;

    // Designer form
    Ui_SurfaceEvolverGUI* ui;
  
    std::vector<SceneObject> sceneObjects = { };
    // === vtk ====
    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    vtkNew<vtkRenderer> renderer;

    vtkNew<vtkNamedColors> colors;
    vtkNew<vtkSphereSource> source;
};

#endif
