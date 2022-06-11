#ifndef QTUIEVENT_H
#define QTUIEVENT_H

#include <QEvent>
#include <QPoint>
#include <QString>
#include <QRect>

class QTuiInputEvent : public QEvent
{
public:
    explicit QTuiInputEvent(Type type, Qt::KeyboardModifiers modifiers = Qt::NoModifier);
    ~QTuiInputEvent();
    inline Qt::KeyboardModifiers modifiers() const { return modState; }
    inline void setModifiers(Qt::KeyboardModifiers amodifiers) { modState = amodifiers; }
    inline ulong timestamp() const { return ts; }
    inline void setTimestamp(ulong atimestamp) { ts = atimestamp; }
protected:
    Qt::KeyboardModifiers modState;
    ulong ts;
};

class QTuiEnterEvent : public QEvent
{
public:
    QTuiEnterEvent(const QPoint &localPos, const QPoint &windowPos, const QPoint &screenPos);
    ~QTuiEnterEvent();
    inline QPoint pos() const { return l; }
    inline QPoint globalPos() const { return s;}
    inline int x() const { return l.x(); }
    inline int y() const { return l.y(); }
    inline int globalX() const { return s.x(); }
    inline int globalY() const { return s.y(); }
    const QPoint &localPos() const { return l; }
    const QPoint &windowPos() const { return w; }
    const QPoint &screenPos() const { return s; }

protected:
    QPoint l, w, s;
};

class QTuiMouseEvent : public QTuiInputEvent
{
public:
    QTuiMouseEvent(Type type, const QPointF &localPos, Qt::MouseButton button,
                Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers);
    QTuiMouseEvent(Type type, const QPointF &localPos, const QPointF &screenPos,
                Qt::MouseButton button, Qt::MouseButtons buttons,
                Qt::KeyboardModifiers modifiers);
    QTuiMouseEvent(Type type, const QPointF &localPos, const QPointF &windowPos, const QPointF &screenPos,
                Qt::MouseButton button, Qt::MouseButtons buttons,
                Qt::KeyboardModifiers modifiers);
    QTuiMouseEvent(Type type, const QPointF &localPos, const QPointF &windowPos, const QPointF &screenPos,
                Qt::MouseButton button, Qt::MouseButtons buttons,
                Qt::KeyboardModifiers modifiers, Qt::MouseEventSource source);
    ~QTuiMouseEvent();

    inline QPoint pos() const { return l.toPoint(); }
    inline QPoint globalPos() const { return s.toPoint(); }
    inline int x() const { return qRound(l.x()); }
    inline int y() const { return qRound(l.y()); }
    inline int globalX() const { return qRound(s.x()); }
    inline int globalY() const { return qRound(s.y()); }
    const QPointF &localPos() const { return l; }
    const QPointF &windowPos() const { return w; }
    const QPointF &screenPos() const { return s; }

    inline Qt::MouseButton button() const { return b; }
    inline Qt::MouseButtons buttons() const { return mouseState; }

    inline void setLocalPos(const QPointF &localPosition) { l = localPosition; }

    Qt::MouseEventSource source() const;
    Qt::MouseEventFlags flags() const;

protected:
    QPointF l, w, s;
    Qt::MouseButton b;
    Qt::MouseButtons mouseState;
    int caps;
};

class QTuiHoverEvent : public QTuiInputEvent
{
public:
    QTuiHoverEvent(Type type, const QPointF &pos, const QPointF &oldPos, Qt::KeyboardModifiers modifiers = Qt::NoModifier);
    ~QTuiHoverEvent();
    inline QPoint pos() const { return p.toPoint(); }
    inline QPoint oldPos() const { return op.toPoint(); }
protected:
    QPointF p, op;
};

class QTuiWheelEvent : public QTuiInputEvent
{
public:
    enum { DefaultDeltasPerStep = 120 };

