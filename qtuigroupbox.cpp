#include "qtuigroupbox.h"


struct QTuiGroupBoxPrivate
{
    void skip();
    void init()
    {
        align           = Qt::AlignLeft;
        flat            = false;
        checkable       = false;
        checked         = true;
        hover           = false;
        overCheckBox    = false;
        calculateFrame();
        //q->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred, QSizePolicy::GroupBox));
    }
    void calculateFrame()
    {
    }


    QString title;
    Qt::Alignment align;
    void click();
    bool flat;
    bool checkable;
    bool checked;
    bool hover;
    bool overCheckBox;
};

QTuiGroupBox::QTuiGroupBox(QTuiWidget *parent) : QTuiWidget(parent), d(new QTuiGroupBoxPrivate)
{
    d->init();
}

QTuiGroupBox::QTuiGroupBox(const QString &title, QTuiWidget *parent)
    : QTuiWidget(parent), d(new QTuiGroupBoxPrivate)
{
    setTitle(title);
}

QString QTuiGroupBox::title() const
{
    return d->title;
}

void QTuiGroupBox::setTitle(const QString &title)
{
    if (d->title == title)
        return;
    d->title = title;
    d->calculateFrame();
    update();
    updateGeometry();
}

Qt::Alignment QTuiGroupBox::alignment() const
{
    return d->align;
}

void QTuiGroupBox::setAlignment(Qt::Alignment alignment)
{
    d->align = alignment;
    updateGeometry();
    update();
}

bool QTuiGroupBox::isFlat() const
{
    return d->flat;
}

void QTuiGroupBox::setFlat(bool flat)
{
    if (d->flat == flat)
    {
        return;
    }
    d->flat = flat;
    updateGeometry();
    update();
}

bool QTuiGroupBox::isCheckable() const
{
    return d->checkable;
}

void QTuiGroupBox::setCheckable(bool checkable)
{
    bool wasCheckable = d->checkable;
    d->checkable = checkable;
    if (checkable)
    {
        setChecked(true);
        if (!wasCheckable)
        {
            setFocusPolicy(Qt::StrongFocus);
            //d->_q_setChildrenEnabled(true);
            updateGeometry();
        }
    }
    else
    {
        if (wasCheckable)
        {
            setFocusPolicy(Qt::NoFocus);
            //d->_q_setChildrenEnabled(true);
            updateGeometry();
        }
        //d->_q_setChildrenEnabled(true);
    }
    if (wasCheckable != checkable)
    {
        d->calculateFrame();
        update();
    }
}

bool QTuiGroupBox::isChecked() const
{
    return d->checked;
}

void QTuiGroupBox::setChecked(bool checked)
{
    if (d->checkable && checked != d->checked)
    {
        update();
        d->checked = checked;
        //d->_q_setChildrenEnabled(b);
        emit toggled(checked);
    }
}
