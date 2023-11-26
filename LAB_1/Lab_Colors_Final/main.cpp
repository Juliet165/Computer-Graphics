
#include "colors.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Colors w;
    w.setWindowTitle("Color Models");
    w.setStyleSheet("font: 20px \"Verdana\";");
    w.setWindowIcon(QIcon("icon.png"));
    w.show();
    return a.exec();
}
