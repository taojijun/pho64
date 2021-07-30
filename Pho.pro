#-------------------------------------------------
#
# Project created by QtCreator 2020-11-16T09:30:47
#
#-------------------------------------------------

QT += core gui network serialport testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pho
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
RC_FILE += icon.rc
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialog.cpp \
    form___.cpp \
    config.cpp

HEADERS += \
        mainwindow.h \
    inc/STDCALL/tmControlClient.h \
    inc/STDCALL/tmMpegCodeID.h \
    inc/STDCALL/tmTransDefine.h \
    dialog.h \
    form___.h \
    time.h \
    config.h

FORMS += \
        mainwindow.ui \
    dialog.ui \
    form___.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/STDCALL -ltmControlClient
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/STDCALL -ltmControlClientd
else:unix: LIBS += -L$$PWD/lib/STDCALL -ltmControlClient

INCLUDEPATH += $$PWD/inc/STDCALL
DEPENDPATH += $$PWD/lib/STDCALL

RESOURCES += \
    image.qrc

DISTFILES += \
    icon.rc


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/ -lopencv_world450
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/ -lopencv_world450d
else:unix: LIBS += -L$$PWD/libs/ -lopencv_world450

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/libs
