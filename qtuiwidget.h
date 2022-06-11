#ifndef QTUIWIDGET_H
#define QTUIWIDGET_H

#include <QObject>
#include <QPoint>
#include <QRect>
#include <QVariant>

class QTuiLayout;

struct  QTuiWidgetPrivate;

class QTuiWidget : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool modal READ isModal)
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled)
    Q_PROPERTY(QRect geometry READ geometry WRITE setGeometry)
    Q_PROPERTY(int x READ x)
    Q_PROPERTY(int y READ y)
    Q_PROPERTY(QPoint pos READ pos WRITE move STORED false)
    Q_PROPERTY(QSize size READ size WRITE resize  STORED false)
    Q_PROPERTY(int width READ width)
    Q_PROPERTY(int height READ height)
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
    const QRect &geometry() const;
    int x() const;
    int y() const;
    QPoint pos() const;
    QSize size() const;
    int width() const;
    int height() const;

    QSize minimumSize() const;
    QSize maximumSize() const;
    int minimumWidth() const;
    int minimumHeight() const;
    int maximumWidth() const;
    int maximumHeight() const;

    void setMinimumSize(const QSize &);
    void setMinimumSize(int minw, int minh);
    void setMaximumSize(const QSize &s);
    void setMaximumSize(int maxw, int maxh);
    void setMinimumWidth(int minw);
    void setMinimumHeight(int minh);
    void setMaximumWidth(int maxw);
    void setMaximumHeight(int maxh);

    QPoint mapToGlobal(const QPoint & pos) const;
    QPoint mapFromGlobal(const QPoint &) const;
    QPoint mapToParent(const QPoint &pos) const;
    QPoint mapFromParent(const QPoint &) const;
    QPoint mapTo(const QTuiWidget *parent, const QPoint &pos) const;
    QPoint mapFrom(const QTuiWidget *, const QPoint &) const;
    QTuiWidget *window() const;
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
    void move(const QPoint &pos);
    void resize(int w, int h);
    void resize(const QSize &s);
    inline void setGeometry(int x, int y, int w, int h);
    void setGeometry(const QRect &r);
    QByteArray saveGeometry() const;
    bool restoreGeometry(const QByteArray &geometry);
    void adjustSize();
    bool isVisible() const;
    bool isVisibleTo(const QTuiWidget *) const;
    inline bool isHidden() const;
public:
    QTuiLayout *layout() const;
//    void setLayout(QLayout *);
    void updateGeometry();
    void setParent(QTuiWidget *parent);
//    void scroll(int dx, int dy);
//    void scroll(int dx, int dy, const QRect&);
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


public Q_SLOTS:
    void update();
    void repaint();
public:
    QRect rect() const;
    void update(const QRect&);
    void repaint(const QRect &);


signals:
    void windowTitleChanged(const QString &title);
protected:
    void setAttribute(Qt::WidgetAttribute, bool on = true);
    inline bool testAttribute(Qt::WidgetAttribute) const;
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
    QTuiWidgetPrivate   *d;
};


#endif // QTUIWIDGET_H
