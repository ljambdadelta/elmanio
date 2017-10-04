#include "mine.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mine w;
    w.show();

    return a.exec();
}
