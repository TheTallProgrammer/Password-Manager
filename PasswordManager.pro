QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += network
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cryptoutils.cpp \
    editpassworddata.cpp \
    main.cpp \
    mainwindow.cpp \
    passwordgenerator.cpp \
    passwordmanagementbuttons.cpp \
    resetpassword.cpp \
    retrievepassword.cpp \
    storepassword.cpp \
    transferdata.cpp

HEADERS += \
    cryptoutils.h \
    editpassworddata.h \
    mainwindow.h \
    passwordgenerator.h \
    passwordmanagementbuttons.h \
    resetpassword.h \
    retrievepassword.h \
    storepassword.h \
    transferdata.h

FORMS += \
    editpassworddata.ui \
    mainwindow.ui \
    passwordgenerator.ui \
    passwordmanagementbuttons.ui \
    resetpassword.ui \
    retrievepassword.ui \
    storepassword.ui \
    transferdata.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
