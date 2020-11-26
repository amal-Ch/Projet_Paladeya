#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class fournisseur
{
public:
    fournisseur();
    fournisseur(QString,QString,int);
    QString get_nom();
    QString get_adress();
    int get_numero();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer ();


    explicit MainWindow(QWidget *empl=nullptr);
    ~MainWindow();
private slots:
   void  on_ajouter_clicked();
   void  on_supprimer_clicked();

private :
   Ui::MainWindow *ui;
 fournisseur tmpfournisseur;


private :
    QString nom,adress;
    int numero;
};


#endif // FOURNISSEUR_H
