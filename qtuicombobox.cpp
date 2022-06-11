#include "qtuicombobox.h"

#include <QList>
#include <QPair>

#include "qtuipainter.h"


struct QTuiComboBoxPrivate
{
    QTuiComboBoxPrivate()
    {

    }


    bool                                editable;
    int                                 currentIndex;
    int                                 maxCount;
    int                                 maxVisibleItems;
    QString                             editText;
    QList<QPair<QString, QVariant> >    model;


};

QTuiComboBox::QTuiComboBox(QTuiWidget *parent) : QTuiWidget(parent), d(new QTuiComboBoxPrivate)
{
    /*
    ╭─────────╮╭─────────╮
    │→ tribute││→ tribute│
    ╰─────────╯╰─────────╯
    ╭──────────────╮╭──────────────╮
    │↓ era         ││↓ module      │
    ├──────────────┤├──────────────┤
    │○ tribute    ┃││○ tribute    ┃│
    │○ clearance  ┃││○ clearance  ┃│
    │○ ally       ┃││○ ally       ┃│
    │○ bend       ╹││○ bend       ╹│
    │○ electronics ││○ electronics │
    │○ module      ││◉ module      │
    │◉ era         ││○ era         │
    │○ cultural    ││○ cultural    │
    │○ sniff       ││○ sniff       │
    │○ nationalism ││○ nationalism │
    │○ negotiation ││○ negotiation │
    │○ deliver     ││○ deliver     │
    ╰──────────────╯╰──────────────╯
    */

    setMaxVisibleItems(10);
}

QTuiComboBox::~QTuiComboBox()
{
    delete d;

}

int QTuiComboBox::maxVisibleItems() const
{
    return d->maxVisibleItems;
}

void QTuiComboBox::setMaxVisibleItems(int maxItems)
{
    if (Q_UNLIKELY(maxItems < 0))
    {
        qWarning("QTuiComboBox::setMaxVisibleItems: Invalid max visible items (%d) must be >= 0", maxItems);
        return;
    }
    d->maxVisibleItems = maxItems;
}

int QTuiComboBox::count() const
{
    return d->model.count();
}

void QTuiComboBox::setMaxCount(int max)
{
    if (Q_UNLIKELY(max < 0))
    {
        qWarning("QTuiComboBox::setMaxCount: Invalid count (%d) must be >= 0", max);
        return;
    }
    const int rowCount = count();
    if (rowCount > max)
    {
        d->model = d->model.mid(0, max);
    }
    d->maxCount = max;
}

int QTuiComboBox::maxCount() const
{
    return maxCount();
}

int QTuiComboBox::findText(const QString &text, Qt::MatchFlags flags) const
{
    for(int i = 0; i < d->model.size(); ++i)
    {
        if(d->model[i].first == text)
        {
            return i;
        }
    }
    return -1;
}

int QTuiComboBox::findData(const QVariant &data, int role, Qt::MatchFlags flags) const
{
    for(int i = 0; i < d->model.size(); ++i)
    {
        if(d->model[i].second == data)
        {
            return i;
        }
    }
    return -1;

}

bool QTuiComboBox::isEditable() const
{
    return d->editable;
}

void QTuiComboBox::setEditable(bool editable)
{
    if (isEditable() == editable)
        return;
    setAttribute(Qt::WA_InputMethodEnabled, false);
    d->editable = editable;
}

int QTuiComboBox::currentIndex() const
{
    return d->currentIndex;
}

QString QTuiComboBox::currentText() const
{
    if (isEditable())
        return d->editText;
    else if (d->currentIndex >= 0 && d->currentIndex < d->model.size())
        return d->model.at(d->currentIndex).first;
    else
        return QString();
}

QVariant QTuiComboBox::currentData(int role) const
{
    if (d->currentIndex >= 0 && d->currentIndex < d->model.size())
        return d->model.at(d->currentIndex).second;
    else
        return QVariant();
}

void QTuiComboBox::addItem(const QString &text, const QVariant &userData)
{
    d->model.append(QPair<QString, QVariant>(text,userData));
}

void QTuiComboBox::showPopup()
{
    int rows = qMin(maxVisibleItems(), count());
    QRect geom = QRect(geometry().bottomLeft(), QSize(width(), rows + 2)); ;
    QTuiPainter *painter = QTuiPainter::instance();

    painter->begin();
    painter->drawPopup(geom);
    for(int i = 0; i < rows; ++i)
    {
        painter->drawText(geom.topLeft() + QPoint(3, i+1), geom.topRight() + QPoint(-1, i+1), d->model[i].first);
    }
    painter->drawText(geometry().bottomLeft(), "├");
    painter->drawText(geometry().bottomRight(), "┤");

    painter->end();
}

void QTuiComboBox::hidePopup()
{
//    parentWidget()->repaint();
//    repaint();
}

void QTuiComboBox::clear()
{
    d->model.clear();
}

void QTuiComboBox::clearEditText()
{
    d->editText.clear();
}

void QTuiComboBox::setEditText(const QString &text)
{
    d->editText = text;
}

void QTuiComboBox::setCurrentIndex(int index)
{
    d->currentIndex = index;
}

void QTuiComboBox::setCurrentText(const QString &text)
{
    if (isEditable())
    {
        setEditText(text);
    }
    else
    {
        const int i = findText(text);
        if (i > -1)
        {
            setCurrentIndex(i);
        }
    }
}





