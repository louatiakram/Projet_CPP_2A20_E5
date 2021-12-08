#include "dialog_perso.h"
#include "ui_dialog_perso.h"
#include"personnel.h"
#include "login.h"
#include "login_bd.h"
#include "connexion.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QDesktopServices>
#include<QFileDialog>
#include <QPushButton>


Dialog_perso::Dialog_perso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_perso)
{

    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Desktop/Smart Parc/PP.jpg");
    ui->label_6->setPixmap(pix.scaled(1200,700,Qt::KeepAspectRatio));
    ui->label_7->setPixmap(pix.scaled(1200,700,Qt::KeepAspectRatio));
    ui->label_9->setPixmap(pix.scaled(1200,700,Qt::KeepAspectRatio));

    ui->le_cin->setValidator( new QIntValidator(0, 99999999, this));
    ui->le_age->setValidator( new QIntValidator(0, 99, this));
    ui->le_salaire->setValidator( new QIntValidator(0,999999, this));
    ui->le_numero->setValidator( new QIntValidator(0, 99999999, this));
    ui->table_cin->setModel(P.afficher_cin());
    ui->tab_personnel->setModel (P.afficher());
    P.write(P.time(),"App started");
    ui->textBrowser->setText(P.read());

}

Dialog_perso::~Dialog_perso()
{
    delete ui;
}

void Dialog_perso::on_pb_ajouter_clicked()
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






void Dialog_perso::on_pb_supprimer_clicked()
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

void Dialog_perso::on_pb_modifier_clicked()
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


void Dialog_perso::on_insererphoto_clicked()
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



void Dialog_perso::on_trier_cin_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_personnel->setModel(P.tri_cin());

}



void Dialog_perso::on_trier_nom_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_personnel->setModel(P.tri_nom());

}


void Dialog_perso::on_trier_salaire_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_personnel->setModel(P.tri_salaire());
}

void Dialog_perso::on_Suprimer_2_clicked()
{
    P.clearh();
    ui->textBrowser->setText(P.read());
}

/*void Dialog_perso::on_envoi_bur_clicked()
{

        QString message = ui->boit_mes_emp->text();
      ui->test->setText(message);


}

void Dialog_perso::on_mess_bur_clicked()
{
    QString message = ui->boite_mes_bur->text();
  ui->test->setText(message);

}*/

void Dialog_perso::on_Quitter_clicked()
{
    close();
}



void Dialog_perso::on_table_cin_currentIndexChanged(int index)
{
    int cin=ui->table_cin->currentText().toInt();
         QString cin_1=QString::number(cin);
        QSqlQuery query;
        query.prepare("SELECT * FROM GESTION_PERSONNEL where CIN='"+cin_1+"'");
        if(query.exec())
        {
            while (query.next())
            {
              ui->le_cin->setText(query.value(0).toString()) ;
              ui->le_nom->setText(query.value(1).toString()) ;
              ui->le_prenom->setText(query.value(2).toString()) ;
              ui->le_age->setText(query.value(3).toString()) ;
              ui->le_salaire->setText(query.value(4).toString()) ;
              ui->le_numero->setText(query.value(5).toString()) ;
            }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                        QObject::tr("ECHEC DE chargement .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}
