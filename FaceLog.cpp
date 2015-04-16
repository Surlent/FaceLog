#include "FaceLog.h"

using namespace std;
using namespace cv;

FaceLog::FaceLog(int cameraNumber, string cascadeName, double scale,
        Size minSize, Size maxSize) {
    this->setCascade(cascadeName);
    this->setScale(scale);
    this->setMinSize(minSize);
    this->setMaxSize(maxSize);  
    this->setCameraNumber(cameraNumber);
}

FaceLog::~FaceLog() {
    this->stopCamera();
    // cout << "Bye bye";
}

void FaceLog::setCascade(string cascadeName) {
    if (!((this->cascade).load(cascadeName))) {
        cerr << "ERROR: Could not load classifier cascade" << endl;
        //return -1;
    }
}

CascadeClassifier FaceLog::getCascade() const {
    return this->cascade;
}

void FaceLog::setScale(double value) {
    this->scale = value;
}

double FaceLog::getScale() const {
    return this->countFaces;
}

void FaceLog::setMinSize(Size value) {
    this->minSize = value;
}

Size FaceLog::getMinSize() const {
    return this->minSize;
}

void FaceLog::setMaxSize(Size value) {
    this->maxSize = value;
}

Size FaceLog::getMaxSize() const {
    return this->maxSize;
}

void FaceLog::setCameraNumber(int value) {
    this->cameraNumber = value;
}

int FaceLog::getCameraNumber() const {
    return this->cameraNumber;
}

void FaceLog::setCapture(CvCapture* value) {
    this->capture = value;
}

CvCapture* FaceLog::getCapture() const {
    return this->capture;
}

void FaceLog::setCountFaces(int value) {
    this->countFaces = value;
}

int FaceLog::getCountFaces() const {
    return this->countFaces;
}

void FaceLog::setCurrentFrame(Mat value)
{
    this->currentFrame=value;
}

Mat FaceLog::getCurrentFrame() const
{
    return this->currentFrame;
}

void FaceLog::setCameraResolution(int width,int height)
{
    cvSetCaptureProperty((this->capture), CV_CAP_PROP_FRAME_HEIGHT, height);
    cvSetCaptureProperty((this->capture), CV_CAP_PROP_FRAME_WIDTH, width);
}

void FaceLog::startCamera() {
    this->capture = 0;
    try {
        this->setCapture(cvCaptureFromCAM(this->cameraNumber));
        if (!(this->capture)) 
        {
            cout << "Capture from CAM " << this->cameraNumber << " didn't work" << endl;
            this->setCapture(cvCaptureFromCAM(-1)); // Try to detect camera
            if (!(this->capture)) 
            {
                throw cv::Exception();
            }

        }
        
        
    } catch (cv::Exception) {
        cout << "Camera capture failed" << endl;
        //        return -1;
    }
    
    this->setCameraResolution(640,480);
    
    
   
     cout << "In capture ..." << endl;
   // cvNamedWindow("result", 1);
   // cvMoveWindow("result",300,200);
    
}

void FaceLog::stopCamera() {
    cvReleaseCapture(&(this->capture));
    //cvDestroyWindow("result");
}

void FaceLog::detectAndDraw(bool tryFlip) {
    if (this->capture) {
        Mat frameCopy;
        //this->startCamera();
       
        IplImage* iplImg = cvQueryFrame(this->capture);
        this->currentFrame = iplImg;
        if (this->currentFrame.empty())
            cout << "Empty frame" << endl;
        if (iplImg->origin == IPL_ORIGIN_TL)
            this->currentFrame.copyTo(frameCopy);
        else
            flip(this->currentFrame, frameCopy, 0);

        int i = 0;
        vector<Rect> faces, faces2;
        const static Scalar colors[] = {
            CV_RGB(0, 0, 255),
            CV_RGB(0, 128, 255),
            CV_RGB(0, 255, 255),
            CV_RGB(0, 255, 0),
            CV_RGB(255, 128, 0),
            CV_RGB(255, 255, 0),
            CV_RGB(255, 0, 0),
            CV_RGB(255, 0, 255)
        };
        Mat gray, smallImg(cvRound(this->currentFrame.rows / this->scale), cvRound(this->currentFrame.cols / this->scale), CV_8UC1);

        cvtColor(this->currentFrame, gray, CV_BGR2GRAY);
        resize(gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR);
        equalizeHist(smallImg, smallImg);

        this->cascade.detectMultiScale(smallImg, faces,
                1.1, 2, 0
                //|CV_HAAR_FIND_BIGGEST_OBJECT
                //|CV_HAAR_DO_ROUGH_SEARCH
                | CV_HAAR_SCALE_IMAGE
                ,
                this->minSize, this->maxSize);
        if (tryFlip) {
            flip(smallImg, smallImg, 1);
            cascade.detectMultiScale(smallImg, faces2,
                    1.1, 2, 0
                    //|CV_HAAR_FIND_BIGGEST_OBJECT
                    //|CV_HAAR_DO_ROUGH_SEARCH
                    | CV_HAAR_SCALE_IMAGE
                    ,
                    Size(30, 30));
            for (vector<Rect>::const_iterator r = faces2.begin(); r != faces2.end(); r++) {
                faces.push_back(Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height));
            }
        }
       
        for (vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); r++, i++) {
            Point center;
            Scalar color = colors[i % 8];
            int radius;

            double aspect_ratio = (double) r->width / r->height;
            if (0.75 < aspect_ratio && aspect_ratio < 1.3) {
                center.x = cvRound((r->x + r->width * 0.5) * this->scale);
                center.y = cvRound((r->y + r->height * 0.5) * this->scale);
                radius = cvRound((r->width + r->height)*0.25 * this->scale);
                circle(this->currentFrame, center, radius, color, 3, 8, 0);
            } else
                rectangle(this->currentFrame, cvPoint(cvRound(r->x * this->scale), cvRound(r->y * this->scale)),
                    cvPoint(cvRound((r->x + r->width - 1) * this->scale), cvRound((r->y + r->height - 1) * this->scale)),
                    color, 3, 8, 0);
        }
        this->setCountFaces(faces.size());
        //cout << this->getCountFaces() << endl;
        
    }

}

