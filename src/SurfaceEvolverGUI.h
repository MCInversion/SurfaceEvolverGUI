#ifndef SurfaceEvolverGUI_H
#define SurfaceEvolverGUI_H

#include <QMainWindow>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>

#include <iostream>

#include <vtkDataReader.h>
#include <vtkSimpleReader.h>
#include <vtkPolyDataReader.h>
#include <vtkXMLImageDataReader.h>
#include <vtkCamera.h>
#include <vtkSmartPointer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkPolyDataMapper.h>

#include <vtksys/SystemTools.hxx>

#include "Engine.h"
#include "PrimitiveBox.h"
#include "Box3.h"
#include "ui_SurfaceEvolverGUI.h"
#include "SDFWidget.h"
#include "SDF.h"

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

  void actionSigned_Distance_Function();
  void actionSurface_Evolution();

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

  void ActionObjectVisibility(QListWidgetItem* item);

  void ActionRenderBoundingBox();

  void ActionComputeSDF();
  void ActionCloseSDFWindow();

private:
    // Engine
    std::shared_ptr<Engine> m_engine;
    // for engine access to library objects through list widget items
    std::map<QListWidgetItem*, int> m_itemValuedObjectIds;

    // Designer form
    Ui_SurfaceEvolverGUI* ui;

    void setColorIcon(QToolButton* button, QColor color);
    void setToolIcon(QToolButton* button, QString name, QString extension = ".ico");
    void setObjectIcon(QListWidgetItem* item, QString name, QString extension = ".ico");
    void setActionIcon(QAction* action, QString name, QString extension = ".ico");

    void removeSelectedObjects();
    void clearAllHelpers();
    bool eventFilter(QObject* object, QEvent* event);

    void addListItem(QString name, int row, QString icon);
    void reIndexLibraryItems();
    void updateMeshUiFromObject(SceneObject* selectedObj);
    void updateMeshUiToDefault();

    std::vector<int> getSelectionIndices();

    int filterSelectionForProcessing();
    int filterForMeshProcessing(int id);

};

/**/
namespace
{
    vtkSmartPointer<vtkPolyData> ReadPolyData(const char* fileName);
    vtkSmartPointer<vtkImageData> ReadImageData(const char* fileName);
}

#endif
