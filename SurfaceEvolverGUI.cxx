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
    this->updateRenderedObjects();   

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

void SurfaceEvolverGUI::updateRenderedObjects()
{
    renderer->RemoveAllViewProps();
    source->Update();

    if (_vertex) {
        vtkNew<vtkActor> vertexActor;
        vtkNew<vtkPolyDataMapper> vertexMapper;
        vertexMapper->SetInputConnection(source->GetOutputPort());
        vertexActor->GetProperty()->SetRepresentationToPoints();
        vertexActor->SetMapper(vertexMapper);
        vertexActor->GetProperty()->SetAmbient(1.0);
        vertexActor->GetProperty()->SetDiffuse(0.0);
        vertexActor->GetProperty()->SetSpecular(0.0);
        vertexActor->GetProperty()->SetColor(colors->GetColor4d("black").GetData());
        vertexActor->GetProperty()->SetPointSize(8.0);
        renderer->AddActor(vertexActor);
    }

    if (_wireframe) {
        vtkNew<vtkActor> edgeActor;
        vtkNew<vtkPolyDataMapper> edgeMapper;
        edgeMapper->SetInputConnection(source->GetOutputPort());
        edgeActor->GetProperty()->SetRepresentationToWireframe();

        edgeActor->SetMapper(edgeMapper);
        edgeActor->GetProperty()->SetAmbient(1.0);
        edgeActor->GetProperty()->SetDiffuse(0.0);
        edgeActor->GetProperty()->SetSpecular(0.0);
        edgeActor->GetProperty()->SetColor(colors->GetColor4d("midnightblue").GetData());
        edgeActor->GetProperty()->SetLineWidth(2.0);
        renderer->AddActor(edgeActor);
    }

    if (_surface) {
        vtkNew<vtkActor> surfaceActor;
        vtkNew<vtkPolyDataMapper> surfaceMapper;
        surfaceMapper->SetInputConnection(source->GetOutputPort());
        surfaceActor->GetProperty()->SetRepresentationToSurface();

        surfaceActor->SetMapper(surfaceMapper);
        surfaceActor->GetProperty()->SetColor(colors->GetColor4d("mintcream").GetData());
        surfaceActor->GetProperty()->SetInterpolationToFlat();
        renderer->AddActor(surfaceActor);
    }
    this->ui->qvtkWidget->GetRenderWindow()->Render();
}

void SurfaceEvolverGUI::ActionRendererBackgroundColor()
{
    this->bgColor = QColorDialog::getColor(this->bgColor, this);

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

void SurfaceEvolverGUI::ActionRenderVertices()
{
    this->_vertex = this->ui->checkBoxVertices->isChecked();
    this->updateRenderedObjects();
}

void SurfaceEvolverGUI::ActionRenderWireframe()
{
    this->_wireframe = this->ui->checkBoxWireframe->isChecked();
    this->updateRenderedObjects();
}

void SurfaceEvolverGUI::ActionRenderSurface()
{
    this->_surface = this->ui->checkBoxSurface->isChecked();
    this->updateRenderedObjects();
}
