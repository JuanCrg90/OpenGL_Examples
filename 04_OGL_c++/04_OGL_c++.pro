TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    figures.cpp

HEADERS += \
    figures.h

win32: LIBS += -lglut32 -lopengl32
else:unix: LIBS += -lGL -lglut
