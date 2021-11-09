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

private:
    Ui::MainWindow *ui;
    Animaux A;
};

#endif // MAINWINDOW_H