    QTuiWheelEvent(const QPointF &pos, int delta,
                Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers,
                Qt::Orientation orient = Qt::Vertical);
    QTuiWheelEvent(const QPointF &pos, const QPointF& globalPos, int delta,
                Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers,
                Qt::Orientation orient = Qt::Vertical);
    QTuiWheelEvent(const QPointF &pos, const QPointF& globalPos,
                QPoint pixelDelta, QPoint angleDelta, int qt4Delta, Qt::Orientation qt4Orientation,
                Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers);
    QTuiWheelEvent(const QPointF &pos, const QPointF& globalPos,
                QPoint pixelDelta, QPoint angleDelta, int qt4Delta, Qt::Orientation qt4Orientation,
                Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, Qt::ScrollPhase phase);
    QTuiWheelEvent(const QPointF &pos, const QPointF &globalPos, QPoint pixelDelta, QPoint angleDelta,
                int qt4Delta, Qt::Orientation qt4Orientation, Qt::MouseButtons buttons,
                Qt::KeyboardModifiers modifiers, Qt::ScrollPhase phase, Qt::MouseEventSource source);
    QTuiWheelEvent(const QPointF &pos, const QPointF &globalPos, QPoint pixelDelta, QPoint angleDelta,
                int qt4Delta, Qt::Orientation qt4Orientation, Qt::MouseButtons buttons,
                Qt::KeyboardModifiers modifiers, Qt::ScrollPhase phase, Qt::MouseEventSource source, bool inverted);

    QTuiWheelEvent(QPointF pos, QPointF globalPos, QPoint pixelDelta, QPoint angleDelta,
                Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, Qt::ScrollPhase phase,
                bool inverted, Qt::MouseEventSource source = Qt::MouseEventNotSynthesized);
    ~QTuiWheelEvent();


    inline QPoint pixelDelta() const { return pixelD; }
    inline QPoint angleDelta() const { return angleD; }

    inline int delta() const  { return qt4D; }
    inline Qt::Orientation orientation() const { return qt4O; }

#ifndef QT_NO_INTEGER_EVENT_COORDINATES
    inline QPoint pos() const { return p.toPoint(); }
    inline QPoint globalPos()   const { return g.toPoint(); }
    inline int x() const { return int(p.x()); }
    inline int y() const { return int(p.y()); }
    inline int globalX() const { return int(g.x()); }
    inline int globalY() const { return int(g.y()); }
#endif
    inline const QPointF &posF() const { return p; }
    inline const QPointF &globalPosF()   const { return g; }

    inline Qt::MouseButtons buttons() const { return mouseState; }

    inline Qt::ScrollPhase phase() const { return Qt::ScrollPhase(ph); }
    inline bool inverted() const { return invertedScrolling; }

    Qt::MouseEventSource source() const { return Qt::MouseEventSource(src); }

protected:
    QPointF p;
    QPointF g;
    QPoint pixelD;
    QPoint angleD;
    int qt4D = 0;
    Qt::Orientation qt4O = Qt::Vertical;
    Qt::MouseButtons mouseState;
    uint _unused_ : 2; // Kept for binary compatibility
    uint src: 2;
    bool invertedScrolling : 1;
    uint ph : 3;
    int reserved : 24;

    friend class QApplication;
};

class QTuiKeyEvent : public QTuiInputEvent
{
public:
    QTuiKeyEvent(Type type, int key, Qt::KeyboardModifiers modifiers, const QString& text = QString(), bool autorep = false, ushort count = 1);
    ~QTuiKeyEvent();

    int key() const { return k; }
    Qt::KeyboardModifiers modifiers() const;
    inline QString text() const { return txt; }
    inline bool isAutoRepeat() const { return autor; }
    inline int count() const { return int(c); }

    inline quint32 nativeScanCode() const { return nScanCode; }
    inline quint32 nativeVirtualKey() const { return nVirtualKey; }
    inline quint32 nativeModifiers() const { return nModifiers; }

protected:
    QString txt;
    int k;
    quint32 nScanCode;
    quint32 nVirtualKey;
    quint32 nModifiers;
    ushort c;
    ushort autor:1;
    // ushort reserved:15;
};

