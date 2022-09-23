#ifndef ECOLAGEDELEGATE_H
#define ECOLAGEDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>

class EcolageDelegate: public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit EcolageDelegate(QObject *parent = 0);


    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QString setDataValueByRow(const QModelIndex &idx) const;

};

#endif // ECOLAGEDELEGATE_H
