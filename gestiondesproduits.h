#ifndef GESTIONDESPRODUITS_H
#define GESTIONDESPRODUITS_H
#include <QPixmap>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDialog>
#include <QTabWidget>
#include <QTableWidgetItem>
#include <QTabWidget>
#include <QtDebug>
#include <QIntValidator>
#include <QMessageBox>
#include <QDate>

#include "gdp.h"

namespace Ui
{
class GestionDesProduits;
}

class GestionDesProduits : public QDialog
{
    Q_OBJECT

public:
    explicit GestionDesProduits(QWidget *parent = nullptr);
    ~GestionDesProduits();

private slots:

    void on_Quitter_clicked();

    void on_Ajouter_clicked();

    void on_Supprimer_clicked();

    void on_Modifier_clicked();

private:
    Ui::GestionDesProduits *ui;
    GDP G;
};

#endif // GESTIONDESPRODUITS_H
