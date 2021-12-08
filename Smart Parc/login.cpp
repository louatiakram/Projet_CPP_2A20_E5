#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "personnel.h"


login::login(QWidget *parent) :
    QDialog(parent),
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
    QString USERNAME = ui->username->text();
    QString PASSWORD = ui->password->text();

        QSqlQuery query;

        if(query.exec("SELECT* from LOGIN where USERNAME ='" + USERNAME + "' and PASSWORD ='" + PASSWORD + "' " ))
        {
            if(query.next())
            {
                QMessageBox::information(nullptr, QObject::tr("DONE"),
                QObject::tr("Logged In Successfully !"), QMessageBox::Ok);
                mainwindow = new MainWindow(this);
                mainwindow->show();
            }
            else
            {
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),
            QObject::tr("Login Failed !, Invalid username or password"), QMessageBox::Ok);
            }
        }
}
