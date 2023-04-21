/****************************************************************************
** Meta object code from reading C++ file 'plotwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ploproject_day4/plotwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plotwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_PlotWindow_t {
    uint offsetsAndSizes[22];
    char stringdata0[11];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[9];
    char stringdata5[18];
    char stringdata6[7];
    char stringdata7[2];
    char stringdata8[24];
    char stringdata9[16];
    char stringdata10[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_PlotWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_PlotWindow_t qt_meta_stringdata_PlotWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "PlotWindow"
        QT_MOC_LITERAL(11, 23),  // "on_randomButton_clicked"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 8),  // "AddPoint"
        QT_MOC_LITERAL(45, 8),  // "SlotTest"
        QT_MOC_LITERAL(54, 17),  // "PointSelectedSlot"
        QT_MOC_LITERAL(72, 6),  // "Point*"
        QT_MOC_LITERAL(79, 1),  // "p"
        QT_MOC_LITERAL(81, 23),  // "on_deletePoints_clicked"
        QT_MOC_LITERAL(105, 15),  // "DeletePointSlot"
        QT_MOC_LITERAL(121, 12)   // "DrawLineSlot"
    },
    "PlotWindow",
    "on_randomButton_clicked",
    "",
    "AddPoint",
    "SlotTest",
    "PointSelectedSlot",
    "Point*",
    "p",
    "on_deletePoints_clicked",
    "DeletePointSlot",
    "DrawLineSlot"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_PlotWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    1,   59,    2, 0x08,    4 /* Private */,
       8,    0,   62,    2, 0x08,    6 /* Private */,
       9,    1,   63,    2, 0x08,    7 /* Private */,
      10,    1,   66,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject PlotWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_PlotWindow.offsetsAndSizes,
    qt_meta_data_PlotWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_PlotWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PlotWindow, std::true_type>,
        // method 'on_randomButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'AddPoint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SlotTest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'PointSelectedSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Point *, std::false_type>,
        // method 'on_deletePoints_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DeletePointSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Point *, std::false_type>,
        // method 'DrawLineSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Point *, std::false_type>
    >,
    nullptr
} };

void PlotWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlotWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_randomButton_clicked(); break;
        case 1: _t->AddPoint(); break;
        case 2: _t->SlotTest(); break;
        case 3: _t->PointSelectedSlot((*reinterpret_cast< std::add_pointer_t<Point*>>(_a[1]))); break;
        case 4: _t->on_deletePoints_clicked(); break;
        case 5: _t->DeletePointSlot((*reinterpret_cast< std::add_pointer_t<Point*>>(_a[1]))); break;
        case 6: _t->DrawLineSlot((*reinterpret_cast< std::add_pointer_t<Point*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Point* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Point* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Point* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *PlotWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlotWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlotWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PlotWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
