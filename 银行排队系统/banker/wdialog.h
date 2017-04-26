#ifndef WDIALOG_H
#define WDIALOG_H
#include <QtNetwork>
#include <QDialog>

namespace Ui {
class wdialog;
}

class wdialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit wdialog(QWidget *parent = 0);
    ~wdialog();
    
private slots:
    void newConnect();
    void readMessage();
    void displayError(QAbstractSocket::SocketError);
    void on_pushButton_clicked();

private:
    Ui::wdialog *ui;
    QTcpSocket *tcpSocket;
    int x;
protected:
    //////////////////////////////
    QUdpSocket *sender2;
    ////////////////////////
};

#endif // WDIALOG_H
