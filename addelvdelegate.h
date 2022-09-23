#ifndef ADDELVDELEGATE_H
#define ADDELVDELEGATE_H

#include <QObject>
#include <QItemDelegate>
#include <QMetaProperty>

class AddElvDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit AddElvDelegate(QObject *parent = 0);
    void setEditorData(QWidget *editor,
                       const QModelIndex &index) const;
    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index) const;

signals:

public slots:
};

#endif // ADDELVDELEGATE_H
