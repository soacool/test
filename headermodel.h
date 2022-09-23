#ifndef HEADERMODEL_H
#define HEADERMODEL_H

#include <QObject>
#include <QIdentityProxyModel>


class HeaderModel :  public QIdentityProxyModel
{
    Q_OBJECT
public:
    explicit HeaderModel(QObject *parent = 0);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

signals:

public slots:
};

#endif // HEADERMODEL_H
