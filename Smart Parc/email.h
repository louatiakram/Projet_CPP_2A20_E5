#ifndef EMAIL_H
#define EMAIL_H

#include <QDialog>

namespace Ui {
class email;
}

class email : public QDialog
{
    Q_OBJECT

public:
    explicit email(QWidget *parent = nullptr);
    explicit email(QString,QString,QString,QWidget *parent = nullptr);
    ~email();
private slots:
void set_tmpemail(QString e){tmpemail=e;}

void on_envoyer_dialog_2_clicked();

private:
    Ui::email *ui;
    QString tmpemail;
};

#endif // EMAIL_H

