#include "gdp.h"

GDP::GDP()
{
    ID_PRODUIT=0; NOM_PRODUIT=""; DATE_PRODUCTION={0000,00,00}; DATE_EXPIRATION={0000,00,00}; PRIX=0.0; QUANTITE=0;
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

   QSqlQueryModel *GDP:: trie_produitQ()
    {
        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT* FROM GESTION_PRODUIT ORDER BY QUANTITE" );
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PRODUIT"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PRODUIT"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_PRODUCTION"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_EXPIRATION"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("QUANTITE"));
        return model;
    }

   QSqlQueryModel *GDP:: trie_produitP()
    {
        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT* FROM GESTION_PRODUIT ORDER BY PRIX" );
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PRODUIT"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PRODUIT"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_PRODUCTION"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_EXPIRATION"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("QUANTITE"));
        return model;
    }

   QSqlQueryModel *GDP:: trie_produitN()
    {
        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT* FROM GESTION_PRODUIT ORDER BY NOM_PRODUIT" );
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PRODUIT"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PRODUIT"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_PRODUCTION"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_EXPIRATION"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("QUANTITE"));
        return model;
    }

   QSqlQueryModel *  GDP::chercherN(QString NOM_PRODUIT)
     {
         QSqlQuery qry;
         qry.prepare("SELECT* FROM GESTION_PRODUIT WHERE NOM_PRODUIT=:NOM_PRODUIT");
         qry.bindValue(":NOM_PRODUIT",NOM_PRODUIT);
         qry.exec();

         QSqlQueryModel *model= new QSqlQueryModel;
         model->setQuery(qry);
         return model;
     }

    QSqlQueryModel *  GDP::chercherP(qreal PRIX)
     {
         QSqlQuery qry;
         qry.prepare("SELECT* FROM GESTION_PRODUIT WHERE PRIX=:PRIX");
         qry.bindValue(":PRIX",PRIX);
         qry.exec();

         QSqlQueryModel *model= new QSqlQueryModel;
         model->setQuery(qry);
         return model;
     }

    QSqlQueryModel * GDP::chercherQ(int QUANTITE)
     {
         QSqlQuery qry;
         qry.prepare("SELECT* FROM GESTION_PRODUIT WHERE QUANTITE=:QUANTITE");
         qry.bindValue(":QUANTITE",QUANTITE);
         qry.exec();

         QSqlQueryModel *model= new QSqlQueryModel;
         model->setQuery(qry);
         return model;
    }

   QSqlQueryModel * GDP::chercherNP(QString NOM_PRODUIT, qreal PRIX)
    {
        QSqlQuery *qry= new QSqlQuery();
        qry->prepare("SELECT* FROM GESTION_PRODUIT WHERE PRIX=:PRIX AND NOM_PRODUIT=:NOM_PRODUIT");
        qry->bindValue(":PRIX",PRIX);
        qry->bindValue(":NOM_PRODUIT",NOM_PRODUIT);
        qry->exec();

        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(*qry);
        return model;
    }

   QSqlQueryModel *GDP::chercherNQ(QString NOM_PRODUIT, int QUANTITE)
    {
        QSqlQuery *qry= new QSqlQuery();
        qry->prepare("SELECT* FROM GESTION_PRODUIT WHERE NOM_PRODUIT=:NOM_PRODUIT AND QUANTITE=:QUANTITE");
        qry->bindValue(":QUANTITE",QUANTITE);
        qry->bindValue(":NOM_PRODUIT",NOM_PRODUIT);
        qry->exec();

        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(*qry);
        return model;
    }

   QSqlQueryModel *GDP::chercherQP(int QUANTITE, qreal PRIX)
    {
         QSqlQuery *qry= new QSqlQuery();
         qry->prepare("SELECT* FROM GESTION_PRODUIT WHERE PRIX=:PRIX AND QUANTITE=:QUANTITE");
         qry->bindValue(":QUANTITE",QUANTITE);
         qry->bindValue(":PRIX",PRIX);
         qry->exec();

         QSqlQueryModel *model = new QSqlQueryModel();
         model->setQuery(*qry);
         return model;
     }

   QSqlQueryModel *GDP:: chercherT(QString NOM_PRODUIT, qreal PRIX, int QUANTITE)
    {
         QSqlQuery *qry= new QSqlQuery();
             qry->prepare("SELECT* FROM GESTION_PRODUIT WHERE NOM_PRODUIT=:NOM_PRODUIT AND PRIX=:PRIX AND QUANTITE=:QUANTITE");
             qry->bindValue(":NOM_PRODUIT",NOM_PRODUIT);
             qry->bindValue(":PRIX",PRIX);
             qry->bindValue(":QUANTITE",QUANTITE);
             qry->exec();

             QSqlQueryModel *model = new QSqlQueryModel();
             model->setQuery(*qry);
             return model;
     }

