#include "addelevedialog.h"
#include "ui_addelevedialog.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>

addEleveDialog::addEleveDialog(QWidget *parent, startUpMode mode, int elvId) :
    QWidget(parent),
    ui(new Ui::addEleveDialog),
    currentMode(mode),
    currentElvId(elvId)
{
    ui->setupUi(this);

    //fill combo mois debut ecolage
    auto *modelDebutEco = new QSqlTableModel(this);
    modelDebutEco->setTable("nature");
    modelDebutEco->setFilter("id<=12");
    modelDebutEco->select();
    ui->combodebutEcolage->setModel(modelDebutEco);
    ui->combodebutEcolage->setModelColumn(1);
    ui->combodebutEcolage->setCurrentIndex(QDate::currentDate().month() - 1);


    //fill combo tarif
    auto *modelTarif = new QSqlQueryModel;
    modelTarif->setQuery("select * from tarifs where id < 4");
    ui->comboTarif->setModel(modelTarif);
    ui->comboTarif->setModelColumn(1);

    //fill combo classe
    auto *modelClasses = new QSqlTableModel(this);
    modelClasses->setTable("classes");
    modelClasses->select();
    ui->comboclasseEdit->setModel(modelClasses);
    ui->comboclasseEdit->setModelColumn(1);

    //ui->contactAEdit->setInputMask("999 99 999 999");
   // ui->contactAEdit->setCursorPosition(0);
   // ui->contactBEdit->setInputMask("999 99 999 999");
    ui->dateNaissEdit->setInputMask("99/99/9999");
    //ui->nomEdit->setInputMask("a");

    //Fill combo genre
    auto *modelGenre = new QSqlTableModel(this);
    modelGenre->setTable("genre");
    modelGenre->select();
    ui->comboGenre->setModel(modelGenre);
    ui->comboGenre->setModelColumn(1);


    currentMode == startUpMode::updateElv ? setupUpdateElv(elvId) : setupAddElv();

}

addEleveDialog::~addEleveDialog()
{
    delete ui;
}

void addEleveDialog::closeEvent(QCloseEvent *event)
{
    emit endEdition();
    event->accept();
}


void addEleveDialog::setStartupMode(addEleveDialog::startUpMode mode)
{
    currentMode = mode;
}

addEleveDialog::startUpMode addEleveDialog::startupmode() const
{
    return currentMode;
}

//ajout eleve fonction
void addEleveDialog::on_addElvButton_clicked()
{
    bool retVal = false;
    if(ui->addElvButton->text() == "Modifier")
       retVal = modifierEleve();
    else
       retVal = ajouteEleve();

    QMessageBox msgBox;
    msgBox.setText("Elève "+ ui->addElvButton->text()+ "\n" +"Avec  " + (retVal ? "succès!" : "Erreur"));
    msgBox.exec();

    clearUi();
    emit endEdition();

}

void addEleveDialog::clearUi()
{
    ui->nomEdit->setText("");
    ui->prenomEdit->setText("");
    ui->comboclasseEdit->setCurrentIndex(0);
    ui->dateNaissEdit->setText("");
    ui->lieuNaissanceEdit->setText("");
    ui->adressEdit->setText("") ;
    ui->mereEdit->setText("");
    ui->pereEdit->setText("");
    ui->contactAEdit->setText("");
    ui->contactBEdit->setText("");
    ui->combodebutEcolage->setCurrentIndex(0);
    ui->comboTarif->setCurrentIndex(0);
    ui->comboclasseEdit->setCurrentIndex(0);
    ui->numeroEdit->setText("");
    ui->comboInsReins->setCurrentIndex(0);
    ui->comboGenre->setCurrentIndex(0);
}

void addEleveDialog::setupAddElv()
{
    //set Date inscription To today
    ui->insDateEdit->setDate(QDate::currentDate());

}

void addEleveDialog::setupUpdateElv(int id)
{
    qDebug()<< "im here" << id;
    ui->addElvButton->setText("Modifier");
    setupMapping();
    eleveDetails->setFilter(QString("elvid=%1").arg(id));
    eleveDetails->select();
    mapper->toFirst();

}

