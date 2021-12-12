#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include "QtPrintSupport"


namespace Ui {
class statistique;
}

class statistique : public QWidget
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();

private slots:
    void on_Quitter_clicked();

private:
    Ui::statistique *ui;
    void MakeStat();
    void statistiques(QVector<double>* ticks,QVector<QString> *labels);
};

#endif // STATISTIQUE_H
