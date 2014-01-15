TEMPLATE = app
TARGET = clepsydra
FORMS  = ui/main.ui ui/grant.ui ui/limits.ui ui/status.ui

QT += dbus

RCC_DIR = tmp
OBJECTS_DIR = tmp
MOC_DIR = tmp

HEADERS += \
    accounts.h \
    user.h \
    mainwindow.h

SOURCES += \
    main.cpp \
    accounts.cpp \
    user.cpp \
    mainwindow.cpp
