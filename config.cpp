#include "config.h"
#include "generic.h"


Config::Config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Config)
{
    ui->setupUi(this);
    this->loadConfig(CONFIG_FILE); 
    //ui->pushButtonRestore->click();
    //ui->pushButtonRestore->setVisible(false);
}

Config::~Config()
{
    delete ui;
}

void Config::on_pushButtonRestore_clicked()
{
 ui->spinBoxMinSize->setValue(30);
 ui->spinBoxMaxSize->setValue(1000);
 ui->spinBoxInterval->setValue(1);
 ui->spinBoxInterval->setValue(0);
}

void Config::on_pushButtonCancel_clicked()
{
    this->close();
}

void Config::on_pushButtonSave_clicked()
{

    QFile config(CONFIG_FILE);
    std::string msg;
    if(config.exists()){
        msg= "File doesn't exist.";
    }
    
    if(!config.open(QIODevice::ReadWrite|QIODevice::Text)){
        msg="Failed to open.";
        
    }
    else
    {
        QTextStream out(&config);
        out<<"minSize:"<<ui->spinBoxMinSize->value()<<"\n";
        out<<"maxSize:"<<ui->spinBoxMaxSize->value()<<"\n";
        out<<"interval:"<<(ui->spinBoxInterval->value())<<"\n";
        out<<"camera:"<<(ui->spinBoxCamera->value());
        msg="Preferences successfully saved.";
    }
    std::cout << msg<<std::endl;
    config.close();

}

void Config::loadConfig(QString fileName)
{
    
    QFile config(fileName);
    std::string msg;
    std::vector< std::vector<std::string> > keyValues;
    
    if(config.exists()){
        msg= "File doesn't exist.";
    }
    
    if(!config.open(QIODevice::ReadOnly|QIODevice::Text)){
        msg="Failed to open file.";
        
    }
    else
    {
        QTextStream in(&config);
        
        while (!in.atEnd()) {
               QString line = in.readLine();
               keyValues.push_back(split(line.toStdString(), ':'));
               //std::cout << line.toStdString()<<std::endl;    
         }
        
        msg="File loaded.";
    }
    config.close();
    std::cout << msg<<std::endl;
    
    
    std::vector< std::vector<std::string> >::iterator keyValuesIterator;
    for(keyValuesIterator = keyValues.begin(); 
        keyValuesIterator != keyValues.end();
        keyValuesIterator++)
        {
        
             std::string key=(*keyValuesIterator)[0];
             int val;
             std::istringstream ss((*keyValuesIterator)[1]);
             ss >> val; 
             if (key=="minSize")
             {           
                ui->spinBoxMinSize->setValue(val);
             }
             if (key=="maxSize")
             {
                ui->spinBoxMaxSize->setValue(val);
             }
             if (key=="interval")
             {
                ui->spinBoxInterval->setValue(val);
             }
             if (key=="camera")
             {
                ui->spinBoxCamera->setValue(val);
             }
       }
    
    
}

