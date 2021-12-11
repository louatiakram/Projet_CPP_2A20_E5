#include "evenements.h"
#include "connexion.h"
#include<QSqlQuery>
#include<QDebug>
#include<QObject>
#include<QFile>
#include<QTextStream>
#include<QIODevice>
evenements::evenements()
{
   //reference=0; nom=" "; sujet=" "; date_e="" ; emplacement=" "; duree=0;
}
    evenements::evenements(int reference,QString nom,QString sujet,QDate date_e,QString emplacement,int duree)
    {this->reference=reference; this->nom=nom; this->sujet=sujet; this->date_e=date_e; this->emplacement=emplacement;this->duree=duree;}
    int evenements::getRef(){return reference;}
    QString evenements::getNom(){return nom;}
    QString evenements::getSujet(){return sujet;}
    QDate evenements::getDate(){return date_e;}
    QString evenements::getEmplacement(){return emplacement;}
    int evenements::getDuree(){return duree;}
    void evenements::setRef(int reference){this->reference=reference;}
    void evenements::setnom(QString nom){this->nom=nom;}
    void evenements::setSujet(QString sujet){this->sujet=sujet;}
    void evenements::setDate(QDate date_e){this->date_e=date_e;}
    void evenements::setEmplacement(QString emplacement){this->emplacement=emplacement;}
    void evenements::setDuree(int duree){this->duree=duree;}

    bool evenements::ajouter()
    {
        QSqlQuery query;
        QString Ref_string=QString::number(reference);
        query.prepare("INSERT INTO EVENEMENTS (reference, nom, sujet, date_e, emplacement,duree) VALUES (:reference, :nom, :sujet, :date_e, :emplacement, :duree)");
        query.bindValue(":reference",Ref_string);
        query.bindValue(":nom", nom);
        query.bindValue(":sujet", sujet);
        query.bindValue(":date_e", date_e);
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
    bool evenements::modifier(int reference)

    {
             connexion c;
             c.createconnect();
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
      QSqlQueryModel *evenements::tri_Ref()
    {
        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("select *from evenements order by reference" );
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("sujet"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_e"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("emplacement"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("duree"));

        return model;
      }
      QSqlQueryModel *evenements::tri_nom()
      {
          QSqlQueryModel *model=new QSqlQueryModel();

          model->setQuery("select * from evenements order by nom" );
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("sujet"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_e"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("emplacement"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("duree"));
          return model;
      }
      QSqlQueryModel *evenements::tri_duree()
      {
          QSqlQueryModel *model=new QSqlQueryModel();

          model->setQuery("select * from evenements order by duree" );
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("sujet"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_e"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("emplacement"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("duree"));
          return model;
      }
      QSqlQueryModel *evenements::rechercher(QString rech)
      {
          QSqlQueryModel *model= new QSqlQueryModel();
          model->setQuery("SELECT * FROM evenements WHERE reference  LIKE'%"+rech+"%' or nom  LIKE'%"+rech+"%' or sujet  LIKE'%"+rech+"%' or date_e  LIKE'%"+rech+"%' or emplacement  LIKE'%"+rech+"%' or duree  LIKE'%"+rech+"%'");
          return model;
      }

      void evenements::Write_on_file()
      {
          QString datee = date_e.toString() ;

          QFile file("C:/Users/MSI/Desktop/gestionE/Atelier_Connexion/Agenda.txt");
                if(file.open(QIODevice::WriteOnly | QIODevice::Text))
                {
                    QSqlQuery query;
                    query.prepare("SELECT * from evenements ");
                    query.exec() ;


                        QTextStream stream(&file);
                        stream << "date d'evenement: " << datee <<"\n"  ;
                        stream << "duree : " <<nom<<"\n"   ;
                       // stream << "***********************************************" << " \n " ;


                }
       }

