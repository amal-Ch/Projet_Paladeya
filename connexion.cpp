#include "connexion.h"
connexion::connexion()
{}

bool connexion::ouvrirconnexion()
{ db=QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("testdb");
db.setUserName("abdou");
db.setPassword("151198");

if(db.open())
    return true;
        return false;

}
void connexion::fermerconnexion()
{db.close();}
