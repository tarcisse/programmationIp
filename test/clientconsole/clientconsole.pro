#-------------------------------------------------
#
# Project created by QtCreator 2015-01-06T10:54:02
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = clientconsole
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    client.cpp

unix|win32: LIBS += -lwsock32

HEADERS += \
    client.h
