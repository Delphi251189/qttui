#include "qtuipainter.h"
#include "qtuiapplication.h"

#include <ncurses.h>

#include "qtuipen.h"
#include "qtuiwidget.h"
#include "qtuigroupbox.h"
#include "qtuicombobox.h"
#include "qtuilineedit.h"

static QTuiPainter *g_painter = Q_NULLPTR;

struct QTuiPainterPrivate
{
    QTuiPainterPrivate() : window(Q_NULLPTR)
    {

        setlocale(LC_CTYPE, "");
        window = initscr();


        if (has_colors())
        {
            start_color();
        }
        wclear(window);
        werase(window);
        wrefresh(window);

    }

    NCURSES_COLOR_T qtColorToNcursesColor(Qt::GlobalColor color)
    {

        switch (color)
        {
            case Qt::white:
                return COLOR_WHITE;

            case Qt::red:
            case Qt::darkRed:
                return COLOR_RED;

            case Qt::green:
            case Qt::darkGreen:
                return COLOR_GREEN;

            case Qt::blue:
            case Qt::darkBlue:
                return COLOR_BLUE;

            case Qt::cyan:
            case Qt::darkCyan:
                return COLOR_CYAN;

            case Qt::magenta:
            case Qt::darkMagenta:
                return COLOR_MAGENTA;

            case Qt::darkYellow:
            case Qt::yellow:
                return COLOR_YELLOW;
        case Qt::black:
        case Qt::lightGray:
        case Qt::gray:
        case Qt::darkGray:
        default:
            return COLOR_BLACK;
            break;
        }
    }

    WINDOW  *window;
    QTuiPen pen;

};
QTuiPainter::QTuiPainter() : d(new QTuiPainterPrivate)
{
//    begin();
//    fillRect(QRect(0, 0, terminalWidth(), terminalHeight()), Qt::yellow);
//    end();
}

QTuiPainter::~QTuiPainter()
{
    delete d;
}

QTuiPainter *QTuiPainter::instance()
{
    return g_painter;
}

int QTuiPainter::terminalWidth()
{
    getmaxx(d->window);
}

int QTuiPainter::terminalHeight()
{
    return getmaxy(d->window);
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
    curs_set(0);
    return true;
}

void QTuiPainter::setPen(const QTuiPen &pen)
{
    d->pen = pen;

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

void QTuiPainter::drawDoubleHorizontalLine(const QPoint &p1, const QPoint &p2)
{
    static const char *str = "═";
    int y  = p1.y();
    int x1 = qMin(p1.x(), p2.x());
    int x2 = qMax(p1.x(), p2.x());

    for(int i = x1; i <= x2; ++i)
    {
        move(y, i);
        addstr(str);
    }

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

void QTuiPainter::drawDoubleVerticalLine(const QPoint &p1, const QPoint &p2)
{
    static const char *str = "║";
    int x  = p1.x();
    int y1 = qMin(p1.y(), p2.y());
    int y2 = qMax(p1.y(), p2.y());

    for(int i = y1; i <= y2; ++i)
    {
        move(i, x);

        addstr(str);
    }
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

void QTuiPainter::drawDoubleRect(const QRect &rect)
{
    /*
╔═════════╗
║         ║
╚═════════╝
    */

    drawDoubleHorizontalLine(rect.topLeft(), rect.topRight());
    drawDoubleHorizontalLine(rect.bottomLeft(), rect.bottomRight());
    drawDoubleVerticalLine(rect.topLeft(), rect.bottomLeft());
    drawDoubleVerticalLine(rect.topRight(), rect.bottomRight());
    move(rect.topLeft().y(), rect.topLeft().x());
    addstr("╔");
    move(rect.topRight().y(), rect.topRight().x());
    addstr("╗");
    move(rect.bottomLeft().y(), rect.bottomLeft().x());
    addstr("╚");
    move(rect.bottomRight().y(), rect.bottomRight().x());
    addstr("╝");

}

void QTuiPainter::fillRect(const QRect &rect, Qt::GlobalColor color)
{

    init_pair(1, COLOR_WHITE, d->qtColorToNcursesColor(color));
    attron(COLOR_PAIR(1));
    for(int i = rect.topLeft().x(); i < rect.topLeft().x() + rect.width(); ++i)
    {
        for(int j = rect.topLeft().y(); j < rect.topLeft().y() + rect.height(); ++j)
        {
            move(j, i);
            addstr(" ");
        }
    }
    attroff(COLOR_PAIR(1));

}

void QTuiPainter::drawText(const QPoint &p, const QString &s)
{
    move(p.y(), p.x());
    addstr(s.toUtf8().constData());
}

void QTuiPainter::drawText(const QPoint &p1, const QPoint &p2, const QString &s)
{
    drawText((p1.x() < p2.x())?p1:p2, s.mid(0, qAbs(p1.x()-p2.x())));
}

void QTuiPainter::drawWindow(const QRect &geom, const QString &title)
{
    drawDoubleRect(geom);
    QRect r2 = geom.marginsRemoved(QMargins(0,0,0,geom.height()-3));
    drawHorizontalLine(r2.bottomLeft(), r2.bottomRight());
    drawText(r2.topLeft() + QPoint(0,2), "╟");
    drawText(r2.topRight() - QPoint(0,-2), "╢");
    drawText( r2.topLeft() + QPoint(3,1), r2.topRight() - QPoint(6,1), title);
    drawText(r2.topRight()  - QPoint(5,-1), "_ ☐ X" );
}

void QTuiPainter::drawPopup(const QRect &geom)
{
    /*
     *
    ╭──────────────╮
    │↓ tribute     │
    ┌──────────────┐
    │ABCD          │
    │ABCDE        ┃│
    │ABCDEF       ┃│
    │ABCDEFG      ╹│
    │ABCDEFGH      │
    │ABCDEFGHI     │
    │ABCDEFGHIJ    │
    │ABCDEFGHIJK   │
    ╰──────────────╯
    */

    drawRect(geom);
    drawText(geom.topLeft(),        "┌");
    drawText(geom.topRight(),       "┐");
    drawText(geom.bottomLeft(),     "╰");
    drawText(geom.bottomRight(),    "╯");
}

void QTuiPainter::drawComboBox(QTuiComboBox *cb)
{
    /*
╭──────────────╮╭─────────╮
│↓ tribute     ││→ tribute│
├──────────────┤╰─────────╯
│◉ tribute    ┃│
│○ clearance  ┃│
│○ ally       ┃│
│○ bend       ╹│
│○ electronics │
│○ module      │
│○ era         │
│○ cultural    │
│○ sniff       │
│○ nationalism │
│○ negotiation │
│○ deliver     │
╰──────────────╯
*/
    QRect geom = cb->geometry();
    drawRect(geom);
    drawText(geom.topLeft() + QPoint(1,1), geom.topRight() + QPoint(-3,1), cb->currentText());
    drawText(geom.topRight() + QPoint(-2,1), QString("↓"));

}

void QTuiPainter::drawGroupBox(QTuiGroupBox *gb)
{
    QRect geom = gb->geometry();
    drawRect(geom);
    geom = geom.marginsRemoved(QMargins(gb->isCheckable() ? 4 : 2, 0, 2, 0));
    drawText(geom.topLeft(), geom.topRight(), gb->title());
    if(gb->isCheckable())
    {
        drawText(geom.topLeft()- QPoint(2,0),  gb->isChecked()? "▣ " : "☐ " );
    }
}
