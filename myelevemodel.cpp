#include "myelevemodel.h"
#include <QDebug>
#include <QPixmap>

MyEleveModel::MyEleveModel(QObject *parent)
    : QSqlTableModel(parent)
{

    setTable("elvesforlistview");
    select();

}

QVariant MyEleveModel::data(const QModelIndex &idx, int role) const
{
    if (!idx.isValid())
        return QVariant();

    if(role == Qt::DecorationRole)
    {
       int genre = this->QSqlQueryModel::data(this->QSqlQueryModel::index(idx.row(),3)).toInt();
       if(genre == 1){
          return QVariant::fromValue(QPixmap(":/images/garcon.png").scaled(QSize(32,32)));
       }else{
          return QVariant::fromValue(QPixmap(":/images/fille.png").scaled(QSize(32,32)));
       }
    }
    return this->QSqlQueryModel::data(idx,role);
}

Qt::ItemFlags MyEleveModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return Qt::NoItemFlags;
    }

    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

//void MyEleveModel::refreshData()
//{

//}

