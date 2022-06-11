#include "qtuiwidget.h"


const quint32 CHANGED_MASK = 0x00000001 << 0;
const quint32 VISIBLE_MASK = 0x00000001 << 1;
const quint32 ENABLED_MASK = 0x00000001 << 2;

struct QTuiWidgetPrivate
{
    QTuiWidgetPrivate()
    {

    }

    quint32             mask;
    Qt::WindowFlags     windowFlags;
    Qt::WindowModality  windowModality;
    QRect               rect;
    QSize               minimumSize;
    QSize               maximumSize;
    QTuiLayout          *layout;
};


QTuiWidget::QTuiWidget(QTuiWidget *parent) : QObject(parent), d(new QTuiWidgetPrivate)
{
    setMaximumSize(QSize(1000,1000));

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

bool QTuiWidget::isTopLevel() const
{
    return (windowType() & Qt::Window);
}

bool QTuiWidget::isWindow() const
{
    return (windowType() & Qt::Window);
}

bool QTuiWidget::isModal() const
{
    return d->windowModality != Qt::NonModal;
}

const QRect &QTuiWidget::geometry() const
{
    return d->rect;
}

int QTuiWidget::x() const
{
    return d->rect.x();
}

int QTuiWidget::y() const
{
    return d->rect.y();
}

QPoint QTuiWidget::pos() const
{
    return d->rect.topLeft();
}

QSize QTuiWidget::size() const
{
    return d->rect.size();
}

int QTuiWidget::width() const
{
    return d->rect.width();
}

int QTuiWidget::height() const
{
    return d->rect.height();
}

QSize QTuiWidget::minimumSize() const
{
    return d->minimumSize;
}

QSize QTuiWidget::maximumSize() const
{
    return d->maximumSize;
}

void QTuiWidget::setMaximumSize(const QSize &s)
{
    d->maximumSize  = s;
}

QPoint QTuiWidget::mapToGlobal(const QPoint &pos) const
{
    QPoint result = pos;
    QTuiWidget *p = parentWidget();
    while (p)
    {
        result = mapTo(p, result);
        p = p->parentWidget();
    }

    return result + topLevelWidget()->pos();
}

QPoint QTuiWidget::mapToParent(const QPoint &pos) const
{
    return pos + d->rect.topLeft();
}

QPoint QTuiWidget::mapTo(const QTuiWidget *parent, const QPoint &pos) const
{
    QPoint p = pos;
    if (parent)
    {
        const QTuiWidget * w = this;
        while (w != parent) {
            Q_ASSERT_X(w, "QWidget::mapTo(const QWidget *parent, const QPoint &pos)", "parent must be in parent hierarchy");
            p = w->mapToParent(p);
            w = w->parentWidget();
        }
    }
    return p;
}

QTuiWidget *QTuiWidget::window() const
{
    QTuiWidget *w = const_cast<QTuiWidget*>(this);
    QTuiWidget *p = w->parentWidget();
    while(!w->isWindow() && p) {
        w = p;
        p = p->parentWidget();
    }
    return w;

}

QTuiWidget *QTuiWidget::topLevelWidget() const
{
    return window();
}

void QTuiWidget::move(int x, int y)
{
    move(QPoint(x,y));
}

void QTuiWidget::move(const QPoint &pos)
{
    setAttribute(Qt::WA_Moved);
    d->rect.moveTopLeft(pos);
    setAttribute(Qt::WA_PendingMoveEvent);
}

void QTuiWidget::resize(int w, int h)
{
    resize(QSize(w, h));
}

void QTuiWidget::resize(const QSize &s)
{
    setAttribute(Qt::WA_Resized);
    d->rect.setSize(s.boundedTo(maximumSize()).expandedTo(minimumSize()));
    setAttribute(Qt::WA_PendingResizeEvent);
}

void QTuiWidget::setGeometry(int x, int y, int w, int h)
{
    setGeometry(QRect(x, y, w, h));
}

void QTuiWidget::setGeometry(const QRect &r)
{
    setAttribute(Qt::WA_Resized);
    setAttribute(Qt::WA_Moved);
    if (isWindow())
    {
        // ?????
    }
    d->rect.setTopLeft(r.topLeft());
    d->rect.setSize(r.size().boundedTo(maximumSize()).expandedTo(minimumSize()));
    setAttribute(Qt::WA_PendingMoveEvent);
    setAttribute(Qt::WA_PendingResizeEvent);
}

QTuiLayout *QTuiWidget::layout() const
{

}

void QTuiWidget::updateGeometry()
{
//    Q_UNIMPLEMENTED();
}

QTuiWidget *QTuiWidget::parentWidget() const
{
    return static_cast<QTuiWidget*>(parent());
}

Qt::WindowType QTuiWidget::windowType() const
{
    return static_cast<Qt::WindowType>(int(d->windowFlags & Qt::WindowType_Mask));
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

void QTuiWidget::setFocusPolicy(Qt::FocusPolicy policy)
{
    //Q_UNIMPLEMENTED();
}

bool QTuiWidget::hasFocus() const
{
    const QTuiWidget* w = this;

    /*
    while (w->d_func()->extra && w->d_func()->extra->focus_proxy)
        w = w->d_func()->extra->focus_proxy;
#if QT_CONFIG(graphicsview)
    if (QWidget *window = w->window()) {
        QWExtra *e = window->d_func()->extra;
        if (e && e->proxyWidget && e->proxyWidget->hasFocus() && window->focusWidget() == w)
            return true;
    }
#endif // QT_CONFIG(graphicsview)
    return (QApplication::focusWidget() == w);
*/
    //Q_UNIMPLEMENTED();
    return false;
}

void QTuiWidget::update()
{
    update(rect());
}

void QTuiWidget::repaint()
{
    repaint(rect());
}

void QTuiWidget::update(const QRect &)
{
    //Q_UNIMPLEMENTED();
}

void QTuiWidget::repaint(const QRect &)
{
    //Q_UNIMPLEMENTED();
}

QRect QTuiWidget::rect() const
{
    return QRect( 0, 0, d->rect.width(), d->rect.height() );
}

void QTuiWidget::setAttribute(Qt::WidgetAttribute, bool on)
{

}

bool QTuiWidget::testAttribute(Qt::WidgetAttribute) const
{
    return false;
}

inline void QTuiWidget::setMaskFlag(quint32 mask, bool value)
{
    if(value) { d->mask |= mask; } else { d->mask &= (!mask); }
}

bool QTuiWidget::getMaskFlag(quint32 mask) const
{
    return d->mask & mask;
}




