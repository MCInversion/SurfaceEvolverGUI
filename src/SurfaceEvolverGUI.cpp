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
    ui->horizontalSpacer->changeSize(150, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

    // Set up action signals and slots
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));
    connect(ui->actionOpen_File, SIGNAL(triggered()), this, SLOT(actionOpen_File()));
    connect(ui->actionSave_File, SIGNAL(triggered()), this, SLOT(actionSave_File()));

    connect(ui->actionSigned_Distance_Function, SIGNAL(triggered()), this, SLOT(actionSigned_Distance_Function()));
    connect(ui->actionSurface_Evolution, SIGNAL(triggered()), this, SLOT(actionSurface_Evolution()));

    setColorIcon(ui->bgColorButton, m_engine->bgColor());
    setColorIcon(ui->vertexColorButton, m_engine->vertexColor());
    setColorIcon(ui->edgeColorButton, m_engine->edgeColor());
    setColorIcon(ui->surfaceColorButton, m_engine->surfaceColor());
    connect(ui->libraryListWidget, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(ActionObjectVisibility(QListWidgetItem*)));

    setToolIcon(ui->deleteButton, "trash");
    setToolIcon(ui->clearButton, "clear");
    setActionIcon(ui->menuFile->actions().at(0), "file-folder", ".png");
    setActionIcon(ui->menuFile->actions().at(1), "save-file", ".png");

    setActionIcon(ui->menuTools->actions().at(0), "sdf", ".png");
    setActionIcon(ui->menuTools->actions().at(1), "evolution", ".png");
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
    m_engine->setVertexRepresentationOfObjects(ui->checkBoxVertices->isChecked(), getSelectionIndices());
    m_engine->updateRenderedObjects();
}

void SurfaceEvolverGUI::ActionRenderWireframe()
{
    m_engine->setWireframeRepresentationOfObjects(ui->checkBoxWireframe->isChecked(), getSelectionIndices());
    m_engine->updateRenderedObjects();
}

void SurfaceEvolverGUI::ActionRenderSurface()
{
    m_engine->setSurfaceRepresentationOfObjects(ui->checkBoxSurface->isChecked(), getSelectionIndices());
    m_engine->updateRenderedObjects();
}

void SurfaceEvolverGUI::ActionVertexColor()
{
    QColor newColor = QColorDialog::getColor(m_engine->vertexColor(), this);
    setColorIcon(ui->vertexColorButton, newColor);
    m_engine->setVertexColorToObjects(newColor, getSelectionIndices());
}

void SurfaceEvolverGUI::ActionEdgeColor()
{
    QColor newColor = QColorDialog::getColor(m_engine->edgeColor(), this);
    setColorIcon(ui->edgeColorButton, newColor);
    m_engine->setEdgeColorToObjects(newColor, getSelectionIndices());
}

void SurfaceEvolverGUI::ActionSurfaceColor()
{
    QColor newColor = QColorDialog::getColor(m_engine->surfaceColor(), this);
    setColorIcon(ui->surfaceColorButton, newColor);
    m_engine->setSurfaceColorToObjects(newColor, getSelectionIndices());
}

void SurfaceEvolverGUI::ActionOpacity()
{
    m_engine->setOpacityToObjects(ui->opacitySpinBox->value(), getSelectionIndices());
}

void SurfaceEvolverGUI::ActionScalarMultipleContours()
{   
    bool singleContour = ui->singleContourButton->isChecked();
    ui->nContoursSpinBox->setEnabled(!singleContour);

    m_engine->setSingleContourToObjects(singleContour, getSelectionIndices());
}

void SurfaceEvolverGUI::ActionNContours()
{
    m_engine->setNContoursToObjects(ui->nContoursSpinBox->value(), getSelectionIndices());
}

void SurfaceEvolverGUI::ActionIsolevel()
{
    if (!m_sliderLock) {
        m_engine->setIsoLevelToObjects(ui->isoLevelSlider->value(), getSelectionIndices());
        ui->isoLevelLabel->setText("iso-level: " + QString::number(m_engine->currentIsoLevel()));
    }
}

void SurfaceEvolverGUI::ActionDIso()
{
    m_engine->setDIsoToObjects(ui->dIsoSpinBox->value(), getSelectionIndices());
}

void SurfaceEvolverGUI::ActionSelectLibraryObject()
{    
    QList<QListWidgetItem*> selection = ui->libraryListWidget->selectedItems();
    if (!selection.isEmpty()) {
        auto found = m_itemValuedObjectIds.find(selection.last());
        int id = found->second;
        SceneObject* selectedObj = m_engine->getLibraryObject(id);
        updateUiFromObject(selectedObj);
    } else {
        updateUiToDefault();
    }
}

