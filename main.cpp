#include "simpletimerqt.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimpleTimerQt w;
    w.show();
    return a.exec();
}
