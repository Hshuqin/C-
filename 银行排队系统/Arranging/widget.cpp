#include "widget.h"
#include "ui_widget.h"
#include <QDialog>
#include <QTimer>
#include <QDateTime>
#include <QString>
#include <QTextCodec>
#include <QtNetwork>
int ptnum = 0;
int vipnum = 0;
int xx = 0;
int num = 0;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    QTimer *time=new QTimer(this);
    tcpSocket = new QTcpSocket(this);
    tcpServer = new QTcpServer(this);

    if(!tcpServer->listen(QHostAddress::LocalHost,6060))
    {  //**本地主机的6666端口，如果出错就输出错误信息，并关闭
        qDebug() << tcpServer->errorString();
        close();
    }
    //连接信号和相应槽函数
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(sendmessage()));
    connect(time,SIGNAL(timeout()),this,SLOT(timeupdate()));
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    time->start(1000);
}

void Widget::timeupdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    ui->label_5->setText(str);
}
Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ptnum++;
    QString strnumb;
    id1=startTimer(3000);
    ui->label_2->setText(tr("普通客户您好,当前有")+strnumb.sprintf("%d",vipnum+ptnum-1)+tr("人排队"));
    ui->lineEdit->setText(tr("取票成功！您的号码是普通")+strnumb.sprintf("%d",ptnum)+tr("号"));
    xx=0;
    num=ptnum;
    newConnect();

}

void Widget::on_pushButton_2_clicked()
{
    vipnum++;
    QString strnumb;
    id2=startTimer(3000);
    ui->label->setText(tr("VIP客户您好,当前有")+strnumb.sprintf("%d",vipnum-1)+tr("人排队"));
    ui->label_2->setText(tr("普通客户您好,当前有")+strnumb.sprintf("%d",vipnum+num)+tr("人排队"));
    ui->lineEdit_2->setText(tr("取票成功！您的号码是VIP")+strnumb.sprintf("%d",vipnum)+tr("号"));
    xx=1;
    num=vipnum;
    newConnect();

}

void Widget::timerEvent(QTimerEvent *event)
{
    if (event->timerId()==id1)
    {
        ui->lineEdit->clear();
    }
    if (event->timerId()==id2)
    {
        ui->lineEdit_2->clear();
    }
}
void Widget::newConnect()
{
    blockSize=0;
    tcpSocket->abort();
    tcpSocket->connectToHost(QHostAddress::LocalHost,6666);
}
void Widget::readMessage()
{

    float x;
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QString strnumb;
    QDataStream in(tcpSocket);
        in.setVersion(QDataStream::Qt_4_6);
        //设置数据流版本，这里要和服务器端相同
        if(blockSize==0) //如果是刚开始接收数据
        {
           //判断接收的数据是否有两字节，也就是文件的大小信息
           //如果有则保存到blockSize变量中，没有则返回，继续接收数据
           if(tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
           in >> blockSize;
        }
        if(tcpSocket->bytesAvailable() < blockSize) return;
        //如果没有得到全部的数据，则返回，继续接收数据
        in >> x;

        //将接收到的数据存放到变量中

}
void Widget::sendmessage()
{


    //用于暂存我们要发送的数据
    QByteArray block;

    //使用数据流写入数据
    QDataStream out(&block,QIODevice::WriteOnly);

    //设置数据流的版本，客户端和服务器端使用的版本要相同
    out.setVersion(QDataStream::Qt_4_6);

    out<<(quint16) 0;
    out<<float(num);
    out<<float(xx);
    //我们获取已经建立的连接的子套接字
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();

    connect(clientConnection,SIGNAL(disconnected()),clientConnection,
           SLOT(deleteLater()));
    clientConnection->write(block);
    clientConnection->disconnectFromHost();


}


