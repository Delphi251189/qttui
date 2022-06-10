#ifndef QTTUI_GLOBAL_H
#define QTTUI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTTUI_LIBRARY)
#  define QTTUI_EXPORT Q_DECL_EXPORT
#else
#  define QTTUI_EXPORT Q_DECL_IMPORT
#endif

#endif // QTTUI_GLOBAL_H
