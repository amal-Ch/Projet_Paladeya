#include "fournisseur.h"

fournisseur::fournisseur()
{
numero=0;
nom="";
adress="";
}
fournisseur::fournisseur(QString nom,QString adress, int numero)
{
    this->nom=nom;
    this->adress=adress;
    this->numero=numero;
}
QString fournisseur::get_nom(){return nom;}
QString fournisseur::get_adress(){return adress;}
int fournisseur::get_numero(){return numero;}


bool fournisseur::ajouter()
{
QSqlQuery query;
QString res=QString::number(numero);
query.prepare("INSERT INTO fournisseur (nom, adress, numero)""VALUES (:nom ,:adress, :numero)");
query.bindValue(":nom",nom);
query.bindValue(":adress",adress);
query.bindValue(":numero",numero);
return query.exec();
}



QSqlQueryModel * fournisseur::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from fournisseur");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("adress"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("numero"));
 return model ;

}



bool fournisseur :: supprimer(int numero)
{
    QSqlQuery query ;
    QString res= QString ::number(numero);
    query.prepare("delete from fournisseur where numero = :numero");
    query.bindValue(":numero",res);
    return query.exec();
}




