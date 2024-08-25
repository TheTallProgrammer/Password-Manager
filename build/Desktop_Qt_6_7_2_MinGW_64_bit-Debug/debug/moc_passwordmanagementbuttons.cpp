/****************************************************************************
** Meta object code from reading C++ file 'passwordmanagementbuttons.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../passwordmanagementbuttons.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'passwordmanagementbuttons.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSpasswordManagementButtonsENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSpasswordManagementButtonsENDCLASS = QtMocHelpers::stringData(
    "passwordManagementButtons",
    "updateTheme",
    "",
    "selectedTheme",
    "on_genPass_clicked",
    "onResetCanceled",
    "on_resetLoginButton_clicked",
    "on_logoutButton_clicked",
    "on_storePass_clicked",
    "handleRequestGenPassword",
    "handleBackStorePassword",
    "handleBackRetrievePassword",
    "on_retrievePass_clicked",
    "on_deleteAllButton_clicked",
    "on_exportPassButton_clicked",
    "onThemeTextChanged",
    "text"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSpasswordManagementButtonsENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   95,    2, 0x08,    3 /* Private */,
       5,    0,   96,    2, 0x08,    4 /* Private */,
       6,    0,   97,    2, 0x08,    5 /* Private */,
       7,    0,   98,    2, 0x08,    6 /* Private */,
       8,    0,   99,    2, 0x08,    7 /* Private */,
       9,    0,  100,    2, 0x08,    8 /* Private */,
      10,    0,  101,    2, 0x08,    9 /* Private */,
      11,    0,  102,    2, 0x08,   10 /* Private */,
      12,    0,  103,    2, 0x08,   11 /* Private */,
      13,    0,  104,    2, 0x08,   12 /* Private */,
      14,    0,  105,    2, 0x08,   13 /* Private */,
      15,    1,  106,    2, 0x0a,   14 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

Q_CONSTINIT const QMetaObject passwordManagementButtons::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSpasswordManagementButtonsENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSpasswordManagementButtonsENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSpasswordManagementButtonsENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<passwordManagementButtons, std::true_type>,
        // method 'updateTheme'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_genPass_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onResetCanceled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_resetLoginButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_logoutButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_storePass_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleRequestGenPassword'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleBackStorePassword'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleBackRetrievePassword'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_retrievePass_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deleteAllButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_exportPassButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onThemeTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void passwordManagementButtons::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<passwordManagementButtons *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateTheme((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->on_genPass_clicked(); break;
        case 2: _t->onResetCanceled(); break;
        case 3: _t->on_resetLoginButton_clicked(); break;
        case 4: _t->on_logoutButton_clicked(); break;
        case 5: _t->on_storePass_clicked(); break;
        case 6: _t->handleRequestGenPassword(); break;
        case 7: _t->handleBackStorePassword(); break;
        case 8: _t->handleBackRetrievePassword(); break;
        case 9: _t->on_retrievePass_clicked(); break;
        case 10: _t->on_deleteAllButton_clicked(); break;
        case 11: _t->on_exportPassButton_clicked(); break;
        case 12: _t->onThemeTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (passwordManagementButtons::*)(QString );
            if (_t _q_method = &passwordManagementButtons::updateTheme; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *passwordManagementButtons::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *passwordManagementButtons::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSpasswordManagementButtonsENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int passwordManagementButtons::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void passwordManagementButtons::updateTheme(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
