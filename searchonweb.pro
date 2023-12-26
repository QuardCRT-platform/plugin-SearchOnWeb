TEMPLATE = lib
CONFIG += plugin
QT += core widgets

INCLUDEPATH += $$PWD/plugininterface \
        $$PWD
HEADERS = plugininterface/plugininterface.h \
        searchonweb.h
SOURCES = plugininterface/plugininterface.cpp \
        searchonweb.cpp

TARGET = $$qtLibraryTarget(searchonweb)

unix:{
    QMAKE_RPATHDIR=$ORIGIN
}