bool addEleveDialog::ajouteEleve()
{
    QSqlQuery query;
    query.prepare("INSERT INTO ELEVES(NAME,PRENAME,CLASSID, GENREID) "
                  "VALUES (?, ?, ?, ?)");

    query.addBindValue(ui->nomEdit->text().trimmed());
    query.addBindValue(ui->prenomEdit->text().trimmed());
    query.addBindValue(ui->comboclasseEdit->currentIndex() + 1);
    query.addBindValue(ui->comboGenre->currentIndex() + 1);
    bool ret = query.exec();
    int elvId = query.lastInsertId().toInt();
    int debutEco = ui->combodebutEcolage->currentIndex() + 1;
    bool ret2 = false;
    if(ret)
    {

        query.prepare("INSERT INTO ELEVEINFO(DATE_NAISSANCE,LIEU_NAISSANCE,ADRESSE,MERE,PERE,CONTACT_A,CONTACT_B,DEBUT_ECOLAGE_ID,TARIF_ID,PROF_ID,ELEVE_ID,NUMERO,DATE_INSCRIPTION) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

        query.addBindValue(ui->dateNaissEdit->text().simplified());
        query.addBindValue(ui->lieuNaissanceEdit->text().simplified());
        query.addBindValue(ui->adressEdit->text().simplified());
        query.addBindValue(ui->mereEdit->text().simplified());
        query.addBindValue(ui->pereEdit->text().simplified());
        query.addBindValue(ui->contactAEdit->text().simplified());
        query.addBindValue(ui->contactBEdit->text().simplified());
        query.addBindValue(ui->combodebutEcolage->currentIndex() + 1);
        query.addBindValue(ui->comboTarif->currentIndex() + 1);
        query.addBindValue(ui->comboclasseEdit->currentIndex() + 1);
        query.addBindValue(elvId);
        query.addBindValue(ui->numeroEdit->text().simplified());
        query.addBindValue(ui->insDateEdit->date().toString("dd/MM/yyyy"));
        ret2 = query.exec();

    }

    QString parrainOrNot = "";

    if(ret2)
    {
        parrainOrNot = ui->checkBoxParain->isChecked() ? "paymentmodelparrain" : "paymentmodel";

        query.prepare("UPDATE "+ parrainOrNot +" set eleve_id =:id");
        query.bindValue(":id",elvId);
        ret2 = query.exec();
       // qDebug()<< "upadte table:" << parrainOrNot << query.lastError() << query.executedQuery();

    }


    if(ret2){

        query.prepare("INSERT INTO PAYMENTS(nature,dateofpayment,firstpay,secondpay,paytype,eleve_id) "
                      "SELECT nature,dateofpayment,firstpay,secondpay,paytype,eleve_id FROM "+ parrainOrNot);
        ret2 = query.exec();
    }

    if(ret2){

        query.prepare("UPDATE payments set paytype= CASE "
                      "when nature in(9,10,11,12) and (nature < (:debut)) then 9 "
                      "when (:debut) not in (9,10,11,12) and nature in(9,10,11,12) then 9 "
                      "when nature in(1,2,3,4,5,6,7) and ((:debut) in (1,2,3,4,5,6,7)) and (nature < (:debut)) then 9 "
                      "else paytype  end "
                      "where eleve_id =:id and paytype = 1");
        query.bindValue(":id",elvId);
        query.bindValue(":debut", debutEco);
        ret2 = query.exec();

        if(ui->comboInsReins->currentIndex() == 1)
        {
            query.prepare("UPDATE payments set paytype= 6 where eleve_id =:id and paytype = 5");
            query.bindValue(":id",elvId);
            query.exec();
        }

    }

    return ret2;
}

bool addEleveDialog::modifierEleve()
{
    bool retVal = false;
    retVal = mapper->submit();
    return retVal;

}

void addEleveDialog::setupMapping()
{
    mapper = new QDataWidgetMapper(this);
    eleveDetails = new QSqlTableModel(this);
    eleveDetails->setTable("ELEVEDETAILSFOREDITO");
    // qDebug()<< "im here" << eleveDetails->rowCount() << eleveDetails->tableName();
    mapper->setModel(eleveDetails);
    mapper->setItemDelegate(new AddElvDelegate(this));
    mapper->addMapping(ui->nomEdit, eleveDetails->fieldIndex("name"));
    mapper->addMapping(ui->prenomEdit, eleveDetails->fieldIndex("prename"));
    mapper->addMapping(ui->dateNaissEdit, eleveDetails->fieldIndex("date_naissance"));
    mapper->addMapping(ui->lieuNaissanceEdit, eleveDetails->fieldIndex("lieu_naissance"));
    mapper->addMapping(ui->pereEdit, eleveDetails->fieldIndex("pere"));
    mapper->addMapping(ui->mereEdit, eleveDetails->fieldIndex("mere"));
    mapper->addMapping(ui->contactAEdit, eleveDetails->fieldIndex("contact_a"));
    mapper->addMapping(ui->contactBEdit, eleveDetails->fieldIndex("contact_b"));
    mapper->addMapping(ui->adressEdit, eleveDetails->fieldIndex("adresse"));
    mapper->addMapping(ui->numeroEdit, eleveDetails->fieldIndex("numero"));
    mapper->addMapping(ui->comboclasseEdit , eleveDetails->fieldIndex("classe"));
    mapper->addMapping(ui->combodebutEcolage, eleveDetails->fieldIndex("debut_ecolage"));
    mapper->addMapping(ui->comboTarif, eleveDetails->fieldIndex("tarif"));
    mapper->addMapping(ui->insDateEdit, eleveDetails->fieldIndex("date_inscription"));
    mapper->addMapping(ui->comboGenre, eleveDetails->fieldIndex("genre"));
    //add parriné et ins/reins

}