void SurfaceEvolverGUI::ActionRemoveSelectedObjects()
{
    removeSelectedObjects();
    updateUiToDefault();
}

void SurfaceEvolverGUI::ActionClearAllObjects()
{
    m_engine->clearObjectLibrary();
    ui->libraryListWidget->clear();
    updateUiToDefault();
}

void SurfaceEvolverGUI::ActionObjectVisibility(QListWidgetItem* item)
{
    auto found = m_itemValuedObjectIds.find(item);
    if (found != m_itemValuedObjectIds.end()) {
        int id = found->second;
        m_engine->setVisibilityOfObject(item->checkState() == Qt::Checked, id);
    }    
}

void SurfaceEvolverGUI::ActionRenderBoundingBox()
{
    SceneObject* object = m_engine->getLibraryObject(m_engine->selectedId());
    Vector3 boxMin = object->getBoxMin();
    Vector3 boxMax = object->getBoxMax();
    Box3 bbox = Box3(boxMin, boxMax);
    Vector3 boxSize = bbox.getSize();
    std::string box_name = object->name().toStdString() + "_bounding_box";
    PrimitiveBox box = PrimitiveBox(boxSize.x, boxSize.y, boxSize.z, 1, 1, 1, true, box_name);
    Matrix4 T = Matrix4().makeTranslation(boxMin.x, boxMin.y, boxMin.z);
    box.applyMatrix(T);
    SceneObject box_object = SceneObject(box);
    m_engine->addHelperObjectToScene(box_object);
    m_engine->updateRenderedObjects();
}

void SurfaceEvolverGUI::ActionComputeSDF()
{
    SDFWidget* sdfWidget = static_cast<SDFWidget*>(sender());
    SDFParams params = sdfWidget->getSDFParams();

    SceneObject* object = m_engine->getLibraryObject(m_engine->selectedId());
    Geometry geom = object->translatePolyDataToGeometry();
    params.targetGeom = &geom;
    SDF sdf = SDF(&params);
    std::cout << sdf.geom_properties << std::endl;
    std::cout << sdf.time_log << std::endl;
    // sdf.exportGrid("", "../../models/");
    QString name = object->name() + "_SDF";
    m_engine->addGridDataObjectToScene(sdf.grid, name);

    int lastrow = ui->libraryListWidget->count();
    m_engine->updateRenderedObjects();

    addListItem(name, lastrow, "scalar-object.png");
}

void SurfaceEvolverGUI::ActionCloseSDFWindow()
{
    clearAllHelpers();
    ui->sceneObjectsGroupBox->setEnabled(true);
    ui->menuBar->setEnabled(true);
}

void SurfaceEvolverGUI::setColorIcon(QToolButton* button, QColor color)
{
    QPixmap px(QSize(20, 20));
    px.fill(color);
    button->setIcon(px);
}

void SurfaceEvolverGUI::setToolIcon(QToolButton* button, QString name, QString extension)
{
    QIcon icon;
    QString path = "../../resources/" + name + extension;
    icon.addFile(path, QSize(20, 20), QIcon::Normal, QIcon::On);
    button->setIcon(icon);
}

void SurfaceEvolverGUI::setObjectIcon(QListWidgetItem* item, QString name, QString extension)
{
    QIcon icon;
    QString path = "../../resources/" + name + extension;
    icon.addFile(path, QSize(20, 20), QIcon::Normal, QIcon::On);
    item->setIcon(icon);
}

void SurfaceEvolverGUI::setActionIcon(QAction* action, QString name, QString extension)
{
    QIcon icon;
    QString path = "../../resources/" + name + extension;
    icon.addFile(path, QSize(20, 20), QIcon::Normal, QIcon::On);
    action->setIcon(icon);
}

void SurfaceEvolverGUI::removeSelectedObjects()
{
    QList<QListWidgetItem*> selection = ui->libraryListWidget->selectedItems();
    if (!selection.isEmpty()) {
        while (!selection.isEmpty()) {
            QListWidgetItem* item = selection.first();
            auto found = m_itemValuedObjectIds.find(item);
            m_engine->removeObjectFromLibrary(found->second);
            m_itemValuedObjectIds.erase(found);
            selection.pop_front();
        }
        qDeleteAll(ui->libraryListWidget->selectedItems());
        reIndexLibraryItems();
    }
}

