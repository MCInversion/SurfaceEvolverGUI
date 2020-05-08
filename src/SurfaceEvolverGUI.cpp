#include "SurfaceEvolverGUI.h"

#if VTK_VERSION_NUMBER >= 89000000000ULL
#define VTK890 1
#endif

// Constructor
SurfaceEvolverGUI::SurfaceEvolverGUI()
{
    this->ui = new Ui_SurfaceEvolverGUI();
    this->ui->setupUi(this);
    installEventFilter(this);

    // create engine instance
    m_engine = std::shared_ptr<Engine>(new Engine(this->ui->qvtkWidget));

    // right menu horizontal spacer
    // QSpacerItem(150, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);
    ui->horizontalSpacer->changeSize(150, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

    // Set up action signals and slots
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));
    connect(ui->actionOpen_File, SIGNAL(triggered()), this, SLOT(actionOpen_File()));
    connect(ui->actionSave_File, SIGNAL(triggered()), this, SLOT(actionSave_File()));

    setColorIcon(ui->bgColorButton, m_engine->bgColor());
    setColorIcon(ui->vertexColorButton, m_engine->vertexColor());
    setColorIcon(ui->edgeColorButton, m_engine->edgeColor());
    setColorIcon(ui->surfaceColorButton, m_engine->surfaceColor());

    setToolIcon(ui->deleteButton, "trash");
    setToolIcon(ui->clearButton, "clear");
}

void SurfaceEvolverGUI::slotExit()
{
  qApp->exit();
}


void SurfaceEvolverGUI::ActionRendererBackgroundColor()
{
    QColor newColor = QColorDialog::getColor(m_engine->bgColor(), this);
    setColorIcon(ui->bgColorButton, newColor);
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

void SurfaceEvolverGUI::ActionVertexColor()
{
    QColor newColor = QColorDialog::getColor(m_engine->vertexColor(), this);
    setColorIcon(ui->vertexColorButton, newColor);
    m_engine->setVertexColorToObjects(newColor);
}

void SurfaceEvolverGUI::ActionEdgeColor()
{
    QColor newColor = QColorDialog::getColor(m_engine->edgeColor(), this);
    setColorIcon(ui->edgeColorButton, newColor);
    m_engine->setEdgeColorToObjects(newColor);
}

void SurfaceEvolverGUI::ActionSurfaceColor()
{
    QColor newColor = QColorDialog::getColor(m_engine->surfaceColor(), this);
    setColorIcon(ui->surfaceColorButton, newColor);
    m_engine->setSurfaceColorToObjects(newColor);
}

void SurfaceEvolverGUI::ActionOpacity()
{
    m_engine->setOpacityToObjects(ui->opacitySpinBox->value());
}

void SurfaceEvolverGUI::ActionSelectLibraryObject()
{
    int id = ui->libraryListWidget->currentIndex().data().toInt();
    m_engine->setSelectedObjectId(id);
    std::shared_ptr<MeshObject> selectedObj = m_engine->getLibraryObject(id);

    // TODO: current state of mesh render props should be a reflection of selectedObj props
}

void SurfaceEvolverGUI::ActionRemoveSelectedObjects()
{
    removeSelectedObjects();
}

void SurfaceEvolverGUI::ActionClearAllObjects()
{
    m_engine->clearMeshObjectLibrary();
    ui->libraryListWidget->clear();
}

void SurfaceEvolverGUI::setColorIcon(QToolButton* button, QColor color)
{
    QPixmap px(QSize(20, 20));
    px.fill(color);
    button->setIcon(px);
}

void SurfaceEvolverGUI::setToolIcon(QToolButton* button, QString name)
{
    QIcon icon;
    QString path = "../../resources/" + name + ".ico";
    icon.addFile(path, QSize(20, 20), QIcon::Normal, QIcon::On);
    button->setIcon(icon);
}

void SurfaceEvolverGUI::removeSelectedObjects()
{
    QModelIndexList selection = ui->libraryListWidget->selectionModel()->selectedIndexes();
    if (!selection.isEmpty()) {
        for (auto&& item : selection) {
            m_engine->removeMeshObjectFromLibrary(item.data().toInt());
        }
        qDeleteAll(ui->libraryListWidget->selectedItems());
    }
}

bool SurfaceEvolverGUI::eventFilter(QObject* object, QEvent* event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent* pKeyEvent = static_cast<QKeyEvent*>(event);
        if (pKeyEvent->key() == Qt::Key_Delete) {
            if (ui->libraryListWidget->hasFocus()) {
                removeSelectedObjects();
            }
            return true;
        }
    }
    return QWidget::eventFilter(object, event);
}

void SurfaceEvolverGUI::actionOpen_File()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "VTK files (*.vtk)");
    if (!fileName.isEmpty()) {
        vtkSmartPointer<vtkPolyData> polyData = ReadPolyData(fileName.toStdString().c_str());
        m_engine->addPolyDataObjectToScene(polyData);
        m_engine->updateRenderedObjects();

        int lastrow = ui->libraryListWidget->count();
        QString name = fileName.split("/").last();
        ui->libraryListWidget->insertItem(lastrow, name);
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
