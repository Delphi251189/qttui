#ifndef QTUIEVENTFILTER_H
#define QTUIEVENTFILTER_H

#include <QObject>
#include <QFile>

class QTuiEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit QTuiEventFilter(QObject *parent = Q_NULLPTR);
    virtual ~QTuiEventFilter();

protected:
    virtual bool eventFilter(QObject *watched, QEvent *event);

signals:

private:
    QFile   logfile;

};

#endif // QTUIEVENTFILTER_H