void SurfaceEvolverGUI::clearAllHelpers()
{
    m_engine->clearHelperObjects();
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

void SurfaceEvolverGUI::addListItem(QString name, int row, QString icon)
{
    QListWidgetItem* newItem = new QListWidgetItem(name);
    QStringList strSplt = icon.split(".");
    setObjectIcon(newItem, strSplt.first(), "." + strSplt.last());
    newItem->setFlags(newItem->flags() | Qt::ItemIsUserCheckable);
    newItem->setCheckState(Qt::Checked);

    m_itemValuedObjectIds.insert({ newItem, row });
    ui->libraryListWidget->insertItem(row, newItem);
}

void SurfaceEvolverGUI::reIndexLibraryItems()
{
    int id = 0;
    for (auto&& item : m_itemValuedObjectIds) {
        item.second = id++;
    }
}

void SurfaceEvolverGUI::updateUiFromObject(SceneObject* selectedObj)
{
    ui->checkBoxVertices->setChecked(selectedObj->vertexRender());
    ui->checkBoxWireframe->setChecked(selectedObj->edgeRender());
    ui->checkBoxSurface->setChecked(selectedObj->surfaceRender());

    setColorIcon(ui->vertexColorButton, selectedObj->vertexColor());
    setColorIcon(ui->edgeColorButton, selectedObj->edgeColor());
    setColorIcon(ui->surfaceColorButton, selectedObj->surfaceColor());

    ui->opacitySpinBox->setValue(selectedObj->opacity());

    if (selectedObj->type() == ObjectType::SGrid) {
        ui->scalarDataGroupBox->setEnabled(true);

        ui->multiContoursButton->setChecked(!selectedObj->singleContour());
        ui->singleContourButton->setChecked(selectedObj->singleContour());

        ui->nContoursSpinBox->setValue(selectedObj->nContours());
        double isolevel = selectedObj->isoLevel();
        ui->isoLevelLabel->setText("iso-level: " + QString::number(isolevel));

        m_sliderLock = true;
        ui->isoLevelSlider->setSliderPosition(
            (int)std::round((isolevel - selectedObj->valMin()) / (selectedObj->valMax() - selectedObj->valMin()) * 100)
        );
        m_sliderLock = false;
        ui->dIsoSpinBox->setValue(selectedObj->dIso());
    }
    else {
        ui->scalarDataGroupBox->setEnabled(false);
    }
}

void SurfaceEvolverGUI::updateUiToDefault()
{
    ui->checkBoxVertices->setChecked(m_engine->vertexRender());
    ui->checkBoxWireframe->setChecked(m_engine->edgeRender());
    ui->checkBoxSurface->setChecked(m_engine->surfaceRender());

    setColorIcon(ui->vertexColorButton, m_engine->vertexColor());
    setColorIcon(ui->edgeColorButton, m_engine->edgeColor());
    setColorIcon(ui->surfaceColorButton, m_engine->surfaceColor());

    ui->opacitySpinBox->setValue(m_engine->opacity());

    ui->scalarDataGroupBox->setEnabled(false);
}

std::vector<int> SurfaceEvolverGUI::getSelectionIndices()
{
    QList<QListWidgetItem*> selection = ui->libraryListWidget->selectedItems();
    std::vector<int> selectionIds = std::vector<int>(selection.count());
    for (int i = 0; i < selectionIds.size(); i++) {
        auto found = m_itemValuedObjectIds.find(selection[i]);
        selectionIds[i] = found->second;
    }
    return selectionIds;
}

int SurfaceEvolverGUI::filterSelectionForProcessing()
{
    if (m_engine->libraryEmpty()) {
        QMessageBox* msgBox = new QMessageBox();
        msgBox->setWindowTitle("Library empty");
        msgBox->setText("There has to be at least one object in the library. Please, import a mesh model for processig.");
        msgBox->setIcon(QMessageBox::Information);
        if (msgBox->exec() == QMessageBox::Ok) {
            return -1;
        }
    }

    QList<QListWidgetItem*> selection = ui->libraryListWidget->selectedItems();
    if (selection.size() > 1) {
        QMessageBox* msgBox = new QMessageBox();
        msgBox->setWindowTitle("Multiple selection");
        msgBox->setText("More than 1 object is selected. Please, select a single scene object in the library.");
        msgBox->setIcon(QMessageBox::Information);
        if (msgBox->exec() == QMessageBox::Ok) {
            return -1;
        }
    }
    else if (selection.isEmpty()) {
        QMessageBox* msgBox = new QMessageBox();
        msgBox->setWindowTitle("Empty selection");
        msgBox->setText("No mesh object is selected. Process the first library object?");
        msgBox->setStandardButtons(QMessageBox::Yes);
        msgBox->addButton(QMessageBox::No);
        msgBox->setDefaultButton(QMessageBox::No);
        if (msgBox->exec() == QMessageBox::Yes) {
            QString name = ui->libraryListWidget->item(0)->text();
            printf("processing %s\n", name.toStdString().c_str());
            return 0;
        }
        else {
            return -1;
        }
    }

    auto found = m_itemValuedObjectIds.find(selection[0]);
    printf("processing %s\n", selection[0]->text().toStdString().c_str());
    return found->second;
}

int SurfaceEvolverGUI::filterForMeshProcessing(int id)
{
    if (id < 0) return id;

    if (m_engine->getLibraryObject(id)->type() != ObjectType::Mesh) {
        QMessageBox* msgBox = new QMessageBox();
        msgBox->setWindowTitle("Invalid target object");
        msgBox->setText("Selected object is not a Mesh Object! Please, select a Mesh Object for processing.");
        msgBox->setIcon(QMessageBox::Critical);
        if (msgBox->exec() == QMessageBox::Ok) {
            return -1;
        }
    }

    return id;
}

void SurfaceEvolverGUI::actionOpen_File()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "../../models", tr("VTK files (*.vtk *.vti)"));
    if (!fileName.isEmpty()) {
        QString name = fileName.split("/").last();
        QString extension = "." + fileName.split(".").last();
        QString icon;

        if (extension == ".vtk") {
            vtkSmartPointer<vtkPolyData> polyData = ReadPolyData(fileName.toStdString().c_str());
            m_engine->addPolyDataObjectToScene(polyData, name);
            icon = "geometry.ico";
        }
        else if (extension == ".vti") {
            vtkSmartPointer<vtkImageData> imgData = ReadImageData(fileName.toStdString().c_str());
            m_engine->addImageDataObjectToScene(imgData, name);
            icon = "scalar-object.png";
        }
        else {
            return;
        }

        int lastrow = ui->libraryListWidget->count();
        m_engine->updateRenderedObjects();

        addListItem(name, lastrow, icon);        
    }
}

