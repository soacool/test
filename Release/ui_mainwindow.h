/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout;
    QTreeView *treeView;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout;
    QToolButton *cmdAdd;
    QToolButton *cmdEdit;
    QToolButton *cmdDelete;
    QToolButton *cmdRefresh;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelInformation;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *tabGestion;
    QHBoxLayout *horizontalLayout_11;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *seachEdit;
    QListView *nomsDesEleves;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *addEleveButton;
    QPushButton *editEleveButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout_3;
    QLabel *labelTtalRecu;
    QLabel *label_13;
    QFormLayout *formLayout_2;
    QLabel *label_12;
    QLabel *labelTarif;
    QFormLayout *formLayout_4;
    QLabel *label_14;
    QLabel *labelRestePayer;
    QFormLayout *formLayout;
    QLabel *label_7;
    QLabel *labelDebutEcolage;
    QFrame *line;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label;
    QLineEdit *classeEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QLineEdit *pereEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QLineEdit *contactBEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLineEdit *adressEdit;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_6;
    QLineEdit *numeroEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *prenomEdit;
    QGraphicsView *photoView;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QLineEdit *contactAEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLineEdit *dateNaissEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QLineEdit *mereEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QLineEdit *nomEdit;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tabGlobale;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1018, 510);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_13 = new QHBoxLayout(centralWidget);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(-1, 5, -1, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 5, 0, -1);
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setMinimumSize(QSize(180, 300));
        treeView->setMaximumSize(QSize(211, 500));
        treeView->setFont(font);

        verticalLayout->addWidget(treeView);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
        groupBox_3->setFont(font1);
        horizontalLayout_12 = new QHBoxLayout(groupBox_3);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cmdAdd = new QToolButton(groupBox_3);
        cmdAdd->setObjectName(QStringLiteral("cmdAdd"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/file_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmdAdd->setIcon(icon);
        cmdAdd->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(cmdAdd);

        cmdEdit = new QToolButton(groupBox_3);
        cmdEdit->setObjectName(QStringLiteral("cmdEdit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/file_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmdEdit->setIcon(icon1);
        cmdEdit->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(cmdEdit);

        cmdDelete = new QToolButton(groupBox_3);
        cmdDelete->setObjectName(QStringLiteral("cmdDelete"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/file_delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmdDelete->setIcon(icon2);
        cmdDelete->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(cmdDelete);

        cmdRefresh = new QToolButton(groupBox_3);
        cmdRefresh->setObjectName(QStringLiteral("cmdRefresh"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/file_refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmdRefresh->setIcon(icon3);
        cmdRefresh->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(cmdRefresh);


        horizontalLayout_12->addLayout(horizontalLayout);


        verticalLayout->addWidget(groupBox_3);

        verticalSpacer_2 = new QSpacerItem(22, 32, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        labelInformation = new QLabel(centralWidget);
        labelInformation->setObjectName(QStringLiteral("labelInformation"));
        labelInformation->setFont(font1);
        labelInformation->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelInformation);

        verticalSpacer = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_13->addLayout(verticalLayout);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFont(font1);
        tabGestion = new QWidget();
        tabGestion->setObjectName(QStringLiteral("tabGestion"));
        horizontalLayout_11 = new QHBoxLayout(tabGestion);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        groupBox_2 = new QGroupBox(tabGestion);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(150, 0));
        groupBox_2->setMaximumSize(QSize(350, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        seachEdit = new QLineEdit(groupBox_2);
        seachEdit->setObjectName(QStringLiteral("seachEdit"));

        verticalLayout_3->addWidget(seachEdit);

        nomsDesEleves = new QListView(groupBox_2);
        nomsDesEleves->setObjectName(QStringLiteral("nomsDesEleves"));
        nomsDesEleves->setFont(font);
        nomsDesEleves->setModelColumn(0);

        verticalLayout_3->addWidget(nomsDesEleves);

        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        verticalLayout_2 = new QVBoxLayout(groupBox_6);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, 6);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        addEleveButton = new QPushButton(groupBox_6);
        addEleveButton->setObjectName(QStringLiteral("addEleveButton"));

        horizontalLayout_10->addWidget(addEleveButton);

        editEleveButton = new QPushButton(groupBox_6);
        editEleveButton->setObjectName(QStringLiteral("editEleveButton"));

        horizontalLayout_10->addWidget(editEleveButton);


        verticalLayout_2->addLayout(horizontalLayout_10);


        verticalLayout_3->addWidget(groupBox_6);


        horizontalLayout_11->addWidget(groupBox_2);

        groupBox = new QGroupBox(tabGestion);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font1);
        groupBox->setFlat(false);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(3);
        gridLayout->setContentsMargins(-1, 1, -1, 9);
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setFont(font1);
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, 0, -1, 3);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout_2 = new QGridLayout(groupBox_5);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_2->setVerticalSpacing(6);
        gridLayout_2->setContentsMargins(-1, 6, -1, 6);
        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        labelTtalRecu = new QLabel(groupBox_5);
        labelTtalRecu->setObjectName(QStringLiteral("labelTtalRecu"));
        labelTtalRecu->setFont(font1);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, labelTtalRecu);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_13);


        gridLayout_2->addLayout(formLayout_3, 1, 2, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font1);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_12);

        labelTarif = new QLabel(groupBox_5);
        labelTarif->setObjectName(QStringLiteral("labelTarif"));
        QFont font2;
        font2.setFamily(QStringLiteral("Ubuntu"));
        font2.setPointSize(10);
        font2.setItalic(false);
        labelTarif->setFont(font2);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, labelTarif);


        gridLayout_2->addLayout(formLayout_2, 1, 0, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setSpacing(6);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font1);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_14);

        labelRestePayer = new QLabel(groupBox_5);
        labelRestePayer->setObjectName(QStringLiteral("labelRestePayer"));
        QFont font3;
        font3.setFamily(QStringLiteral("Ubuntu"));
        font3.setBold(true);
        font3.setWeight(75);
        labelRestePayer->setFont(font3);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, labelRestePayer);


        gridLayout_2->addLayout(formLayout_4, 1, 3, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_7);

        labelDebutEcolage = new QLabel(groupBox_5);
        labelDebutEcolage->setObjectName(QStringLiteral("labelDebutEcolage"));
        labelDebutEcolage->setFont(font2);

        formLayout->setWidget(0, QFormLayout::FieldRole, labelDebutEcolage);


        gridLayout_2->addLayout(formLayout, 1, 1, 1, 1);


        verticalLayout_4->addWidget(groupBox_5);

        line = new QFrame(groupBox_4);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        tableView = new QTableView(groupBox_4);
        tableView->setObjectName(QStringLiteral("tableView"));
        QFont font4;
        font4.setFamily(QStringLiteral("Ubuntu"));
        font4.setPointSize(9);
        tableView->setFont(font4);
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableView->setAlternatingRowColors(false);
        tableView->setCornerButtonEnabled(false);
        tableView->horizontalHeader()->setDefaultSectionSize(120);
        tableView->horizontalHeader()->setMinimumSectionSize(100);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setDefaultSectionSize(30);
        tableView->verticalHeader()->setHighlightSections(false);
        tableView->verticalHeader()->setMinimumSectionSize(25);

        verticalLayout_4->addWidget(tableView);


        verticalLayout_5->addLayout(verticalLayout_4);


        gridLayout->addWidget(groupBox_4, 5, 0, 2, 5);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(10);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        horizontalLayout_14->addWidget(label);

        classeEdit = new QLineEdit(groupBox);
        classeEdit->setObjectName(QStringLiteral("classeEdit"));
        classeEdit->setFont(font);

        horizontalLayout_14->addWidget(classeEdit);


        gridLayout->addLayout(horizontalLayout_14, 4, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(10);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        horizontalLayout_8->addWidget(label_3);

        pereEdit = new QLineEdit(groupBox);
        pereEdit->setObjectName(QStringLiteral("pereEdit"));
        pereEdit->setFont(font);

        horizontalLayout_8->addWidget(pereEdit);


        gridLayout->addLayout(horizontalLayout_8, 2, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font1);

        horizontalLayout_5->addWidget(label_11);

        contactBEdit = new QLineEdit(groupBox);
        contactBEdit->setObjectName(QStringLiteral("contactBEdit"));
        contactBEdit->setFont(font);

        horizontalLayout_5->addWidget(contactBEdit);


        gridLayout->addLayout(horizontalLayout_5, 3, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);

        horizontalLayout_3->addWidget(label_9);

        adressEdit = new QLineEdit(groupBox);
        adressEdit->setObjectName(QStringLiteral("adressEdit"));
        adressEdit->setFont(font);

        horizontalLayout_3->addWidget(adressEdit);


        gridLayout->addLayout(horizontalLayout_3, 1, 2, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(10);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_15->addWidget(label_6);

        numeroEdit = new QLineEdit(groupBox);
        numeroEdit->setObjectName(QStringLiteral("numeroEdit"));
        numeroEdit->setFont(font);

        horizontalLayout_15->addWidget(numeroEdit);


        gridLayout->addLayout(horizontalLayout_15, 4, 2, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_7->addWidget(label_4);

        prenomEdit = new QLineEdit(groupBox);
        prenomEdit->setObjectName(QStringLiteral("prenomEdit"));
        prenomEdit->setFont(font);

        horizontalLayout_7->addWidget(prenomEdit);


        gridLayout->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        photoView = new QGraphicsView(groupBox);
        photoView->setObjectName(QStringLiteral("photoView"));
        photoView->setMaximumSize(QSize(100, 90));

        gridLayout->addWidget(photoView, 0, 4, 4, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        horizontalLayout_4->addWidget(label_10);

        contactAEdit = new QLineEdit(groupBox);
        contactAEdit->setObjectName(QStringLiteral("contactAEdit"));
        contactAEdit->setFont(font);

        horizontalLayout_4->addWidget(contactAEdit);


        gridLayout->addLayout(horizontalLayout_4, 2, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        horizontalLayout_2->addWidget(label_8);

        dateNaissEdit = new QLineEdit(groupBox);
        dateNaissEdit->setObjectName(QStringLiteral("dateNaissEdit"));
        dateNaissEdit->setFont(font);

        horizontalLayout_2->addWidget(dateNaissEdit);


        gridLayout->addLayout(horizontalLayout_2, 0, 2, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(10);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout_9->addWidget(label_5);

        mereEdit = new QLineEdit(groupBox);
        mereEdit->setObjectName(QStringLiteral("mereEdit"));
        mereEdit->setFont(font);

        horizontalLayout_9->addWidget(mereEdit);


        gridLayout->addLayout(horizontalLayout_9, 3, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(10);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_6->addWidget(label_2);

        nomEdit = new QLineEdit(groupBox);
        nomEdit->setObjectName(QStringLiteral("nomEdit"));
        nomEdit->setFont(font);
        nomEdit->setReadOnly(true);

        horizontalLayout_6->addWidget(nomEdit);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 1, 1, 1);


        horizontalLayout_11->addWidget(groupBox);

        horizontalLayout_11->setStretch(1, 1);
        tabWidget->addTab(tabGestion, QString());
        tabGlobale = new QWidget();
        tabGlobale->setObjectName(QStringLiteral("tabGlobale"));
        tabWidget->addTab(tabGlobale, QString());

        horizontalLayout_13->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1018, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion Eleves POMME D'API", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Command", Q_NULLPTR));
        cmdAdd->setText(QApplication::translate("MainWindow", "Ajouter nouveau", Q_NULLPTR));
        cmdEdit->setText(QApplication::translate("MainWindow", "Modifier selection", Q_NULLPTR));
        cmdDelete->setText(QApplication::translate("MainWindow", "Supprimer selection", Q_NULLPTR));
        cmdRefresh->setText(QApplication::translate("MainWindow", "Actualiser les donn\303\251es", Q_NULLPTR));
        labelInformation->setText(QApplication::translate("MainWindow", "INFO SUR LA BASE SELECTIONNEE", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Listes des \303\251l\303\250ves", Q_NULLPTR));
        seachEdit->setPlaceholderText(QApplication::translate("MainWindow", "Rechercher un \303\251l\303\250ve", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "El\303\250ve", Q_NULLPTR));
        addEleveButton->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        editEleveButton->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Details", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Infos Payements", Q_NULLPTR));
        groupBox_5->setTitle(QString());
        labelTtalRecu->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "Total Re\303\247u", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Tarif:", Q_NULLPTR));
        labelTarif->setText(QString());
        label_14->setText(QApplication::translate("MainWindow", "Total \303\240 Payer", Q_NULLPTR));
        labelRestePayer->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "Debut Eco:", Q_NULLPTR));
        labelDebutEcolage->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Classe:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "P\303\250re:", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Contact:", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Adresse:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "N\302\260 :", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Pr\303\251nom :", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Contact:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Date de naissance:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "M\303\250re:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Nom:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabGestion), QApplication::translate("MainWindow", "Gestion Des \303\251l\303\250ves", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabGlobale), QApplication::translate("MainWindow", "Info Globale", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
