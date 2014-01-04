TEMPLATE = app
TARGET = clepsydra
FORMS  = ui/main.ui ui/grant.ui ui/limits.ui ui/status.ui

QT += dbus

RCC_DIR = tmp
OBJECTS_DIR = tmp
MOC_DIR = tmp

HEADERS += users.h

SOURCES += \
    main.cpp \
    users.cpp
