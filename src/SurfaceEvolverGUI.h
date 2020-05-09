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
#include <vtkCamera.h>
#include <vtkSmartPointer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkPolyDataMapper.h>

#include <vtksys/SystemTools.hxx>

#include "Engine.h"
#include "ui_SurfaceEvolverGUI.h"
#include "SDFWidget.h"

class Engine;
class SDFWidget;

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

private:
    // Engine
    std::shared_ptr<Engine> m_engine;
    // for engine access to library objects through list widget items
    std::map<QListWidgetItem*, int> m_itemValuedObjectIds;

    // Designer form
    Ui_SurfaceEvolverGUI* ui;
    SDFWidget* m_sdfWidget = nullptr;

    void setColorIcon(QToolButton* button, QColor color);
    void setToolIcon(QToolButton* button, QString name, QString extension = ".ico");
    void setObjectIcon(QListWidgetItem* item, QString name, QString extension = ".ico");
    void setActionIcon(QAction* action, QString name, QString extension = ".ico");

    void removeSelectedObjects();
    bool eventFilter(QObject* object, QEvent* event);

    void addListItem(QString name, int row);
    void reIndexLibraryItems();
    void updateMeshUiFromObject(std::shared_ptr<MeshObject> selectedObj);
    void updateMeshUiToDefault();

    std::vector<int> getSelectionIndices();

    int filterSelectionForProcessing();    
};

/**/
namespace
{
    vtkSmartPointer<vtkPolyData> ReadPolyData(const char* fileName);
}

#endif
