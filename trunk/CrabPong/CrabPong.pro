#-------------------------------------------------
#
# Project created by QtCreator 2014-04-03T14:11:38
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CrabPong
TEMPLATE = app


SOURCES += main.cpp\
        myframe.cpp \
    viewport.cpp \
    text3d.cpp \
    vec3f.cpp \
    game.cpp \
    gamedrawer.cpp \
    md2model.cpp \
    imageloader.cpp \
    glm.cpp

HEADERS  += myframe.h \
    viewport.h \
    text3d.h \
    game.h \
    gamedrawer.h \
    imageloader.h \
    vec3f.h \
    md2model.h \
    glm.h

RESOURCES += \
    Resources.qrc

OTHER_FILES += \
    content/Ball.obj \
    content/charset \
    content/crab.md2 \
    content/crab1.bmp \
    content/crab2.bmp \
    content/crab3.bmp \
    content/crab4.bmp \
    content/sand.bmp \
    content/vtr.bmp \
    content/water.bmp \
    content/Ball.mtl
