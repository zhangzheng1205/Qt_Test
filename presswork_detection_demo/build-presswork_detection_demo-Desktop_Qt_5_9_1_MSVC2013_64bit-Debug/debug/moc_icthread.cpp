/****************************************************************************
** Meta object code from reading C++ file 'icthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../presswork_detection_demo/icthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'icthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IcThread_t {
    QByteArrayData data[7];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IcThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IcThread_t qt_meta_stringdata_IcThread = {
    {
QT_MOC_LITERAL(0, 0, 8), // "IcThread"
QT_MOC_LITERAL(1, 9, 17), // "signal_send_image"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "HObject"
QT_MOC_LITERAL(4, 36, 19), // "signal_create_model"
QT_MOC_LITERAL(5, 56, 19), // "signal_detect_image"
QT_MOC_LITERAL(6, 76, 18) // "signal_open_Camera"

    },
    "IcThread\0signal_send_image\0\0HObject\0"
    "signal_create_model\0signal_detect_image\0"
    "signal_open_Camera"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IcThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       5,    1,   40,    2, 0x06 /* Public */,
       6,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void IcThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IcThread *_t = static_cast<IcThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_send_image((*reinterpret_cast< HObject(*)>(_a[1]))); break;
        case 1: _t->signal_create_model((*reinterpret_cast< HObject(*)>(_a[1]))); break;
        case 2: _t->signal_detect_image((*reinterpret_cast< HObject(*)>(_a[1]))); break;
        case 3: _t->signal_open_Camera((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IcThread::*_t)(HObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IcThread::signal_send_image)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (IcThread::*_t)(HObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IcThread::signal_create_model)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (IcThread::*_t)(HObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IcThread::signal_detect_image)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (IcThread::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IcThread::signal_open_Camera)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject IcThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_IcThread.data,
      qt_meta_data_IcThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *IcThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IcThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IcThread.stringdata0))
        return static_cast<void*>(const_cast< IcThread*>(this));
    return QThread::qt_metacast(_clname);
}

int IcThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void IcThread::signal_send_image(HObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IcThread::signal_create_model(HObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void IcThread::signal_detect_image(HObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IcThread::signal_open_Camera(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
