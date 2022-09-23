#ifndef ELVPAYMENTMODEL_H
#define ELVPAYMENTMODEL_H

#include <QAbstractTableModel>
#include <QSqlTableModel>
#include <QObject>

class ElvPaymentModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit ElvPaymentModel(QObject *parent = 0);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QVariant data(const QModelIndex &idx, int role) const override;

    void setFilterPayment(const QString &filter);

    //set column editable ou non editable
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    QString TotalRecu();
    QString ResteApayer();

signals:
    void recalculateTotal();

private:

};

#endif // ELVPAYMENTMODEL_H
