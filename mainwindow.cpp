#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipement.h"
#include "fournisseur.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *empl)
    : QMainWindow(empl)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabequipement->setModel(temequipement.afficherE());
    ui->tabfournisseur->setModel(temfournisseur.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{
    QString nom = ui->nom->text();
    QString adress = ui->adress->text();
    int numero = ui->numero->text().toInt();
    fournisseur f (nom, adress,numero);
    bool test = f.ajouter();
    if (test)
    {   ui->tabfournisseur->setModel(temfournisseur.afficher();
      QMessageBox::information(nullptr,QObjet::tr("ajouter un fournisseur"),
                               QObjet::tr("fournisseur ajouté .\n")
                               "Click Cancel to exit ."),QMessageBox::Cancel);
    }
}




void MainWindow::on_afficher_clicked()
{
    MainWindow::MainWindow(QWidget *emp):

 QMainWindow(emp ),ui(new Ui::MainWindow)
    {ui->setupUi(this);
        ui->tabfournisseur->setModel(temfournisseur.afficher());
    }


}


void MainWindow::on_supprimer_clicked()

{
    int numero = ui->numero->text().toInt();
    bool test = temfournisseur.supprimer(numero);
    if (test)
    {QMessageBox::information(nullptr,QObject::tr("supprimer un fournisseur "),
                              QObject::tr("fournisseur supprimer .\n"
                              "Click Cancel to exit ."),QMessageBox::Cancel);
 }
    else
        QMessageBox::critical(nullptr,QObject::tr("supprimer un fournisseur"),
                              QObject::tr("Erreur . \n"
                                          "Click Cancel to exit"),QMessageBox::Cancel);

}



































void MainWindow::on_ajouterE_clicked()
{
    QString objet = ui->objet->text();
    QString ref = ui->ref->text();
    int quantite = ui->quantite->text().toInt();
   equipement E (objet, ref,quantite);
    bool test = E.ajouterE();
    if (test)
    {
        ui->tabequipement->setModel(temequipement.afficherE());


      QMessageBox::information(nullptr,QObject::tr("ajouter un objet"),
                               QObject::tr("objet ajouté .\n"
                               "Click Cancel to exit ."),QMessageBox::Cancel);

}



void MainWindow::on_afficherE_clicked()
{
    MainWindow::MainWindow(QWidget *emp):

 QMainWindow(emp ),ui(new Ui::MainWindow)
    {ui->setupUi(this);
        ui->tabequipement->setModel(temequipement.afficherE());
    }


}

void MainWindow::on_supprimerE_clicked()
{
    int ref = ui->numero->text().toInt();
    bool test = tmpequipement.supprimer(ref);
    if (test)
    {        ui->tabequipement->setModel(temequipement.afficherE());

        QMessageBox::information(nullptr,QObject::tr("supprimer un objet ");
 }
    else
        QMessageBox::critical(nullptr,QObject::tr("supprimer un objet"),
                              QObject::tr("Erreur . \n"
                                          "Click Cancel to exit"),QMessageBox::Cancel);
}
}
