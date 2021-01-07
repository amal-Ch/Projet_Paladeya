#ifndef ABONNEMENT_H
#define ABONNEMENT_H

#include <QSqlQuery>
#include <QSqlQueryModel>

class abonnement
{
public:
    abonnement();
    abonnement(int,QString,QString,QString,QString,QString);

    bool ajouter();
    bool modifier(int);
     QSqlQueryModel * afficher();
      bool supprimer(int);


      int id;
      QString nom, prenom, debut, fin,mun;
};

#endif // ABONNEMENT_H
