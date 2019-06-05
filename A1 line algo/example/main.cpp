#include "mainwindow.h"
#include <QApplication>
#include<QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;    
    w.setWindowTitle("Example");



    w.show();

    return a.exec();
}
