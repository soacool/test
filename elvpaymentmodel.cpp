#include "elvpaymentmodel.h"
#include <QFont>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlField>
#include <QVariant>
#include <QBrush>


ElvPaymentModel::ElvPaymentModel(QObject *parent)
    : QSqlTableModel(parent)
{

    setTable("elevepayments");
    select();
    setEditStrategy(QSqlTableModel::OnRowChange);
    connect(this ,&QAbstractItemModel::dataChanged, [this](const QModelIndex &selected){
        if(selected.isValid() && selected.data().isValid())
        {
            submitAll();
            select();
            emit recalculateTotal();
        }
        else
            return;
    });
}

QVariant ElvPaymentModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal)
    {
        if(role == Qt::DisplayRole)
            switch(section)
            {
            case 0: return "id";            break;
            case 1: return "Date de Payment";            break;
            case 2: return "Nature";   break;
            case 3: return "1er Versement";       break;
            case 4: return "2ème Versement";   break;
            case 5: return "Total Réçu";   break;
            case 6: return "Reste à payer";   break;
            default:
                return QString("Column %1").arg(section + 1);
                break;
            }
    }
    else if(orientation == Qt::Vertical)
    {
        if(role == Qt::DisplayRole)
            switch(section)
            {
            case 0: return "Inscription";     break;
            case 1: return "Carnet";   break;
            case 2: return "Septembre";       break;
            case 3: return "Octobre";   break;
            case 4: return "Novembre";   break;
            case 5: return "Decembre";     break;
            case 6: return "Janvier";   break;
            case 7: return "Fevrier";       break;
            case 8: return "Mars";   break;
            case 9: return "Avril";   break;
            case 10: return "Mai";   break;
            case 11: return "Juin";   break;
            case 12: return "Juillet";   break;
            case 13: return "Assurance";   break;
            case 14: return "T_Shirt";   break;
            case 15: return "Evenement";   break;
            default:
                return QString("Column %1").arg(section + 1);
                break;
            }

        if(role == Qt::SizeHintRole)
        {
            return QSize(100,0);
        }
    }

    if(role == Qt::FontRole)
    {
        QFont boldFont;
        boldFont.setFamily("Ubuntu");
        boldFont.setBold(true);
        return boldFont;

    }

    return QVariant();
}

QVariant ElvPaymentModel::data(const QModelIndex &idx, int role) const
{
    if (!idx.isValid())
        return QVariant();

    if( role ==  Qt::ForegroundRole)
    {
        if (idx.column() == 6 && this->QSqlQueryModel::data(idx).toInt() > 0)
        {
            QBrush redText(Qt::red);
            return redText;
        }
        else
        {
            QBrush blackTxt(Qt::black);
            return blackTxt;
        }

    }
    if(role == Qt::TextAlignmentRole){
        if(idx.column() == 1)
        {
            return Qt::AlignCenter;
        }
        else
        {
            return Qt::AlignRight + Qt::AlignVCenter;
        }
    }

    return this->QSqlQueryModel::data(idx,role);
}

void ElvPaymentModel::setFilterPayment(const QString &filter)
{
    setFilter(filter);
}

Qt::ItemFlags ElvPaymentModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return Qt::NoItemFlags;
    }


    if(index.column() >= 5)
    {
        // qDebug()<< "im column Disabled :";
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    }

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;

}

QString ElvPaymentModel::TotalRecu()
{
    int val = 0;
    for(int i = 0; i < this->rowCount(); i++)
    {
        val += this->QSqlQueryModel::data(this->QSqlQueryModel::index(i,5)).toInt();
    }
    return QString::number(val);
}

QString ElvPaymentModel::ResteApayer()
{
    int val = 0;
    for(int i = 0; i < this->rowCount(); i++)
    {
        val += this->QSqlQueryModel::data(this->QSqlQueryModel::index(i,6)).toInt();
    }
    return QString::number(val);
}
