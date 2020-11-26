#include "equipement.h"
#include <QSqlDatabase>
#include "connexion.h"

equipement::equipement()
{
quantite=0;
objet="";
ref="";

}
 equipement::equipement(QString obejt, QString ref, int quantite)
 {
     this->objet=objet;
     this->ref=ref;
     this->quantite;

 }
 QString equipement::get_object(){return objet;}
 QString equipement::get_ref(){return ref;}
 int equipement::get_quantite(){return quantite;}

 bool equipement::ajouterE()
 {
     QSqlQuery query;
     query.prepare("INSERT INTO equipement(obejt,ref,quantite)" " VALUES (:objet,:ref, :quntite)");
     query.bindValue(":objet",objet);
     query.bindValue(":ref",ref);
     query.bindValue(":quantite",quantite);
     return query.exec();

 }

 QSqlQueryModel * equipement::afficherE()
 {QSqlQueryModel * model= new QSqlQueryModel();
  model->setQuery("select * from equipement");
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("objet"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("ref"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite"));
  return model ;
 }


 bool equipement::supprimer(int ref)
 {
     QSqlQuery query ;
     QString res= QString ::number(ref);
     query.prepare("delete from equipement where ref = :ref");
     query.bindValue(":ref",res);
     return query.exec();
 }
