#include "widget.h"
#include <QApplication>

int WinMain(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
