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
    qtuilineedit.cpp \
    qtuipainter.cpp \
    qtuiwidget.cpp
HEADERS         += qttui_global.h qttui.h \
    qtuiapplication.h \
    qtuicombobox.h \
    qtuiconsolereader.h \
    qtuieventfilter.h \
    qtuilineedit.h \
    qtuipainter.h \
    qtuiwidget.h

