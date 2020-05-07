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

    // create engine instance
    m_engine = std::shared_ptr<Engine>(new Engine(this->ui->qvtkWidget));

    // Set up action signals and slots
    connect(this->ui->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));
}

void SurfaceEvolverGUI::slotExit()
{
  qApp->exit();
}


void SurfaceEvolverGUI::ActionRendererBackgroundColor()
{
    m_engine->setBackgroundColor(QColorDialog::getColor(QColor("black"), this));
}

void SurfaceEvolverGUI::ActionRenderVertices()
{
    m_engine->setVertexRepresentationOfAllObjects(ui->checkBoxVertices->isChecked());
    m_engine->updateRenderedObjects();
}

void SurfaceEvolverGUI::ActionRenderWireframe()
{
    m_engine->setWireframeRepresentationOfAllObjects(ui->checkBoxWireframe->isChecked());
    m_engine->updateRenderedObjects();
}

void SurfaceEvolverGUI::ActionRenderSurface()
{
    m_engine->setSurfaceRepresentationOfAllObjects(ui->checkBoxSurface->isChecked());
    m_engine->updateRenderedObjects();
}

void SurfaceEvolverGUI::ActionOpenFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "VTK files (*.vtk)");
    if (!fileName.isEmpty()) {
        vtkSmartPointer<vtkPolyData> polyData = ReadPolyData(fileName.toStdString().c_str());
        m_engine->addPolyDataObjectToScene(polyData);
        m_engine->updateRenderedObjects();
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
            vtkSmartPointer<vtkPolyDataReader> reader = vtkSmartPointer<vtkPolyDataReader>::New();
            reader->SetFileName(fileName);
            reader->Update();
            polyData = reader->GetOutput();
        }

        return polyData;
    }
}
