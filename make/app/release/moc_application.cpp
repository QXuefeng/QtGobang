/****************************************************************************
** Meta object code from reading C++ file 'application.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../app/application.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'application.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Application_t {
    QByteArrayData data[13];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Application_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Application_t qt_meta_stringdata_Application = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Application"
QT_MOC_LITERAL(1, 12, 7), // "onStart"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "onClickFinish"
QT_MOC_LITERAL(4, 35, 7), // "index_t"
QT_MOC_LITERAL(5, 43, 4), // "next"
QT_MOC_LITERAL(6, 48, 5), // "COLOR"
QT_MOC_LITERAL(7, 54, 5), // "color"
QT_MOC_LITERAL(8, 60, 4), // "prev"
QT_MOC_LITERAL(9, 65, 16), // "onRollbackFinish"
QT_MOC_LITERAL(10, 82, 9), // "onVictory"
QT_MOC_LITERAL(11, 92, 13), // "onChoiceModel"
QT_MOC_LITERAL(12, 106, 5) // "model"

    },
    "Application\0onStart\0\0onClickFinish\0"
    "index_t\0next\0COLOR\0color\0prev\0"
    "onRollbackFinish\0onVictory\0onChoiceModel\0"
    "model"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Application[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    3,   40,    2, 0x08 /* Private */,
       9,    2,   47,    2, 0x08 /* Private */,
      10,    1,   52,    2, 0x08 /* Private */,
      11,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 4,    5,    7,    8,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    8,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void Application::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Application *_t = static_cast<Application *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onStart(); break;
        case 1: _t->onClickFinish((*reinterpret_cast< index_t(*)>(_a[1])),(*reinterpret_cast< COLOR(*)>(_a[2])),(*reinterpret_cast< index_t(*)>(_a[3]))); break;
        case 2: _t->onRollbackFinish((*reinterpret_cast< index_t(*)>(_a[1])),(*reinterpret_cast< index_t(*)>(_a[2]))); break;
        case 3: _t->onVictory((*reinterpret_cast< COLOR(*)>(_a[1]))); break;
        case 4: _t->onChoiceModel((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Application::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Application.data,
      qt_meta_data_Application,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Application::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Application::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Application.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Application::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
