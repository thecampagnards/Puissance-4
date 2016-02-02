#-------------------------------------------------
#
# Project created by QtCreator 2015-10-05T11:42:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = puissance4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    plateau.cpp \
    controleur.cpp

HEADERS  += mainwindow.h \
    plateau.h \
    controleur.h

FORMS    += mainwindow.ui
