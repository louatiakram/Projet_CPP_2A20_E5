#include "mainwindow.h"
#include "connexion.h"
#include "login.h"
#include "login_bd.h"
#include <QApplication>
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    login l;
    connexion c;
    login_bd b;
    bool test=b.createconnect1();
    if(test)
    {
        l.show();
        c.createconnect();
        QMessageBox::information(nullptr, QObject::tr("Database Is Open"),
                    QObject::tr("Connected Successfully !\n"
                                "Click Ok to exit."), QMessageBox::Ok);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Database Is Not Open"),
                    QObject::tr("Connection Failed.\n"
                                "Click Ok to exit."), QMessageBox::Ok);

    return a.exec();
}

