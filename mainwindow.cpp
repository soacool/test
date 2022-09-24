#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSplitter>
#include <QTextEdit>
#include <QMessageBox>
#include <QItemSelectionModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QHeaderView>
#include <QToolTip>
#include <QSqlRelationalTableModel>
#include <QFileDialog>
#include "databasemanager.h"
#include "treemodel.h"
#include "addelevedialog.h"
#include "mydatedelegate.h"
#include "ecolagedelegate.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mDatabase(DatabaseManager::instance())

{

    ui->setupUi(this);
    QSplitter *splitter = new QSplitter(ui->tabGestion);
    splitter->addWidget(ui->groupBox_2);
    splitter->addWidget(ui->groupBox);
    ui->tabGestion->layout()->addWidget(splitter);
    ui->seachEdit->setClearButtonEnabled(true);
    currentElvId = 0;

    filterEleveModel = new NameCalssesFilterModel;
    m_myeleveModel = new MyEleveModel;
    //m_myeleveModel->setEditStrategy(QSqlTableModel::OnRowChange);
    filterEleveModel->setSourceModel(m_myeleveModel);
    //filterEleveModel->setFilterKeyColumn(1);
    //filterEleveModel->setFilterCaseSensitivity(Qt::CaseInsensitive);

    //ui->nomsDesEleves->setViewMode(QListView::IconMode);
    ui->nomsDesEleves->setIconSize(QSize(40,40));
    ui->nomsDesEleves->setModel(filterEleveModel);
    ui->nomsDesEleves->setModelColumn(1);
    ui->nomsDesEleves->setAlternatingRowColors(true);
    ui->nomsDesEleves->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->nomsDesEleves, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(elvContextMenu(QPoint)));

    //envoie l'id de leleve selectionné pour infoPayment
    connect(ui->nomsDesEleves->selectionModel(), &QItemSelectionModel::selectionChanged, [this](const QItemSelection &selected) {
        if (selected.isEmpty()) {
            return;
        }
        loadEleve(selected.indexes().first());
    });

    mapper = new QDataWidgetMapper(this);
    m_eleveDetails = new QSqlTableModel(this);
    m_eleveDetails->setTable("elevedetails");

    m_elvPaymentModel = new ElvPaymentModel(this);

    ui->tableView->setModel(m_elvPaymentModel);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(2, true);
    ui->tableView->setItemDelegateForColumn(1, new MyDateDelegate(this));
    ui->tableView->setItemDelegateForColumn(3, new EcolageDelegate(this));
    ui->tableView->setAlternatingRowColors(true);
    //ui->tableView->verticalHeader()->setHighlightSections(true);
    //ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    //recalcule les somme total
    //connect(m_elvPaymentModel,SIGNAL(recalculateTotal()), this, SLOT(showTotal()));


    createMenu();
    setelvDetailsMap();
    ui->nomsDesEleves->setCurrentIndex(ui->nomsDesEleves->model()->index(0,1));
    fillTreeView();
    ui->addEleveButton->setToolTip("Ajoute un Elève");
    ui->editEleveButton->setToolTip("Modifier un Elève");
    ui->cmdAddClasse->setToolTip("Ajouter une classe");
    ui->cmdAddSection->setToolTip("Ajouter une section");
    ui->cmdDelete->setToolTip("Supprimer une entrée");
    ui->cmdRefresh->setToolTip("Actualiser");
    setDbInfoText();
}

//fill treeView Data
void MainWindow::fillTreeView()
{
    TreeModel *model = new TreeModel();
    ui->treeView->setModel(model);
    ui->treeView->expand(model->index(0,0));
    ui->treeView->setUniformRowHeights(true);
    //to Fix
    //  ui->treeView->setContentsMargins(QMargins(6,10,6,10));
    connect(ui->treeView,SIGNAL(clicked(QModelIndex)),this,SLOT(treeviewIndexChanged(QModelIndex)));
    connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateActions);

    connect(ui->cmdAddClasse,&QToolButton::clicked, this, &MainWindow::insertRow);
    connect(ui->cmdAddSection,&QToolButton::clicked, this, &MainWindow::insertChild);
    connect(ui->cmdDelete,&QToolButton::clicked, this, &MainWindow::removeRow);
    connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateActions);

    updateActions();
}

