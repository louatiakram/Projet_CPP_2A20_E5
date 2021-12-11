#ifndef SDA_H
#define SDA_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include "string"

namespace Ui {
class SDA;
}

class SDA : public QDialog
{
    Q_OBJECT

public:
    explicit SDA(QWidget *parent = nullptr);
    ~SDA();
private slots:

    void serial_read();

    void update_dist(const QString );

    void on_pushButton_04_clicked();

private:
    Ui::SDA *ui;
    QSerialPort *serial;
    QString portname;
    quint16 vendorId;
    quint16 productId;
    bool arduino_available;
    void arduino_init();
    QByteArray serialData;
    QString serialBuffer;
};

#endif // SDA_H
