
#include <QtCore>

#include "qtuiapplication.h"
#include "qtuilineedit.h"
#include "qtuicombobox.h"



int main(int argc, char** argv)
{
    QTuiApplication a(argc, argv);



    QTuiLineEdit le;
    le.show();

    return a.exec();

}
