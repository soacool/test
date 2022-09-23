#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QDataWidgetMapper>
#include <QSqlRelationalTableModel>
#include <QSortFilterProxyModel>
#include "elvpaymentmodel.h"
#include "myelevemodel.h"
#include "namecalssesfiltermodel.h"
#include <QListWidgetItem>


namespace Ui {
class MainWindow;
}

class DatabaseManager;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void showTotal();    
    void updateActions();

private slots:  

    void on_seachEdit_textChanged(const QString &arg1);

    void on_addEleveButton_clicked();

    void setDbInfoText();

    void refreshAllModel();
    void treeviewIndexChanged(const QModelIndex &index);

    void insertChild();
    void insertRow();
    void removeRow();
    void on_editEleveButton_clicked();
    void on_pushButton_clicked();
    void elvContextMenu(QPoint);

private:
    Ui::MainWindow *ui;   
    void createMenu();   
    QDataWidgetMapper *mapper;
    void loadEleve(const QModelIndex& eleveIndex);
    void clearUi();
    QSqlTableModel *m_eleveDetails;
    NameCalssesFilterModel *filterEleveModel ;
    DatabaseManager *mDatabase;
    QSqlQueryModel *eleveModel;
    QItemSelectionModel* eleveSelectionModel;
    void loadPayment(QString &id);
    void fillTreeView();
    //void filterElevesList(QString &str);
    ElvPaymentModel *m_elvPaymentModel;
    MyEleveModel *m_myeleveModel;
    void setelvDetailsMap();    
    int currentElvId;

};



#endif // MAINWINDOW_H
