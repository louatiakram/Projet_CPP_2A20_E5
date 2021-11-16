#ifndef EVENEMENTS_H
#define EVENEMENTS_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class evenements
{
private:
    int reference;
    QString nom;
    QString sujet;
    int date_e;
    QString emplacement;
    int duree;
public:
      evenements();
      evenements(int,QString,QString,int,QString,int);
      int getRef();
      QString getNom();
      QString getSujet();
      int getDate();
      QString getEmplacement();
      int getDuree();
      void setRef(int);
      void setnom(QString);
      void setSujet(QString);
      void setDate(int);
      void setEmplacement(QString);
      void setDuree(int);
      bool ajouter();
      bool supprimer(int);
      QSqlQueryModel* afficher();
      bool modifier();
};


#endif // EVENEMENTS_H
