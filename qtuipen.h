#ifndef QTUIPEN_H
#define QTUIPEN_H

#include "qnamespace.h"

class QTuiPenPrivate;
class  QTuiPen
{
public:
    QTuiPen();
    ~QTuiPen();

    enum ConsolePenStyle
    {
        NoPen,
        SolidLine,      // │ ┃
        DashLine2,      // ╎ ╏
        DashLine3,      // ┆ ┇
        DashLine4,      // ┊ ┋
        DoubleLine,     // ║

    };

    Qt::PenStyle style() const;
    void setStyle(Qt::PenStyle style);

    qreal widthF() const;
    void setWidthF(qreal width);

    int width() const;
    void setWidth(int width);

    Qt::GlobalColor color() const;
    void setColor(Qt::GlobalColor color);

    Qt::GlobalColor backgroundColor() const;
    void setBackgroundColor(Qt::GlobalColor color);

private:
    QTuiPenPrivate *d;
};


#endif // QTUIPEN_H
