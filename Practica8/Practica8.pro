# -------------------------------------------------
# Project created by QtCreator 2009-11-24T00:42:51
# -------------------------------------------------
QT -= core \
    gui
TARGET = Practica8
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    alumno.cpp
HEADERS += BSTree \
    alumno.h
INCLUDEPATH += /Users/Emmanuel/bin/include/yaml-cpp
LIBS += -L/Users/emmanuel/bin/lib -lyaml-cpp
