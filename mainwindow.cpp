#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"personnel.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QDoubleValidator>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_cin->setValidator( new QIntValidator(0, 9999, this));
    ui->le_age->setValidator( new QIntValidator(0, 9999, this));
    ui->le_salaire->setValidator( new QDoubleValidator(0.00,99999.00,5, this));
    ui->tab_personnel->setModel (P.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int age=ui->le_age->text().toInt();
    double salaire=ui->le_salaire->text().toDouble();

    Personnel P(cin,nom,prenom,age,salaire);

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


