#ifndef QTUIAPPLICATION_H
#define QTUIAPPLICATION_H


#include <QCoreApplication>

struct QTuiApplicationPrivate;

#include <qtuiwidget.h>


#if defined(qApp)
#undef qApp
#endif
#define qApp (static_cast<QTuiApplication *>(QTuiApplication::instance()))


class QTuiApplication : public QCoreApplication
{
    Q_OBJECT
    Q_PROPERTY(int terminalWidth READ terminalWidth)
    Q_PROPERTY(int terminalHeight READ terminalHeight)

//    Q_PROPERTY(QIcon windowIcon READ windowIcon WRITE setWindowIcon)
//    Q_PROPERTY(QString applicationDisplayName READ applicationDisplayName WRITE setApplicationDisplayName NOTIFY applicationDisplayNameChanged)
//    Q_PROPERTY(QString desktopFileName READ desktopFileName WRITE setDesktopFileName)
//    Q_PROPERTY(Qt::LayoutDirection layoutDirection READ layoutDirection WRITE setLayoutDirection NOTIFY layoutDirectionChanged)
//    Q_PROPERTY(QString platformName READ platformName STORED false)
//    Q_PROPERTY(bool quitOnLastWindowClosed  READ quitOnLastWindowClosed WRITE setQuitOnLastWindowClosed)
//    Q_PROPERTY(QScreen *primaryScreen READ primaryScreen NOTIFY primaryScreenChanged STORED false)


//    Q_PROPERTY(int cursorFlashTime READ cursorFlashTime WRITE setCursorFlashTime)
//    Q_PROPERTY(int doubleClickInterval  READ doubleClickInterval WRITE setDoubleClickInterval)
//    Q_PROPERTY(int keyboardInputInterval READ keyboardInputInterval WRITE setKeyboardInputInterval)
//    Q_PROPERTY(int wheelScrollLines  READ wheelScrollLines WRITE setWheelScrollLines)
//    Q_PROPERTY(QSize globalStrut READ globalStrut WRITE setGlobalStrut)
public:
    explicit QTuiApplication(int &argc, char **argv);

    virtual ~QTuiApplication();

    int terminalWidth();
    int terminalHeight();



    static void setApplicationDisplayName(const QString &name);
    static QString applicationDisplayName();

    static void setDesktopFileName(const QString &name);
    static QString desktopFileName();

//    static QWindowList allWindows();
//    static QWindowList topLevelWindows();
//    static QWindow *topLevelAt(const QPoint &pos);

    static void setWindowIcon(const QIcon &icon);
//    static QIcon windowIcon();

    static QString platformName();

//    static QTuiWindow *modalWindow();
//    static QTuiWindow *focusWindow();
    static QObject *focusObject();






    static Qt::KeyboardModifiers keyboardModifiers();
    static Qt::KeyboardModifiers queryKeyboardModifiers();
    static Qt::MouseButtons mouseButtons();

    static void setLayoutDirection(Qt::LayoutDirection direction);
    static Qt::LayoutDirection layoutDirection();

    static inline bool isRightToLeft() { return layoutDirection() == Qt::RightToLeft; }
    static inline bool isLeftToRight() { return layoutDirection() == Qt::LeftToRight; }


    static void setDesktopSettingsAware(bool on);
    static bool desktopSettingsAware();


    static void setQuitOnLastWindowClosed(bool quit);
    static bool quitOnLastWindowClosed();

    static Qt::ApplicationState applicationState();

    bool isSessionRestored() const;
    QString sessionId() const;
    QString sessionKey() const;
    bool isSavingSession() const;

    static bool isFallbackSessionManagementEnabled();
    static void setFallbackSessionManagementEnabled(bool);
    static void sync();


    void fontDatabaseChanged();

    void lastWindowClosed();
    void focusObjectChanged(QObject *focusObject);
//    void focusWindowChanged(QWindow *focusWindow);
    void applicationStateChanged(Qt::ApplicationState state);
    void layoutDirectionChanged(Qt::LayoutDirection direction);

//    void commitDataRequest(QSessionManager &sessionManager);
//    void saveStateRequest(QSessionManager &sessionManager);


    void applicationDisplayNameChanged();




//    static QStyle *style();
//    static void setStyle(QStyle*);
//    static QStyle *setStyle(const QString&);

    static QTuiWidgetList allWidgets();
    static QTuiWidgetList topLevelWidgets();
    static QTuiWidget *activePopupWidget();
    static QTuiWidget *activeModalWidget();
    static QTuiWidget *focusWidget();

    static QTuiWidget *activeWindow();
    static void setActiveWindow(QTuiWidget* act);

    static QTuiWidget *widgetAt(const QPoint &p);
    static QTuiWidget *topLevelAt(const QPoint &p);

    static void beep();
    static void alert(QTuiWidget *widget, int duration = 0);

    static void setCursorFlashTime(int);
    static int cursorFlashTime();

    static void setDoubleClickInterval(int);
    static int doubleClickInterval();

    static void setKeyboardInputInterval(int);
    static int keyboardInputInterval();

    static void setWheelScrollLines(int);
    static int wheelScrollLines();

    static void setGlobalStrut(const QSize &);
    static QSize globalStrut();

    //static int exec();
//    bool notify(QObject *, QEvent *);

Q_SIGNALS:
    void focusChanged(QWidget *old, QWidget *now);
public Q_SLOTS:
    static void closeAllWindows();
    static void aboutQt();
protected:
//    bool event(QEvent *) ;
//    bool compressEvent(QEvent *, QObject *receiver, QPostEventList *);


private slots:
    void onConsoleKeyPressed(char ch);

private:
    QTuiApplicationPrivate *d;
};

#endif // QTUIAPPLICATION_H

