#-------------------------------------------------
#
# Project created by QtCreator 2019-06-12T19:14:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = emptydirdel
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

RC_ICONS = "main.ico"
QMAKE_TARGET_DESCRIPTION = "空目录删除"
QMAKE_TARGET_COMPANY = "wujian"
QMAKE_TARGET_PRODUCT = "空目录删除助手"

