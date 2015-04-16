#include "LogMaker.h" 
#define DATASIZE 6 // Date Array Size

using namespace std;

LogMaker::LogMaker(string filename)    
{
    this->filename=filename;
    OpenLog(this->filename);
}

LogMaker::~LogMaker()    
{
    CloseLog();
}

void LogMaker::MakeLog(tm* time, int nFaces)
{
    if (!file.is_open())
        this->OpenLog(filename);
    
    string timevec=this->UnwrapTime(time);
  

    file << timevec << "," << nFaces << endl;
    //cout << timevec << "," << nFaces << endl;


    
}

void LogMaker::OpenLog(string filename)
{
   file.open(filename.c_str(),fstream::app|fstream::out);       
}

void LogMaker::CloseLog()
{
   file.close();     
}

    
//desembrulha o tempo em um vetor [ano, mes, dia, etc...]
    
string LogMaker::UnwrapTime(tm* time)  
{   
char t[15];
strftime (t,15,"%Y%m%d%H%M%S",time); // yyyymmddhhmmss
return t;
    
}
