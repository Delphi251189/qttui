#include "qtuilayout.h"

#include "qtuiwidget.h"

struct QTuiLayoutItem
{
    QTuiLayoutItem() : layout(Q_NULLPTR), widget(Q_NULLPTR), alignment(Qt::AlignCenter)
    {

    }
    QTuiLayout          *layout;
    QTuiWidget          *widget;
    Qt::AlignmentFlag   alignment;

};

struct QTuiLayoutPrivate
{
    QTuiLayoutPrivate() {}
};

QTuiLayout::QTuiLayout(QTuiWidget *parent) : QObject(parent), d(new QTuiLayoutPrivate)
{

}

int QTuiLayout::margin() const
{

}

int QTuiLayout::spacing() const
{

}

void QTuiLayout::setMargin(int)
{

}

void QTuiLayout::setSpacing(int)
{

}
