#include "toolbox1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    toolbox1 w;
    w.resize(300, 600);//设置主窗口大小宽300，高600
    w.show();

    return a.exec();
}
