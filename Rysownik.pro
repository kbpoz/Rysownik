TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    interfejs.cpp \
    listy.cpp \
    pliki.cpp \
    sortowanie.cpp \
    sprawdzenia.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    interfejs.h \
    listy.h \
    pliki.h \
    sortowanie.h \
    sprawdzenia.h \
    struktury.h

