#include "ecolagedelegate.h"
#include <QPainter>
#include <QLineEdit>

EcolageDelegate::EcolageDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

QWidget *EcolageDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    QLineEdit *da = new QLineEdit(parent);
    da->setAttribute(Qt::WA_DeleteOnClose);
    //da->setText()
    return da;
}

void EcolageDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
     QStyledItemDelegate::paint(painter, option, index);

}

void EcolageDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString text = setDataValueByRow(index);
//    qDebug() << "col: "<<index.column() << "row: "<<index.row();
//    if (text == "0")
//        text = "65000";

    QLineEdit *lineEdit = qobject_cast<QLineEdit *>(editor);
    if(lineEdit){
        QObject src;
        //the lambda function is executed using a queued connection
        connect(&src, &QObject::destroyed, lineEdit, [lineEdit](){
                            //set default selection in the line edit
                            int lastDotIndex= lineEdit->text().size();
                            lineEdit->setSelection(0,lastDotIndex);
                        }, Qt::QueuedConnection);
    }
    lineEdit->setText(text);
}

void EcolageDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *lineEdit = qobject_cast<QLineEdit *>(editor);
    QString text = lineEdit->text();
    model->setData(index, text);
}


void EcolageDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}


QString EcolageDelegate::setDataValueByRow(const QModelIndex &idx) const
{
    QString text = idx.model()->data(idx, Qt::DisplayRole).toString();
    if(idx.column() == 3){
        switch (idx.row()) {
            case 0: return "330000";
            break;
            case 1: return "5000";
            break;
            case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
            return "70000";
            break;
            case 13: return "20000";
            break;
        default: return text;

        }

    }
    return text;
}
