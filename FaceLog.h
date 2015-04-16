#ifndef FACELOG_H
#define FACELOG_H

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <cctype>
#include <iostream>
#include <iterator>
#include <stdio.h>
#include <string>

class FaceLog {
private:
    cv::CascadeClassifier cascade;
    double scale;
    int countFaces,cameraNumber;
    cv::Size minSize, maxSize;
    CvCapture* capture;
    cv::Mat currentFrame;
public:
    FaceLog(int cameraNumber = 0, std::string cascadeName = "data/haarcascades/haarcascade_frontalface_default.xml",
            double scale = 1, cv::Size minSize = cv::Size(30, 30), 
            cv::Size maxSize = cv::Size(1000, 1000));

    ~FaceLog();

    void setCascade(std::string cascadeName);

    cv::CascadeClassifier getCascade() const;

    void setScale(double value);

    double getScale() const;

    void setMinSize(cv::Size value);

    cv::Size getMinSize() const;

    void setMaxSize(cv::Size value);

    cv::Size getMaxSize() const;

    void setCapture(CvCapture* value);

    CvCapture* getCapture() const;
    
    void setCameraNumber(int value);

    int getCameraNumber() const;

    void setCountFaces(int value);

    int getCountFaces() const;
    
    void setCurrentFrame(cv::Mat value);

    cv::Mat getCurrentFrame() const;

    void setCameraResolution(int width,int height);

    void startCamera();

    void stopCamera();

    void detectAndDraw(bool tryFlip = false);


};

#endif // FACELOG_H