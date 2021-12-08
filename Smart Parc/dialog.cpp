#include "dialog.h"
#include "ui_dialog.h"
#include"gestion_animaux.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QDesktopServices>
#include<QUrl>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include <QFileDialog>
#include "email.h"

#include <QPainter>
#include<ctime>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Desktop/Smart Parc/AA.jpg");
    ui->label_10->setPixmap(pix.scaled(1200,700,Qt::KeepAspectRatio));
    ui->label_12->setPixmap(pix.scaled(1200,700,Qt::KeepAspectRatio));
    ui->label_20->setPixmap(pix.scaled(1200,700,Qt::KeepAspectRatio));

     ui->le_id->setValidator( new QIntValidator(0, 9999, this));
     ui->le_age->setValidator( new QIntValidator(0, 9999, this));
     ui->tab_animal->setModel(A.afficher());
     ui->table_id->setModel(A.afficher_id());

     /////////////////

         connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
     /////////////
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pb_ajouter_clicked()
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

void Dialog::on_pb_supprimer_clicked()
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



void Dialog::on_modifier_clicked()
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




void Dialog::on_trier_id_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
 ui->tab_animal->setModel(A.tri_id());

}


void Dialog::on_trier_age_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
 ui->tab_animal->setModel(A.tri_age());
}

void Dialog::on_trier_nom_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
 ui->tab_animal->setModel(A.tri_nom());
}




//////////////////////////////////////////////////////////////////////////////



void Dialog::on_le_rechercher_textChanged()
{
    A.clearTable(ui->tab_animal);
        int id_animal=ui->le_rechercher->text().toInt();
        A.rechercher(ui->tab_animal,id_animal);
}








void Dialog::on_Lienderenseignement_2_clicked()
{

    QDesktopServices::openUrl(QUrl("https://animalzone.tn/11-chiens"));
}

void Dialog::on_Lienderenseignement_5_clicked()
{
    QDesktopServices::openUrl(QUrl("https://animalzone.tn/10-chats"));
}

void Dialog::on_Lienderenseignement_8_clicked()
{
    QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/mammals/facts/giant-panda"));
}

void Dialog::on_Lienderenseignement_7_clicked()
{
     QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/mammals/facts/bottlenose-dolphin"));
}

void Dialog::on_Lienderenseignement_6_clicked()
{
    QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/birds/facts/adelie-penguin"));
}

void Dialog::on_Lienderenseignement_4_clicked()
{
    QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/mammals/facts/harp-seal"));
}

void Dialog::on_Lienderenseignement_3_clicked()
{
    QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/mammals/facts/tiger"));
}

void Dialog::on_Lienderenseignement_11_clicked()
{
    QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/birds/facts/ostrich"));
}

void Dialog::on_Lienderenseignement_10_clicked()
{
    QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/mammals/facts/lion"));
}

void Dialog::on_Lienderenseignement_12_clicked()
{
   QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/mammals/facts/giraffe"));
}

void Dialog::on_Lienderenseignement_9_clicked()
{
    QDesktopServices::openUrl(QUrl("https://kids.nationalgeographic.com/animals/mammals/facts/giraffe"));
}


/////////////////////////////////////////////////////////



void Dialog::on_ImportPDF_clicked()
{


         ///////////////////////////////

             QPdfWriter pdf("C:/Users/ASUS/Desktop/Smart Parc/Liste.pdf");

             QPainter painter(&pdf);

             int i = 4000;
             painter.setPen(Qt::black);
             painter.setFont(QFont("Arial", 30));
             painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("C:/Users/ASUS/Desktop/Smart Parc/logo.jpg"));
             painter.drawText(3000,1500,"LISTE DES ANIMAUX");
             painter.setPen(Qt::blue);
             painter.setFont(QFont("Arial", 50));
             painter.drawRect(2700,200,6300,2600);
             painter.drawRect(0,3000,9600,500);
             painter.setPen(Qt::black);
             painter.setFont(QFont("Arial", 9));
             painter.drawText(300,3300,"id_animal");
             painter.drawText(2300,3300,"nom");
             painter.drawText(4300,3300,"race");
             painter.drawText(6000,3300,"age");
             painter.drawText(8300,3300,"date_entree");
             painter.drawText(10300,3300,"emplacement");
             QSqlQuery query;
             query.prepare("<SELECT CAST( GETDATE() AS Date ) ");
             time_t tt;
             struct tm* ti;
             time(&tt);
             ti=localtime(&tt);
             asctime(ti);
             painter.drawText(500,300, asctime(ti));
             query.prepare("select * from GESTION_ANIMAUX");
             query.exec();
             while (query.next())
             {
                 painter.drawText(300,i,query.value(0).toString());
                 painter.drawText(2300,i,query.value(1).toString());
                 painter.drawText(4300,i,query.value(2).toString());
                 painter.drawText(6300,i,query.value(3).toString());
                 painter.drawText(8000,i,query.value(4).toString());
                 painter.drawText(10000,i,query.value(5).toString());
                 i = i +500;
             }

             int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
             if (reponse == QMessageBox::Yes)
             {
                 QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/Smart Parc/Liste.pdf"));

                 painter.end();
             }
             if (reponse == QMessageBox::No)
             {
                 painter.end();
             }
         }




         ////////////////////////////////





void Dialog::on_insererphoto_clicked()
{
   QString filename = QFileDialog::getSaveFileName(this,tr("choose"),"",tr("Image( *.jpeg *.jpg *.bmp *.gif)"));
   if (QString::compare(filename,QString()) !=0)
   {
       QImage image;
       bool valid = image.load(filename);
       if(valid)
       {
           image=image.scaledToWidth(ui->lbl_image->width(), Qt::SmoothTransformation);
                   ui->lbl_image->setPixmap(QPixmap::fromImage(image));
       }
       else
       {
           //ERROR HANDLING
       }
   }
}


//////////////////////////////////////////


/////////////////////////////////////////




void Dialog::on_mailing_clicked()
{
   email email;
   email.setModal(true);
   email.exec();

}












void Dialog::on_code_qr_clicked()
{
    QDesktopServices::openUrl(QUrl("https://qrcode.tec-it.com/fr"));
    QString filename = QFileDialog::getSaveFileName(this,tr("choose"),"",tr("Image(*.png )"));
    if (QString::compare(filename,QString()) !=0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            image=image.scaledToWidth(ui->lbl_image_2->width(), Qt::SmoothTransformation);
                    ui->lbl_image_2->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            //ERROR HANDLING
        }
    }



}


void Dialog::on_table_id_currentIndexChanged(int )
{

        int id_animal=ui->table_id->currentText().toInt();
        QString id_animal_string=QString::number(id_animal);

        QSqlQuery query;
        query.prepare("SELECT * FROM GESTION_ANIMAUX where id_animal='"+id_animal_string+"'");

        if(query.exec())
        {
            while (query.next())
            {
              ui->le_id->setText(query.value(0).toString()) ;
              ui->le_nom->setText(query.value(1).toString()) ;
              ui->la_race->setText(query.value(2).toString()) ;
              ui->le_age->setText(query.value(3).toString()) ;
              ui->la_date->setText(query.value(4).toString()) ;
              ui->le_emplacement->setText(query.value(5).toString()) ;
            }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                        QObject::tr("Echec.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }




void Dialog::on_Quitter_clicked()
{
    close();
}
