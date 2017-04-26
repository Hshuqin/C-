#include "mydialog.h"
#include "ui_mydialog.h"
#include <QMessageBox>
#include <QTextCodec>
#include<QLabel>
#include <wdialog.h>

mydialog::mydialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mydialog)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Login"));
    this->setFixedSize( this->width (),this->height ()); //固定大小
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    this->setAttribute(Qt::WA_TranslucentBackground);// 背景透明

}

mydialog::~mydialog()
{
    delete ui;
}

void mydialog::on_pushButton_clicked()
{
    if(ui->lineEdit->text()==tr("qt")&&ui->lineEdit_2->text()==tr("1234"))                    //用户名和密码判断
    {
        close();
        accept();
    }
    else if(ui->lineEdit->text()==tr("worker1")&&ui->lineEdit_2->text()==tr("001"))
    {
            close();
            wdialog wd;
            wd.show();
            wd.exec();

    }
    else
        {
            QMessageBox::warning(this,tr("Warning"),("user name or password wrong!"),QMessageBox::Yes);    //警告对话框
            ui->lineEdit->clear();                      //清除用户名
            ui->lineEdit_2->clear();                 //清除密码
            ui->lineEdit->setFocus();              //鼠标回到用户名栏
        }
}

