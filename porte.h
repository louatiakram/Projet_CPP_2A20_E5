#ifndef PORTE_H
#define PORTE_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

namespace Ui {
class porte;
}

class porte : public QDialog
{
    Q_OBJECT


private slots:
    void on_pushButton_ON_clicked();

    void on_pushButton_OFF_clicked();

    void serial_read();

    void update_dist(const QString );
    //void on_textEdit_currentCharFormatChanged(const QTextCharFormat &format);

public:
    explicit porte(QWidget *parent = nullptr);
    ~porte();

private:
    Ui::porte *ui;
    QSerialPort *serial;
    QString portname;
    quint16 vendorId;
    quint16 productId;
    bool arduino_available;
    void arduino_init();
    QByteArray serialData;
    QString serialBuffer;
};

#endif // PORTE_H
