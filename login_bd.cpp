#include "login_bd.h"

login_bd::login_bd()
{

}

bool login_bd::createconnect1()
{
    bool test=false;
QSqlDatabase db1 = QSqlDatabase::addDatabase("QODBC");
db1.setDatabaseName("SmartParc");//inserer le nom de la source de données ODBC
db1.setUserName("system");//inserer nom de l'utilisateur
db1.setPassword("86842624");//inserer mot de passe de cet utilisateur



if (db1.open())
test=true;

    return  test;
}
    void login_bd::fermerConnexion1(){db1.close();}

    bool login_bd::ourirConnexion1(){
        if (db1.open())
            return true ;
        else
            return false;
    }


