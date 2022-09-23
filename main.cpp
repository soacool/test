#include <QApplication>
#include <QFile>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(ressources);
    QApplication a(argc, argv);
    MainWindow w;
    QFile styleFile( ":/style/darkorange.stylesheet");
    styleFile.open( QFile::ReadOnly );
    QString style( styleFile.readAll() );
    a.setStyleSheet(style);
    w.setWindowState(Qt::WindowMaximized);
    w.show();

    return a.exec();
}
