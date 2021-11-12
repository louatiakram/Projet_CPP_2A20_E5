#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"personnel.h"
#include<QIntValidator>
#include<QMessageBox>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_cin->setValidator( new QIntValidator(0, 99999999, this));
    ui->le_age->setValidator( new QIntValidator(0, 99, this));
    ui->le_salaire->setValidator( new QIntValidator(0,999999, this));
    ui->le_numero->setValidator( new QIntValidator(0, 99999999, this));
    ui->tab_personnel->setModel (P.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int CIN=ui->le_cin->text().toInt();
    QString NOM=ui->le_nom->text();
    QString PRENOM=ui->le_prenom->text();
    int AGE=ui->le_age->text().toInt();
    int SALAIRE=ui->le_salaire->text().toInt();
    int NUM_TEL=ui->le_numero->text().toInt();
    int CIN_DIRIGEUR;
    Personnel P(CIN,NOM,PRENOM,AGE,SALAIRE,NUM_TEL,CIN_DIRIGEUR);

    bool test=P.ajouter();

     if(test)
     {
         QMessageBox::information(nullptr, QObject::tr("Ok"),
              QObject::tr("Ajout effectué.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_personnel->setModel(P.afficher());

     }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
              QObject::tr("Ajout non effectué.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);


     }
}



void MainWindow::on_pb_afficher_clicked()
{


}


void MainWindow::on_pb_supprimer_clicked()
{
    Personnel P;
    P.setcin(ui->le_cin->text().toInt());
    bool test=P.supprimer(P.getcin());
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("Suppression effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);


   ui->tab_personnel->setModel(P.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
             QObject::tr("Suppression non effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);


    }
}

void MainWindow::on_pb_modifier_clicked()
{
    int CIN=ui->le_cin->text().toInt();
    QString NOM=ui->le_nom->text();
    QString PRENOM=ui->le_prenom->text();
    int AGE=ui->le_age->text().toInt();
    int SALAIRE=ui->le_salaire->text().toInt();
    int NUM_TEL=ui->le_numero->text().toInt();
    int CIN_DIRIGEUR;
    Personnel P(CIN,NOM,PRENOM,AGE,SALAIRE,NUM_TEL,CIN_DIRIGEUR);

    bool test=P.modifierP();

     if(test)
     {

         QMessageBox::information(nullptr, QObject::tr("Ok"),
              QObject::tr("Modification effectué.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_personnel->setModel(P.afficher());

     }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
              QObject::tr("Modification non effectué.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);


     }
}
