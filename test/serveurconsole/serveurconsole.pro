#-------------------------------------------------
#
# Project created by QtCreator 2015-01-05T00:42:21
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = serveurconsole
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    serveur.cpp

unix|win32: LIBS += -lwsock32

HEADERS += \
    serveur.h
