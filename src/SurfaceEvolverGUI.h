#ifndef SurfaceEvolverGUI_H
#define SurfaceEvolverGUI_H

#include <QMainWindow>
#include <QColorDialog>
#include <QFileDialog>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>

#include <iostream>

#include <vtkDataReader.h>
#include <vtkSimpleReader.h>
#include <vtkPolyDataReader.h>
#include <vtkCamera.h>
#include <vtkSmartPointer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkPolyDataMapper.h>

#include <vtksys/SystemTools.hxx>

#include "Engine.h"
#include "ui_SurfaceEvolverGUI.h"

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

  void actionOpen_File();
  void actionSave_File();

  void ActionRendererBackgroundColor();
  void ActionRenderVertices();
  void ActionRenderWireframe();
  void ActionRenderSurface();

  void ActionVertexColor();
  void ActionEdgeColor();
  void ActionSurfaceColor();

  void ActionOpacity();
  
  void ActionSelectLibraryObject();
  void ActionRemoveSelectedObjects();
  void ActionClearAllObjects();

private:
    // Engine
    std::shared_ptr<Engine> m_engine;

    // Designer form
    Ui_SurfaceEvolverGUI* ui;

    void setColorIcon(QToolButton* button, QColor color);
    void setToolIcon(QToolButton* button, QString name);

    void removeSelectedObjects();
    bool eventFilter(QObject* object, QEvent* event);
};

/**/
namespace
{
    vtkSmartPointer<vtkPolyData> ReadPolyData(const char* fileName);
}

#endif
