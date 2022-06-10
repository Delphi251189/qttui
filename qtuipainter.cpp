#include "qtuipainter.h"
#include "qtuiapplication.h"

#include <ncurses.h>

struct QTuiPainterPrivate
{
    QTuiPainterPrivate() : window(Q_NULLPTR)
    {
    }



    WINDOW *window;
};
QTuiPainter::QTuiPainter() : d(new QTuiPainterPrivate)
{

}

QTuiPainter::~QTuiPainter()
{
    delete d;
}

bool QTuiPainter::begin()
{
//    start_color();
//    init_pair(1, COLOR_YELLOW, COLOR_BLUE);
//    attron(COLOR_PAIR(1));
//    clear();
    return true;
}

bool QTuiPainter::end()
{

//    attroff(COLOR_PAIR(1));
    refresh();
    return true;
}

void QTuiPainter::drawHorizontalLine(int x1, int y1, int x2, int y2)
{
    drawHorizontalLine(QPoint(x1,y1), QPoint(x2,y2));
}

void QTuiPainter::drawHorizontalLine(const QPoint &p1, const QPoint &p2)
{
    static const char *str = "─";
    int y  = p1.y();
    int x1 = qMin(p1.x(), p2.x());
    int x2 = qMax(p1.x(), p2.x());

    for(int i = x1; i <= x2; ++i)
    {
        move(y, i);
        addstr(str);
    }
}

void QTuiPainter::drawVerticalLine(int x1, int y1, int x2, int y2)
{
    drawVerticalLine(QPoint(x1, y1), QPoint(x2, y2));
}

void QTuiPainter::drawVerticalLine(const QPoint &p1, const QPoint &p2)
{

    static const char *str = "│";
    int x  = p1.x();
    int y1 = qMin(p1.y(), p2.y());
    int y2 = qMax(p1.y(), p2.y());

    for(int i = y1; i <= y2; ++i)
    {
        move(i, x);

        addstr(str);
    }


}

void QTuiPainter::drawRect(int x1, int y1, int w, int h)
{
    drawRect(QRect(x1, y1, w, h));
}

void QTuiPainter::drawRect(const QRect &rect)
{

    /*
╭─────────╮
│         │
╰─────────╯
    */

    drawHorizontalLine(rect.topLeft(), rect.topRight());
    drawHorizontalLine(rect.bottomLeft(), rect.bottomRight());
    drawVerticalLine(rect.topLeft(), rect.bottomLeft());
    drawVerticalLine(rect.topRight(), rect.bottomRight());

    move(rect.topLeft().y(), rect.topLeft().x());
    addstr("╭");

    move(rect.topRight().y(), rect.topRight().x());
    addstr("╮");

    move(rect.bottomLeft().y(), rect.bottomLeft().x());
    addstr("╰");

    move(rect.bottomRight().y(), rect.bottomRight().x());
    addstr("╯");

}

void QTuiPainter::drawText(const QPoint &p, const QString &s)
{
    move(p.y(), p.x());
    addstr(s.toUtf8().constData());
}
