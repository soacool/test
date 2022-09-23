#ifndef MYELEVEMODEL_H
#define MYELEVEMODEL_H

#include <QAbstractTableModel>
#include <QSqlTableModel>

class MyEleveModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit MyEleveModel(QObject *parent = 0);

    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
};

#endif // MYELEVEMODEL_H
