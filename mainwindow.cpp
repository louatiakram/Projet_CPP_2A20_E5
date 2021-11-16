#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <evenements.h>
#include <QIntValidator>
#include <QDebug>
#include <QRegExpValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->le_ref->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_duree->setValidator(new QIntValidator(0, 999, this));
    ui->le_date->setValidator(new QIntValidator(0, 99999999, this));
    ui->tab_evenements->setModel(E.afficher());
    #define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
    QRegExp rxNom(NOM_RX);
    QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
    ui->le_nom->setValidator(valiNom);
    ui->le_sujet->setValidator(valiNom);
    ui->le_emplacement->setValidator(valiNom);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int reference=ui->le_ref->text().toInt();
   QString nom=ui->le_nom->text();
   QString sujet=ui->le_sujet->text();
   int date_e=ui->le_date->text().toInt();
   QString emplacement=ui->le_emplacement->text();
   int duree=ui->le_duree->text().toInt();
   evenements E(reference,nom,sujet,date_e,emplacement,duree);
   bool test=E.ajouter();
   QMessageBox msgbox;
   if(test)
 {msgbox.setText("Ajout avec succes.");
           ui->tab_evenements->setModel(E.afficher());
           ui->le_ref->setText("");
           ui->le_nom->setText("");
           ui->le_sujet->setText("");
           ui->le_date->setText("");
           ui->le_emplacement->setText("");
           ui->le_duree->setText("");
       }
   else
            msgbox.setText("Echec d'ajout");
        msgbox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    evenements E1;
     E1.setRef(ui->le_ref_supprimer->text().toInt());
     bool test=E1.supprimer(E1.getRef());
     QMessageBox msgbox;
     if(test)
         {msgbox.setText("Suppression avec succes.");
             ui->tab_evenements->setModel(E.afficher());
             ui->le_ref_supprimer->setText("");
         }
         else
             msgbox.setText("Echec de suppression");
         msgbox.exec();
}

void MainWindow::on_pb_modifier_clicked()
{

    int reference=ui->le_ref_modif->text().toInt();
    QString nom=ui->le_nom_modif->text();
    QString sujet=ui->le_sujet_modif->text();
    int date_e=ui->le_date_modif->text().toInt();
    QString emplacement=ui->le_emplacement_modif->text();
    int duree=ui->le_duree_modif->text().toInt();
    evenements E(reference,nom,sujet,date_e,emplacement,duree);
    bool test=E.modifier();
    QMessageBox msgbox;
    if(test)
{msgbox.setText("Modification avec succes.");
            ui->tab_evenements->setModel(E.afficher());
            ui->le_ref_modif->setText("");
            ui->le_nom_modif->setText("");
            ui->le_sujet_modif->setText("");
            ui->le_date_modif->setText("");
            ui->le_emplacement_modif->setText("");
            ui->le_duree_modif->setText("");
        }
        else
            msgbox.setText("Echec de modification");
        msgbox.exec();


}

void MainWindow::on_pb_verifier_clicked()
{
    QSqlQuery query ;
            QString reference=ui->le_ref_modif->text() ;
            query.prepare("Select * from EVENEMENTS WHERE reference=:reference");
            query.bindValue(":reference",reference) ;
            query.exec() ;
            query.next() ;
            ui->le_nom_modif->setText(query.value(1).toString());
            ui->le_sujet_modif->setText(query.value(2).toString());
            ui->le_date_modif->setText(query.value(3).toString());
            ui->le_emplacement_modif->setText(query.value(4).toString());
            ui->le_duree_modif->setText(query.value(5).toString());
}
