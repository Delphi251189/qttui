#include "qtuieventfilter.h"
#include <QEvent>
#include "qtuiapplication.h"

QTuiEventFilter::QTuiEventFilter(QObject *parent) : QObject(parent)
{
    logfile.setFileName("events.log");
    logfile.open(QIODevice::WriteOnly);

}

QTuiEventFilter::~QTuiEventFilter()
{
    logfile.close();
}

bool QTuiEventFilter::eventFilter(QObject *watched, QEvent *event)
{

    QString temp = QString("Event to %1 : %2").arg(watched->objectName()).arg(event->type());
    logfile.write( temp.toUtf8() );
    return qApp->eventFilter(watched, event);
}
