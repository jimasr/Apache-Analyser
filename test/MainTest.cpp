
#include "HitCounter.h"
#include "LogReader.h"
using namespace std;

void showFunction(LogInfo & log){
    cout << log.IPAddress << endl;
    cout << log.logname << endl;
    cout << log. username << endl;
    cout << log. referer << endl;
    cout << log. target << endl;
    cout << log.timeOfOperation.hour << ":" << log.timeOfOperation.min <<  ":" << log.timeOfOperation.sec << " - " << log.timeOfOperation.day << "/" << log.timeOfOperation.month <<  "/" << log.timeOfOperation.year << endl;
    cout << log. extension << endl;
    cout << log. status << endl;
    cout << log. dataQuantity << endl;
    cout << log. action << endl;
    cout << log. navigator << endl;
    cout << endl;
}


int main(int nbargs, char* argvs[]){

    HitCounter<string> orderedHits;
    orderedHits.Augment("Supercalifrag",37);
    orderedHits.Augment("Hello", 8);
    orderedHits.Augment("Heldasdsaasdasdasdlo", 8);
    orderedHits.Augment("wow", 3);
    orderedHits.Augment("incredible", 52);

    ifstream file("fichier.log");
    LogInfo log;
    LogReader lr(&log);


    
    while(file >> lr)
    {
        showFunction(log);
    }


    /*
    
    HitCounter<char> orderedHits;
    orderedHits.Augment(111,37);
    orderedHits.Augment(78, 8);
    orderedHits.Augment(46, 8);
    orderedHits.Augment(97, 3);
    orderedHits.Augment(126, 52);*/
    /*
    orderedHits.Show(-1);
    cout << endl;
    orderedHits.Show(3);
    cout << endl;
    orderedHits.Clear();
    orderedHits.Show();*/
}