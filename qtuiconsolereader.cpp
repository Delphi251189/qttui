#include "qtuiconsolereader.h"
#include <stdio.h>
#include <unistd.h>
#include <termios.h>


static struct termios oldSettings;
static struct termios newSettings;

void initTermios(int echo)
{
  tcgetattr(0, &oldSettings); /* grab old terminal i/o settings */
  newSettings = oldSettings; /* make new settings same as old settings */
  newSettings.c_lflag &= ~ICANON; /* disable buffered i/o */
  newSettings.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &newSettings); /* use these new terminal i/o settings now */
}

void resetTermios(void)
{
  tcsetattr(0, TCSANOW, &oldSettings);
}

QTuiConsoleReader::QTuiConsoleReader(QObject *parent) :QThread(parent)
{
    initTermios(0);
}

QTuiConsoleReader::~QTuiConsoleReader()
{
    resetTermios();
}

void QTuiConsoleReader::run()
{
    forever
    {
        char key = getchar();
        emit keyPressed(key);
    }
}
