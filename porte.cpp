#include "porte.h"
#include "ui_porte.h"
#include "personnel.h"

porte::porte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::porte)
{
    ui->setupUi(this);

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
    if(arduino_available){
        arduino_init();
    }
}

porte::~porte()
{
    delete ui;
}


void porte::arduino_init()
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


void porte::on_pushButton_ON_clicked()
{

    if(serial->isWritable()){
        serial->write("1");
        qDebug()<<"Encender";
    }

}

void porte::on_pushButton_OFF_clicked()
{
    if(serial->isWritable()){
        serial->write("2");
        qDebug()<<"Apagar";
    }
}

void porte::serial_read()
{
    if(serial->isWritable()&&arduino_available)
    {
     serialData = serial->readAll();
     serialBuffer +=QString::fromStdString(serialData.toStdString());
        qDebug()<<serialBuffer;
    porte::update_dist(serialBuffer);




    }
}


void porte::update_dist(const QString sensor_reading)
{


    ui->lcdNumber->display(sensor_reading);


              ui->lineEdit->setText(sensor_reading);



}
