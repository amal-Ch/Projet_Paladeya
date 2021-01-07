#ifndef MUNICIPALITE_H
#define MUNICIPALITE_H

#include <QSqlQuery>
#include <QSqlQueryModel>

class municipalite
{
public:
    municipalite();
     municipalite(QString, QString ,  int ,QString , int);

     QString nom,local,prenom;
     int nb,code;

     bool ajouter();
     bool modifier(QString);
      QSqlQueryModel * afficher();
       bool supprimer(QString);



};

#endif // MUNICIPALITE_H
