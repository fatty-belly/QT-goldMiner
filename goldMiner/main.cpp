#include "startWindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow s;
    s.show();
    return a.exec();
}
