#include <QtGui/QApplication>
#include "widget.h"
#include <mydialog.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    mydialog dl;

    dl.show();
    if(dl.exec()==QDialog::Accepted)
        {
            w.show();
            return a.exec();
        }

        else
            return 0;


    }
