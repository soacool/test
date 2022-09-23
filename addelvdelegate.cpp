#include "addelvdelegate.h"
#include <QDebug>
#include <QDateEdit>

AddElvDelegate::AddElvDelegate(QObject *parent) : QItemDelegate(parent)
{

}

void AddElvDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{

    if (editor->property("currentIndex").isValid()) {
        editor->setProperty("currentIndex", index.data().toInt() - 1);
        return;
    }

    if(editor->property("date").isValid()){

        QVariant value;
        if(index.data().toDate().isValid()) qDebug() << "Editor DAta Is date";
        value = QDate::fromString(index.data().toString(), "dd/MM/yyyy");
       // qDebug() << "Editor DAta"<< value <<"Editor: "<<  editor->property("date");
        editor->setProperty("date", value);
        return;
    }

    QItemDelegate::setEditorData(editor, index);
}

void AddElvDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QVariant value = editor->property("currentIndex");
    if (value.isValid()) {
        model->setData(index, value.toInt() + 1);
        return;
    }

    if(editor->property("date").isValid()){
        QVariant value = editor->property("date");
        QString str = value.toDate().toString("dd/MM/yyyy");
        // qDebug()<< "dataModel is: " << str;
         model->setData(index, str);
        return;
    }

    QItemDelegate::setModelData(editor, model, index);

}
