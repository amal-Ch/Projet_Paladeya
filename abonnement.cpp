#include "abonnement.h"

abonnement::abonnement()
{

}

abonnement::abonnement(int i, QString n, QString p, QString d,QString f, QString m)
{
id=i;
nom=n;
prenom=p;
debut=d;
fin=f;
mun=m;
}



bool abonnement::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO ABONNEMENT (ID, NOM,PRENOM,DEBUT,FIN,MUNICIPALITE) "
                        "VALUES (:i, :n, :p,:d,:f,:m)");
    query.bindValue(":i", id);
    query.bindValue(":n",nom); //remplir la valeur d'une maniere securisée
    query.bindValue(":p", prenom);
    query.bindValue(":d", debut);
    query.bindValue(":f", fin);
    query.bindValue(":m", mun);

    return    query.exec();

}

bool abonnement::modifier(int selected){

    QSqlQuery query;


    query.prepare(" UPDATE ABONNEMENT SET NOM= :n ,PRENOM= :p ,DEBUT= :d,FIN= :f ,MUNICIPALITE= :m where ID= :integer");
    query.bindValue(":integer", selected);
    query.bindValue(":n",nom);
    query.bindValue(":p", prenom);
    query.bindValue(":d", debut);
    query.bindValue(":f", fin);
    query.bindValue(":m", mun);

    return    query.exec();

}

 QSqlQueryModel * abonnement::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM ABONNEMENT");

     return modal;

 }
  bool abonnement::supprimer(int selected){

      QSqlQuery query;
      query.prepare("Delete from ABONNEMENT where ID = :sel ");
      query.bindValue(":sel", selected);
      return    query.exec();


  }
