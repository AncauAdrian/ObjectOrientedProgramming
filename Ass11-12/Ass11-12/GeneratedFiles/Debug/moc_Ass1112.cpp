/****************************************************************************
** Meta object code from reading C++ file 'Ass1112.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Ass1112.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Ass1112.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Ass1112_t {
    QByteArrayData data[11];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ass1112_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ass1112_t qt_meta_stringdata_Ass1112 = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Ass1112"
QT_MOC_LITERAL(1, 8, 11), // "filter_list"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 3), // "add"
QT_MOC_LITERAL(4, 25, 6), // "remove"
QT_MOC_LITERAL(5, 32, 6), // "update"
QT_MOC_LITERAL(6, 39, 12), // "add_to_wlist"
QT_MOC_LITERAL(7, 52, 17), // "remove_from_wlist"
QT_MOC_LITERAL(8, 70, 4), // "save"
QT_MOC_LITERAL(9, 75, 8), // "view_all"
QT_MOC_LITERAL(10, 84, 10) // "view_wlist"

    },
    "Ass1112\0filter_list\0\0add\0remove\0update\0"
    "add_to_wlist\0remove_from_wlist\0save\0"
    "view_all\0view_wlist"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ass1112[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Ass1112::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Ass1112 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filter_list(); break;
        case 1: _t->add(); break;
        case 2: _t->remove(); break;
        case 3: _t->update(); break;
        case 4: _t->add_to_wlist(); break;
        case 5: _t->remove_from_wlist(); break;
        case 6: _t->save(); break;
        case 7: _t->view_all(); break;
        case 8: _t->view_wlist(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Ass1112::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Ass1112.data,
    qt_meta_data_Ass1112,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Ass1112::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ass1112::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Ass1112.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Ass1112::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
