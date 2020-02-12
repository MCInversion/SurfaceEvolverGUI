#ifndef SurfaceEvolverGUI_H
#define SurfaceEvolverGUI_H

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

  // ===================================
  vtkNew <vtkNamedColors> colors;
  vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
  vtkNew <vtkPolyDataMapper> sceneMapper;
  vtkNew <vtkActor> sceneActor;
  vtkNew <vtkSphereSource> sphereSource;
  vtkNew <vtkRenderer> renderer;
  // ===================================
public slots:

  void slotExit();
  void ActionOpenColorPicker();

private:
  // Designer form
  Ui_SurfaceEvolverGUI* ui;
};

#endif
