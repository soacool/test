#include "mydatedelegate.h"
#include <QDateEdit>
#include <QPainter>
#include <QLineEdit>
#include <QDebug>

MyDateDelegate::MyDateDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

QWidget *MyDateDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);   
    QLineEdit *da = new QLineEdit(parent);
    da->setAttribute(Qt::WA_DeleteOnClose);
    da->setInputMask("00-00-00");
    return da;

}

void MyDateDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{

    QString text = index.model()->data(index, Qt::DisplayRole).toString();
    QDate date = QDate::fromString(text,"dd-MM-yy");
    if (!date.isValid())
        text = QDate::currentDate().toString("dd-MM-yy");

    QLineEdit *lineEdit = qobject_cast<QLineEdit *>(editor);
    if(lineEdit){
        QObject src;
        //the lambda function is executed using a queued connection
        connect(&src, &QObject::destroyed, lineEdit, [lineEdit](){
                            //set default selection in the line edit
                            int lastDotIndex= lineEdit->text().indexOf("-");
                            lineEdit->setSelection(0,lastDotIndex);
                        }, Qt::QueuedConnection);
    }
    lineEdit->setText(text);

}

void MyDateDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}

void MyDateDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{   
    QLineEdit *lineEdit = qobject_cast<QLineEdit *>(editor);
    QString text = lineEdit->text();
    QDate date = QDate::fromString(text,"dd-MM-yy");
    if (!date.isValid())
         text = "0";

    model->setData(index, text);
}

void MyDateDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //layout direction pour vrai datetime type de sqlite ::de droite à gauche
    QStyledItemDelegate::paint(painter, option, index);
}