class QTuiFocusEvent : public QEvent
{
public:
    explicit QTuiFocusEvent(Type type, Qt::FocusReason reason=Qt::OtherFocusReason);
    ~QTuiFocusEvent();

    inline bool gotFocus() const { return type() == FocusIn; }
    inline bool lostFocus() const { return type() == FocusOut; }

    Qt::FocusReason reason() const;

private:
    Qt::FocusReason m_reason;
};

class QTuiPaintEvent : public QEvent
{
public:
    explicit QTuiPaintEvent(const QRect &paintRect);
    ~QTuiPaintEvent();

    inline const QRect &rect() const { return m_rect; }
protected:
    QRect m_rect;
    bool m_erased;
};

class QTuiMoveEvent : public QEvent
{
public:
    QTuiMoveEvent(const QPoint &pos, const QPoint &oldPos);
    ~QTuiMoveEvent();

    inline const QPoint &pos() const { return p; }
    inline const QPoint &oldPos() const { return oldp;}
protected:
    QPoint p, oldp;
    friend class QApplication;
};

class QTuiResizeEvent : public QEvent
{
public:
    QTuiResizeEvent(const QSize &size, const QSize &oldSize);
    ~QTuiResizeEvent();

    inline const QSize &size() const { return s; }
    inline const QSize &oldSize()const { return olds;}
protected:
    QSize s, olds;
    friend class QApplication;
};

class QTuiCloseEvent : public QEvent
{
public:
    QTuiCloseEvent();
    ~QTuiCloseEvent();
};

class QTuiShowEvent : public QEvent
{
public:
    QTuiShowEvent();
    ~QTuiShowEvent();
};

class QTuiHideEvent : public QEvent
{
public:
    QTuiHideEvent();
    ~QTuiHideEvent();
};

class QTuiHelpEvent : public QEvent
{
public:
    QTuiHelpEvent(Type type, const QPoint &pos, const QPoint &globalPos);
    ~QTuiHelpEvent();

    inline int x() const { return p.x(); }
    inline int y() const { return p.y(); }
    inline int globalX() const { return gp.x(); }
    inline int globalY() const { return gp.y(); }

    inline const QPoint& pos()  const { return p; }
    inline const QPoint& globalPos() const { return gp; }

private:
    QPoint p;
    QPoint gp;
};

class QTuitatusTipEvent : public QEvent
{
public:
    explicit QTuitatusTipEvent(const QString &tip);
    ~QTuitatusTipEvent();

    inline QString tip() const { return s; }
private:
    QString s;
};

class QTuiWhatsThisClickedEvent : public QEvent
{
public:
    explicit QTuiWhatsThisClickedEvent(const QString &href);
    ~QTuiWhatsThisClickedEvent();
    inline QString href() const { return s; }
private:
    QString s;
};

class QTuiActionEvent : public QEvent
{
public:
    QTuiActionEvent();
    ~QTuiActionEvent();
};

class QTuiWindowStateChangeEvent: public QEvent
{
public:
    explicit QTuiWindowStateChangeEvent(Qt::WindowStates aOldState, bool isOverride = false);
    ~QTuiWindowStateChangeEvent();

    inline Qt::WindowStates oldState() const { return ostate; }
    bool isOverride() const;

private:
    Qt::WindowStates ostate;
    bool m_override;
};

class QTuiScreenOrientationChangeEvent : public QEvent
{
public:
    QTuiScreenOrientationChangeEvent(Qt::ScreenOrientation orientation);
    ~QTuiScreenOrientationChangeEvent();
    Qt::ScreenOrientation orientation() const;

private:
    Qt::ScreenOrientation m_orientation;
};

class QTuiApplicationStateChangeEvent : public QEvent
{
public:
    explicit QTuiApplicationStateChangeEvent(Qt::ApplicationState state);
    Qt::ApplicationState applicationState() const;
private:
    Qt::ApplicationState m_applicationState;
};



#endif // QTUIEVENT_H
