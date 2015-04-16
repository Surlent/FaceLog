#-------------------------------------------------#
#                                                 #
# Project created by QtCreator 2013-11-22T08:29:36#
#                                                 #
#-------------------------------------------------#

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XX
TEMPLATE = app




SOURCES += main.cpp\
        mainwindow.cpp \
    config.cpp

HEADERS  += mainwindow.h \
    config.h

FORMS    += mainwindow.ui \
    config.ui


RESOURCES += \
    imgs.qrc \
    files.qrc

OTHER_FILES += \
    file/log.txt

