/****************************************************************************
** Meta object code from reading C++ file 'wdialog.h'
**
** Created: Mon Jul 18 00:25:20 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "wdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_wdialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      22,    8,    8,    8, 0x08,
      36,    8,    8,    8, 0x08,
      79,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_wdialog[] = {
    "wdialog\0\0newConnect()\0readMessage()\0"
    "displayError(QAbstractSocket::SocketError)\0"
    "on_pushButton_clicked()\0"
};

const QMetaObject wdialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_wdialog,
      qt_meta_data_wdialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &wdialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *wdialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *wdialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_wdialog))
        return static_cast<void*>(const_cast< wdialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int wdialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newConnect(); break;
        case 1: readMessage(); break;
        case 2: displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 3: on_pushButton_clicked(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
