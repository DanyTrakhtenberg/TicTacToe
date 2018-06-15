#-------------------------------------------------
#
# Project created by QtCreator 2015-02-22T16:59:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TicTacToe
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    player.cpp \
    utlls.cpp

HEADERS  += mainwindow.h \
    game.h \
    player.h \
    utlls.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
