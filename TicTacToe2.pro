#-------------------------------------------------
#
# Project created by QtCreator 2018-06-30T13:49:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TicTacToe2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    utlls.cpp \
    player.cpp

HEADERS  += mainwindow.h \
    player.h \
    game.h \
    utlls.h

FORMS    += mainwindow.ui
