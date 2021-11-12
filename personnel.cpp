    #include "personnel.h"
#include<QtDebug>
#include<QObject>
#include <QMainWindow>

Personnel::Personnel()
{

    CIN=0;
    NOM=" ";
    PRENOM=" ";
    AGE=0;
    SALAIRE=0;
    NUM_TEL=0;
    }


Personnel::Personnel(int CIN, QString NOM, QString PRENOM ,int AGE ,int SALAIRE, int NUM_TEL,int CIN_DIRIGEUR)
{
    this->CIN=CIN;
    this->NOM=NOM;
    this->PRENOM=PRENOM;
    this->AGE=AGE;
    this->SALAIRE=SALAIRE;
    this->NUM_TEL=NUM_TEL;
}


int Personnel::getcin()
{
    return CIN;
}
QString Personnel::getnom()
{
    return NOM;
}
QString Personnel::getprenom()
{
    return PRENOM;
}
int Personnel::getage()
{
    return AGE;
}
int Personnel::getsalaire()
{
    return SALAIRE;
}
int Personnel::getnumero_tel()
{
    return NUM_TEL;
}



void Personnel::setcin(int CIN)
{
    this->CIN=CIN;

}
void Personnel::setnom(QString NOM)
{
    this->NOM=NOM;

}
void Personnel::setprenom(QString PRENOM)
{
    this->PRENOM=PRENOM;

}
void Personnel::setage(int AGE)
{
    this->AGE=AGE;

}
void Personnel::setsalaire(int SALAIRE)
{
    this->SALAIRE=SALAIRE;
}

void Personnel::setnumero_tel(int NUM_TEL)
{
    this->NUM_TEL=NUM_TEL;

}



bool Personnel::ajouter()
{


    QSqlQuery query;
    QString id_string=QString::number(CIN);
    QString age_string=QString::number(AGE);
    QString salaire_string=QString::number(SALAIRE);
    QString numero_tel_string=QString::number(NUM_TEL);
         query.prepare("INSERT INTO GESTION_PERSONNEL(CIN,NOM,PRENOM,AGE,SALAIRE,NUM_TEL,CIN_DIRIGEUR)" "VALUES (:CIN,:NOM,:PRENOM,:AGE,:SALAIRE,:NUM_TEL,:CIN_DIRIGEUR)");
         query.bindValue(":CIN", CIN);
         query.bindValue(":NOM", NOM);
         query.bindValue(":PRENOM", PRENOM);
         query.bindValue(":AGE", AGE);
         query.bindValue(":SALAIRE", SALAIRE);
         query.bindValue(":NUM_TEL", NUM_TEL);
         query.bindValue(":CIN_DIRIGEUR", CIN_DIRIGEUR);

         return query.exec();


}


bool Personnel::supprimer(int CIN)
{
    QSqlQuery query;

         query.prepare("DELETE FROM GESTION_PERSONNEL where CIN= :CIN");
         query.bindValue(0, CIN);

return query.exec();
}


QSqlQueryModel* Personnel::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM GESTION_PERSONNEL");
          model->setHeaderData(0, Qt::Horizontal,QObject::tr("CIN"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("SALAIRE"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUM_TEL"));

          return  model;
}




bool Personnel::modifierP()
{
    QSqlQuery query;
                query.prepare("UPDATE GESTION_PERSONNEL SET NOM=:NOM, PRENOM=:PRENOM, AGE=:AGE, SALAIRE=:SALAIRE, NUM_TEL=:NUM_TEL WHERE CIN=:CIN ");
                query.bindValue(":NOM", NOM);
                query.bindValue(":PRENOM", PRENOM);
                query.bindValue(":AGE", AGE);
                query.bindValue(":SALAIRE", SALAIRE);
                query.bindValue(":NUM_TEL", NUM_TEL);

                query.bindValue(":CIN", CIN);



                 return query.exec();

}
