#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "personnel.h"


login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pb_login_clicked()
{

    Personnel P;
    P.USERNAME=ui->username->text();
    P.PASSWORD=ui->password->text();
    P.ajouter1();

    mainwindow = new MainWindow(this);
        mainwindow->show();
}
