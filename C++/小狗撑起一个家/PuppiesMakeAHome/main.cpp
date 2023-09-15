#include "shijx_widget.h"
#include <QApplication>
int haveLoadGame=0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShiJX_Widget w;
    w.show();

    return a.exec();
}
