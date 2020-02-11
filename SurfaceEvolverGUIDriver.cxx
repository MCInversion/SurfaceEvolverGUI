#include <QApplication>
#include <QSurfaceFormat>
#include <QVTKOpenGLNativeWidget.h>

#include "SurfaceEvolverGUI.h"
 
int main( int argc, char** argv )
{
  // needed to ensure appropriate OpenGL context is created for VTK rendering.
  QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());

  // QT Stuff
  QApplication app( argc, argv );
 
  SurfaceEvolverGUI surfaceEvolverGUI;
  surfaceEvolverGUI.show();
 
  return app.exec();
}
