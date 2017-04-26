/********************************************************************************
** Form generated from reading UI file 'wdialog.ui'
**
** Created: Sun Jul 17 23:07:22 2016
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WDIALOG_H
#define UI_WDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_wdialog
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *wdialog)
    {
        if (wdialog->objectName().isEmpty())
            wdialog->setObjectName(QString::fromUtf8("wdialog"));
        wdialog->resize(205, 133);
        wdialog->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        pushButton = new QPushButton(wdialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 20, 98, 41));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/QtRes/back.jpg);\n"
"font: 63 oblique 16pt \"URW Gothic L\";"));
        label = new QLabel(wdialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 80, 151, 31));
        label->setStyleSheet(QString::fromUtf8(""));
        label->raise();
        pushButton->raise();

        retranslateUi(wdialog);

        QMetaObject::connectSlotsByName(wdialog);
    } // setupUi

    void retranslateUi(QDialog *wdialog)
    {
        wdialog->setWindowTitle(QApplication::translate("wdialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("wdialog", "\345\217\253\345\217\267", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class wdialog: public Ui_wdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WDIALOG_H
