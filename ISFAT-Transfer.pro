#-------------------------------------------------
#
# Project created by QtCreator 2016-09-28T09:16:39
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ISFAT-Transfer
TEMPLATE = app

SOURCES += main.cpp \
    MainWindow.cpp \
    ContactButton.cpp \
    smtp.cpp \
    ConfigSmtp.cpp

HEADERS  += \
    MainWindow.h \
    ContactButton.h \
    smtp.h \
    ConfigSmtp.h

FORMS    +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/C:/OpenSSL-Win32/lib/ -llibssl

INCLUDEPATH += $$PWD/C:/OpenSSL-Win32/include
DEPENDPATH += $$PWD/C:/OpenSSL-Win32/include
