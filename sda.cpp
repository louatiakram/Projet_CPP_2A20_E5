#include "sda.h"
#include "ui_sda.h"


SDA::SDA(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SDA)
{
    ui->setupUi(this);
    serial = new QSerialPort(); //Inicializa la variable Serial
        arduino_available = false;

        foreach (const QSerialPortInfo &serial_Info, QSerialPortInfo::availablePorts()) {//Lee la información de cada puerto serial
            qDebug()<<"port: "<<serial_Info.portName();
            portname = serial_Info.portName();
            qDebug()<<"Vendor Id: "<<serial_Info.vendorIdentifier();
            vendorId = serial_Info.vendorIdentifier();
            qDebug()<<"Product Id: "<<serial_Info.productIdentifier();
            productId = serial_Info.productIdentifier();
            arduino_available = true;
        }
        if(arduino_available)
        {
            arduino_init();
        }
}

SDA::~SDA()
{
    delete ui;
}

void SDA::arduino_init()
{
    serial->setPortName(portname);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    connect(serial,SIGNAL(readyRead()),this,SLOT(serial_read()));
}

void SDA::serial_read()
{
    if(serial->isWritable()&&arduino_available)
    {
     serialData = serial->readAll();
     serialBuffer +=QString::fromStdString(serialData.toStdString());
        qDebug()<<serialBuffer;
     SDA::update_dist(serialBuffer);

    }
}


void SDA::update_dist(const QString sensor_reading)
{
    ui->lineEdit->setText(sensor_reading);
}




void SDA::on_pushButton_04_clicked()
{
    close();
}

