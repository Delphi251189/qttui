TEMPLATE        = app
QT              -= gui
DEFINES         += QTTUI_LIBRARY
CONFIG          += c++11

SOURCES         += qttui.cpp \
    main.cpp \
    qtuicombobox.cpp \
    qtuilineedit.cpp \
    qtuiwidget.cpp
HEADERS         += qttui_global.h qttui.h \
    qtuicombobox.h \
    qtuilineedit.h \
    qtuiwidget.h

