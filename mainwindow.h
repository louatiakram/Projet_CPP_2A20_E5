#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include"gestion_animaux.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_ajouter_clicked();

    void on_pb_afficher_clicked();

    void on_pb_supprimer_clicked();

    void on_Animaux_currentChanged(int index);

    void on_modifier_clicked();

    void on_comboBox_activated(int index);

    void on_table_id_activated(const QString &arg1);

    void on_table_id_activated(int index);

    void on_table_id_currentIndexChanged(int index);

    void on_trier_clicked();

    void on_trier_id_clicked();

    void on_trier_4_clicked();

    void on_trier_age_clicked();

    void on_trier_nom_clicked();

    void on_le_rechercher_textChanged();

    void on_Lienderenseignement_clicked();

    void on_Lienderenseignement_2_clicked();

    void on_Lienderenseignement_5_clicked();

    void on_Lienderenseignement_8_clicked();

    void on_Lienderenseignement_7_clicked();

    void on_Lienderenseignement_6_clicked();

    void on_Lienderenseignement_4_clicked();

    void on_Lienderenseignement_3_clicked();

    void on_Lienderenseignement_11_clicked();

    void on_Lienderenseignement_10_clicked();

    void on_Lienderenseignement_12_clicked();

    void on_sendBtn_clicked();

    void on_Lienderenseignement_9_clicked();

    void on_ImportPDF_clicked();

    void on_insererphoto_clicked();

private:
    Ui::MainWindow *ui;

    Animaux A;

};

#endif // MAINWINDOW_H
