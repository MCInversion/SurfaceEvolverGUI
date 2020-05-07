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
#include <vtkSmartPointer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkPolyDataMapper.h>

#include <vtksys/SystemTools.hxx>

#include <Engine.h>

namespace
{
    vtkSmartPointer<vtkPolyData> ReadPolyData(const char* fileName);
}

// Forward Qt class declarations
class Ui_SurfaceEvolverGUI;
class Engine;

class SurfaceEvolverGUI : public QMainWindow
{
  Q_OBJECT
public:
  // Constructor/Destructor
  SurfaceEvolverGUI();
  ~SurfaceEvolverGUI() = default;

public slots:

  void slotExit();

  void ActionRendererBackgroundColor();
  void ActionRenderVertices();
  void ActionRenderWireframe();
  void ActionRenderSurface();

  void ActionOpenFile();
  void ActionSaveFile();

private:
    // Engine
    std::shared_ptr<Engine> m_engine;

    // Designer form
    Ui_SurfaceEvolverGUI* ui;
};

#endif
