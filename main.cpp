
#include <QtCore>

#include "qtuiapplication.h"
#include "qtuilineedit.h"
#include "qtuicombobox.h"
#include "qtuigroupbox.h"

#include "qtuipainter.h"




int main(int argc, char** argv)
{
    QTuiApplication a(argc, argv);








    QTuiGroupBox *gb = new QTuiGroupBox;
    gb->setCheckable(true);
    gb->setChecked(false);
    gb->setGeometry(QRect(QPoint(6,6),QSize(32, 12)));
    gb->setTitle("Eng Рус Հայ");

    QTuiComboBox *cb = new QTuiComboBox;
    cb->setEditable(false);
    cb->setGeometry(QRect(QPoint(40,6),QSize(16, 3)));
    cb->addItem("Apple");
    cb->addItem("Corel");
    cb->addItem("Adobe");
    cb->addItem("Intel");
    cb->addItem("AMD");



    QTuiPainter *painter = QTuiPainter::instance();
    painter->begin();
    painter->drawWindow(QRect(QPoint(2,3), QSize(64, 18)), "Hellow TUI");
    painter->drawGroupBox(gb);
    painter->drawComboBox(cb);
    painter->end();


    QTimer::singleShot(3000, cb, SLOT(showPopup()));



    return a.exec();

}
