#ifndef GDP_H
#define GDP_H
#include <QPixmap>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDialog>
#include <QDate>

class GDP
{
private:
   int ID_PRODUIT;
   QString NOM_PRODUIT;
   QDate DATE_PRODUCTION;
   QDate DATE_EXPIRATION;
   double PRIX;
   int QUANTITE;

public:
   GDP();
   GDP(int,QString,QDate,QDate,qreal,int);

   int getid();
   QString getnom();
   QDate getdate_p();
   QDate getdate_e();
   qreal getprix();
   int getquantiter();

   void setid(int);
   void setnom(QString);
   void setdate_p(QDate);
   void setdate_e(QDate);
   void setprix(qreal);
   void setquantiter(int);

   bool ajouter();
   bool modifier(int);
   bool supprimer(int);
   QSqlQueryModel* afficher();
};

#endif // GDP_H
