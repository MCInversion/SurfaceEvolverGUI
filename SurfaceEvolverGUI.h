#ifndef SurfaceEvolverGUI_H
#define SurfaceEvolverGUI_H

#include <vtkSmartPointer.h>

#include <QMainWindow>
#include <QColorDialog>

// Forward Qt class declarations
class Ui_SurfaceEvolverGUI;

class SurfaceEvolverGUI : public QMainWindow
{
  Q_OBJECT
public:
  // Constructor/Destructor
  SurfaceEvolverGUI();
  ~SurfaceEvolverGUI() = default;
  void updatePipeline();
  // sss
  QColor bgColor = QColor("black");
public slots:

  void slotExit();
  void ActionOpenColorPicker();

private:
  // Designer form
  Ui_SurfaceEvolverGUI* ui;
};

#endif
