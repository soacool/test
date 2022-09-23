#ifndef CONNECTION_H
#define CONNECTION_H
#include <QString>
#include <QVariant>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QList>
#include <QFile>
#include <QtSql>
#include <QDebug>



static bool createConnection()
{
   QString dbName("database.db");
   QHash<QString, QString> nameToPathHash;
   QString localDBName = nameToPathHash[dbName];
   QString applicationPath = QCoreApplication::applicationDirPath();
   QDir dbDir(QStandardPaths::writableLocation(QStandardPaths::DataLocation));
   QString databasePath = dbDir.absolutePath();
   //qDebug()<< "data path: "<<databasePath;
   if (!dbDir.exists())
       dbDir.mkpath(dbDir.absolutePath());

   QFile dbFile(databasePath + "/" + dbName);
   if (!dbFile.exists())
    {
        QFile dbTemplate(applicationPath + "/databases/" + dbName);
        if (dbTemplate.exists())
            dbTemplate.copy(dbFile.fileName());
       // qDebug()<< dbTemplate.fileName();
    }
    else
    dbFile.setPermissions(QFile::ReadOwner|QFile::WriteOwner);
    nameToPathHash[dbName] = dbFile.fileName();
    localDBName = nameToPathHash[dbName];    
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(localDBName);
    db.setHostName("localhost");
    if (!db.open()) {

        return false;
    }

    return true;

}


#endif // CONNECTION_H
