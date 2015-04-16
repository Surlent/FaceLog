#ifndef CONFIG_H
#define CONFIG_H

#include "mainwindow.h"
#include "ui_config.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <string>
#include <sstream>
#include <QDialog>

namespace Ui {
class Config;
}

class Config : public QDialog
{
    Q_OBJECT

private: 
    void loadConfig(QString fileName);
public:
    explicit Config(QWidget *parent = 0);
    ~Config();
    

private slots:
    void on_pushButtonRestore_clicked();

    void on_pushButtonCancel_clicked();

    void on_pushButtonSave_clicked();
   
private:
    Ui::Config *ui;
};

#endif // CONFIG_H
