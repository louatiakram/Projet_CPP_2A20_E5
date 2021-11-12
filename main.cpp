#include "mainwindow.h"
#include "connexion.h"

#include <QApplication>
#include <QMessageBox>
#include <QApplication>

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
