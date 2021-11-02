#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"gestion_animaux.h"
#include<QIntValidator>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->le_id->setValidator( new QIntValidator(0, 9999, this));
     ui->le_age->setValidator( new QIntValidator(0, 9999, this));
     ui->tab_animal->setModel(A.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id_animal=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString race=ui->la_race->text();
    int age=ui->le_age->text().toInt();
    QString date_entree=ui->la_date->text();
    QString emplacement=ui->le_emplacement->text();
    Animaux A(id_animal,nom,race,age,date_entree,emplacement);

    bool test=A.ajouter();

     if(test)
     {
         QMessageBox::information(nullptr, QObject::tr("Ok"),
              QObject::tr("Ajout effectué.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_animal->setModel(A.afficher());

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
    Animaux A;
    A.setid(ui->le_id->text().toInt());
    bool test=A.supprimer(A.getid());
    if(test)
    {
        ui->tab_animal->setModel(A.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ok"),

                                 QObject::tr("Suppression effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);

   ui->tab_animal->setModel(A.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
             QObject::tr("Suppression non effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);


    }
}


