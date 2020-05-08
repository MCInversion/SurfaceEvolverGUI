#include "SurfaceEvolverGUI.h"

#if VTK_VERSION_NUMBER >= 89000000000ULL
#define VTK890 1
#endif

// Constructor
SurfaceEvolverGUI::SurfaceEvolverGUI()
{
    this->ui = new Ui_SurfaceEvolverGUI();
    this->ui->setupUi(this);

    // create engine instance
    m_engine = std::shared_ptr<Engine>(new Engine(this->ui->qvtkWidget));

    // Set up action signals and slots
    connect(this->ui->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));
    connect(ui->actionOpen_File, SIGNAL(triggered()), this, SLOT(actionOpen_File()));
    connect(ui->actionSave_File, SIGNAL(triggered()), this, SLOT(actionSave_File()));

    setBgColorIcon(m_engine->bgColor());
}

void SurfaceEvolverGUI::slotExit()
{
  qApp->exit();
}


void SurfaceEvolverGUI::ActionRendererBackgroundColor()
{
    QColor newColor = QColorDialog::getColor(m_engine->bgColor(), this);
    setBgColorIcon(newColor);
    m_engine->setBackgroundColor(newColor);
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

void SurfaceEvolverGUI::actionOpen_File()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "VTK files (*.vtk)");
    if (!fileName.isEmpty()) {
        vtkSmartPointer<vtkPolyData> polyData = ReadPolyData(fileName.toStdString().c_str());
        m_engine->addPolyDataObjectToScene(polyData);
        m_engine->updateRenderedObjects();
    }
}

void SurfaceEvolverGUI::actionSave_File()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save VTK file"), "", tr("VTK file (*.vtk)"));
    if (fileName.isEmpty()) {
        return;
    }
    else {
        QFile file(fileName);
    }
}

void SurfaceEvolverGUI::setBgColorIcon(QColor color)
{
    QPixmap px(ui->bgColorButton->size());
    px.fill(color);
    ui->bgColorButton->setIcon(px);
}

/**/
namespace {
    vtkSmartPointer<vtkPolyData> ReadPolyData(const char* fileName)
    {
        vtkSmartPointer<vtkPolyData> polyData;

        /**/
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
