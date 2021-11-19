#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"personnel.h"
#include "login.h"
#include "login_bd.h"
#include "connection.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QDesktopServices>
#include<QFileDialog>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    login_bd l;
    l.fermerConnexion1();

        Connection c;
        c.createconnect();


        bool test;
        test=c.ourirConnexion();




    ui->setupUi(this);
    ui->le_cin->setValidator( new QIntValidator(0, 99999999, this));
    ui->le_age->setValidator( new QIntValidator(0, 99, this));
    ui->le_salaire->setValidator( new QIntValidator(0,999999, this));
    ui->le_numero->setValidator( new QIntValidator(0, 99999999, this));
    ui->table_cin->setModel(P.afficher_cin());
    ui->tab_personnel->setModel (P.afficher());
    P.write(P.time(),"App started");
    ui->textBrowser->setText(P.read());

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
        ui->table_cin->setModel(P.afficher_cin());
         ui->tab_personnel->setModel(P.afficher());
         P.write(P.time(),"ajout effectué");
         ui->textBrowser->setText(P.read());

     }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
              QObject::tr("Ajout non effectué.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);


     }
}






void MainWindow::on_pb_supprimer_clicked()
{
    Personnel P;
    P.setcin(ui->table_cin->currentText().toInt());
    bool test=P.supprimer(P.getcin());
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("Suppression effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);


   ui->tab_personnel->setModel(P.afficher());
   ui->table_cin->setModel(P.afficher_cin());
   P.write(P.time(),"supression effectuée");
   ui->textBrowser->setText(P.read());
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
    int CIN=ui->table_cin->currentText().toInt();
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
    ui->table_cin->setModel(P.afficher_cin());
    P.write(P.time(),"modification effectuée");
    ui->textBrowser->setText(P.read());

     }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
              QObject::tr("Modification non effectué.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);


     }
}


void MainWindow::on_insererphoto_clicked()
{
   QString filename = QFileDialog::getSaveFileName(this,tr("choose"),"",tr("Image(*.png *.jpeg *.jpg *.bmp *.gif)"));
   if (QString::compare(filename,QString()) !=0)
   {
       QImage image;
       bool valid = image.load(filename);
       if(valid)
       {
           image=image.scaledToWidth(ui->imagee->width(), Qt::SmoothTransformation);
                   ui->imagee->setPixmap(QPixmap::fromImage(image));
       }
       else
       {
           //ERROR HANDLING
       }
   }
}



void MainWindow::on_trier_cin_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_personnel->setModel(P.tri_cin());

}



void MainWindow::on_trier_nom_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_personnel->setModel(P.tri_nom());

}






void MainWindow::on_trier_salaire_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_personnel->setModel(P.tri_salaire());
}

void MainWindow::on_Suprimer_2_clicked()
{
    P.clearh();
    ui->textBrowser->setText(P.read());
}











void MainWindow::on_envoi_bur_clicked()
{

        QString message = ui->boit_mes_emp->text();
      ui->test->setText(message);


}

void MainWindow::on_mess_bur_clicked()
{
    QString message = ui->boite_mes_bur->text();
  ui->test->setText(message);

}
