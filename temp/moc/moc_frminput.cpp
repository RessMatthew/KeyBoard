/****************************************************************************
** Meta object code from reading C++ file 'frminput.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../frminput.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frminput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmInput_t {
    QByteArrayData data[20];
    char stringdata0[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmInput_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmInput_t qt_meta_stringdata_frmInput = {
    {
QT_MOC_LITERAL(0, 0, 8), // "frmInput"
QT_MOC_LITERAL(1, 9, 12), // "focusChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "QWidget*"
QT_MOC_LITERAL(4, 32, 9), // "oldWidget"
QT_MOC_LITERAL(5, 42, 9), // "nowWidget"
QT_MOC_LITERAL(6, 52, 11), // "btn_clicked"
QT_MOC_LITERAL(7, 64, 11), // "changeStyle"
QT_MOC_LITERAL(8, 76, 8), // "topColor"
QT_MOC_LITERAL(9, 85, 11), // "bottomColor"
QT_MOC_LITERAL(10, 97, 11), // "borderColor"
QT_MOC_LITERAL(11, 109, 9), // "textColor"
QT_MOC_LITERAL(12, 119, 9), // "reClicked"
QT_MOC_LITERAL(13, 129, 19), // "on_btnStyle_clicked"
QT_MOC_LITERAL(14, 149, 21), // "on_btnStyle_2_clicked"
QT_MOC_LITERAL(15, 171, 27), // "on_SPEECHpushButton_pressed"
QT_MOC_LITERAL(16, 199, 28), // "on_SPEECHpushButton_released"
QT_MOC_LITERAL(17, 228, 11), // "receiveData"
QT_MOC_LITERAL(18, 240, 4), // "data"
QT_MOC_LITERAL(19, 245, 19) // "on_pushHand_clicked"

    },
    "frmInput\0focusChanged\0\0QWidget*\0"
    "oldWidget\0nowWidget\0btn_clicked\0"
    "changeStyle\0topColor\0bottomColor\0"
    "borderColor\0textColor\0reClicked\0"
    "on_btnStyle_clicked\0on_btnStyle_2_clicked\0"
    "on_SPEECHpushButton_pressed\0"
    "on_SPEECHpushButton_released\0receiveData\0"
    "data\0on_pushHand_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmInput[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    4,   70,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,
      13,    0,   80,    2, 0x08 /* Private */,
      14,    0,   81,    2, 0x08 /* Private */,
      15,    0,   82,    2, 0x08 /* Private */,
      16,    0,   83,    2, 0x08 /* Private */,
      17,    1,   84,    2, 0x08 /* Private */,
      19,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    9,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,

       0        // eod
};

void frmInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        frmInput *_t = static_cast<frmInput *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->focusChanged((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 1: _t->btn_clicked(); break;
        case 2: _t->changeStyle((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 3: _t->reClicked(); break;
        case 4: _t->on_btnStyle_clicked(); break;
        case 5: _t->on_btnStyle_2_clicked(); break;
        case 6: _t->on_SPEECHpushButton_pressed(); break;
        case 7: _t->on_SPEECHpushButton_released(); break;
        case 8: _t->receiveData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->on_pushHand_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject frmInput::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_frmInput.data,
      qt_meta_data_frmInput,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *frmInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmInput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmInput.stringdata0))
        return static_cast<void*>(const_cast< frmInput*>(this));
    return QWidget::qt_metacast(_clname);
}

int frmInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
