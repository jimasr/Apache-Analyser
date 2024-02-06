#include "LogHistory.h"

int Size(const char * str)
{
    int i = 0;
    while(str[i] != '\0'){ i++; }
    return i;
}


bool verifyTime(const string str) 
{  
    return (Size(str.c_str()) == 2) && ((str[0]>=48 && str[0] <= 49 && str[1]<= 57 && str[1] >= 48) || (str[0] == 50 && str[1]<= 52 && str[1] >= 48)) ;
}

bool CheckExtension(const char * str, const char * extension)
{
    int size = Size(str);
    int extensionSize = Size(extension);
    if(extensionSize < size)
    {
        int i = 0;
        bool check = true;
        while( i < extensionSize && check)
        {
            check = (str[size - extensionSize + i] == extension[i]);
            i++;
        }
        return check;
    }
    return false;
}

int main(int nbargs, char* argvs[]){
    LogHistory logHist;
    if(nbargs < 2 || !(CheckExtension(argvs[nbargs - 1], ".log")))
    {
        cerr << "Please provide a log file." << endl;
        return 1;
    }   

    char timeLim[3] = "xx";
    bool excludeMediaF = false;
    bool writing = false;
    string dotFileName = "output.dot";

    if(nbargs > 2)
    {
        int i = 1;
        while(i < nbargs - 1)
        {
            switch(argvs[i][1])
            {
                case 'g':
                    writing = true;
                    if(CheckExtension(argvs[i + 1], ".dot"))
                    {
                        i++; 
                        dotFileName = argvs[i];
                    }
                    break;
                case 'e':
                    excludeMediaF = true;
                    break;
                case 't':
                    i++;
                    if(!verifyTime(argvs[i])) 
                    {
                        cerr << "Valid time was not given (00 - 24)." << endl;
                        return 1;
                    }
                    timeLim[0] = argvs[i][0];
                    timeLim[1] = argvs[i][1];
                    break;
                default:
                    cerr << "Invalid argument." << endl;
                    return 1;
            }
            i++;
        }
        
    }
    
    bool readSuccess = logHist.ReadLog(argvs[nbargs - 1], true, excludeMediaF, timeLim);
    if(readSuccess) {
        logHist.Show(10);
        if(writing)
        {
            logHist.WriteGraph(dotFileName);
        }
    }


    return 0;

}