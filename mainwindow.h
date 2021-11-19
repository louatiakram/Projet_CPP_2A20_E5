#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QDoubleValidator>
#include <QMainWindow>
#include "personnel.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:

    void on_pb_ajouter_clicked();

    void on_pb_afficher_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_insererphoto_clicked();

      void on_Suprimer_2_clicked();






    void on_trier_cin_clicked();

    void on_trier_nom_clicked();

    void on_trier_salaire_clicked();

    void on_envoi_bur_clicked();

    void on_mess_bur_clicked();

private:
    Ui::MainWindow *ui;
    Personnel P;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



};





#endif // MAINWINDOW_H


