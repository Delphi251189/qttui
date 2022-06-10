#ifndef QTUIAPPLICATION_H
#define QTUIAPPLICATION_H


#include <QCoreApplication>

struct QTuiApplicationPrivate;

class QTuiApplication : public QCoreApplication
{
    Q_OBJECT
    Q_PROPERTY(int terminalWidth READ terminalWidth)
    Q_PROPERTY(int terminalHeight READ terminalHeight)
public:
    explicit QTuiApplication(int &argc, char **argv);

    virtual ~QTuiApplication();

    int terminalWidth();
    int terminalHeight();

private slots:
    void onConsoleKeyPressed(char ch);

private:
    QTuiApplicationPrivate *d;
};

#endif // QTUIAPPLICATION_H

