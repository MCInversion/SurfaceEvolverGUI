#ifndef SurfaceEvolverGUI_H
#define SurfaceEvolverGUI_H

#include <QMainWindow>
#include <QColorDialog>
#include <QFileDialog>

#include <iostream>

#include <vtkDataReader.h>
#include <vtkSimpleReader.h>
#include <vtkPolyDataReader.h>
#include <vtkCamera.h>
#include <vtkCenterOfMass.h>
#include <vtkBoundingBox.h>

#include <vtkNew.h>
#include <vtkSmartPointer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkNamedColors.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSphereSource.h>
#include <vtkVersion.h>

#include <vtksys/SystemTools.hxx>

#include <Engine.h>

namespace
{
    vtkSmartPointer<vtkPolyData> ReadPolyData(const char* fileName);
}

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
  void fitToView();

public slots:

  void slotExit();

  void ActionRendererBackgroundColor();
  void ActionRenderVertices();
  void ActionRenderWireframe();
  void ActionRenderSurface();

  void ActionOpenFile();
  void ActionSaveFile();

private:
   // render style
    bool _vertex = false;
    bool _wireframe = true;
    bool _surface = true;

    // Engine
    Engine m_engine;

    // Designer form
    Ui_SurfaceEvolverGUI* ui;
  
    // === vtk ====
    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    vtkNew<vtkRenderer> renderer;

    vtkNew<vtkNamedColors> colors;
    vtkNew<vtkSphereSource> source;

    bool _polyDataLoaded = false;
    vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
};

#endif
