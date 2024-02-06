/*************************************************************************
                           LogHistory  -  description
                             -------------------
    début                : 16/01/2024
    copyright            : (C) 2024 par ...
    e-mail               : 
*************************************************************************/

//---------- Réalisation de la classe <LogHistory> (fichier LogHistory.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "LogHistory.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
LogHistory & LogHistory::operator = ( const LogHistory & l )
// Algorithme :
//
{
    logHits = l.logHits;
    graphWriter = l.graphWriter;
    return (*this);
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
LogHistory::LogHistory ( const LogHistory & l ) : logHits(l.logHits), graphWriter(l.graphWriter)
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <LogHistory>" << endl;
    #endif
} //----- Fin de LogHistory (constructeur de copie)


LogHistory::LogHistory () 
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur avec fichier de <LogHistory>" << endl;
    #endif
} //----- Fin de LogHistory

LogHistory::~LogHistory ()
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au destructeur de <LogHistory>" << endl;
    #endif
} //----- Fin de ~LogHistory


bool LogHistory::WriteGraph (const string dotFileName) const
// Algorithme :
//
{
    ofstream output(dotFileName);

    if(output.is_open()) 
    {
        output << graphWriter; 
        return true;
    } else {
        cerr << "Couldn't open "<< dotFileName << " to write." << endl;
        return false;
    }

} //----- Fin de WrtieGraph


void LogHistory::Clear()
// Algorithme :
//
{
    graphWriter.Clear();
    logHits.Clear();
} //----- Fin de Clear


bool LogHistory::ReadLog (const string logFileName, const bool flush, const bool excludeMediaFiles, const char timeLim[2 + 1])
// Algorithme :
//
{   
    if(flush)
    {
        Clear(); // remise à zero
    }

    ifstream fileRead(logFileName);
    if(fileRead)
    {
        LogInfo current_log;
        LogReader LReader(&current_log);

        while(fileRead >> LReader){
            // if(current_log.status == "200" && searchFilter(current_log,excludeMediaFiles,timeLim)) selon l'implementation
            if(searchFilter(current_log,excludeMediaFiles,timeLim))
            {
                graphWriter.AddRelation(current_log.referer, current_log.target, 1);
                logHits.Augment(current_log.target,1);
            }
        }
        return true;
    }
    else
    {
        cerr << "Couldn't open "<< logFileName << " to read." << endl;
        return false;
    }
} //----- Fin de ReadLog

void LogHistory::Show(const unsigned int nLogs) const
// Algorithme :
//
{   
    if(nLogs)
    {
        logHits.Show(nLogs);
    }   
    else{
        logHits.Show();
    }
    
} //----- Fin de Show

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes privées
bool LogHistory::searchFilter(const LogInfo & log, const bool excludeMediaFiles, const char timeLim[2 + 1]) const
// Algorithme :
//
{
    bool valid = true;
    if(timeLim[0] != 'x' && (log.timeOfOperation.hour[0] != timeLim[0] || log.timeOfOperation.hour[1] != timeLim[1]))
    {  
        valid = false;
    }

    if(valid && excludeMediaFiles && (log.extension ==  "js" || log.extension ==  "css" || log.extension ==  "jpg" || log.extension ==  "jpeg" || log.extension ==  "png"))
    {
        valid = false;
    }

    return valid;

} //----- Fin de searchFilter
