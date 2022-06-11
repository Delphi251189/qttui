#include "qtuiapplication.h"
#include "qtuipainter.h"
#include "qtuieventfilter.h"
#include "qtuiconsolereader.h"

#include <ncurses.h>

#include "qtuigroupbox.h"

struct QTuiApplicationPrivate
{
    QTuiApplicationPrivate()
        : window(Q_NULLPTR)
    {

    }




    WINDOW *window;
};



QTuiApplication::QTuiApplication(int &argc, char **argv)
    :QCoreApplication(argc, argv), d(new QTuiApplicationPrivate)
{

    installEventFilter(new QTuiEventFilter);
    QTuiConsoleReader *reader = new QTuiConsoleReader();
    connect (reader, SIGNAL (keyPressed(char)), this, SLOT(onConsoleKeyPressed(char)));
    reader->start();

    setlocale(LC_CTYPE, "");
    d->window = initscr();
    wclear(d->window);
    werase(d->window);
    wrefresh(d->window);

    QTuiGroupBox *gb = new QTuiGroupBox;
    gb->setCheckable(true);
    //gb->setChecked(false);
    gb->setGeometry(QRect(QPoint(10,6),QSize(32, 12)));
    gb->setTitle("Eng Рус Հայ");

    QTuiPainter painter;
    painter.begin();

    painter.drawWindow(QRect(QPoint(2,3), QSize(48, 18)), "Hellow TUI");

//    painter.drawRect(QRect(QPoint(3,2),QSize(20, 8)));
//    painter.drawText(QPoint(5,5), "Eng Рус Հայ");

    painter.drawGroupBox(gb);

    painter.end();


}

QTuiApplication::~QTuiApplication()
{
    delete d;
}

int QTuiApplication::terminalWidth()
{
    return getmaxx(d->window);

}

int QTuiApplication::terminalHeight()
{
    return getmaxy(d->window);
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
