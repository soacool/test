/********************************************************************************
** Form generated from reading UI file 'addelevedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDELEVEDIALOG_H
#define UI_ADDELEVEDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addEleveDialog
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QFormLayout *formLayout_3;
    QLabel *label_8;
    QLineEdit *dateNaissEdit;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout_12;
    QLabel *label_12;
    QComboBox *combodebutEcolage;
    QFormLayout *formLayout_7;
    QLabel *label_10;
    QLineEdit *contactBEdit;
    QFormLayout *formLayout_13;
    QLabel *label_13;
    QComboBox *comboTarif;
    QFormLayout *formLayout_6;
    QLabel *label_11;
    QLineEdit *contactAEdit;
    QFormLayout *formLayout_4;
    QLabel *label_5;
    QLineEdit *mereEdit;
    QFormLayout *formLayout_10;
    QLabel *label_6;
    QLineEdit *numeroEdit;
    QFormLayout *formLayout_8;
    QLabel *label_9;
    QLineEdit *adressEdit;
    QFormLayout *formLayout_9;
    QLabel *label;
    QComboBox *comboclasseEdit;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLineEdit *prenomEdit;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *nomEdit;
    QFormLayout *formLayout_5;
    QLabel *label_3;
    QLineEdit *pereEdit;
    QFormLayout *formLayout_14;
    QLabel *label_14;
    QDateEdit *insDateEdit;
    QFormLayout *formLayout_11;
    QLabel *label_7;
    QLineEdit *lieuNaissanceEdit;
    QFormLayout *formLayout_16;
    QLabel *label_15;
    QComboBox *comboInsReins;
    QCheckBox *checkBoxParain;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *annulerButton;
    QPushButton *addElvButton;

    void setupUi(QWidget *addEleveDialog)
    {
        if (addEleveDialog->objectName().isEmpty())
            addEleveDialog->setObjectName(QStringLiteral("addEleveDialog"));
        addEleveDialog->resize(641, 373);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(10);
        addEleveDialog->setFont(font);
        groupBox = new QGroupBox(addEleveDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 621, 301));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setHorizontalSpacing(10);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
        label_8->setFont(font1);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_8);

        dateNaissEdit = new QLineEdit(groupBox);
        dateNaissEdit->setObjectName(QStringLiteral("dateNaissEdit"));
        dateNaissEdit->setFont(font);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, dateNaissEdit);


        gridLayout->addLayout(formLayout_3, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        formLayout_12 = new QFormLayout();
        formLayout_12->setObjectName(QStringLiteral("formLayout_12"));
        formLayout_12->setHorizontalSpacing(10);
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_12->setWidget(0, QFormLayout::LabelRole, label_12);

        combodebutEcolage = new QComboBox(groupBox);
        combodebutEcolage->setObjectName(QStringLiteral("combodebutEcolage"));

        formLayout_12->setWidget(0, QFormLayout::FieldRole, combodebutEcolage);


        gridLayout->addLayout(formLayout_12, 5, 2, 1, 1);

        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName(QStringLiteral("formLayout_7"));
        formLayout_7->setHorizontalSpacing(10);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_10);

        contactBEdit = new QLineEdit(groupBox);
        contactBEdit->setObjectName(QStringLiteral("contactBEdit"));
        contactBEdit->setFont(font);

        formLayout_7->setWidget(0, QFormLayout::FieldRole, contactBEdit);


        gridLayout->addLayout(formLayout_7, 3, 2, 1, 1);

        formLayout_13 = new QFormLayout();
        formLayout_13->setObjectName(QStringLiteral("formLayout_13"));
        formLayout_13->setHorizontalSpacing(10);
        formLayout_13->setContentsMargins(0, -1, 0, -1);
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_13->setWidget(0, QFormLayout::LabelRole, label_13);

        comboTarif = new QComboBox(groupBox);
        comboTarif->setObjectName(QStringLiteral("comboTarif"));

        formLayout_13->setWidget(0, QFormLayout::FieldRole, comboTarif);


        gridLayout->addLayout(formLayout_13, 6, 0, 1, 1);

        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        formLayout_6->setHorizontalSpacing(10);
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font1);

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_11);

        contactAEdit = new QLineEdit(groupBox);
        contactAEdit->setObjectName(QStringLiteral("contactAEdit"));
        contactAEdit->setFont(font);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, contactAEdit);


        gridLayout->addLayout(formLayout_6, 2, 2, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setHorizontalSpacing(10);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_5);

        mereEdit = new QLineEdit(groupBox);
        mereEdit->setObjectName(QStringLiteral("mereEdit"));
        mereEdit->setFont(font);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, mereEdit);


        gridLayout->addLayout(formLayout_4, 3, 0, 1, 1);

        formLayout_10 = new QFormLayout();
        formLayout_10->setObjectName(QStringLiteral("formLayout_10"));
        formLayout_10->setHorizontalSpacing(10);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        formLayout_10->setWidget(0, QFormLayout::LabelRole, label_6);

        numeroEdit = new QLineEdit(groupBox);
        numeroEdit->setObjectName(QStringLiteral("numeroEdit"));
        numeroEdit->setFont(font);

        formLayout_10->setWidget(0, QFormLayout::FieldRole, numeroEdit);


        gridLayout->addLayout(formLayout_10, 4, 2, 1, 1);

        formLayout_8 = new QFormLayout();
        formLayout_8->setObjectName(QStringLiteral("formLayout_8"));
        formLayout_8->setHorizontalSpacing(10);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);

        formLayout_8->setWidget(0, QFormLayout::LabelRole, label_9);

        adressEdit = new QLineEdit(groupBox);
        adressEdit->setObjectName(QStringLiteral("adressEdit"));
        adressEdit->setFont(font);

        formLayout_8->setWidget(0, QFormLayout::FieldRole, adressEdit);


        gridLayout->addLayout(formLayout_8, 4, 0, 1, 1);

        formLayout_9 = new QFormLayout();
        formLayout_9->setObjectName(QStringLiteral("formLayout_9"));
        formLayout_9->setHorizontalSpacing(10);
        formLayout_9->setContentsMargins(-1, -1, 0, -1);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        formLayout_9->setWidget(0, QFormLayout::LabelRole, label);

        comboclasseEdit = new QComboBox(groupBox);
        comboclasseEdit->setObjectName(QStringLiteral("comboclasseEdit"));

        formLayout_9->setWidget(0, QFormLayout::FieldRole, comboclasseEdit);


        gridLayout->addLayout(formLayout_9, 5, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setHorizontalSpacing(10);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        prenomEdit = new QLineEdit(groupBox);
        prenomEdit->setObjectName(QStringLiteral("prenomEdit"));
        prenomEdit->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, prenomEdit);


        gridLayout->addLayout(formLayout_2, 0, 2, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(10);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        nomEdit = new QLineEdit(groupBox);
        nomEdit->setObjectName(QStringLiteral("nomEdit"));
        nomEdit->setFont(font);
        nomEdit->setReadOnly(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, nomEdit);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        formLayout_5->setHorizontalSpacing(10);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_3);

        pereEdit = new QLineEdit(groupBox);
        pereEdit->setObjectName(QStringLiteral("pereEdit"));
        pereEdit->setFont(font);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, pereEdit);


        gridLayout->addLayout(formLayout_5, 2, 0, 1, 1);

        formLayout_14 = new QFormLayout();
        formLayout_14->setObjectName(QStringLiteral("formLayout_14"));
        formLayout_14->setHorizontalSpacing(10);
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_14->setWidget(0, QFormLayout::LabelRole, label_14);

        insDateEdit = new QDateEdit(groupBox);
        insDateEdit->setObjectName(QStringLiteral("insDateEdit"));
        insDateEdit->setCalendarPopup(true);
        insDateEdit->setDate(QDate(2017, 11, 30));

        formLayout_14->setWidget(0, QFormLayout::FieldRole, insDateEdit);


        gridLayout->addLayout(formLayout_14, 6, 2, 1, 1);

        formLayout_11 = new QFormLayout();
        formLayout_11->setObjectName(QStringLiteral("formLayout_11"));
        formLayout_11->setHorizontalSpacing(10);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_11->setWidget(0, QFormLayout::LabelRole, label_7);

        lieuNaissanceEdit = new QLineEdit(groupBox);
        lieuNaissanceEdit->setObjectName(QStringLiteral("lieuNaissanceEdit"));

        formLayout_11->setWidget(0, QFormLayout::FieldRole, lieuNaissanceEdit);


        gridLayout->addLayout(formLayout_11, 1, 2, 1, 1);

        formLayout_16 = new QFormLayout();
        formLayout_16->setObjectName(QStringLiteral("formLayout_16"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout_16->setWidget(0, QFormLayout::LabelRole, label_15);

        comboInsReins = new QComboBox(groupBox);
        comboInsReins->setObjectName(QStringLiteral("comboInsReins"));

        formLayout_16->setWidget(0, QFormLayout::FieldRole, comboInsReins);


        gridLayout->addLayout(formLayout_16, 7, 0, 1, 1);

        checkBoxParain = new QCheckBox(groupBox);
        checkBoxParain->setObjectName(QStringLiteral("checkBoxParain"));

        gridLayout->addWidget(checkBoxParain, 7, 2, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        layoutWidget = new QWidget(addEleveDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(400, 330, 191, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        annulerButton = new QPushButton(layoutWidget);
        annulerButton->setObjectName(QStringLiteral("annulerButton"));

        horizontalLayout->addWidget(annulerButton);

        addElvButton = new QPushButton(layoutWidget);
        addElvButton->setObjectName(QStringLiteral("addElvButton"));

        horizontalLayout->addWidget(addElvButton);

        QWidget::setTabOrder(nomEdit, prenomEdit);
        QWidget::setTabOrder(prenomEdit, dateNaissEdit);
        QWidget::setTabOrder(dateNaissEdit, lieuNaissanceEdit);
        QWidget::setTabOrder(lieuNaissanceEdit, pereEdit);
        QWidget::setTabOrder(pereEdit, contactAEdit);
        QWidget::setTabOrder(contactAEdit, mereEdit);
        QWidget::setTabOrder(mereEdit, contactBEdit);
        QWidget::setTabOrder(contactBEdit, adressEdit);
        QWidget::setTabOrder(adressEdit, numeroEdit);
        QWidget::setTabOrder(numeroEdit, comboclasseEdit);
        QWidget::setTabOrder(comboclasseEdit, combodebutEcolage);
        QWidget::setTabOrder(combodebutEcolage, comboTarif);
        QWidget::setTabOrder(comboTarif, insDateEdit);

        retranslateUi(addEleveDialog);
        QObject::connect(annulerButton, SIGNAL(clicked()), addEleveDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(addEleveDialog);
    } // setupUi

    void retranslateUi(QWidget *addEleveDialog)
    {
        addEleveDialog->setWindowTitle(QApplication::translate("addEleveDialog", "Ajout Eleve ", 0));
        groupBox->setTitle(QString());
        label_8->setText(QApplication::translate("addEleveDialog", "Date de naissance:", 0));
        label_12->setText(QApplication::translate("addEleveDialog", "Debut Ecolage", 0));
        label_10->setText(QApplication::translate("addEleveDialog", "Contact:", 0));
        label_13->setText(QApplication::translate("addEleveDialog", "Tarif", 0));
        label_11->setText(QApplication::translate("addEleveDialog", "Contact:", 0));
        label_5->setText(QApplication::translate("addEleveDialog", "M\303\250re:", 0));
        label_6->setText(QApplication::translate("addEleveDialog", "N\302\260 :", 0));
        label_9->setText(QApplication::translate("addEleveDialog", "Adresse:", 0));
        label->setText(QApplication::translate("addEleveDialog", "Classe:", 0));
        label_4->setText(QApplication::translate("addEleveDialog", "Pr\303\251nom :", 0));
        label_2->setText(QApplication::translate("addEleveDialog", "Nom:", 0));
        label_3->setText(QApplication::translate("addEleveDialog", "P\303\250re:", 0));
        label_14->setText(QApplication::translate("addEleveDialog", "Date Inscription", 0));
        label_7->setText(QApplication::translate("addEleveDialog", "Lieu de Naissance", 0));
        label_15->setText(QApplication::translate("addEleveDialog", "Insc/Reins", 0));
        comboInsReins->clear();
        comboInsReins->insertItems(0, QStringList()
         << QApplication::translate("addEleveDialog", "Inscription", 0)
         << QApplication::translate("addEleveDialog", "Rinscription", 0)
        );
        checkBoxParain->setText(QApplication::translate("addEleveDialog", "Parrainn\303\251", 0));
        annulerButton->setText(QApplication::translate("addEleveDialog", "Annuler", 0));
        addElvButton->setText(QApplication::translate("addEleveDialog", "Ajouter  ", 0));
    } // retranslateUi

};

namespace Ui {
    class addEleveDialog: public Ui_addEleveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDELEVEDIALOG_H
