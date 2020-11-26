#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class equipement
{
public:
    equipement();
    equipement(QString,QString,int);
    QString get_object();
    QString get_ref();
    int get_quantite();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);

    explicit MainWindow(QWidget *empl=nullptr);
    ~MainWindow();
private slots:
   void  on_ajouterE_clicked();
   void  on_supprimerE_clicked();

private :
   Ui::MainWindow *ui;
   equipement tmpequipement;


private :
    QString objet,ref;
    int quantite;
};

#endif // EQUIPEMENT_H
