#include "personnel.h"
#include<QtDebug>
#include<QObject>
#include <QMainWindow>
Personnel::Personnel()
{

    cin=0; nom=" "; prenom=" "; age=0; salaire=0;
}


Personnel::Personnel(int cin,QString nom,QString prenom ,int age ,double salaire)
{
    this->cin=cin; this->nom=nom; this->age=age; this->prenom=prenom; this->salaire=salaire;
}


int Personnel::getcin()
{
    return cin;
}
QString Personnel::getnom()
{
    return nom;
}
QString Personnel::getprenom()
{
    return prenom;
}
double Personnel::getsalaire()
{
    return salaire;
}

int Personnel::getage()
{
    return age;
}

void Personnel::setcin(int cin)
{
    this->cin=cin;

}
void Personnel::setnom(QString nom)
{
    this->nom=nom;

}
void Personnel::setprenom(QString prenom)
{
    this->prenom=prenom;

}
void Personnel::setage(int age)
{
    this->age=age;

}
void Personnel::setsalaire(float salaire)
{
    this->salaire=salaire;
}

bool Personnel::ajouter()
{


    QSqlQuery query;
    QString id_string=QString::number(cin);
    QString age_string=QString::number(age);
    QString salaire_string=QString::number(salaire);
         query.prepare("INSERT INTO Atelier_Connexion (cin,nom,prenom,age,salaire) VALUES (:cin, :nom, :prenom, :age, :salaire )");
         query.bindValue(":cin", cin);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":age", age);
         query.bindValue(":salaire", salaire);

         return query.exec();


}


bool Personnel::supprimer(int cin)
{
    QSqlQuery query;

         query.prepare("Delete from Atelier_Connexion where cin=cin");
         query.bindValue(0, cin);

return query.exec();
}


QSqlQueryModel* Personnel::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM Atelier_Connexion");
          model->setHeaderData(0, Qt::Horizontal,QObject::tr("cin"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));

          return  model;
}

