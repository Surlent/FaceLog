#ifndef LOGMAKER_H
#define	LOGMAKER_H

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <sstream>

class LogMaker
{
private:
    std::string filename;
    int nfaces; 
    tm* time;
    std::fstream file;
public:
    LogMaker(std::string filename);
    ~LogMaker();
    void OpenLog(std::string filename);
    void CloseLog();
    void MakeLog(tm* time, int nFaces);
    std::string UnwrapTime(tm* time);
};
#endif	/* LOGMAKER_H */

