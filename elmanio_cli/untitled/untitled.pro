TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    box.cpp \
    game.cpp \
    field.cpp \
    boxbomb.cpp \
    ui_cli.cpp

HEADERS += \
    box.h \
    game.h \
    boxes.h \
    field.h \
    boxbomb.h \
    ui_cli.h
