#include "myframe.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::string source;
    source.assign(a.applicationDirPath().toStdString());
    MyFrame w(0,source);
    w.show();

    return a.exec();
}
