#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_pushButton_clicked();
    void newConnect();
    void readMessage();
    void displayError(QAbstractSocket::SocketError);
    //////////////////////////////////////
    void processPendingDatagram();
    void processPendingDatagram1();
    void processPendingDatagram3();
    //////////////////////////////////////

private:
    Ui::Widget *ui;
    QTcpSocket *tcpSocket;
    int viped,nored,vip,nor,;
    ///////////////////////////
    QUdpSocket *receiver;
    QUdpSocket *receiver1;
    QUdpSocket *receiver3;
    /////////////////////////////
};

#endif // WIDGET_H
