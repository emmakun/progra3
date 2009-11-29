#include <QtGui/QApplication>
#include "principal.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Principal w;
    w.show();
    return a.exec();
}
