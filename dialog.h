#ifndef Dialog_H
#define Dialog_H

#include <QDialog>

#include"gestion_animaux.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

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

    void on_mailing_clicked();

    void on_somme_clicked();



    void on_code_qr_clicked();

    void on_load_clicked();

    void on_insererphoto_2_clicked();

    void on_Quitter_clicked();

private:
    Ui::Dialog *ui;

    Animaux A;

};

#endif // Dialog_H
