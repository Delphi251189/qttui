#ifndef QTUIBOXLAYOUT_H
#define QTUIBOXLAYOUT_H

#include "qtuilayout.h"


class QTuiBoxLayout : public QTuiLayout
{
    Q_OBJECT
public:
    explicit QTuiBoxLayout(QTuiWidget *parent);
    ~QTuiBoxLayout();
};



class QTuiHBoxLayout : public QTuiBoxLayout
{
    Q_OBJECT
public:
    explicit QTuiHBoxLayout(QTuiWidget *parent);
    ~QTuiHBoxLayout();
private:
};



class QTuiVBoxLayout : public QTuiBoxLayout
{
    Q_OBJECT
public:
    explicit QTuiVBoxLayout(QWidget *parent);
    ~QTuiVBoxLayout();
private:
};


#endif // QTUIBOXLAYOUT_H



