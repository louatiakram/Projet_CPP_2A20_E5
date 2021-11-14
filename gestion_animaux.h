#ifndef GESTION_ANIMAUX_H
#define GESTION_ANIMAUX_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>

using namespace std;
class Animaux
{
private:

   int id_animal;
   QString nom;
   QString race;
   int age;
   QString date_entree;
   QString emplacement;
public:
   Animaux();
   Animaux(int,QString,QString,int,QString,QString);

   int getid();
   QString getnom();
   QString getrace();
   int getage();
   QString getdate();
   QString getemplacement();

   void setid(int);
   void setnom(QString);
   void setrace(QString);
   void setage(int);
   void setdate(QString);
   void setemplacement(QString);

   bool ajouter();
   bool modifier();
   bool supprimer(int);
   QSqlQueryModel* afficher();
   QSqlQueryModel* afficher_id();
    QSqlQueryModel* tri_id();
    QSqlQueryModel* tri_age();
    QSqlQueryModel* tri_nom();
    void clearTable(QTableView * table);
       void rechercher(QTableView *table, int x);



};

#endif // GESTION_ANIMAUX_H
