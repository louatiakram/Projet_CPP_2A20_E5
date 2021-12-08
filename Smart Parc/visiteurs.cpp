#include "visiteurs.h"
#include "connexion.h"
#include<QSqlQuery>
#include<QDebug>
#include<QObject>
#include <QSystemTrayIcon>
visiteurs::visiteurs()
{
    numero_visiteur=0; nom=" "; prenom=" "; age=0; num_tel=0; adresse_mail=" ";
}
visiteurs::visiteurs(int numero_visiteur,QString nom,QString prenom,int age,int num_tel,QString adresse_mail)

{this->numero_visiteur=numero_visiteur; this->nom=nom; this->prenom=prenom; this->age=age; this->num_tel=num_tel; this->adresse_mail=adresse_mail;}
int visiteurs::getnum(){return numero_visiteur;}
QString visiteurs::getnom(){return nom;}
QString visiteurs::getprenom(){return prenom;}
int visiteurs::getage(){return age;}
int visiteurs::getnum_tel(){return num_tel;}
QString visiteurs::getadresse(){return adresse_mail;}
void visiteurs::setnum(int numero_visiteur){this->numero_visiteur=numero_visiteur;}
void visiteurs::setnom(QString nom){this->nom=nom;}
void visiteurs::setprenom(QString prenom){this->prenom=prenom;}
void visiteurs::setage(int age){this->age=age;}
void visiteurs::setnum_tel(int num_tel){this->num_tel=num_tel;}
void visiteurs::setadresse(QString adresse_mail){this->adresse_mail=adresse_mail;}

bool visiteurs::ajouter()
{

    QSqlQuery query;
    QString numero_string=QString::number(numero_visiteur);
    QString age_string=QString::number(age);
    QString num_tel_string=QString::number(num_tel);
    query.prepare("INSERT INTO VISITEURS (numero_visiteur, nom, prenom , age, num_tel, adresse_mail) VALUES (:numero_visiteur, :nom, :prenom, :age, :num_tel, :adresse_mail)");
    query.bindValue(":numero_visiteur", numero_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":age", age_string);
    query.bindValue(":num_tel", num_tel_string);
    query.bindValue(":adresse_mail", adresse_mail);
    return query.exec();

}

bool visiteurs::supprimer(int numero_visiteur)
{

    QSqlQuery query;
    query.prepare("DELETE from VISITEURS where numero_visiteur=:numero_visiteur");
    query.bindValue(":numero_visiteur",numero_visiteur);
    return query.exec();

}

QSqlQueryModel* visiteurs::afficher()

{

    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM VISITEURS");

          model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero_visiteur"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_tel"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse_mail"));
    return model;

}

bool visiteurs::modifier()

{
         QSqlQuery query;
         query.prepare("UPDATE VISITEURS set numero_visiteur=:numero_visiteur,nom=:nom,prenom=:prenom,age=:age,num_tel=:num_tel,adresse_mail=:adresse_mail where numero_visiteur=:numero_visiteur");
         query.bindValue(":numero_visiteur", numero_visiteur);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":age", age);
         query.bindValue(":num_tel", num_tel);
         query.bindValue(":adresse_mail", adresse_mail);
         return query.exec();
}

QSqlQueryModel *visiteurs ::tri_num()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT *from visiteurs order by numero_visiteur" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero_visiteur"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse_mail"));
    return model;
}

QSqlQueryModel * visiteurs ::tri_nom()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT *from visiteurs order by nom" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero_visiteur"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse_mail"));
    return model;
}

QSqlQueryModel * visiteurs ::tri_prenom()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT *from visiteurs order by prenom" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero_visiteur"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse_mail"));
    return model;
}

QSqlQueryModel * visiteurs::rechercher(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM visiteurs WHERE numero_visiteur  LIKE'%"+rech+"%' or nom  LIKE'%"+rech+"%' or prenom  LIKE'%"+rech+"%' or age  LIKE'%"+rech+"%' ");
    return model;
}

void visiteurs::notification(QString cls)
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("operation effectué",cls,QSystemTrayIcon::Information,15000);
  //  QSound newMessage(":/mixkit-positive-interface-beep-221.wav");
   // newMessage.play();
}

