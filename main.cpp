#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include  <QDebug>
#include "connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test=c.ouvrirConnexion();
    MainWindow w;
    if (test)
   { w.show();}


    else
        QMessageBox::information(nullptr,QObject::tr("database is not found"),QObject::tr("Echec de la connexion.\n"));

    return a.exec();


}
