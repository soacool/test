#ifndef MYDATEDELEGATE_H
#define MYDATEDELEGATE_H
#include <QObject>
#include <QStyledItemDelegate>
//#include <QWidget>


class MyDateDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit MyDateDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

signals:

public slots:

private:

};

#endif // MYDATEDELEGATE_H
