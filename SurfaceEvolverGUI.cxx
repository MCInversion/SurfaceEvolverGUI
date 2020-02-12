#include "SurfaceEvolverGUI.h"

// This is included here because it is forward declared in
// SurfaceEvolverGUI.h
#include "ui_SurfaceEvolverGUI.h"

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

#if VTK_VERSION_NUMBER >= 89000000000ULL
#define VTK890 1
#endif

// Constructor
SurfaceEvolverGUI::SurfaceEvolverGUI()
{
  this->updatePipeline();
}

void SurfaceEvolverGUI::slotExit()
{
  qApp->exit();
}

void SurfaceEvolverGUI::updatePipeline()
{
    this->ui = new Ui_SurfaceEvolverGUI;
    this->ui->setupUi(this);

    vtkNew<vtkNamedColors> colors;

    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
#if VTK890
    this->ui->qvtkWidget->setRenderWindow(renderWindow);
#else
    this->ui->qvtkWidget->SetRenderWindow(renderWindow);
#endif

    // Sphere
    vtkNew<vtkSphereSource> sphereSource;
    sphereSource->Update();
    vtkNew<vtkPolyDataMapper> sphereMapper;
    sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
    vtkNew<vtkActor> sphereActor;
    sphereActor->SetMapper(sphereMapper);
    sphereActor->GetProperty()->SetColor(colors->GetColor4d("Tomato").GetData());

    // VTK Renderer
    vtkNew<vtkRenderer> renderer;
    renderer->AddActor(sphereActor);

    double r = (double)this->bgColor.red() / 255.;
    double g = (double)this->bgColor.green() / 255.;
    double b = (double)this->bgColor.blue() / 255.;
    renderer->SetBackground(r, g, b);

    // VTK/Qt wedded
#if VTK890
    this->ui->qvtkWidget->renderWindow()->AddRenderer(renderer);
    this->ui->qvtkWidget->renderWindow()->SetWindowName(
        "SurfaceEvolverGUI");
#else
    this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
    this->ui->qvtkWidget->GetRenderWindow()->SetWindowName(
        "SurfaceEvolverGUI");
#endif
    // Set up action signals and slots
    connect(this->ui->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));
}

void SurfaceEvolverGUI::ActionOpenColorPicker()
{
    this->bgColor = QColorDialog::getColor(Qt::black, this);
    this->updatePipeline();
}
