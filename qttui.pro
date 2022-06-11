TEMPLATE        = app
QT              += gui widgets

DEFINES         += QTTUI_LIBRARY
CONFIG          += c++11

LIBS            += -lncursesw

SOURCES         += qttui.cpp \
    main.cpp \
    qtuiapplication.cpp \
    qtuicombobox.cpp \
    qtuiconsolereader.cpp \
    qtuieventfilter.cpp \
    qtuigroupbox.cpp \
    qtuilineedit.cpp \
    qtuipainter.cpp \
    qtuislider.cpp \
    qtuiwidget.cpp
HEADERS         += qttui_global.h qttui.h \
    qtuiapplication.h \
    qtuicombobox.h \
    qtuiconsolereader.h \
    qtuieventfilter.h \
    qtuigroupbox.h \
    qtuilineedit.h \
    qtuipainter.h \
    qtuislider.h \
    qtuiwidget.h

