/****************************************************************************
** Meta object code from reading C++ file 'limitstabwidget.h'
**
** Created: Wed Mar 12 22:59:04 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../limitstabwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'limitstabwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LimitsTabWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      39,   16,   16,   16, 0x0a,
      64,   16,   16,   16, 0x0a,
      97,   89,   16,   16, 0x0a,
     125,   89,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LimitsTabWidget[] = {
    "LimitsTabWidget\0\0disableControls(bool)\0"
    "ckLimitStateChanged(int)\0"
    "ckBoundStateChanged(int)\0checked\0"
    "ckLimitDayStateChanged(int)\0"
    "ckBoundDayStateChanged(int)\0"
};

void LimitsTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LimitsTabWidget *_t = static_cast<LimitsTabWidget *>(_o);
        switch (_id) {
        case 0: _t->disableControls((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->ckLimitStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ckBoundStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ckLimitDayStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->ckBoundDayStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LimitsTabWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LimitsTabWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LimitsTabWidget,
      qt_meta_data_LimitsTabWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LimitsTabWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LimitsTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LimitsTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LimitsTabWidget))
        return static_cast<void*>(const_cast< LimitsTabWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int LimitsTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
