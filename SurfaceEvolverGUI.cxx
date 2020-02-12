#include "SurfaceEvolverGUI.h"

// This is included here because it is forward declared in
// SurfaceEvolverGUI.h
#include "ui_SurfaceEvolverGUI.h"

#if VTK_VERSION_NUMBER >= 89000000000ULL
#define VTK890 1
#endif

// Constructor
SurfaceEvolverGUI::SurfaceEvolverGUI()
{
    this->ui = new Ui_SurfaceEvolverGUI;
    this->ui->setupUi(this);

#if VTK890
    this->ui->qvtkWidget->setRenderWindow(renderWindow);
#else
    this->ui->qvtkWidget->SetRenderWindow(renderWindow);
#endif
    sphereSource->Update();
    sceneMapper->SetInputConnection(sphereSource->GetOutputPort());
    sceneActor->SetMapper(sceneMapper);
    sceneActor->GetProperty()->SetColor(colors->GetColor4d("Tomato").GetData());
    renderer->AddActor(sceneActor);

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

void SurfaceEvolverGUI::slotExit()
{
  qApp->exit();
}

void SurfaceEvolverGUI::ActionOpenColorPicker()
{
    this->bgColor = QColorDialog::getColor(Qt::black, this);

    // Qt ui update
    QPixmap pixmap(100, 100);
    pixmap.fill(this->bgColor);
    QIcon bgIcon(pixmap);
    this->ui->bgColorButton->setIcon(bgIcon);

    double r = (double)this->bgColor.red() / 255.;
    double g = (double)this->bgColor.green() / 255.;
    double b = (double)this->bgColor.blue() / 255.;
    renderer->SetBackground(r, g, b);
    this->ui->qvtkWidget->GetRenderWindow()->Render();
}
