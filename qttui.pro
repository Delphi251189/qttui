TEMPLATE        = app
QT              += gui widgets

DEFINES         += QTTUI_LIBRARY
CONFIG          += c++11

LIBS            += -lncursesw

SOURCES         += qttui.cpp \
    main.cpp \
    qtuiapplication.cpp \
    qtuiboxlayout.cpp \
    qtuibrush.cpp \
    qtuicombobox.cpp \
    qtuiconsolereader.cpp \
    qtuievent.cpp \
    qtuieventfilter.cpp \
    qtuigroupbox.cpp \
    qtuilayout.cpp \
    qtuilineedit.cpp \
    qtuipainter.cpp \
    qtuipen.cpp \
    qtuislider.cpp \
    qtuiwidget.cpp
HEADERS         += qttui_global.h qttui.h \
    qtuiapplication.h \
    qtuiboxlayout.h \
    qtuibrush.h \
    qtuicombobox.h \
    qtuiconsolereader.h \
    qtuievent.h \
    qtuieventfilter.h \
    qtuigroupbox.h \
    qtuilayout.h \
    qtuilineedit.h \
    qtuipainter.h \
    qtuipen.h \
    qtuislider.h \
    qtuiwidget.h

