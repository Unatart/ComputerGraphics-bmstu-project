/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "info_buttons"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "about"
QT_MOC_LITERAL(4, 31, 10), // "load_model"
QT_MOC_LITERAL(5, 42, 9), // "load_ship"
QT_MOC_LITERAL(6, 52, 12), // "create_model"
QT_MOC_LITERAL(7, 65, 11), // "create_ship"
QT_MOC_LITERAL(8, 77, 19), // "on_clearScr_clicked"
QT_MOC_LITERAL(9, 97, 16), // "on_model_toggled"
QT_MOC_LITERAL(10, 114, 7), // "checked"
QT_MOC_LITERAL(11, 122, 15), // "on_ship_toggled"
QT_MOC_LITERAL(12, 138, 17), // "on_camera_toggled"
QT_MOC_LITERAL(13, 156, 13), // "keyPressEvent"
QT_MOC_LITERAL(14, 170, 10), // "QKeyEvent*"
QT_MOC_LITERAL(15, 181, 11), // "drawZBuffer"
QT_MOC_LITERAL(16, 193, 20), // "rasterCompareAndDraw"
QT_MOC_LITERAL(17, 214, 18), // "std::vector<Point>"
QT_MOC_LITERAL(18, 233, 8) // "double**"

    },
    "MainWindow\0info_buttons\0\0about\0"
    "load_model\0load_ship\0create_model\0"
    "create_ship\0on_clearScr_clicked\0"
    "on_model_toggled\0checked\0on_ship_toggled\0"
    "on_camera_toggled\0keyPressEvent\0"
    "QKeyEvent*\0drawZBuffer\0rasterCompareAndDraw\0"
    "std::vector<Point>\0double**"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x0a /* Public */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    1,   86,    2, 0x08 /* Private */,
      11,    1,   89,    2, 0x08 /* Private */,
      12,    1,   92,    2, 0x08 /* Private */,
      13,    1,   95,    2, 0x08 /* Private */,
      15,    0,   98,    2, 0x08 /* Private */,
      16,    2,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 18,    2,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->info_buttons(); break;
        case 1: _t->about(); break;
        case 2: _t->load_model(); break;
        case 3: _t->load_ship(); break;
        case 4: _t->create_model(); break;
        case 5: _t->create_ship(); break;
        case 6: _t->on_clearScr_clicked(); break;
        case 7: _t->on_model_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_ship_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_camera_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 11: _t->drawZBuffer(); break;
        case 12: _t->rasterCompareAndDraw((*reinterpret_cast< std::vector<Point>(*)>(_a[1])),(*reinterpret_cast< double**(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE