#ifndef ADDELEVEDIALOG_H
#define ADDELEVEDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QSqlTableModel>
#include <QCloseEvent>
#include <QDataWidgetMapper>
#include "addelvdelegate.h"

namespace Ui {
class addEleveDialog;
}

class addEleveDialog : public QWidget
{
    Q_OBJECT


public:
    enum startUpMode{ addElv, updateElv};
    explicit addEleveDialog(QWidget *parent = 0, startUpMode mode = startUpMode::addElv, int elvId = 0);
    ~addEleveDialog();
    void closeEvent(QCloseEvent *event);   
    Q_ENUM(startUpMode)
    void setStartupMode(startUpMode mode);
    startUpMode startupmode() const;
signals:
    void endEdition();

private slots:
    void on_addElvButton_clicked();

private:
    Ui::addEleveDialog *ui;
    void clearUi();
    startUpMode currentMode;
    int currentElvId;
    void setupAddElv();
    void setupUpdateElv(int id);
    bool ajouteEleve();
    bool modifierEleve();
    QSqlTableModel *eleveDetails;
    QDataWidgetMapper *mapper;
    void setupMapping();

};

#endif // ADDELEVEDIALOG_H
