#include "municipalite.h"

municipalite::municipalite()
{

}

municipalite::municipalite(QString n, QString l, int nbe ,QString p, int c)
{
nom=n;
local=l;
nb=nbe;
prenom=p;
code=c;

}

bool municipalite::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO MUNICIPALITE ( NOM,PRENOM,CODEBUR,NB_EMP,LOCALISATION) "
                        "VALUES (:n, :p,:c,:nb,:l)");
    query.bindValue(":n",nom); //remplir la valeur d'une maniere securisée
    query.bindValue(":p", prenom);
    query.bindValue(":l", local);
    query.bindValue(":c", code);
    query.bindValue(":nb", nb);

    return    query.exec();

}

bool municipalite::modifier(QString selected){

    QSqlQuery query;


    query.prepare(" UPDATE MUNICIPALITE SET PRENOM= :p ,LOCALISATION= :l,NB_EMP= :nb ,CODEBUR= :c where NOM= :n");
    query.bindValue(":n",selected); //remplir la valeur d'une maniere securisée
    query.bindValue(":p", prenom);
    query.bindValue(":l", local);
    query.bindValue(":c", code);
    query.bindValue(":nb", nb);

    return    query.exec();

}

 QSqlQueryModel * municipalite::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM MUNICIPALITE");

     return modal;

 }
  bool municipalite::supprimer(QString selected){

      QSqlQuery query;
      query.prepare("Delete from MUNICIPALITE where NOM = :sel ");
      query.bindValue(":sel", selected);
      return    query.exec();


  }