//map to ui elv Details
void MainWindow::setelvDetailsMap()
{
    mapper->setModel(m_eleveDetails);
    mapper->addMapping(ui->nomEdit, m_eleveDetails->fieldIndex("name"));
    mapper->addMapping(ui->dateNaissEdit, m_eleveDetails->fieldIndex("date_naissance"));
    mapper->addMapping(ui->prenomEdit,m_eleveDetails->fieldIndex("prename"));
    mapper->addMapping(ui->adressEdit,m_eleveDetails->fieldIndex("adresse"));
    mapper->addMapping(ui->contactAEdit, m_eleveDetails->fieldIndex("contact_a"));
    mapper->addMapping(ui->contactBEdit, m_eleveDetails->fieldIndex("contact_b"));
    mapper->addMapping(ui->pereEdit,m_eleveDetails->fieldIndex("pere"));
    mapper->addMapping(ui->mereEdit,m_eleveDetails->fieldIndex("mere"));
    mapper->addMapping(ui->numeroEdit,m_eleveDetails->fieldIndex("numero"));
    mapper->addMapping(ui->classeEdit,m_eleveDetails->fieldIndex("classe"));
    mapper->addMapping(ui->labelDebutEcolage, m_eleveDetails->fieldIndex("debut_ecolage"), "text");
    mapper->addMapping(ui->labelTarif, m_eleveDetails->fieldIndex("tarif"), "text");
}

//calcul des Totaux
void MainWindow::showTotal()
{
    ui->labelTtalRecu->setText(m_elvPaymentModel->TotalRecu());
    ui->labelRestePayer->setText(m_elvPaymentModel->ResteApayer());
}

//create menubar Menu
void MainWindow::createMenu()
{
    QAction *openAction = new QAction(tr("Configuration"),this);
    QAction *closeAction = new QAction(tr("Quitter"),this);
    QMenu *fileMenu = menuBar()->addMenu(tr("&Menu"));
    fileMenu->addAction(openAction);
    fileMenu->addAction(closeAction);
    connect(closeAction, &QAction::triggered, this, &MainWindow::close);
}

//affiche eleve details
void MainWindow::loadEleve(const QModelIndex &eleveIndex)
{   
    QString id = m_myeleveModel->index(filterEleveModel->mapToSource(eleveIndex).row(),0).data().toString();
    currentElvId = id.toInt();
    m_eleveDetails->setFilter(QString("id=%1").arg(id));
    m_eleveDetails->select();
    mapper->toFirst();
    ui->adressEdit->setCursorPosition(0);
    loadPayment(id);
}

void MainWindow::clearUi()
{

}

