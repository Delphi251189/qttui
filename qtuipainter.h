#ifndef QTUIPAINTER_H
#define QTUIPAINTER_H

#include <QtCore>

struct QTuiPainterPrivate;

class QTuiPainter
{
    Q_GADGET
public:
    QTuiPainter();
    ~QTuiPainter();

    bool begin();
    bool end();
    bool isActive() const;
    void setPen(const QColor &color);
    void setPen(const QPen &pen);
    void setPen(Qt::PenStyle style);
    const QPen &pen() const;
    void setBrush(const QBrush &brush);
    void setBrush(Qt::BrushStyle style);
    const QBrush &brush() const;

    // drawing functions
    void drawHorizontalLine(int x1, int y1, int x2, int y2);
    void drawHorizontalLine(const QPoint &p1, const QPoint &p2);


    void drawVerticalLine(int x1, int y1, int x2, int y2);
    void drawVerticalLine(const QPoint &p1, const QPoint &p2);

    void drawRect(int x1, int y1, int w, int h);
    void drawRect(const QRect &rect);

    void drawText(const QPoint &p, const QString &s);



    // drawing functions

private:
    QTuiPainterPrivate *d;

};

/*

class Q_GUI_EXPORT QPainter
{




    void strokePath(const QPainterPath &path, const QPen &pen);
    void fillPath(const QPainterPath &path, const QBrush &brush);
    void drawPath(const QPainterPath &path);

    inline void drawPoint(const QPointF &pt);
    inline void drawPoint(const QPoint &p);
    inline void drawPoint(int x, int y);

    void drawPoints(const QPointF *points, int pointCount);
    inline void drawPoints(const QPolygonF &points);
    void drawPoints(const QPoint *points, int pointCount);
    inline void drawPoints(const QPolygon &points);

    inline void drawLine(const QLineF &line);
    inline void drawLine(const QLine &line);
    void drawLines(const QLineF *lines, int lineCount);
    inline void drawLines(const QVector<QLineF> &lines);
    void drawLines(const QPointF *pointPairs, int lineCount);
    inline void drawLines(const QVector<QPointF> &pointPairs);
    void drawLines(const QLine *lines, int lineCount);
    inline void drawLines(const QVector<QLine> &lines);
    void drawLines(const QPoint *pointPairs, int lineCount);
    inline void drawLines(const QVector<QPoint> &pointPairs);


    void drawRects(const QRectF *rects, int rectCount);
    inline void drawRects(const QVector<QRectF> &rectangles);
    void drawRects(const QRect *rects, int rectCount);
    inline void drawRects(const QVector<QRect> &rectangles);

    void drawEllipse(const QRectF &r);
    void drawEllipse(const QRect &r);
    inline void drawEllipse(int x, int y, int w, int h);

    inline void drawEllipse(const QPointF &center, qreal rx, qreal ry);
    inline void drawEllipse(const QPoint &center, int rx, int ry);

    void drawPolyline(const QPointF *points, int pointCount);
    inline void drawPolyline(const QPolygonF &polyline);
    void drawPolyline(const QPoint *points, int pointCount);
    inline void drawPolyline(const QPolygon &polygon);

    void drawPolygon(const QPointF *points, int pointCount, Qt::FillRule fillRule = Qt::OddEvenFill);
    inline void drawPolygon(const QPolygonF &polygon, Qt::FillRule fillRule = Qt::OddEvenFill);
    void drawPolygon(const QPoint *points, int pointCount, Qt::FillRule fillRule = Qt::OddEvenFill);
    inline void drawPolygon(const QPolygon &polygon, Qt::FillRule fillRule = Qt::OddEvenFill);

    void drawConvexPolygon(const QPointF *points, int pointCount);
    inline void drawConvexPolygon(const QPolygonF &polygon);
    void drawConvexPolygon(const QPoint *points, int pointCount);
    inline void drawConvexPolygon(const QPolygon &polygon);

    void drawArc(const QRectF &rect, int a, int alen);
    inline void drawArc(const QRect &, int a, int alen);
    inline void drawArc(int x, int y, int w, int h, int a, int alen);

    void drawPie(const QRectF &rect, int a, int alen);
    inline void drawPie(int x, int y, int w, int h, int a, int alen);
    inline void drawPie(const QRect &, int a, int alen);

    void drawChord(const QRectF &rect, int a, int alen);
    inline void drawChord(int x, int y, int w, int h, int a, int alen);
    inline void drawChord(const QRect &, int a, int alen);

    void drawRoundedRect(const QRectF &rect, qreal xRadius, qreal yRadius,
                         Qt::SizeMode mode = Qt::AbsoluteSize);
    inline void drawRoundedRect(int x, int y, int w, int h, qreal xRadius, qreal yRadius,
                                Qt::SizeMode mode = Qt::AbsoluteSize);
    inline void drawRoundedRect(const QRect &rect, qreal xRadius, qreal yRadius,
                                Qt::SizeMode mode = Qt::AbsoluteSize);

    void drawRoundRect(const QRectF &r, int xround = 25, int yround = 25);
    inline void drawRoundRect(int x, int y, int w, int h, int = 25, int = 25);
    inline void drawRoundRect(const QRect &r, int xround = 25, int yround = 25);

    void drawTiledPixmap(const QRectF &rect, const QPixmap &pm, const QPointF &offset = QPointF());
    inline void drawTiledPixmap(int x, int y, int w, int h, const QPixmap &, int sx=0, int sy=0);
    inline void drawTiledPixmap(const QRect &, const QPixmap &, const QPoint & = QPoint());



    void setLayoutDirection(Qt::LayoutDirection direction);
    Qt::LayoutDirection layoutDirection() const;



    void drawStaticText(const QPointF &topLeftPosition, const QStaticText &staticText);
    inline void drawStaticText(const QPoint &topLeftPosition, const QStaticText &staticText);
    inline void drawStaticText(int left, int top, const QStaticText &staticText);

    inline void drawText(int x, int y, const QString &s);

    void drawText(const QPointF &p, const QString &str, int tf, int justificationPadding);

    void drawText(const QRectF &r, int flags, const QString &text, QRectF *br = nullptr);
    void drawText(const QRect &r, int flags, const QString &text, QRect *br = nullptr);
    inline void drawText(int x, int y, int w, int h, int flags, const QString &text, QRect *br = nullptr);

    void drawText(const QRectF &r, const QString &text, const QTextOption &o = QTextOption());

    QRectF boundingRect(const QRectF &rect, int flags, const QString &text);
    QRect boundingRect(const QRect &rect, int flags, const QString &text);
    inline QRect boundingRect(int x, int y, int w, int h, int flags, const QString &text);

    QRectF boundingRect(const QRectF &rect, const QString &text, const QTextOption &o = QTextOption());

    void drawTextItem(const QPointF &p, const QTextItem &ti);
    inline void drawTextItem(int x, int y, const QTextItem &ti);
    inline void drawTextItem(const QPoint &p, const QTextItem &ti);

    void fillRect(const QRectF &, const QBrush &);
    inline void fillRect(int x, int y, int w, int h, const QBrush &);
    void fillRect(const QRect &, const QBrush &);

    void fillRect(const QRectF &, const QColor &color);
    inline void fillRect(int x, int y, int w, int h, const QColor &color);
    void fillRect(const QRect &, const QColor &color);

    inline void fillRect(int x, int y, int w, int h, Qt::GlobalColor c);
    inline void fillRect(const QRect &r, Qt::GlobalColor c);
    inline void fillRect(const QRectF &r, Qt::GlobalColor c);

    inline void fillRect(int x, int y, int w, int h, Qt::BrushStyle style);
    inline void fillRect(const QRect &r, Qt::BrushStyle style);
    inline void fillRect(const QRectF &r, Qt::BrushStyle style);

    inline void fillRect(int x, int y, int w, int h, QGradient::Preset preset);
    inline void fillRect(const QRect &r, QGradient::Preset preset);
    inline void fillRect(const QRectF &r, QGradient::Preset preset);

    void eraseRect(const QRectF &);
    inline void eraseRect(int x, int y, int w, int h);
    inline void eraseRect(const QRect &);

    void setRenderHint(RenderHint hint, bool on = true);
    void setRenderHints(RenderHints hints, bool on = true);
    RenderHints renderHints() const;
    inline bool testRenderHint(RenderHint hint) const { return renderHints() & hint; }

    QPaintEngine *paintEngine() const;

    static void setRedirected(const QPaintDevice *device, QPaintDevice *replacement,
                              const QPoint& offset = QPoint());
    static QPaintDevice *redirected(const QPaintDevice *device, QPoint *offset = nullptr);
    static void restoreRedirected(const QPaintDevice *device);

    void beginNativePainting();
    void endNativePainting();

private:
    Q_DISABLE_COPY(QPainter)

    QScopedPointer<QPainterPrivate> d_ptr;

    friend class QWidget;
    friend class QFontEngine;
    friend class QFontEngineBox;
    friend class QFontEngineFT;
    friend class QFontEngineMac;
    friend class QFontEngineWin;
    friend class QPaintEngine;
    friend class QPaintEngineExPrivate;
    friend class QOpenGLPaintEngine;
    friend class QWin32PaintEngine;
    friend class QWin32PaintEnginePrivate;
    friend class QRasterPaintEngine;
    friend class QAlphaPaintEngine;
    friend class QPreviewPaintEngine;
    friend class QTextEngine;
};
Q_DECLARE_TYPEINFO(QPainter::PixmapFragment, Q_RELOCATABLE_TYPE);

Q_DECLARE_OPERATORS_FOR_FLAGS(QPainter::RenderHints)

//
// functions
//
inline void QPainter::drawLine(const QLineF &l)
{
    drawLines(&l, 1);
}

inline void QPainter::drawLine(const QLine &line)
{
    drawLines(&line, 1);
}

inline void QPainter::drawLine(int x1, int y1, int x2, int y2)
{
    QLine l(x1, y1, x2, y2);
    drawLines(&l, 1);
}

inline void QPainter::drawLine(const QPoint &p1, const QPoint &p2)
{
    QLine l(p1, p2);
    drawLines(&l, 1);
}

inline void QPainter::drawLine(const QPointF &p1, const QPointF &p2)
{
    drawLine(QLineF(p1, p2));
}

inline void QPainter::drawLines(const QVector<QLineF> &lines)
{
    drawLines(lines.constData(), lines.size());
}

inline void QPainter::drawLines(const QVector<QLine> &lines)
{
    drawLines(lines.constData(), lines.size());
}

inline void QPainter::drawLines(const QVector<QPointF> &pointPairs)
{
    drawLines(pointPairs.constData(), pointPairs.size() / 2);
}

inline void QPainter::drawLines(const QVector<QPoint> &pointPairs)
{
    drawLines(pointPairs.constData(), pointPairs.size() / 2);
}

inline void QPainter::drawPolyline(const QPolygonF &polyline)
{
    drawPolyline(polyline.constData(), polyline.size());
}

inline void QPainter::drawPolyline(const QPolygon &polyline)
{
    drawPolyline(polyline.constData(), polyline.size());
}

inline void QPainter::drawPolygon(const QPolygonF &polygon, Qt::FillRule fillRule)
{
    drawPolygon(polygon.constData(), polygon.size(), fillRule);
}

inline void QPainter::drawPolygon(const QPolygon &polygon, Qt::FillRule fillRule)
{
    drawPolygon(polygon.constData(), polygon.size(), fillRule);
}

inline void QPainter::drawConvexPolygon(const QPolygonF &poly)
{
    drawConvexPolygon(poly.constData(), poly.size());
}

inline void QPainter::drawConvexPolygon(const QPolygon &poly)
{
    drawConvexPolygon(poly.constData(), poly.size());
}

inline void QPainter::drawRect(const QRectF &rect)
{
    drawRects(&rect, 1);
}

inline void QPainter::drawRect(int x, int y, int w, int h)
{
    QRect r(x, y, w, h);
    drawRects(&r, 1);
}

inline void QPainter::drawRect(const QRect &r)
{
    drawRects(&r, 1);
}

inline void QPainter::drawRects(const QVector<QRectF> &rects)
{
    drawRects(rects.constData(), rects.size());
}

inline void QPainter::drawRects(const QVector<QRect> &rects)
{
    drawRects(rects.constData(), rects.size());
}

inline void QPainter::drawPoint(const QPointF &p)
{
    drawPoints(&p, 1);
}

inline void QPainter::drawPoint(int x, int y)
{
    QPoint p(x, y);
    drawPoints(&p, 1);
}

inline void QPainter::drawPoint(const QPoint &p)
{
    drawPoints(&p, 1);
}

inline void QPainter::drawPoints(const QPolygonF &points)
{
    drawPoints(points.constData(), points.size());
}

inline void QPainter::drawPoints(const QPolygon &points)
{
    drawPoints(points.constData(), points.size());
}

inline void QPainter::drawRoundRect(int x, int y, int w, int h, int xRnd, int yRnd)
{
    drawRoundRect(QRectF(x, y, w, h), xRnd, yRnd);
}

inline void QPainter::drawRoundRect(const QRect &rect, int xRnd, int yRnd)
{
    drawRoundRect(QRectF(rect), xRnd, yRnd);
}

inline void QPainter::drawRoundedRect(int x, int y, int w, int h, qreal xRadius, qreal yRadius,
                            Qt::SizeMode mode)
{
    drawRoundedRect(QRectF(x, y, w, h), xRadius, yRadius, mode);
}

inline void QPainter::drawRoundedRect(const QRect &rect, qreal xRadius, qreal yRadius,

::SizeMode mode)
{
    drawRoundedRect(QRectF(rect), xRadius, yRadius, mode);
}

inline void QPainter::drawEllipse(int x, int y, int w, int h)
{
    drawEllipse(QRect(x, y, w, h));
}

inline void QPainter::drawEllipse(const QPointF &center, qreal rx, qreal ry)
{
    drawEllipse(QRectF(center.x() - rx, center.y() - ry, 2 * rx, 2 * ry));
}

inline void QPainter::drawEllipse(const QPoint &center, int rx, int ry)
{
    drawEllipse(QRect(center.x() - rx, center.y() - ry, 2 * rx, 2 * ry));
}

inline void QPainter::drawArc(const QRect &r, int a, int alen)
{
    drawArc(QRectF(r), a, alen);
}

inline void QPainter::drawArc(int x, int y, int w, int h, int a, int alen)
{
    drawArc(QRectF(x, y, w, h), a, alen);
}

inline void QPainter::drawPie(const QRect &rect, int a, int alen)
{
    drawPie(QRectF(rect), a, alen);
}

inline void QPainter::drawPie(int x, int y, int w, int h, int a, int alen)
{
    drawPie(QRectF(x, y, w, h), a, alen);
}

inline void QPainter::drawChord(const QRect &rect, int a, int alen)
{
    drawChord(QRectF(rect), a, alen);
}

inline void QPainter::drawChord(int x, int y, int w, int h, int a, int alen)
{
    drawChord(QRectF(x, y, w, h), a, alen);
}

inline void QPainter::setClipRect(int x, int y, int w, int h, Qt::ClipOperation op)
{
    setClipRect(QRect(x, y, w, h), op);
}

inline void QPainter::eraseRect(const QRect &rect)
{
    eraseRect(QRectF(rect));
}

inline void QPainter::eraseRect(int x, int y, int w, int h)
{
    eraseRect(QRectF(x, y, w, h));
}

inline void QPainter::fillRect(int x, int y, int w, int h, const QBrush &b)
{
    fillRect(QRect(x, y, w, h), b);
}

inline void QPainter::fillRect(int x, int y, int w, int h, const QColor &b)
{
    fillRect(QRect(x, y, w, h), b);
}

inline void QPainter::fillRect(int x, int y, int w, int h, Qt::GlobalColor c)
{
    fillRect(QRect(x, y, w, h), QColor(c));
}

inline void QPainter::fillRect(const QRect &r, Qt::GlobalColor c)
{
    fillRect(r, QColor(c));
}

inline void QPainter::fillRect(const QRectF &r, Qt::GlobalColor c)
{
    fillRect(r, QColor(c));
}

inline void QPainter::fillRect(int x, int y, int w, int h, Qt::BrushStyle style)
{
    fillRect(QRectF(x, y, w, h), QBrush(style));
}

inline void QPainter::fillRect(const QRect &r, Qt::BrushStyle style)
{
    fillRect(QRectF(r), QBrush(style));
}

inline void QPainter::fillRect(const QRectF &r, Qt::BrushStyle style)
{
    fillRect(r, QBrush(style));
}

inline void QPainter::fillRect(int x, int y, int w, int h, QGradient::Preset p)
{
    fillRect(QRect(x, y, w, h), QGradient(p));
}

inline void QPainter::fillRect(const QRect &r, QGradient::Preset p)
{
    fillRect(r, QGradient(p));
}




QT_END_NAMESPACE

#endif // QPAINTER_H



*/
#endif // QTUIPAINTER_H
