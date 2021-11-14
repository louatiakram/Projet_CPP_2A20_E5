#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"gestion_animaux.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QDesktopServices>
#include<QUrl>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->le_id->setValidator( new QIntValidator(0, 9999, this));
     ui->le_age->setValidator( new QIntValidator(0, 9999, this));
     ui->tab_animal->setModel(A.afficher());
     ui->table_id->setModel(A.afficher_id());
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
         ui->table_id->setModel(A.afficher_id());
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
    A.setid(ui->table_id->currentText().toInt());
    bool test=A.supprimer(A.getid());


    if(test)
    {
        ui->tab_animal->setModel(A.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ok"),

                                 QObject::tr("Suppression effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);

   ui->tab_animal->setModel(A.afficher());
   ui->table_id->setModel(A.afficher_id());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
             QObject::tr("Suppression non effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);


    }
}



void MainWindow::on_modifier_clicked()
{
    int id_animal=ui->table_id->currentText().toInt();
    QString nom=ui->le_nom->text();
    QString race=ui->la_race->text();
    int age=ui->le_age->text().toInt();
    QString date_entree=ui->la_date->text();
    QString emplacement=ui->le_emplacement->text();
    Animaux A(id_animal,nom,race,age,date_entree,emplacement);

    bool test=A.modifier();

     if(test)
     {

         QMessageBox::information(nullptr, QObject::tr("Ok"),
              QObject::tr("Modification effectué.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_animal->setModel(A.afficher());
    ui->table_id->setModel(A.afficher_id());

     }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
              QObject::tr("Modification non effectué.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);


     }
}




void MainWindow::on_trier_id_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
 ui->tab_animal->setModel(A.tri_id());

}


void MainWindow::on_trier_age_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
 ui->tab_animal->setModel(A.tri_age());
}

void MainWindow::on_trier_nom_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
 ui->tab_animal->setModel(A.tri_nom());
}




//////////////////////////////////////////////////////////////////////////////



void MainWindow::on_le_rechercher_textChanged()
{
    A.clearTable(ui->tab_animal);
        int id_animal=ui->le_rechercher->text().toInt();
        A.rechercher(ui->tab_animal,id_animal);
}








void MainWindow::on_Lienderenseignement_2_clicked()
{

    QDesktopServices::openUrl(QUrl("https://animalzone.tn/11-chiens"));
}

void MainWindow::on_Lienderenseignement_5_clicked()
{
    QDesktopServices::openUrl(QUrl("https://animalzone.tn/10-chats"));
}

void MainWindow::on_Lienderenseignement_8_clicked()
{
    QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/mammals/facts/giant-panda"));
}

void MainWindow::on_Lienderenseignement_7_clicked()
{
     QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/mammals/facts/bottlenose-dolphin"));
}

void MainWindow::on_Lienderenseignement_6_clicked()
{
    QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/birds/facts/adelie-penguin"));
}

void MainWindow::on_Lienderenseignement_4_clicked()
{
    QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/mammals/facts/harp-seal"));
}

void MainWindow::on_Lienderenseignement_3_clicked()
{
    QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/mammals/facts/tiger"));
}

void MainWindow::on_Lienderenseignement_11_clicked()
{
    QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/birds/facts/ostrich"));
}

void MainWindow::on_Lienderenseignement_10_clicked()
{
    QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/mammals/facts/lion"));
}

void MainWindow::on_Lienderenseignement_12_clicked()
{
   QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/mammals/facts/giraffe"));
}

void MainWindow::on_Lienderenseignement_9_clicked()
{
    QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/mammals/facts/giraffe"));
}