//filter & load eleve payment
void MainWindow::loadPayment(QString &id)
{  
    m_elvPaymentModel->setFilterPayment(QString("id=%1").arg(id));
    ui->tableView->resizeRowsToContents();
    showTotal();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::insertChild()
{
    QModelIndex index = ui->treeView->selectionModel()->currentIndex();
    QAbstractItemModel *model = ui->treeView->model();

    if (model->columnCount(index) == 0) {
        if (!model->insertColumn(0, index))
            return;
    }

    if (!model->insertRow(0, index))
        return;

    for (int column = 0; column < model->columnCount(index); ++column) {
        QModelIndex child = model->index(0, column, index);
        model->setData(child, QVariant("[No data]"), Qt::EditRole);
        if (!model->headerData(column, Qt::Horizontal).isValid())
            model->setHeaderData(column, Qt::Horizontal, QVariant("[No header]"), Qt::EditRole);
    }

    ui->treeView->selectionModel()->setCurrentIndex(model->index(0, 0, index),
                                                    QItemSelectionModel::ClearAndSelect);
    updateActions();
}

void MainWindow::insertRow()
{
    QModelIndex index = ui->treeView->selectionModel()->currentIndex();
    QAbstractItemModel *model = ui->treeView->model();

    if (!model->insertRow(index.row()+1, index.parent()))
        return;

    updateActions();

    for (int column = 0; column < model->columnCount(index.parent()); ++column) {
        QModelIndex child = model->index(index.row()+1, column, index.parent());
        model->setData(child, QVariant("[No data]"), Qt::EditRole);
    }
}

void MainWindow::removeRow()
{
    QModelIndex index = ui->treeView->selectionModel()->currentIndex();
    QAbstractItemModel *model = ui->treeView->model();
    if (model->removeRow(index.row(), index.parent()))
        updateActions();
}




void MainWindow::updateActions(){

    bool hasSelection = !ui->treeView->selectionModel()->selection().isEmpty();
    ui->cmdDelete->setEnabled(hasSelection);

    bool hasCurrent = ui->treeView->selectionModel()->currentIndex().isValid();
    ui->cmdAddClasse->setEnabled(hasCurrent);

    if (hasCurrent)
        ui->treeView->closePersistentEditor(ui->treeView->selectionModel()->currentIndex());

}


void MainWindow::on_seachEdit_textChanged(const QString &arg1)
{
    filterEleveModel->setNamefilter(arg1);
}

void MainWindow::on_addEleveButton_clicked()
{
    auto addDlg = new addEleveDialog();
    addDlg->setWindowModality(Qt::ApplicationModal);
    addDlg->setAttribute(Qt::WA_DeleteOnClose);
    connect(addDlg,SIGNAL(endEdition()),this,SLOT(refreshAllModel()));
    addDlg->show();

}

void MainWindow::on_deleteEleveButton_clicked(QModelIndex &idx)
{   
    m_myeleveModel->removeRows(filterEleveModel->mapToSource(idx).row(), 1, filterEleveModel->mapToSource(idx).parent());
    refreshAllModel();
}

void MainWindow::setDbInfoText()
{
    QSqlQuery query("SELECT * FROM INFO");
    QString varFname;
    while (query.next()){
        varFname = query.record().field("info").value().toString();
        qDebug() << "var info : " << varFname;
    }
    if(!varFname.isEmpty())
        ui->labelInformation->setText(varFname);

    qDebug() << "dbinfo : "<<varFname;
}

void MainWindow::on_editEleveButton_clicked()
{
    auto addDlg = new addEleveDialog(0,addEleveDialog::updateElv, currentElvId);
    addDlg->setWindowModality(Qt::ApplicationModal);
    addDlg->setAttribute(Qt::WA_DeleteOnClose);
    connect(addDlg,SIGNAL(endEdition()),this,SLOT(refreshAllModel()));
    addDlg->show();
}


void MainWindow::refreshAllModel()
{
    m_myeleveModel->select();
    m_elvPaymentModel->select();
    m_eleveDetails->select();
    ui->nomsDesEleves->setCurrentIndex(ui->nomsDesEleves->model()->index(ui->nomsDesEleves->model()->rowCount(),1));
}

void MainWindow::treeviewIndexChanged(const QModelIndex &index)
{
    if((index.parent().data().toString() == "CLASSES") && index.data().toString() != "Tous"){
        filterEleveModel->setClassesfilter(QString::number(index.row()));
    }else{
        ui->seachEdit->setText("");
        filterEleveModel->showAll();
    }
}


void MainWindow::on_pushButton_clicked()
{
    QDir dbDir(QStandardPaths::writableLocation(QStandardPaths::DataLocation));
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Database"), dbDir.absolutePath(), tr("Database Files (*.db *.sql *.txt)"));
    if(!fileName.isEmpty()){
        bool dbStatus = mDatabase->setCurrentDB(fileName);
        qDebug() << "Database connection: " << fileName << "  status "<< dbStatus;
    }
    setDbInfoText();
    refreshAllModel();
}

void MainWindow::elvContextMenu(QPoint posit)
{
    QModelIndex idx = ui->nomsDesEleves->indexAt(posit);
    QString id = m_myeleveModel->index(filterEleveModel->mapToSource(idx).row(),0).data().toString();
    currentElvId = id.toInt();
    qDebug() << "Context" << posit << "elv id " << id;
    QPoint globalpos = ui->nomsDesEleves->mapToGlobal(posit);
    QMenu menuBeyondItem;
    QAction* action_addElement = menuBeyondItem.addAction("AJouter Elève");

    QMenu menuForItem;
    QAction* action_editElement = menuForItem.addAction("Modifier Elève");

    QAction* selectedAction;
    menuForItem.addSeparator();

    QAction* deleteAction = menuForItem.addAction("Supprimer Elève");


    if(!idx.isValid()) {
        selectedAction = menuBeyondItem.exec(globalpos);
        if(selectedAction) {
            if(selectedAction == action_addElement) {
                //qDebug() << "AJouter Elève";
                emit on_addEleveButton_clicked();
            }
        }
    }
    else {
        selectedAction = menuForItem.exec(globalpos);
        if(selectedAction) {
            if(selectedAction == action_editElement) {
                //qDebug() << "Modifier Elève";
                emit on_editEleveButton_clicked();
            }
            if(selectedAction == deleteAction) {
                //qDebug() << "Supprimer Elève";
                on_deleteEleveButton_clicked(idx);
            }
        }
    }
}





















