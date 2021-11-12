#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestiondesproduits.h"
#include "ui_gestiondesproduits.h"
#include "gdp.h"

#include <QTabWidget>
#include <QTableWidgetItem>
#include <QTabWidget>
#include <QSqlQuery>
#include <QtDebug>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QMessageBox>
#include <QDate>

GestionDesProduits::GestionDesProduits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionDesProduits)
{
    ui->setupUi(this);
#define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
    QRegExp rxNom(NOM_RX);
    QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);

#define PRIX_RX "^([0-9]+[,.]?[ ]?|[0-9]+['-]?)+$"
    QRegExp rxPrix(PRIX_RX);
    QRegExpValidator*valiPrix= new QRegExpValidator(rxPrix,this);

    QPixmap pix("C:/Users/ASUS/Desktop/Gestion Des Produits/F.jpg");
    ui->IMG->setPixmap(pix.scaled(1200,700,Qt::KeepAspectRatio));

    ui->lineEdit_01->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_02->setValidator(valiNom);
    ui->lineEdit_03->setValidator(valiPrix);
    ui->lineEdit_04->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_05->setValidator(valiNom);
    ui->lineEdit_06->setValidator(valiPrix);
    ui->lineEdit_07->setValidator(new QIntValidator(0,999999,this));

    ui->tableView->setModel(G.afficher());
    ui->comboBox_01->setModel(G.afficher());
    ui->comboBox_02->setModel(G.afficher());

    GDP G;
}

GestionDesProduits::~GestionDesProduits()
{
    delete ui;
}

void GestionDesProduits::on_Quitter_clicked()
{
    close();
}

void GestionDesProduits::on_Ajouter_clicked()
{
        int ID_PRODUIT=ui->lineEdit_01->text().toInt();
        QString NOM_PRODUIT=ui->lineEdit_02->text();
        QDate DATE_PRODUCTION=ui->dateEdit->date();
        QDate DATE_EXPIRATION=ui->dateEdit_2->date();
        qreal PRIX=ui->lineEdit_03->text().toDouble();
        int QUANTITE=ui->lineEdit_04->text().toInt();

        GDP G(ID_PRODUIT,NOM_PRODUIT,DATE_PRODUCTION,DATE_EXPIRATION,PRIX,QUANTITE);


        if(ui->lineEdit_01->text().isEmpty()||ui->lineEdit_02->text().isEmpty()||ui->dateEdit->date().isNull()||ui->dateEdit_2->date().isNull()||ui->lineEdit_03->text().isEmpty()||ui->lineEdit_04->text().isEmpty())
        {
            QMessageBox::information(nullptr, QObject::tr("ERROR"),
            QObject::tr("Please Fill All Data"), QMessageBox::Ok);
        }
        else
        {
         bool test=G.ajouter();
         if(test)
         {
             QMessageBox::information(nullptr, QObject::tr("DONE"),
             QObject::tr("Added Successfully !"), QMessageBox::Ok);
         }
         else
         {
             QMessageBox::critical(nullptr, QObject::tr("ERROR"),
             QObject::tr("Add Failed !"), QMessageBox::Ok);
         }
        }
        ui->tableView->setModel(G.afficher());
        ui->comboBox_01->setModel(G.afficher());
        ui->comboBox_02->setModel(G.afficher());
}

void GestionDesProduits::on_Modifier_clicked()
{
    int ID_PRODUIT=ui->comboBox_01->currentText().toInt();
    QString NOM_PRODUIT=ui->lineEdit_05->text();
    QDate DATE_PRODUCTION=ui->dateEdit_3->date();
    QDate DATE_EXPIRATION=ui->dateEdit_4->date();
    qreal PRIX=ui->lineEdit_06->text().toDouble();
    int QUANTITE=ui->lineEdit_07->text().toInt();

    GDP G(ID_PRODUIT,NOM_PRODUIT,DATE_PRODUCTION,DATE_EXPIRATION,PRIX,QUANTITE);

    if(ui->comboBox_01->currentText().isEmpty()||ui->lineEdit_05->text().isEmpty()||ui->dateEdit_3->text().isEmpty()||ui->dateEdit_4->text().isEmpty()||ui->lineEdit_06->text().isEmpty()||ui->lineEdit_07->text().isEmpty())
    {
        QMessageBox::information(nullptr, QObject::tr("ERROR"),
        QObject::tr("Please Fill All Data"), QMessageBox::Ok);
    }
    else
    {
     bool test=G.modifier(ID_PRODUIT);
     if(test)
     {
         QMessageBox::information(nullptr, QObject::tr("DONE"),
         QObject::tr("Modified Successfully !"), QMessageBox::Ok);
     }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("ERROR"),
         QObject::tr("Modification Failed !"), QMessageBox::Ok);
     }
    }
    ui->tableView->setModel(G.afficher());
    ui->comboBox_01->setModel(G.afficher());
    ui->comboBox_02->setModel(G.afficher());
}

void GestionDesProduits::on_Supprimer_clicked()
{
    GDP G;
       G.setid(ui->comboBox_02->currentText().toInt());

       if(ui->comboBox_02->currentText().isEmpty())
       {
           QMessageBox::information(nullptr, QObject::tr("ERROR"),
           QObject::tr("No 'ID' Selected"), QMessageBox::Ok);
       }
       else
       {
       bool test=G.supprimer(G.getid());
       if(test)
       {
          QMessageBox::information(nullptr, QObject::tr("DONE"),
          QObject::tr("Deleted Successfully !"), QMessageBox::Ok);
       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("ERROR"),
           QObject::tr("Delete Failed !"), QMessageBox::Ok);
       }
       }
       ui->tableView->setModel(G.afficher());
       ui->comboBox_01->setModel(G.afficher());
       ui->comboBox_02->setModel(G.afficher());
}
