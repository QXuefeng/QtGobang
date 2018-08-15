/****************************************************************************
** Meta object code from reading C++ file 'activity.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../app/activity/activity.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'activity.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Activity_t {
    QByteArrayData data[11];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Activity_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Activity_t qt_meta_stringdata_Activity = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Activity"
QT_MOC_LITERAL(1, 9, 11), // "clickFinish"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "index_t"
QT_MOC_LITERAL(4, 30, 5), // "COLOR"
QT_MOC_LITERAL(5, 36, 14), // "rollbackFinish"
QT_MOC_LITERAL(6, 51, 7), // "victory"
QT_MOC_LITERAL(7, 59, 8), // "rollback"
QT_MOC_LITERAL(8, 68, 1), // "n"
QT_MOC_LITERAL(9, 70, 10), // "clickBoard"
QT_MOC_LITERAL(10, 81, 5) // "index"

    },
    "Activity\0clickFinish\0\0index_t\0COLOR\0"
    "rollbackFinish\0victory\0rollback\0n\0"
    "clickBoard\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Activity[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,
       5,    2,   46,    2, 0x06 /* Public */,
       6,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   54,    2, 0x0a /* Public */,
       9,    1,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4, 0x80000000 | 3,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void Activity::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Activity *_t = static_cast<Activity *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clickFinish((*reinterpret_cast< index_t(*)>(_a[1])),(*reinterpret_cast< COLOR(*)>(_a[2])),(*reinterpret_cast< index_t(*)>(_a[3]))); break;
        case 1: _t->rollbackFinish((*reinterpret_cast< index_t(*)>(_a[1])),(*reinterpret_cast< index_t(*)>(_a[2]))); break;
        case 2: _t->victory((*reinterpret_cast< COLOR(*)>(_a[1]))); break;
        case 3: _t->rollback((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 4: _t->clickBoard((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Activity::*)(index_t , COLOR , index_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Activity::clickFinish)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Activity::*)(index_t , index_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Activity::rollbackFinish)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Activity::*)(COLOR );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Activity::victory)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Activity::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Activity.data,
      qt_meta_data_Activity,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Activity::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Activity::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Activity.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Activity::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void Activity::clickFinish(index_t _t1, COLOR _t2, index_t _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Activity::rollbackFinish(index_t _t1, index_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Activity::victory(COLOR _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
