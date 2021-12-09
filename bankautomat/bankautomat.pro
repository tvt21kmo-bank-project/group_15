QT       += core gui
QT +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    datab.cpp \
    main.cpp \
    mainwindow.cpp \
    muusumma.cpp \
    naytasaldo.cpp \
    nostarahaa.cpp \
    selaatapahtumia.cpp \
    valikko.cpp

HEADERS += \
    datab.h \
    mainwindow.h \
    muusumma.h \
    naytasaldo.h \
    nostarahaa.h \
    selaatapahtumia.h \
    valikko.h

FORMS += \
    datab.ui \
    mainwindow.ui \
    muusumma.ui \
    naytasaldo.ui \
    nostarahaa.ui \
    selaatapahtumia.ui \
    valikko.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
