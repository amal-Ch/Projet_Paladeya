#include "connexion.h"

connexion::connexion()
{}
bool connexion::ouvrirConnexion()
{
  db=QsqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Gestion_Municipalite");
db.steUserName("mezen bayounes");
db.setPassword("mezen2000");

if (db.open()) return true; return false ;
}

void connexion::fermerConnexion()
{db.close();}
