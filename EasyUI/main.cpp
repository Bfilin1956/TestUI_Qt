#include <QApplication>
#include "easyui.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EasyUI w;

    w.show();
    return a.exec();
}
