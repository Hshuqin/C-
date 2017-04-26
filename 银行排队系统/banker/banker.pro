#-------------------------------------------------
#
# Project created by QtCreator 2016-07-16T20:05:53
#
#-------------------------------------------------

QT       += core gui
QT        +=network

TARGET = banker
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mydialog.cpp \
    wdialog.cpp

HEADERS  += widget.h \
    mydialog.h \
    wdialog.h

FORMS    += widget.ui \
    mydialog.ui \
    wdialog.ui

OTHER_FILES +=

RESOURCES += \
    resource.qrc
