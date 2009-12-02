# -------------------------------------------------
# Project created by QtCreator 2009-11-28T18:23:33
# -------------------------------------------------
TARGET = Bonsai
TEMPLATE = app
SOURCES += main.cpp \
    principal.cpp \
    sqlquery.cpp \
    parser.cpp
HEADERS += principal.h \
    sqlquery.h \
    parser.h \
    SQLParser.h
FORMS += principal.ui
RESOURCES += resources.qrc
macx:INCLUDEPATH += resources/libs-mac/10.5/include/yaml-cpp
macx:LIBS += -Lresources/libs-mac/10.5/lib \
    -lyaml-cpp
macx:ICON = resources/images/bonsai.icns
