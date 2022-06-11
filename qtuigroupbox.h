#ifndef QTUIGROUPBOX_H
#define QTUIGROUPBOX_H

#include "qtuiwidget.h"

struct QTuiGroupBoxPrivate;
class QTuiGroupBox : public QTuiWidget
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle)
    Q_PROPERTY(Qt::Alignment alignment READ alignment WRITE setAlignment)
    Q_PROPERTY(bool flat READ isFlat WRITE setFlat)
    Q_PROPERTY(bool checkable READ isCheckable WRITE setCheckable)
    Q_PROPERTY(bool checked READ isChecked WRITE setChecked DESIGNABLE isCheckable NOTIFY toggled USER true)
public:
    explicit QTuiGroupBox(QTuiWidget *parent = Q_NULLPTR);
    explicit QTuiGroupBox(const QString &title, QTuiWidget *parent = Q_NULLPTR);

    QString title() const;
    void setTitle(const QString &title);

    Qt::Alignment alignment() const;
    void setAlignment(Qt::Alignment alignment);

    bool isFlat() const;
    void setFlat(bool flat);

    bool isCheckable() const;
    void setCheckable(bool checkable);

    bool isChecked() const;
public slots:
    void setChecked(bool checked);
signals:
    void clicked(bool checked = false);
    void toggled(bool);

private:
    QTuiGroupBoxPrivate *d;
};

#endif // QTUIGROUPBOX_H

