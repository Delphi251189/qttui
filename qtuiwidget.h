#ifndef QTUIWIDGET_H
#define QTUIWIDGET_H

#include <QObject>
#include <QPoint>
#include <QRect>
#include <QVariant>

class QTuiWidget : public QObject
{
    Q_OBJECT
//    Q_PROPERTY(bool modal READ isModal)
//    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled)
//    Q_PROPERTY(QRect geometry READ geometry WRITE setGeometry)
//    Q_PROPERTY(int x READ x)
//    Q_PROPERTY(int y READ y)
//    Q_PROPERTY(QPoint pos READ pos WRITE move STORED false)
//    Q_PROPERTY(QSize size READ size WRITE resize  STORED false)
//    Q_PROPERTY(int width READ width)
//    Q_PROPERTY(int height READ height)
//    Q_PROPERTY(QRect rect READ rect)
////Q_PROPERTY(QSizePolicy sizePolicy READ sizePolicy WRITE setSizePolicy)
//    Q_PROPERTY(QSize minimumSize READ minimumSize WRITE setMinimumSize)
//    Q_PROPERTY(QSize maximumSize READ maximumSize WRITE setMaximumSize)
//    Q_PROPERTY(int minimumWidth READ minimumWidth WRITE setMinimumWidth STORED false )
//    Q_PROPERTY(int minimumHeight READ minimumHeight WRITE setMinimumHeight STORED false )
//    Q_PROPERTY(int maximumWidth READ maximumWidth WRITE setMaximumWidth STORED false )
//    Q_PROPERTY(int maximumHeight READ maximumHeight WRITE setMaximumHeight STORED false )

//    Q_PROPERTY(Qt::FocusPolicy focusPolicy READ focusPolicy WRITE setFocusPolicy)
//    Q_PROPERTY(bool focus READ hasFocus)
//    Q_PROPERTY(QString windowTitle READ windowTitle WRITE setWindowTitle NOTIFY windowTitleChanged )
//    Q_PROPERTY(double windowOpacity READ windowOpacity WRITE setWindowOpacity )
//    Q_PROPERTY(bool windowModified READ isWindowModified WRITE setWindowModified )
//    Q_PROPERTY(QString toolTip READ toolTip WRITE setToolTip)
//    Q_PROPERTY(int toolTipDuration READ toolTipDuration WRITE setToolTipDuration)
//    Q_PROPERTY(QString whatsThis READ whatsThis WRITE setWhatsThis)
//    Q_PROPERTY(QLocale locale READ locale WRITE setLocale RESET unsetLocale)
//    Q_PROPERTY(Qt::InputMethodHints inputMethodHints READ inputMethodHints WRITE setInputMethodHints)

public:
    explicit QTuiWidget(QTuiWidget *parent = Q_NULLPTR);

