#ifndef GDP_H
#define GDP_H
#include <QPixmap>
#include <QString>
#include <QDialog>
#include <QDate>
#include <QtDebug>
#include <QIntValidator>
#include <QMessageBox>
#include <QObject>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTabWidget>
#include <QTableWidgetItem>
#include <QTextDocument>
#include "QtPrintSupport"

class GDP
{
private:
   int ID_PRODUIT;
   QString NOM_PRODUIT;
   QDate DATE_PRODUCTION;
   QDate DATE_EXPIRATION;
   qreal PRIX;
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
   QSqlQueryModel* trie_produitQ();
   QSqlQueryModel* trie_produitP();
   QSqlQueryModel* trie_produitN();
   QSqlQueryModel* chercherN(QString);
   QSqlQueryModel* chercherP(qreal);
   QSqlQueryModel* chercherQ(int);
   QSqlQueryModel* chercherNP(QString, qreal);
   QSqlQueryModel* chercherNQ(QString, int);
   QSqlQueryModel* chercherQP(int, qreal);
   QSqlQueryModel* chercherT( QString, qreal, int);
};

#endif // GDP_H
