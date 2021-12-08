#ifndef DIALOG_V_H
#define DIALOG_V_H
#include <visiteurs.h>

#include <QDialog>

namespace Ui {
class Dialog_v;
}

class Dialog_v : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_v(QWidget *parent = nullptr);
    ~Dialog_v();

private slots:
    void on_pb_ajouter_2_clicked();

    void on_pb_modifier_2_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_tester_2_clicked();

    void on_pb_tri_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pb_excel_clicked();

    void on_Quitter_clicked();

private:
    Ui::Dialog_v *ui;
    visiteurs V;
};

#endif // DIALOG_V_H
