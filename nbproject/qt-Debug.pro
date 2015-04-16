# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = FaceLog_Qt
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += link_pkgconfig debug 
PKGCONFIG += opencv
QT = core gui widgets
SOURCES += FaceLog.cpp LogMaker.cpp config.cpp main.cpp mainwindow.cpp
HEADERS += FaceLog.h LogMaker.h config.h generic.h mainwindow.h ui_mainwindow.h
FORMS += config.ui mainwindow.ui
RESOURCES += files.qrc imgs.qrc
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
