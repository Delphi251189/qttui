#ifndef QTUILAYOUT_H
#define QTUILAYOUT_H

#include <QObject>
#include <QMargins>
#include <QRect>
class QTuiWidget;


struct  QTuiLayoutPrivate;

class QTuiLayout : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int margin READ margin WRITE setMargin)
    Q_PROPERTY(int spacing READ spacing WRITE setSpacing)
public:
    explicit QTuiLayout(QTuiWidget *parent = Q_NULLPTR);

    int margin() const;
    int spacing() const;

    void setMargin(int);
    void setSpacing(int);

    bool setAlignment(QTuiWidget *w, Qt::Alignment alignment);
    bool setAlignment(QTuiLayout *l, Qt::Alignment alignment);

    QTuiWidget *parentWidget() const;

    void addWidget(QTuiWidget *w);
    virtual void addItem(QTuiLayout *l) = 0;

    void removeWidget(QTuiWidget *w);
    void removeItem(QTuiLayout *l);

    int count() const;
    bool isEmpty();
private:
    QTuiLayoutPrivate *d;

};
#endif // QTUILAYOUT_H