    virtual void setVisible(bool visible);
    void setHidden(bool hidden);
    void show();
    void hide();
    void showMaximized();
    void showNormal();
    void setEnabled(bool enabled);
    bool isEnabled() const;
    bool close();
    void raise();
    void lower();
    bool isTopLevel() const;
    bool isWindow() const;
    bool isModal() const;
    const QRect geometry() const;
    int x() const;
    int y() const;
    QPoint pos() const;
    QSize size() const;
    inline int width() const;
    inline int height() const;
    QSize minimumSize() const;
    QSize maximumSize() const;
    int minimumWidth() const;
    int minimumHeight() const;
    int maximumWidth() const;
    int maximumHeight() const;
    void setMinimumSize(const QSize &);
    void setMinimumSize(int minw, int minh);
    void setMaximumSize(const QSize &);
    void setMaximumSize(int maxw, int maxh);
    void setMinimumWidth(int minw);
    void setMinimumHeight(int minh);
    void setMaximumWidth(int maxw);
    void setMaximumHeight(int maxh);
    void setFixedSize(const QSize &);
    void setFixedSize(int w, int h);
    void setFixedWidth(int w);
    void setFixedHeight(int h);
    QPoint mapToGlobal(const QPoint &) const;
    QPoint mapFromGlobal(const QPoint &) const;
    QPoint mapToParent(const QPoint &) const;
    QPoint mapFromParent(const QPoint &) const;
    QPoint mapTo(const QTuiWidget *, const QPoint &) const;
    QPoint mapFrom(const QTuiWidget *, const QPoint &) const;
    QTuiWidget *window() const;
    QTuiWidget *nativeParentWidget() const;
    QTuiWidget *topLevelWidget() const;
    void setMouseTracking(bool enable);
    bool hasMouseTracking() const;
    bool underMouse() const;
    void setTabletTracking(bool enable);
    bool hasTabletTracking() const;
    void setWindowTitle(const QString &);
    QString windowTitle() const;
    void setWindowOpacity(qreal level);
    qreal windowOpacity() const;
    void setToolTip(const QString &);
    QString toolTip() const;
    void setToolTipDuration(int msec);
    int toolTipDuration() const;
    void setWhatsThis(const QString &);
    QString whatsThis() const;
    void stackUnder(QTuiWidget*);
    void move(int x, int y);
    void move(const QPoint &);
    void resize(int w, int h);
    void resize(const QSize &);
    inline void setGeometry(int x, int y, int w, int h);
    void setGeometry(const QRect &);
    QByteArray saveGeometry() const;
    bool restoreGeometry(const QByteArray &geometry);
    void adjustSize();
    bool isVisible() const;
    bool isVisibleTo(const QTuiWidget *) const;
    inline bool isHidden() const;
public:
//    QLayout *layout() const;
//    void setLayout(QLayout *);
    void updateGeometry();
    void setParent(QTuiWidget *parent);
    void scroll(int dx, int dy);
    void scroll(int dx, int dy, const QRect&);
    QTuiWidget *focusWidget() const;
    QTuiWidget *nextInFocusChain() const;
    QTuiWidget *previousInFocusChain() const;
    QTuiWidget *parentWidget() const;
    void setWindowFlags(Qt::WindowFlags type);
    inline Qt::WindowFlags windowFlags() const;
    void setWindowFlag(Qt::WindowType, bool on = true);
    void overrideWindowFlags(Qt::WindowFlags type);
    inline Qt::WindowType windowType() const;
    QTuiWidget *childAt(const QPoint &p) const;
    inline QTuiWidget *childAt(int x, int y) const;
    bool isAncestorOf(const QTuiWidget *child) const;

    void clearFocus();
    void setFocus(Qt::FocusReason reason);
    Qt::FocusPolicy focusPolicy() const;
    void setFocusPolicy(Qt::FocusPolicy policy);
    bool hasFocus() const;

signals:
    void windowTitleChanged(const QString &title);
protected:
    /*
    virtual bool event(QEvent *event) Q_DECL_OVERRIDE;
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void wheelEvent(QWheelEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    virtual void moveEvent(QMoveEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual void closeEvent(QCloseEvent *event);
    virtual void contextMenuEvent(QContextMenuEvent *event);
    virtual void tabletEvent(QTabletEvent *event);
    virtual void actionEvent(QActionEvent *event);
    virtual void showEvent(QShowEvent *event);
    virtual void hideEvent(QHideEvent *event);
    virtual void changeEvent(QEvent *);
    virtual void inputMethodEvent(QInputMethodEvent *);
    */

    void setMaskFlag(quint32 mask, bool value);
    bool getMaskFlag(quint32 mask) const;
private:
    quint32 m_mask;

    QPoint  m_topleft;
    QSize   m_size;
    QSize   m_minimum_size;
    QSize   m_maximum_size;

};


#endif // QTUIWIDGET_H



