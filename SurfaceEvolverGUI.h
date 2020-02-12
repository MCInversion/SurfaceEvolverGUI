#ifndef SurfaceEvolverGUI_H
#define SurfaceEvolverGUI_H

#include "SceneObject.h"

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

public slots:

  void slotExit();
  void ActionRendererBackgroundColor();

private:
   // render style
    bool _vertex = true;
    bool _wireframe = true;
    bool _surface = true;

  // Designer form
  Ui_SurfaceEvolverGUI* ui;
  
  std::vector<SceneObject> sceneObjects = { };
  // === vtk ====
  vtkNew <vtkGenericOpenGLRenderWindow> renderWindow;
  vtkNew <vtkRenderer> renderer;
};

#endif
