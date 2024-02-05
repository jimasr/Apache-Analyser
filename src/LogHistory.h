/*************************************************************************
                           LogHistory  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LogHistory> (fichier LogHistory.h) ----------------
#if ! defined ( LOG_HISTORY_H )
#define LOG_HISTORY_H

//--------------------------------------------------- Interfaces utilisées
#include "GraphWriter.h"
#include "LogReader.h"
#include "HitCounter.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogHistory>
//
//
//------------------------------------------------------------------------

class LogHistory
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    LogHistory & operator = ( const LogHistory & unLogHistory );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    LogHistory ( const LogHistory & unLogHistory );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LogHistory ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool WriteGraph (const string dotFileName = "Graph.dot", const char sep = ':') const;
    // Mode d'emploi :
    //
    // Contrat :  
    //

    bool ReadLog (const string logFileName, const bool excludeMediaFiles = false , const char timeLim[2 + 1] = "xx" , const bool flush = true);
    // Mode d'emploi :
    //
    // Contrat :  
    //


    virtual ~LogHistory ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Show(const unsigned int nLogs = 0) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Clear();
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------------------------ PRIVE
private:

//----------------------------------------------------- Méthodes privées

    bool searchFilter(const LogInfo & log, const bool excludeMediaFiles, const char timeLim[2 + 1]) const;

//----------------------------------------------------- Attributs privés
    HitCounter<string> logHits;
    GraphWriter graphWriter;
};

//-------------------------------- Autres définitions dépendantes de <LogHistory>



#endif // LogHistory_H

