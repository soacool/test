#include "namecalssesfiltermodel.h"

NameCalssesFilterModel::NameCalssesFilterModel(QObject *parent) : QSortFilterProxyModel(parent)
{
    nameRegExp.setCaseSensitivity(Qt::CaseInsensitive);
    classesRegExp.setCaseSensitivity(Qt::CaseInsensitive);
    classesRegExp.setPatternSyntax(QRegExp::RegExp);
    nameRegExp.setPatternSyntax(QRegExp::RegExp);
}

bool NameCalssesFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex indexName = sourceModel()->index(source_row,1, source_parent);
    QModelIndex indexClasses = sourceModel()->index(source_row, 2, source_parent);

    QString name= sourceModel()->data(indexName).toString();
    QString classes= sourceModel()->data(indexClasses).toString();

    return (name.contains(nameRegExp) && classes.contains(classesRegExp));

}

void NameCalssesFilterModel::setNamefilter(const QString &regExp)
{
    nameRegExp.setPattern(regExp);
    invalidateFilter();
}

void NameCalssesFilterModel::setClassesfilter(const QString &regExp)
{
    classesRegExp.setPattern(regExp);
    invalidateFilter();
}

void NameCalssesFilterModel::showAll()
{
    setClassesfilter("");
    setNamefilter("");
}