/*


#include <QtWidgets/qtwidgetsglobal.h>
#include <QtGui/qwindowdefs.h>
#include <QtCore/qobject.h>
#include <QtCore/qmargins.h>
#include <QtGui/qpaintdevice.h>
#include <QtGui/qpalette.h>
#include <QtGui/qfont.h>
#include <QtGui/qfontmetrics.h>
#include <QtGui/qfontinfo.h>
#include <QtWidgets/qsizepolicy.h>
#include <QtGui/qregion.h>
#include <QtGui/qbrush.h>
#include <QtGui/qcursor.h>
#include <QtGui/qkeysequence.h>

#ifdef QT_INCLUDE_COMPAT
#include <QtGui/qevent.h>
#endif

QT_BEGIN_NAMESPACE


class QLayout;
class QWSRegionManager;
class QStyle;
class QAction;
class QVariant;
class QWindow;
class QActionEvent;
class QMouseEvent;
class QWheelEvent;
class QHoverEvent;
class QKeyEvent;
class QFocusEvent;
class QPaintEvent;
class QMoveEvent;
class QResizeEvent;
class QCloseEvent;
class QContextMenuEvent;
class QInputMethodEvent;
class QTabletEvent;
class QDragEnterEvent;
class QDragMoveEvent;
class QDragLeaveEvent;
class QDropEvent;
class QShowEvent;
class QHideEvent;
class QIcon;
class QBackingStore;
class QPlatformWindow;
class QLocale;
class QGraphicsProxyWidget;
class QGraphicsEffect;
class QRasterWindowSurface;
class QUnifiedToolbarSurface;
class QPixmap;
#ifndef QT_NO_DEBUG_STREAM
class QDebug;
#endif

class QWidgetData
{
public:
    WId winid;
    uint widget_attributes;
    Qt::WindowFlags window_flags;
    uint window_state : 4;
    uint focus_policy : 4;
    uint sizehint_forced :1;
    uint is_closing :1;
    uint in_show : 1;
    uint in_set_window_state : 1;
    mutable uint fstrut_dirty : 1;
    uint context_menu_policy : 3;
    uint window_modality : 2;
    uint in_destructor : 1;
    uint unused : 13;
    QRect crect;
    mutable QPalette pal;
    QFont fnt;
    QRect wrect;
};

class QWidgetPrivate;

class Q_WIDGETS_EXPORT QWidget : public QObject, public QPaintDevice
{
public:
    enum RenderFlag {
        DrawWindowBackground = 0x1,
        DrawChildren = 0x2,
        IgnoreMask = 0x4
    };
    Q_DECLARE_FLAGS(RenderFlags, RenderFlag)

    explicit QWidget(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~QWidget();

    int devType() const Q_DECL_OVERRIDE;

    WId winId() const;
    void createWinId(); // internal, going away
    inline WId internalWinId() const { return data->winid; }
    WId effectiveWinId() const;

scasc
public Q_SLOTS:
    void setDisabled(bool);
    void setWindowModified(bool);

    // Widget coordinates

public:
public Q_SLOTS:
    inline void setFocus() { setFocus(Qt::OtherFocusReason); }

public:
    bool isActiveWindow() const;
    void activateWindow();
    static void setTabOrder(QWidget *, QWidget *);
    void setFocusProxy(QWidget *);
    QWidget *focusProxy() const;
    Qt::ContextMenuPolicy contextMenuPolicy() const;
    void setContextMenuPolicy(Qt::ContextMenuPolicy policy);

    // Grab functions
    void grabMouse();
#ifndef QT_NO_CURSOR
    void grabMouse(const QCursor &);
#endif
    void releaseMouse();
    void grabKeyboard();
    void releaseKeyboard();
#ifndef QT_NO_SHORTCUT
    int grabShortcut(const QKeySequence &key, Qt::ShortcutContext context = Qt::WindowShortcut);
    void releaseShortcut(int id);
    void setShortcutEnabled(int id, bool enable = true);
    void setShortcutAutoRepeat(int id, bool enable = true);
#endif
    static QWidget *mouseGrabber();
    static QWidget *keyboardGrabber();

    // Update/refresh functions
    inline bool updatesEnabled() const;
    void setUpdatesEnabled(bool enable);

#if QT_CONFIG(graphicsview)
    QGraphicsProxyWidget *graphicsProxyWidget() const;
#endif

public Q_SLOTS:
    void update();
    void repaint();

public:
    inline void update(int x, int y, int w, int h);
    void update(const QRect&);
    void update(const QRegion&);

    void repaint(int x, int y, int w, int h);
    void repaint(const QRect &);
    void repaint(const QRegion &);


public:

protected:

public:
    virtual QVariant inputMethodQuery(Qt::InputMethodQuery) const;

    Qt::InputMethodHints inputMethodHints() const;
    void setInputMethodHints(Qt::InputMethodHints hints);

protected Q_SLOTS:
    void updateMicroFocus();
protected:

    void create(WId = 0, bool initializeWindow = true,
                         bool destroyOldWindow = true);
    void destroy(bool destroyWindow = true,
                 bool destroySubWindows = true);

    friend class QDataWidgetMapperPrivate; // for access to focusNextPrevChild
    virtual bool focusNextPrevChild(bool next);
    inline bool focusNextChild() { return focusNextPrevChild(true); }
    inline bool focusPreviousChild() { return focusNextPrevChild(false); }

protected:
    QWidget(QWidgetPrivate &d, QWidget* parent, Qt::WindowFlags f);
private:
    void setBackingStore(QBackingStore *store);

    bool testAttribute_helper(Qt::WidgetAttribute) const;

    QLayout *takeLayout();

    friend class QBackingStoreDevice;
    friend class QWidgetBackingStore;
    friend class QApplication;
    friend class QApplicationPrivate;
    friend class QGuiApplication;
    friend class QGuiApplicationPrivate;
    friend class QBaseApplication;
    friend class QPainter;
    friend class QPainterPrivate;
    friend class QPixmap; // for QPixmap::fill()
    friend class QFontMetrics;
    friend class QFontInfo;
    friend class QLayout;
    friend class QWidgetItem;
    friend class QWidgetItemV2;
    friend class QGLContext;
    friend class QGLWidget;
    friend class QGLWindowSurface;
    friend class QX11PaintEngine;
    friend class QWin32PaintEngine;
    friend class QShortcutPrivate;
    friend class QWindowSurface;
    friend class QGraphicsProxyWidget;
    friend class QGraphicsProxyWidgetPrivate;
    friend class QStyleSheetStyle;
    friend struct QWidgetExceptionCleaner;
    friend class QWidgetWindow;
    friend class QAccessibleWidget;
    friend class QAccessibleTable;
#ifndef QT_NO_GESTURES
    friend class QGestureManager;
    friend class QWinNativePanGestureRecognizer;
#endif // QT_NO_GESTURES
    friend class QWidgetEffectSourcePrivate;

#ifdef Q_OS_MAC
    friend bool qt_mac_is_metal(const QWidget *w);
#endif
    friend Q_WIDGETS_EXPORT QWidgetData *qt_qwidget_data(QWidget *widget);
    friend Q_WIDGETS_EXPORT QWidgetPrivate *qt_widget_private(QWidget *widget);

private:
    Q_DISABLE_COPY(QWidget)
    Q_PRIVATE_SLOT(d_func(), void _q_showIfNotHidden())

    QWidgetData *data;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(QWidget::RenderFlags)

#ifndef Q_QDOC

#define QWIDGETSIZE_MAX ((1<<24)-1)

#ifndef QT_NO_DEBUG_STREAM
Q_WIDGETS_EXPORT QDebug operator<<(QDebug, const QWidget *);
#endif

QT_END_NAMESPACE

#endif // QWIDGET_H


*/
