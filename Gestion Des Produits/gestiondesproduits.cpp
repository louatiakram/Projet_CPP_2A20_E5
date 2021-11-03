#include "gestiondesproduits.h"
#include "ui_gestiondesproduits.h"
#include <QIntValidator>
#include <QMessageBox>


GestionDesProduits::GestionDesProduits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionDesProduits)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Desktop/Projects/C++Qt/Projects/Gestion Des Produits/FF.jpg");
    ui->IMG->setPixmap(pix.scaled(1200,700,Qt::KeepAspectRatio));
}

GestionDesProduits::~GestionDesProduits()
{
    delete ui;
}

void GestionDesProduits::on_Quitter_clicked()
{
    close();
}

GDP::GDP()
{
id_produit=0; nom=""; date_p="";date_e="";quantiter=0;prix=0;
}
GDP::GDP(int id_prouit, QString nom, QString date_p, QString date_e, int quantiter, float prix)
{

    this->id_produit=id_prouit;
    this->nom=nom;
    this->date_p=date_p;
    this->date_e=date_e;
    this->quantiter=quantiter;
    this->prix=prix;
}
    int GDP::getid()
    {
        return id_produit;
    }
    QString GDP::getnom()
    {
        return nom;
    }
    QString GDP::getdate_p()
    {
        return date_p;
    }
    QString GDP::getdate_e()
    {
        return date_e;
    }
    int GDP::getquantiter()
    {
        return quantiter;
    }
    float GDP::getprix()
    {
        return prix;
    }


    void GDP::setid(int id_produit)
    {
        this->id_produit=id_produit;
    }
    void GDP::setnom(QString nom)
    {
        this->nom=nom;
    }
    void GDP::setdate_p(QString date_p)
    {
        this->date_p=date_p;
    }
    void GDP::setdate_e(QString date_e)
    {
        this->date_e=date_e;
    }
    void GDP::setquantiter(int quantiter)
    {
        this->quantiter=quantiter;
    }
    void GDP::setprix(float prix)
    {
        this->prix=prix;
    }

    bool GDP::ajouter()
    {
        QSqlQuery query;
        QString id_string=QString::number(id_produit);
        QString age_string=QString::number(quantiter);

             query.prepare("INSERT INTO GESTION DES PRODUITS (id_produit,nom,date_p,date_e,quantiter,prix) VALUES (:id, :nom, :date_p, :date_e, :qte, :prix)");
             query.bindValue(":id", id_produit);
             query.bindValue(":nom", nom);
             query.bindValue(":date_p", date_p);
             query.bindValue(":date_e", date_e);
             query.bindValue(":qte", quantiter);
             query.bindValue(":prix", prix);

             return query.exec();


    }
   bool GDP::supprimer(int id)
   {
       QSqlQuery query;

            query.prepare("Delete from GESTION DES PRODUITS where id_produit=:id");
            query.bindValue(0, id);

   return query.exec();
   }

    QSqlQueryModel* GDP::afficher()
    {
        QSqlQueryModel* model=new QSqlQueryModel();

              model->setQuery("SELECT* FROM GESTION DES PRODUITS");
              model->setHeaderData(0, Qt::Horizontal,QObject::tr("id_produit"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_p"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_e"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantiter"));
              model->setHeaderData(5, Qt::Horizontal, QObject::tr("prix"));

              return  model;
    }

void GestionDesProduits::on_Ajouter_clicked()
{
        int id_produit=ui->lineEdit_01->text().toInt();
        QString nom=ui->lineEdit_02->text();
        QString date_p=ui->lineEdit_03->text();
        QString date_e=ui->lineEdit_04->text();
        int quantiter=ui->lineEdit_05->text().toInt();
        float prix=ui->lineEdit_06->text().toFloat();
        GDP P(id_produit,nom,date_p,date_e,quantiter,prix);

        bool test=P.ajouter();

         if(test)
         {
             QMessageBox::information(nullptr, QObject::tr("OK"),
             QObject::tr("Ajout effectué.\nClick OK to exit."), QMessageBox::Ok);
        //ui->TAB_P->setModel(P.afficher());
         }
         else
         {
             QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                  QObject::tr("Ajout non effectué.\nClick OK to exit."), QMessageBox::Ok);


         }
}


void GestionDesProduits::on_Supprimer_clicked()
{
    GDP P;
       P.setid(ui->label_01->text().toInt());
       bool test=P.supprimer(P.getid());
       if(test)
       {
           //ui->TAB_P->setModel(P.afficher());
           QMessageBox::information(nullptr, QObject::tr("Ok"),

                                    QObject::tr("Suppression effectué.\n"
                            "Click OK to exit."), QMessageBox::Ok);

      //ui->TAB_P->setModel(P.afficher());
       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                QObject::tr("Suppression non effectué.\n"
                            "Click OK to exit."), QMessageBox::Ok);


       }
}
