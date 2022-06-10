
#include <QCoreApplication>

#include "qtuilineedit.h"
#include "qtuicombobox.h"


int main(int argc, char** argv)
{
    QCoreApplication a(argc, argv);


    QTuiLineEdit le;
    le.show();

    return a.exec();

}
