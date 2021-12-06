#ifndef Dialog_perso_H
#define Dialog_perso_H
#include<QDoubleValidator>
#include <QDialog>
#include "personnel.h"
namespace Ui {
class Dialog_perso;
}

class Dialog_perso : public QDialog
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

   /* void on_envoi_bur_clicked();

    void on_mess_bur_clicked();*/

    void on_Quitter_clicked();

    void on_table_cin_currentIndexChanged(const QString &arg1);

    void on_table_cin_currentIndexChanged(int index);

private:
    Ui::Dialog_perso *ui;
    Personnel P;

public:
    explicit Dialog_perso(QWidget *parent = nullptr);
    ~Dialog_perso();



};





#endif // Dialog_perso_H