void SurfaceEvolverGUI::actionSave_File()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save VTK file"), "../../models", tr("VTK file (*.vtk)"));
    if (fileName.isEmpty()) {
        return;
    }
    else {
        QFile file(fileName);
    }
}

// ============== SDF =================================

void SurfaceEvolverGUI::actionSigned_Distance_Function()
{
    int selectedId = filterForMeshProcessing(
        filterSelectionForProcessing()
    );

    if (selectedId >= 0) {
        SDFWidget* sdfWidget = new SDFWidget(this);

        sdfWidget->processMeshInfo(m_engine->getLibraryObject(selectedId));
        connect(sdfWidget, SIGNAL(closeSDF()), this, SLOT(ActionCloseSDFWindow()));
        connect(sdfWidget, SIGNAL(sdfInit()), this, SLOT(ActionComputeSDF()));
        ui->sceneObjectsGroupBox->setEnabled(false);
        ui->menuBar->setEnabled(false);

        sdfWidget->show();

        m_engine->setSelectedObjectId(selectedId);
        ActionRenderBoundingBox();
    }
}

// ---------------------------------------------------

// ============== EVOLUTION ==========================

void SurfaceEvolverGUI::actionSurface_Evolution()
{
    int selectedId = filterForMeshProcessing(filterSelectionForProcessing());

    if (selectedId >= 0) {
        m_engine->setSelectedObjectId(selectedId);
    }
}

// ----------------------------------------------------

/**/
namespace {
    vtkSmartPointer<vtkPolyData> ReadPolyData(const char* fileName)
    {
        vtkSmartPointer<vtkPolyData> polyData;
        vtkSmartPointer<vtkPolyDataReader> reader = vtkSmartPointer<vtkPolyDataReader>::New();
        reader->SetFileName(fileName);
        reader->Update();
        polyData = reader->GetOutput();

        return polyData;
    }
    vtkSmartPointer<vtkImageData> ReadImageData(const char* fileName)
    {
        vtkSmartPointer<vtkImageData> imgData;
        vtkSmartPointer<vtkXMLImageDataReader> reader = vtkSmartPointer<vtkXMLImageDataReader>::New();
        reader->SetFileName(fileName);
        reader->Update();
        imgData = reader->GetOutput();

        return imgData;
    }
}
