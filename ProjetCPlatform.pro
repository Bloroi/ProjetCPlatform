#-------------------------------------------------
#
# Project created by QtCreator 2017-11-09T15:16:20
#
#-------------------------------------------------

QT       += core gui

CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetCPlatform
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
        main.cpp \
    animation.cpp \
    player.cpp \
    collider.cpp \
    platform.cpp \
    functions.cpp \
    enemy.cpp \
    projectile.cpp \
    panel.cpp \
    psettings.cpp \
    button.cpp \
    pgame.cpp \
    plevel.cpp \
    pmenus.cpp \
    pwelcome.cpp \
    pabout.cpp \
    item.cpp\
    soundengine.cpp

HEADERS += \
    animation.h \
    player.h \
    collider.h \
    platform.h \
    functions.h \
    item.h \
    enemy.h \
    projectile.h \
    panel.h \
    psettings.h \
    button.h \
    pgame.h \
    plevel.h \
    pmenus.h \
    pwelcome.h \
    pabout.h \
    soundengine.h


FORMS += \


INCLUDEPATH += C:\Librairies\SFML\SFML-2.4.2\include
DEPENDPATH+= C:\Librairies\SFML\SFML-2.4.2\include

LIBS += -LC:\Librairies\SFML\TestSFML\LIBS\

CONFIG(debug,debug|release): LIBS += -lsfml-audio-d -lsfml-system-d -lsfml-network-d -lsfml-main-d -lsfml-window-d -lsfml-graphics-d
CONFIG(release,debug|release): LIBS += -lsfml-audio -lsfml-system -lsfml-network -lsfml-main -lsfml-window -lsfml-graphics

