QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    booking.cpp \
    car.cpp \
    client.cpp \
    company.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    motorcycle.cpp \
    person.cpp \
    vehicle.cpp \
    worker.cpp \
    zarezerwowany.cpp \
    staf.cpp

HEADERS += \
    booking.h \
    car.h \
    client.h \
    company.h \
    login.h \
    mainwindow.h \
    motorcycle.h \
    person.h \
    vehicle.h \
    worker.h \
    zarezerwowany.h \
    staf.h

FORMS += \
    booking.ui \
    login.ui \
    mainwindow.ui \
    worker.ui \
    zarezerwowany.ui

TRANSLATIONS += \
    Car_rental_pl_PL.ts
CONFIG += lrelease
CONFIG += embed_translations


