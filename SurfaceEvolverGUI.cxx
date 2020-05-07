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

    m_engine = Engine();

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

    if (!_polyDataLoaded) {
        source->Update();
    }    

    if (_vertex) {
        vtkNew<vtkActor> vertexActor;
        vtkNew<vtkPolyDataMapper> vertexMapper;

        if (_polyDataLoaded) {
            vertexMapper->SetInputData(polyData);
        }
        else {
            vertexMapper->SetInputConnection(source->GetOutputPort());
        }        
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

        if (_polyDataLoaded) {
            edgeMapper->SetInputData(polyData);
        }
        else {
            edgeMapper->SetInputConnection(source->GetOutputPort());
        }
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

        if (_polyDataLoaded) {
            surfaceMapper->SetInputData(polyData);
        }
        else {
            surfaceMapper->SetInputConnection(source->GetOutputPort());
        }
        surfaceActor->GetProperty()->SetRepresentationToSurface();

        surfaceActor->SetMapper(surfaceMapper);
        surfaceActor->GetProperty()->SetColor(colors->GetColor4d("mintcream").GetData());
        surfaceActor->GetProperty()->SetInterpolationToFlat();
        renderer->AddActor(surfaceActor);
    }

    renderer->ResetCamera();
    this->ui->qvtkWidget->GetRenderWindow()->Render();
}

void SurfaceEvolverGUI::fitToView()
{
    // up vector:
    double up[3] = { 0., 0., 1. };
    // distance:
    double bounds[6]; // vtkIdType id = 0;
    polyData->GetBounds(bounds);
    // bounds = {xmin, xmax, ymin, ymax, zmin, zmax};
    // focus:
    double focus[3] = { 
        bounds[0] + 0.5 * (bounds[1] - bounds[0]),
        bounds[2] + 0.5 * (bounds[3] - bounds[2]),
     0.};
    double distance = sqrt((bounds[1] - bounds[0]) * (bounds[1] - bounds[0]) +
        (bounds[5] - bounds[4]) * (bounds[5] - bounds[4]));

    printf_s("bbox:\n min=(%lf, %lf, %lf)\n max=(%lf, %lf, %lf)\n",
        bounds[0], bounds[2], bounds[4], bounds[1], bounds[3], bounds[5]);
    printf_s(" ------- Active Camera Settings: -------\n");
    printf_s("up = (%lf, %lf, %lf)\n", up[0], up[1], up[2]);
    printf_s("focus = (%lf, %lf, %lf)\n", focus[0], focus[1], focus[2]);
    printf_s("distance = %lf\n", distance);

    auto camera = renderer->GetActiveCamera();
    camera->SetFocalPoint(focus);
    camera->SetViewUp(up);
    camera->SetDistance(distance);
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

void SurfaceEvolverGUI::ActionOpenFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "VTK files (*.vtk)");
    if (!fileName.isEmpty()) {
        polyData = ReadPolyData(fileName.toStdString().c_str());
        _polyDataLoaded = true; // polyData->GetVerts()->GetSize() > 0;

        this->updateRenderedObjects();
    }
}

void SurfaceEvolverGUI::ActionSaveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save VTK file"), "", tr("VTK file (*.vtk)"));
    if (fileName.isEmpty()) {
        return;
    }
    else {
        QFile file(fileName);
    }
}

namespace {
    vtkSmartPointer<vtkPolyData> ReadPolyData(const char* fileName)
    {
        vtkSmartPointer<vtkPolyData> polyData;

        std::string extension =
            vtksys::SystemTools::GetFilenameLastExtension(std::string(fileName));

        // Drop the case of the extension
        std::transform(extension.begin(), extension.end(),
            extension.begin(), ::tolower);

        if (extension == ".vtk") {
            auto reader = vtkSmartPointer<vtkPolyDataReader>::New();
            reader->SetFileName(fileName);
            reader->Update();
            polyData = reader->GetOutput();
        }
        else {
            auto source = vtkSmartPointer<vtkSphereSource>::New();
            source->Update();
            polyData = source->GetOutput();
        }

        return polyData;
    }
}
