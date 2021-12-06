#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestiondesproduits.h"
#include "dialog_perso.h"
#include "dialog.h"
#include "login.h"
#include "login_bd.h"
#include "connexion.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    /*login_bd l;
    l.fermerConnexion1();

        connexion c;
        c.createconnect();


        bool test;
        test=c.ourirConnexion();
      */

    ui->setupUi(this);

    QPixmap pix("C:/Users/wassim/Desktop/khedma integreeeV1/Projet_CPP_2A20_E5-GestionDesProduits/MW.jpg");
    ui->IMG->setPixmap(pix.scaled(1200,700,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    GestionDesProduits GDP;
    GDP.setModal(true);
    GDP.exec();
}

void MainWindow::on_pushButton_04_clicked()
{
    exit(1);
}

void MainWindow::on_pushButton_2_clicked()
{
     Dialog_perso dialog;
    dialog.setModal(true);
    dialog.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    Dialog dialog;
   dialog.setModal(true);
   dialog.exec();
}
