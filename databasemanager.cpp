#include "databasemanager.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QStandardPaths>

DatabaseManager::DatabaseManager(const QString &path):
    mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE")))

{
    Q_UNUSED(path);  
    QString applicationPath = QCoreApplication::applicationDirPath();
    QDir dbDir(QStandardPaths::writableLocation(QStandardPaths::DataLocation));
    QString databasePath = dbDir.absolutePath();
    if (!dbDir.exists())
        dbDir.mkpath(dbDir.absolutePath());

    QFile dbFile(databasePath + "/" + DATABASE_FILENAME);
    QString localDBName = dbFile.fileName();
    if (!dbFile.exists())
    {
        QFile dbTemplate(applicationPath + "/databases/" + DATABASE_FILENAME);
        if (dbTemplate.exists())
            dbTemplate.copy(dbFile.fileName());
    }
    else
       setCurrentDB(localDBName);

}


void DatabaseManager::debugQuery(const QSqlQuery &query)
{
    if (query.lastError().type() == QSqlError::ErrorType::NoError) {
            qDebug() << "Query OK:"  << query.lastQuery();
        } else {
           qWarning() << "Query KO:" << query.lastError().text();
           qWarning() << "Query text:" << query.lastQuery();
    }
}

bool DatabaseManager::setCurrentDB(QString &dbUrl)
{
    if(mDatabase->isOpen())
          mDatabase->close();

    qDebug()  <<  QSqlDatabase::drivers();
    QFile dbFile(dbUrl);
    dbFile.setPermissions(QFile::ReadOwner|QFile::WriteOwner);
    QString localDBName = dbFile.fileName();
    mDatabase->setDatabaseName(localDBName);
    mDatabase->setHostName("localhost");
    bool openStatus = mDatabase->open();
    qDebug() << "Database connection: " << (openStatus ? "OK" : "Error");
    return openStatus;
}

DatabaseManager *DatabaseManager::singleton = nullptr;

DatabaseManager *DatabaseManager::instance()
{

    if(singleton == nullptr)
        singleton = new DatabaseManager();
    return singleton;
}

QSqlDatabase DatabaseManager::myDb()
{
    return *mDatabase;
}

DatabaseManager::~DatabaseManager()
{
    mDatabase->close();
    delete singleton;
}


