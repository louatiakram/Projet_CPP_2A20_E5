#include "mainwindow.h"
#include "connexion.h"
#include "login.h"
#include "login_bd.h"
#include <QApplication>
#include <QMessageBox>
#include <QApplication>

/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion c;
    bool test=c.createconnect();
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database Is Open"),
                    QObject::tr("Connected Successfully"), QMessageBox::Ok);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Database Is Not Open"),
                    QObject::tr("Connection Failed"), QMessageBox::Ok);

    return a.exec();
}

*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    login l;
    connexion c;
    login_bd b;
    bool test=b.createconnect1();
    if(test)
    {l.show();
        c.createconnect();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}

