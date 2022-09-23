#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include<QtCore>
#include <memory>
#include <QSqlDatabase>

class QSqlQuery;



const QString DATABASE_FILENAME = "database.db";


class DatabaseManager
{
public:
    static void debugQuery(const QSqlQuery& query);
    bool setCurrentDB(QString& dbUrl);
    static DatabaseManager *instance();
    QSqlDatabase myDb();
    ~DatabaseManager();

protected:
    DatabaseManager(const QString& path = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager& rhs);

private:
    QSqlDatabase *mDatabase;
    static DatabaseManager *singleton;
};

#endif // DATABASEMANAGER_H
