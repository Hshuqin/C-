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
     void newConnect();
    ~Widget();

private:
    Ui::Widget *ui;
    int id1,id2;
    QTcpSocket *tcpSocket;
    QTcpServer *tcpServer;
    quint16 blockSize;
private slots:
    void timeupdate();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void readMessage();
    void sendmessage();



protected:
    void timerEvent(QTimerEvent *);
};

#endif // WIDGET_H
