# -------------------------------------------------
# Project created by QtCreator 2009-11-28T18:23:33
# -------------------------------------------------
TARGET = yquery
TEMPLATE = app
SOURCES += main.cpp \
    principal.cpp
HEADERS += principal.h
FORMS += principal.ui
RESOURCES += resources.qrc
INCLUDEPATH += ./resources/libs-mac/10.5/include/yaml-cpp
LIBS += -L./resources/libs-mac/10.5/lib -lyaml-cpp
