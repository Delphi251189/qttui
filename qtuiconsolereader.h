#ifndef QTUICONSOLEREADER_H
#define QTUICONSOLEREADER_H

#include <QThread>

class QTuiConsoleReader : public QThread
{
    Q_OBJECT
signals:
    void keyPressed(char ch);
public:
   QTuiConsoleReader(QObject *parent = Q_NULLPTR);
   ~QTuiConsoleReader();
   void run();
};

#endif // QTUICONSOLEREADER_H
