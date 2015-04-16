#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTimer"
#include "opencv2/highgui/highgui.hpp"
#include "QDebug"
#include "QStringListModel"
#include "QFile"
#include "QTextStream"
#include <stdio.h>
#include <stdlib.h>
#include "generic.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    int minSize,maxSize,interval,cameraNumber;
    void startCapture();
    void stopCapture();
public:
    explicit MainWindow(QWidget *parent = 0);    
    void saveToFile(std::string fileName="file/log.txt");
    QImage getQImageFromFrame(cv::Mat frame);
    void loadPreferences(QString fileName);

    QTimer *timer1;
    QTimer *timer2;
    ~MainWindow();

public slots:
    void displayFrame();
    void updateList();
    
private slots:
    void toggleCapture();
    
    void on_actionPreferences_triggered();

private:
    Ui::MainWindow *ui;
    
};




#endif // MAINWINDOW_H
