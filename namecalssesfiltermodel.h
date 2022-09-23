#ifndef NAMECALSSESFILTERMODEL_H
#define NAMECALSSESFILTERMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

class NameCalssesFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit NameCalssesFilterModel(QObject *parent = 0);
    
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
    void setNamefilter(const QString& regExp);
    void setClassesfilter(const QString& regExp);
    void showAll();

signals:

public slots:

private:
    QRegExp nameRegExp;
    QRegExp classesRegExp;
};

#endif // NAMECALSSESFILTERMODEL_H
