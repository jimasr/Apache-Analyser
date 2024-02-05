#include "LogHistory.h"

int Size(const char * str)
{
    int i = 0;
    while(str[i] != '\0'){ i++; }
    return i;
}

bool CheckExtension(const char * str)
{
    int size = Size(str);
    const char * const extension = ".log";
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
    if(nbargs < 2 || !(CheckExtension(argvs[nbargs - 1])))
    {
        cerr << "Please provide a log file." << endl;
        return 1;
    }   

    char timeLim[3] = "xx";
    bool excludeMediaF = false;
    bool writing = false;
    string dotFileName;

    if(nbargs > 2)
    {
        int i = 1;
        while(i < nbargs - 1)
        {
            switch(argvs[i][1])
            {
                case 'g':
                    writing = true;
                    i++; 
                    if(i >= nbargs - 1)
                    {
                        cerr << "Please provide a file name for the graph." << endl;
                        return 1;
                    }
                    dotFileName = argvs[i];
                    break;
                case 'e':
                    excludeMediaF = true;
                    break;
                case 't':
                    i++; 
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
    
    logHist.ReadLog(argvs[nbargs - 1], excludeMediaF, timeLim);
    logHist.Show(10);
    if(writing)
    {
        logHist.WriteGraph(dotFileName);
    }

    return 0;

}