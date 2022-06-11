#include "qtuievent.h"

QTuiKeyEvent::QTuiKeyEvent(QEvent::Type type, int key, Qt::KeyboardModifiers modifiers, const QString &text, bool autorep, ushort count)
    :QTuiInputEvent(type, modifiers),txt(text), k(key)
{
}

QTuiKeyEvent::~QTuiKeyEvent()
{

}

QTuiInputEvent::QTuiInputEvent(QEvent::Type type, Qt::KeyboardModifiers modifiers)
    :QEvent(type), modState(modifiers)
{

}

QTuiInputEvent::~QTuiInputEvent()
{

}
