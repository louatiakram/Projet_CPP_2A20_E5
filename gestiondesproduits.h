#ifndef GESTIONDESPRODUITS_H
#define GESTIONDESPRODUITS_H
#include <QPixmap>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>
#include <QTabWidget>
#include <QTableWidgetItem>
#include <QTabWidget>
#include <QtDebug>
#include <QIntValidator>
#include <QMessageBox>
#include <QDate>
#include <QTextDocument>
#include <QFileDialog>
#include "statistique.h"
#include "QtPrintSupport"
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

    void on_PDF_clicked();

    void on_TRIN_clicked();

    void on_TRIQ_clicked();

    void on_TRIP_clicked();

    void on_Chercher_clicked();

    void on_Reafficher_clicked();

    void on_Statistique_clicked();

    void on_Inserer_IMG_clicked();

    void on_comboBox_01_currentIndexChanged(int);

private:
    Ui::GestionDesProduits *ui;
    GDP G;
    statistique *stat;
};

#endif // GESTIONDESPRODUITS_H
