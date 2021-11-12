#include "gdp.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QIntValidator>
#include <QMessageBox>
#include <QDate>
#include <QObject>

GDP::GDP()
{
    ID_PRODUIT=0; NOM_PRODUIT=""; DATE_PRODUCTION={0,0,0}; DATE_EXPIRATION={0,0,0}; PRIX=0.0; QUANTITE=0;
}
GDP::GDP(int ID_PRODUIT, QString NOM_PRODUIT, QDate DATE_PRODUCTION, QDate DATE_EXPIRATION, qreal PRIX, int QUANTITE)
{

    this->ID_PRODUIT=ID_PRODUIT;
    this->NOM_PRODUIT=NOM_PRODUIT;
    this->DATE_PRODUCTION=DATE_PRODUCTION;
    this->DATE_EXPIRATION=DATE_EXPIRATION;
    this->PRIX=PRIX;
    this->QUANTITE=QUANTITE;
}
    int GDP::getid()
    {
        return ID_PRODUIT;
    }
    QString GDP::getnom()
    {
        return NOM_PRODUIT;
    }
    QDate GDP::getdate_p()
    {
        return DATE_PRODUCTION;
    }
    QDate GDP::getdate_e()
    {
        return DATE_EXPIRATION;
    }
    qreal GDP::getprix()
    {
        return PRIX;
    }
    int GDP::getquantiter()
    {
        return QUANTITE;
    }

    void GDP::setid(int ID_PRODUIT)
    {
        this->ID_PRODUIT=ID_PRODUIT;
    }
    void GDP::setnom(QString NOM_PRODUIT)
    {
        this->NOM_PRODUIT=NOM_PRODUIT;
    }
    void GDP::setdate_p(QDate DATE_PRODUCTION)
    {
        this->DATE_PRODUCTION=DATE_PRODUCTION;
    }
    void GDP::setdate_e(QDate DATE_EXPIRATION)
    {
        this->DATE_EXPIRATION=DATE_EXPIRATION;
    }
    void GDP::setprix(qreal PRIX)
    {
        this->PRIX=PRIX;
    }
    void GDP::setquantiter(int QUANTITE)
    {
        this->QUANTITE=QUANTITE;
    }

    bool GDP::ajouter()
    {
        QSqlQuery query;
        QString ID_PRODUIT_string=QString::number(ID_PRODUIT);
        QString QUANTITE_string=QString::number(QUANTITE);


             query.prepare("INSERT INTO GESTION_PRODUIT(ID_PRODUIT,NOM_PRODUIT,DATE_PRODUCTION,DATE_EXPIRATION,PRIX,QUANTITE)" "VALUES (:ID_PRODUIT, :NOM_PRODUIT, :DATE_PRODUCTION, :DATE_EXPIRATION, :PRIX, :QUANTITE)");
             query.bindValue(":ID_PRODUIT", ID_PRODUIT);
             query.bindValue(":NOM_PRODUIT", NOM_PRODUIT);
             query.bindValue(":DATE_PRODUCTION", DATE_PRODUCTION);
             query.bindValue(":DATE_EXPIRATION", DATE_EXPIRATION);
             query.bindValue(":PRIX", PRIX);
             query.bindValue(":QUANTITE", QUANTITE);

             return query.exec();
    }

    bool GDP::modifier(int ID)
    {
    QSqlQuery query,rech;
    QString res = QString::number(ID);
    query.prepare("UPDATE GESTION_PRODUIT SET NOM_PRODUIT = :NOM_PRODUIT, DATE_PRODUCTION = :DATE_PRODUCTION, DATE_EXPIRATION= :DATE_EXPIRATION, PRIX = :PRIX, QUANTITE = :QUANTITE WHERE ID_PRODUIT = :ID");
    query.bindValue(":ID", res);
    query.bindValue(":NOM_PRODUIT", NOM_PRODUIT);
    query.bindValue(":DATE_PRODUCTION", DATE_PRODUCTION);
    query.bindValue(":DATE_EXPIRATION", DATE_EXPIRATION);
    query.bindValue(":PRIX", PRIX);
    query.bindValue(":QUANTITE", QUANTITE);

             return query.exec();
    }

   bool GDP::supprimer(int ID)
   {
   QSqlQuery query;

            query.prepare("DELETE FROM GESTION_PRODUIT WHERE ID_PRODUIT=:ID");
            query.bindValue(0, ID);

   return query.exec();
   }

   QSqlQueryModel* GDP::afficher()
    {
         QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery("SELECT* FROM GESTION_PRODUIT");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PRODUIT"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PRODUIT"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_PRODUCTION"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_EXPIRATION"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("QUANTITE"));

      return  model;
    }
