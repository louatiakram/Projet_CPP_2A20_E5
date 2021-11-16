#include "evenements.h"
#include "connection.h"
#include<QSqlQuery>
#include<QDebug>
#include<QObject>

evenements::evenements()
{
   reference=0; nom=" "; sujet=" "; date_e=0 ; emplacement=" "; duree=0;
}
    evenements::evenements(int reference,QString nom,QString sujet,int date_e,QString emplacement,int duree)
    {this->reference=reference; this->nom=nom; this->sujet=sujet; this->date_e=date_e; this->emplacement=emplacement;this->duree=duree;}
    int evenements::getRef(){return reference;}
    QString evenements::getNom(){return nom;}
    QString evenements::getSujet(){return sujet;}
    int evenements::getDate(){return date_e;}
    QString evenements::getEmplacement(){return emplacement;}
    int evenements::getDuree(){return duree;}
    void evenements::setRef(int reference){this->reference=reference;}
    void evenements::setnom(QString nom){this->nom=nom;}
    void evenements::setSujet(QString sujet){this->sujet=sujet;}
    void evenements::setDate(int date_e){this->date_e=date_e;}
    void evenements::setEmplacement(QString emplacement){this->emplacement=emplacement;}
    void evenements::setDuree(int duree){this->duree=duree;}

    bool evenements::ajouter()
    {
        QSqlQuery query;
        QString Ref_string=QString::number(reference);
        QString date_string=QString::number(date_e);
        query.prepare("INSERT INTO EVENEMENTS (reference, nom, sujet, date_e, emplacement,duree) VALUES (:reference, :nom, :sujet, :date_e, :emplacement, :duree)");
        query.bindValue(":reference",Ref_string);
        query.bindValue(":nom", nom);
        query.bindValue(":sujet", sujet);
        query.bindValue(":date_e", date_string);
        query.bindValue(":emplacement", emplacement);
        query.bindValue(":duree",duree);
        return query.exec();
    }
    bool evenements::supprimer(int reference)
    {
        QSqlQuery query;
        query.prepare("DELETE from EVENEMENTS where reference=:reference");
        query.bindValue(":reference",reference);
        return query.exec();
    }
    QSqlQueryModel* evenements::afficher()
    {
        QSqlQueryModel* model=new QSqlQueryModel();

              model->setQuery("SELECT* FROM evenements");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("sujet"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_e"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("emplacement"));
              model->setHeaderData(5, Qt::Horizontal, QObject::tr("duree"));
                 return model;
             }
    bool evenements::modifier()

    {
             QSqlQuery query;
             query.prepare("UPDATE EVENEMENTS set reference=:reference,nom=:nom,sujet=:sujet,date_e=:date_e,emplacement=:emplacement,duree=:duree where reference=:reference");
             query.bindValue(":reference", reference);
             query.bindValue(":nom", nom);
             query.bindValue(":sujet", sujet);
             query.bindValue(":date_e", date_e);
             query.bindValue(":emplacement", emplacement);
             query.bindValue(":duree", duree);
             return query.exec();

    }
