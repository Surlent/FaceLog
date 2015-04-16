#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"
#include "FaceLog.h"
#include "LogMaker.h"



using namespace cv;
using namespace std;
QStringList qList;
QStringList qList2;
int nLinhas;
int sec=1000;
float fps;
FaceLog* faceLog;
LogMaker* logMaker;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(QString(":/img/off.png")));   
    
    // Connect button signal to appropriate slot
    connect(ui->startButton, SIGNAL(released()), this, SLOT(toggleCapture()));
   


}

MainWindow::~MainWindow()
{
    delete faceLog;
    delete logMaker;
    delete ui;
}


void MainWindow::on_actionPreferences_triggered()
{
    if (ui->startButton->text()=="Stop")
    {
    this->toggleCapture();
    }
    
    Config conf(this);
    conf.exec();
}

void MainWindow::saveToFile(string fileName){

    if (!logMaker)
    {     
        logMaker=new LogMaker(fileName);        
    }

    time_t now;
    time(&now);
    tm* localTime=localtime(&now);
    logMaker->MakeLog(localTime,faceLog->getCountFaces());

}

void MainWindow::updateList(){
    this->saveToFile();
    qList.append(QString::number(faceLog->getCountFaces()));
    if (qList.size()<=5)
    {      
        qList2=qList;              
    }
    else
    {
        qList2.clear();
        int i;
        for (i=5;i>0;i--)
        {
        qList2.append(qList.at(qList.length()-i));
        }    
    }
    QStringListModel *listModel=new QStringListModel(qList2);
    ui->listView->setModel(listModel);
}

QImage MainWindow::getQImageFromFrame(Mat frame) {
    //converts the color model of the image from RGB to BGR because OpenCV uses BGR
     
    cvtColor(frame, frame, CV_RGB2BGR);
    return QImage((uchar*) (frame.data), frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
}

void MainWindow::displayFrame() {
    faceLog->detectAndDraw(false);
    QImage image = getQImageFromFrame(faceLog->getCurrentFrame());
    
    //set the image of the label to be the captured frame and resize the label appropriately
    ui->cameraLabel->setPixmap(QPixmap::fromImage(image));
    ui->cameraLabel->resize(ui->cameraLabel->pixmap()->size());
}

void MainWindow::toggleCapture() {
     if (ui->startButton->text()=="Stop")
     {
         this->stopCapture();
     }
     else
     {
         this->startCapture();
     }
    
}

void MainWindow::startCapture() {
       this->loadPreferences(CONFIG_FILE);
        
        faceLog=new FaceLog(this->cameraNumber);
        faceLog->setMinSize(Size(this->minSize,this->minSize));
        faceLog->setMaxSize(Size(this->maxSize,this->maxSize)); 
        faceLog->startCamera(); 
        
        this->timer1 = new QTimer(this);
        this->timer2 = new QTimer(this);
        this->timer1->start(this->interval/1000);
        this->timer2->start(this->interval);
        
        this->connect(this->timer1, SIGNAL(timeout()), this, SLOT(displayFrame()));
        this->connect(this->timer2, SIGNAL(timeout()), this, SLOT(updateList()));
        ui->label->setPixmap(QPixmap(QString(":/img/on.png")));
        ui->startButton->setText("Stop");   
}

void MainWindow::stopCapture() {
        faceLog->stopCamera();
        delete faceLog;
        logMaker->CloseLog();
        this->timer1->stop();
        this->timer2->stop();
        delete this->timer1;
        delete this->timer2;
        this->disconnect(this,SLOT(displayFrame()));
        this->disconnect(this,SLOT(updateList()));
        ui->cameraLabel->setPixmap(QPixmap(""));
        ui->label->setPixmap(QPixmap(QString(":/img/off.png")));
        ui->startButton->setText("Start");     
}

void MainWindow::loadPreferences(QString fileName)
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
         }
        
        msg="File loaded.";
    }
    std::cout << msg<<std::endl;
    config.close();
    
    vector< std::vector<std::string> >::iterator keyValuesIterator;
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
                this->minSize=val;
             }
             if (key=="maxSize")
             {
                this->maxSize=val;
             }
             if (key=="interval")
             {
                this->interval=val;
             }
             if (key=="camera")
             {
                this->cameraNumber=val;
             }
        }
    
    
}



