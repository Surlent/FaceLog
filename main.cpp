#include "mainwindow.h"
#include <QApplication>
#include "FaceLog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.move(0,0);
    return a.exec();
    
}


/*
int main() {
  FaceLog* l = new FaceLog(0);
  l->detectAndDraw();
  return 0;
}*/



