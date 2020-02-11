#ifndef SurfaceEvolverGUI_H
#define SurfaceEvolverGUI_H

#include <vtkSmartPointer.h>

#include <QMainWindow>

// Forward Qt class declarations
class Ui_SurfaceEvolverGUI;

class SurfaceEvolverGUI : public QMainWindow
{
  Q_OBJECT
public:
  // Constructor/Destructor
  SurfaceEvolverGUI();
  ~SurfaceEvolverGUI() = default;
  // sss
public slots:

  void slotExit();

private:
  // Designer form
  Ui_SurfaceEvolverGUI* ui;
};

#endif
