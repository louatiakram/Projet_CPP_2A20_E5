#ifndef GDE_H
#define GDE_H

#include <QDialog>
#include "evenements.h"
#include "gdp.h"

namespace Ui {
class GDE;
}

class GDE : public QDialog
{
    Q_OBJECT

public:
    explicit GDE(QWidget *parent = nullptr);
    ~GDE();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_verifier_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pb_tri_clicked();

    void on_radioButton_clicked();

    void on_pb_PDF_clicked();

    void on_pushButton_2_clicked();

    void on_Quitter_clicked();

private:
    Ui::GDE *ui;
    evenements E;
};

#endif // GDE_H
