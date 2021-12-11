#ifndef EVENEMENTS_H
#define EVENEMENTS_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>


class evenements
{
private:
    int reference;
    QString nom;
    QString sujet;
    QDate date_e;
    QString emplacement;
    int duree;
public:
      evenements();
      evenements(int,QString,QString,QDate,QString,int);
      int getRef();
      QString getNom();
      QString getSujet();
      QDate getDate();
      QString getEmplacement();
      int getDuree();
      void setRef(int);
      void setnom(QString);
      void setSujet(QString);
      void setDate(QDate);
      void setEmplacement(QString);
      void setDuree(int);
      bool ajouter();
      bool supprimer(int);
      QSqlQueryModel* afficher();
      bool modifier(int);
      QSqlQueryModel *tri_Ref();
      QSqlQueryModel *tri_nom();
      QSqlQueryModel *tri_duree();
      QSqlQueryModel *rechercher(QString);
      void Write_on_file();
};


#endif // EVENEMENTS_H
