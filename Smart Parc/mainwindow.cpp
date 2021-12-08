#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestiondesproduits.h"
#include "dialog_perso.h"
#include "dialog.h"
#include "login.h"
#include "login_bd.h"
#include "connexion.h"
#include "dialog_v.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QPixmap pix("C:/Users/ASUS/Desktop/Smart Parc/MW.jpg");
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

void MainWindow::on_pushButton_4_clicked()
{
   Dialog_v Dialog_v;
   Dialog_v.setModal(true);
   Dialog_v.exec();
}

void MainWindow::on_Quitter_clicked()
{
    close();
}
