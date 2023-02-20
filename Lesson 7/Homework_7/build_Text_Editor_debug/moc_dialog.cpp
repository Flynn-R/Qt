/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Text_Editor/dialog.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_Dialog_t {
    uint offsetsAndSizes[28];
    char stringdata0[7];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[33];
    char stringdata4[17];
    char stringdata5[14];
    char stringdata6[28];
    char stringdata7[27];
    char stringdata8[27];
    char stringdata9[27];
    char stringdata10[26];
    char stringdata11[22];
    char stringdata12[22];
    char stringdata13[31];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Dialog_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
        QT_MOC_LITERAL(0, 6),  // "Dialog"
        QT_MOC_LITERAL(7, 13),  // "hotkeyChanged"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 32),  // "QMap<const QString,QKeySequence>"
        QT_MOC_LITERAL(55, 16),  // "languageSelected"
        QT_MOC_LITERAL(72, 13),  // "themeSelected"
        QT_MOC_LITERAL(86, 27),  // "on_closeSeq_editingFinished"
        QT_MOC_LITERAL(114, 26),  // "on_saveSeq_editingFinished"
        QT_MOC_LITERAL(141, 26),  // "on_openSeq_editingFinished"
        QT_MOC_LITERAL(168, 26),  // "on_helpSeq_editingFinished"
        QT_MOC_LITERAL(195, 25),  // "on_newSeq_editingFinished"
        QT_MOC_LITERAL(221, 21),  // "on_buttonBox_accepted"
        QT_MOC_LITERAL(243, 21),  // "on_buttonBox_rejected"
        QT_MOC_LITERAL(265, 30)   // "on_readOnlySeq_editingFinished"
    },
    "Dialog",
    "hotkeyChanged",
    "",
    "QMap<const QString,QKeySequence>",
    "languageSelected",
    "themeSelected",
    "on_closeSeq_editingFinished",
    "on_saveSeq_editingFinished",
    "on_openSeq_editingFinished",
    "on_helpSeq_editingFinished",
    "on_newSeq_editingFinished",
    "on_buttonBox_accepted",
    "on_buttonBox_rejected",
    "on_readOnlySeq_editingFinished"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Dialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,
       4,    1,   83,    2, 0x06,    3 /* Public */,
       5,    1,   86,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   89,    2, 0x08,    7 /* Private */,
       7,    0,   90,    2, 0x08,    8 /* Private */,
       8,    0,   91,    2, 0x08,    9 /* Private */,
       9,    0,   92,    2, 0x08,   10 /* Private */,
      10,    0,   93,    2, 0x08,   11 /* Private */,
      11,    0,   94,    2, 0x08,   12 /* Private */,
      12,    0,   95,    2, 0x08,   13 /* Private */,
      13,    0,   96,    2, 0x08,   14 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
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

Q_CONSTINIT const QMetaObject Dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dialog.offsetsAndSizes,
    qt_meta_data_Dialog,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Dialog_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Dialog, std::true_type>,
        // method 'hotkeyChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMap<const QString,QKeySequence>, std::false_type>,
        // method 'languageSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'themeSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_closeSeq_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_saveSeq_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_openSeq_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_helpSeq_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_newSeq_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_buttonBox_accepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_buttonBox_rejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_readOnlySeq_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->hotkeyChanged((*reinterpret_cast< std::add_pointer_t<QMap<const QString,QKeySequence>>>(_a[1]))); break;
        case 1: _t->languageSelected((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->themeSelected((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->on_closeSeq_editingFinished(); break;
        case 4: _t->on_saveSeq_editingFinished(); break;
        case 5: _t->on_openSeq_editingFinished(); break;
        case 6: _t->on_helpSeq_editingFinished(); break;
        case 7: _t->on_newSeq_editingFinished(); break;
        case 8: _t->on_buttonBox_accepted(); break;
        case 9: _t->on_buttonBox_rejected(); break;
        case 10: _t->on_readOnlySeq_editingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dialog::*)(QMap<const QString,QKeySequence> );
            if (_t _q_method = &Dialog::hotkeyChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(bool );
            if (_t _q_method = &Dialog::languageSelected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(bool );
            if (_t _q_method = &Dialog::themeSelected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Dialog::hotkeyChanged(QMap<const QString,QKeySequence> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dialog::languageSelected(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Dialog::themeSelected(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
