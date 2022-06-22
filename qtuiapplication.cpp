#include "qtuiapplication.h"
#include "qtuipainter.h"
#include "qtuieventfilter.h"
#include "qtuiconsolereader.h"


struct QTuiApplicationPrivate
{
    QTuiApplicationPrivate() :focusWidget(Q_NULLPTR)
    {

    }




    QTuiWidget focusWidget;
};



QTuiApplication::QTuiApplication(int &argc, char **argv)
    :QCoreApplication(argc, argv), d(new QTuiApplicationPrivate)
{


    installEventFilter(new QTuiEventFilter);
    QTuiConsoleReader *reader = new QTuiConsoleReader();
    connect (reader, SIGNAL (keyPressed(char)), this, SLOT(onConsoleKeyPressed(char)));
    reader->start();

    new QTuiPainter;
}

QTuiApplication::~QTuiApplication()
{
    delete d;
}

int QTuiApplication::terminalWidth()
{
    return QTuiPainter::instance()->terminalWidth();

}

int QTuiApplication::terminalHeight()
{
    return QTuiPainter::instance()->terminalHeight();
}

QTuiWidget *QTuiApplication::focusWidget()
{
    return Q_NULLPTR;
}

void QTuiApplication::closeAllWindows()
{

}

void QTuiApplication::aboutQt()
{

}

void QTuiApplication::onConsoleKeyPressed(char ch)
{
    QFile f("keys.log");
    f.open(QIODevice::Append);
    QByteArray ba = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toLatin1();
    ba.append(" Key Pressed Event ");
    ba.append(ch);
    ba.append('\n');
    f.write(ba);
    f.close();

}
