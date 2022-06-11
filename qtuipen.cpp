#include "qtuipen.h"

struct QTuiPenPrivate
{
    QTuiPenPrivate()
    {

    }

    Qt::PenStyle    style;
    qreal           width;
    Qt::GlobalColor color;
    Qt::GlobalColor bgnd;
};


QTuiPen::QTuiPen()
    : d(new QTuiPenPrivate)
{

}


QTuiPen::~QTuiPen()
{
    delete d;
}

Qt::PenStyle QTuiPen::style() const
{
    return d->style;
}

void QTuiPen::setStyle(Qt::PenStyle style)
{
    d->style = style;
}

qreal QTuiPen::widthF() const
{
    return d->width;
}

void QTuiPen::setWidthF(qreal width)
{
    d->width = width;
}

int QTuiPen::width() const
{
    return (int)(d->width);
}

void QTuiPen::setWidth(int width)
{
    d->width = width;
}

Qt::GlobalColor QTuiPen::color() const
{
    return d->color;
}

void QTuiPen::setColor(Qt::GlobalColor color)
{
    d->color = color;
}

Qt::GlobalColor QTuiPen::backgroundColor() const
{
    return d->bgnd;
}

void QTuiPen::setBackgroundColor(Qt::GlobalColor color)
{
    d->bgnd = color;
}
