#include "widget.h"
#include "ui_widget.h"
#include "mydialog.h"
#include<QDebug>

int num=0,vipnum=0;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
////////////
    receiver = new QUdpSocket(this);
    receiver -> bind(45454,QUdpSocket::ShareAddress);
    connect(receiver,SIGNAL(readyRead()),this,SLOT(processPendingDatagram()));
 ////////
    this->setWindowTitle(tr("Work"));
    this->setFixedSize( this->width (),this->height ()); //固定大小
    tcpSocket = new QTcpSocket(this);

    /////////////////////////////////
/*
    receiver = new QUdpSocket(this);
    receiver -> bind(45454,QUdpSocket::ShareAddress);
    connect(receiver,SIGNAL(readyRead()),this,SLOT(processPendingDatagram()));
  */  ////////////////////////////////////////

    receiver1 = new QUdpSocket(this);
    receiver1 -> bind(45453,QUdpSocket::ShareAddress);
    connect(receiver1,SIGNAL(readyRead()),this,SLOT(processPendingDatagram1()));
    ///////////////////////////////////////

    receiver3 = new QUdpSocket(this);
    receiver3 -> bind(45452,QUdpSocket::ShareAddress);
    connect(receiver3,SIGNAL(readyRead()),this,SLOT(processPendingDatagram3()));

    ////////
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(displayError(QAbstractSocket::SocketError)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
           newConnect();
}
void Widget::newConnect()
{
    tcpSocket->abort();    tcpSocket->connectToHost(QHostAddress("10.0.2.15"),6060);
}
void Widget::readMessage()
{

    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_6);
    in>>viped;    in>>nored;      in>>vip;      in>>nor;
    char  vipedl,noredl,vipl,norl;
    vipedl=viped;       noredl= nored;   vipl= vip;  norl = nor;
    ui->lineEdit_6->setText((char*)vipedl);
    ui->lineEdit_5->setText((char*)noredl);
    ui->lineEdit_3->setText((char*)vipl);
    ui->lineEdit_2->setText((char*)norl);
}
void Widget::displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpSocket->errorString(); //输出错误信息
}

/////////////////////////////
/////////////////////////////
void Widget::processPendingDatagram()
{
    while (receiver->hasPendingDatagrams())
    {
        QByteArray  datagram;
        datagram.resize(receiver->pendingDatagramSize());
        receiver->readDatagram(datagram.data(),datagram.size());
        char b;
        b=*datagram;

        num=b-48;
        QString stra;
        ui->lineEdit_2->setText(stra.sprintf("%d",num));
        ui->lineEdit->setText(stra.sprintf("%d",num+vipnum));

    }
}
///////////////////////////////////////

void Widget::processPendingDatagram1()
{
    while (receiver1->hasPendingDatagrams())
    {
        QByteArray  datagram;
        datagram.resize(receiver1->pendingDatagramSize());
        receiver1->readDatagram(datagram.data(),datagram.size());
        char c;
        c=*datagram;

        vipnum=c-48;
        QString strd;
        ui->lineEdit_3->setText(strd.sprintf("%d",vipnum));
        ui->lineEdit->setText(strd.sprintf("%d",num+vipnum));
    }
}
//////////////////////////////////////


void Widget::processPendingDatagram3()
{
    while (receiver3->hasPendingDatagrams())
    {
        QByteArray  datagram;
        datagram.resize(receiver3->pendingDatagramSize());
        receiver3->readDatagram(datagram.data(),datagram.size());
        char b;
        b=*datagram;
        int a;
        a=b-48;
        QString stra;
        ui->lineEdit_7->setText(stra.sprintf("%d",a));
        ui->lineEdit_4->setText(stra.sprintf("%d",a));

    }
}

