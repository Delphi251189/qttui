#include "qtuiwidget.h"


const quint32 CHANGED_MASK = 0x00000001 << 0;
const quint32 VISIBLE_MASK = 0x00000001 << 1;
const quint32 ENABLED_MASK = 0x00000001 << 2;


QTuiWidget::QTuiWidget(QTuiWidget *parent) : QObject(parent)
{

}


void QTuiWidget::setVisible(bool visible)
{
    setMaskFlag(VISIBLE_MASK, visible);
    setMaskFlag(CHANGED_MASK, true);
}

void QTuiWidget::setHidden(bool hidden)
{
    setVisible(!hidden);
}

void QTuiWidget::show()
{
    setVisible(true);
}

void QTuiWidget::hide()
{
    setVisible(false);
}

void QTuiWidget::setEnabled(bool enabled)
{
    setMaskFlag(ENABLED_MASK, enabled);
    setMaskFlag(CHANGED_MASK, true);
}

bool QTuiWidget::isEnabled() const
{
    return getMaskFlag(ENABLED_MASK);
}

const QRect QTuiWidget::geometry() const
{
    return QRect(m_topleft, m_size);
}

int QTuiWidget::x() const
{
    return m_topleft.x();
}

int QTuiWidget::y() const
{
    return m_topleft.y();
}

QPoint QTuiWidget::pos() const
{
    return m_topleft;
}

QSize QTuiWidget::size() const
{
    return m_size;
}

int QTuiWidget::width() const
{
    return m_size.width();
}

int QTuiWidget::height() const
{
    return m_size.height();
}

QSize QTuiWidget::minimumSize() const
{
    return m_minimum_size;
}

QSize QTuiWidget::maximumSize() const
{
    return m_maximum_size;
}

QTuiWidget *QTuiWidget::childAt(const QPoint &p) const
{
    Q_UNIMPLEMENTED();
    return Q_NULLPTR;
}

QTuiWidget *QTuiWidget::childAt(int x, int y) const
{
    return childAt(QPoint(x, y));
}

bool QTuiWidget::isAncestorOf(const QTuiWidget *child) const
{
    Q_UNIMPLEMENTED();
    return false;
}

inline void QTuiWidget::setMaskFlag(quint32 mask, bool value)
{
    if(value) { m_mask |= mask; } else { m_mask &= (!mask); }
}

bool QTuiWidget::getMaskFlag(quint32 mask) const
{
    return m_mask & mask;
}




