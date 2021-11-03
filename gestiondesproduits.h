#ifndef GESTIONDESPRODUITS_H
#define GESTIONDESPRODUITS_H
#include <QPixmap>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDialog>

namespace Ui {
class GestionDesProduits;
}

class GestionDesProduits : public QDialog
{
    Q_OBJECT

public:
    explicit GestionDesProduits(QWidget *parent = nullptr);
    ~GestionDesProduits();

private slots:

    void on_Quitter_clicked();

    void on_Ajouter_clicked();

    void on_Supprimer_clicked();

private:
    Ui::GestionDesProduits *ui;
};
class GDP
       {
private:
   int id_produit;
   QString nom;
   QString date_p;
   QString date_e;
   int quantiter;
   float prix;

public:
   GDP();
   GDP(int,QString,QString,QString,int,float);

   int getid();
   QString getnom();
   QString getdate_p();
   QString getdate_e();
   int getquantiter();
   float getprix();

   void setid(int);
   void setnom(QString);
   void setdate_p(QString);
   void setdate_e(QString);
   void setquantiter(int);
   void setprix(float);

   bool ajouter();
   bool modifier();
   bool supprimer(int);
   QSqlQueryModel* afficher();

};

#endif // GESTIONDESPRODUITS_H
