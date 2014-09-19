TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c

win32: LIBS += -lglut32 -lopengl32
else:unix: LIBS += -lGL -lglut
