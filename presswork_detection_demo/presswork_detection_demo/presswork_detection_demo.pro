#-------------------------------------------------
#
# Project created by QtCreator 2018-04-16T09:22:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = presswork_detection_demo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    icthread.cpp

HEADERS += \
        mainwindow.h \
    icthread.h

FORMS += \
        mainwindow.ui

#头文件路径包含

INCLUDEPATH += G:/HALCON/include

INCLUDEPATH += G:/HALCON/include/halconcpp

#lib文件路径包含

LIBS += G:/HALCON/lib/x64-win64/halcon.lib

LIBS += G:/HALCON/lib/x64-win64/halconcpp.lib
