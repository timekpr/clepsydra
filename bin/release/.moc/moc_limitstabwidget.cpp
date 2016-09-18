/****************************************************************************
** Meta object code from reading C++ file 'limitstabwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../app/limitstabwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'limitstabwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LimitsTabWidget_t {
    QByteArrayData data[9];
    char stringdata0[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LimitsTabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LimitsTabWidget_t qt_meta_stringdata_LimitsTabWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "LimitsTabWidget"
QT_MOC_LITERAL(1, 16, 15), // "disableControls"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 32), // "ckLimitAccessTimeDurationChanged"
QT_MOC_LITERAL(4, 66, 29), // "ckLimitAccessTimeFrameChanged"
QT_MOC_LITERAL(5, 96, 40), // "chkLimitAccessTimeDurationEac..."
QT_MOC_LITERAL(6, 137, 38), // "ckLimitAccessDurationPerEachD..."
QT_MOC_LITERAL(7, 176, 36), // "ckLimitAccessTimeFrameEachDay..."
QT_MOC_LITERAL(8, 213, 35) // "chLimitAccessTimeFramePerDayC..."

    },
    "LimitsTabWidget\0disableControls\0\0"
    "ckLimitAccessTimeDurationChanged\0"
    "ckLimitAccessTimeFrameChanged\0"
    "chkLimitAccessTimeDurationEachDayChanged\0"
    "ckLimitAccessDurationPerEachDayChanged\0"
    "ckLimitAccessTimeFrameEachDayChanged\0"
    "chLimitAccessTimeFramePerDayChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LimitsTabWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       3,    1,   52,    2, 0x0a /* Public */,
       4,    1,   55,    2, 0x0a /* Public */,
       5,    1,   58,    2, 0x0a /* Public */,
       6,    1,   61,    2, 0x0a /* Public */,
       7,    1,   64,    2, 0x0a /* Public */,
       8,    1,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void LimitsTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LimitsTabWidget *_t = static_cast<LimitsTabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->disableControls((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->ckLimitAccessTimeDurationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ckLimitAccessTimeFrameChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->chkLimitAccessTimeDurationEachDayChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->ckLimitAccessDurationPerEachDayChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->ckLimitAccessTimeFrameEachDayChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->chLimitAccessTimeFramePerDayChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject LimitsTabWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LimitsTabWidget.data,
      qt_meta_data_LimitsTabWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LimitsTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LimitsTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LimitsTabWidget.stringdata0))
        return static_cast<void*>(const_cast< LimitsTabWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int LimitsTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
