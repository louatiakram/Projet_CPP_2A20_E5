#ifndef GDV_H
#define GDV_H

#include "visiteurs.h"
#include "gdp.h"
#include "QtPrintSupport"
#include <QFileDialog>
#include "excel.h"

namespace Ui {
class GDV;
}

class GDV : public QDialog
{
    Q_OBJECT

public:
    explicit GDV(QWidget *parent = nullptr);
    ~GDV();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_modifier_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_tester_clicked();

    void on_pb_tri_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pb_excel_clicked();

    void on_Quitter_clicked();

private:
    Ui::GDV *ui;
    visiteurs V;
};

#endif // GDV_H
