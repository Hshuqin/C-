#include "wdialog.h"
#include "ui_wdialog.h"
#include<QtNetwork>
#include <QString>
#include<QDebug>
int numb=0;
wdialog::wdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wdialog)
{
    ui->setupUi(this);
    ////////////////
    sender2 = new QUdpSocket(this);
    ////////////////
    this->setWindowTitle(tr("Work"));
    this->setFixedSize( this->width (),this->height ()); //固定大小

    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
             this,SLOT(displayError(QAbstractSocket::SocketError)));
}

wdialog::~wdialog()
{
    delete ui;
}


void wdialog::newConnect()
{
    tcpSocket->abort();
    tcpSocket->connectToHost(QHostAddress("10.0.2.15"),6060);
}
void wdialog::readMessage()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_6);
    in>>x;
    char xx;
    xx=x+64;
    ui->label->setText((char*)x);
}
void wdialog::displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpSocket->errorString(); //输出错误信息
}

void wdialog::on_pushButton_clicked()
{
    //////////////////////
    numb++;
    char b=numb+48;
    const char *a=&b;
    QByteArray datagram = a;
    sender2->writeDatagram(datagram.data(),datagram.size(),QHostAddress::Broadcast,45452);
    ///////////////////////////////////
    newConnect();
}
