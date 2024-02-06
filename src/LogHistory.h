/*************************************************************************
                           LogHistory  -  description
                             -------------------
    début                : 16/01/2024
    copyright            : (C) 2024 par SOW Amadou - LARRAZ MARTIN Diego - ASRI Hazim - CATHERINE Noam
    e-mail               : 
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
// Gestionnaire qui permet de lire un fichier log et obtenir le nombre de 
// hits pour chaque cible. Ceux-ci peuvent s'afficher de manière ordonnée 
// décroissante. Il peut même écrire un fichier .dot contenant 
// l'ensemble d'appels entre réferers et targets
//------------------------------------------------------------------------

class LogHistory
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs
    LogHistory & operator = ( const LogHistory & unLogHistory );

//-------------------------------------------- Constructeurs - destructeur
    LogHistory ( const LogHistory & unLogHistory );
    // Mode d'emploi (constructeur de copie) :

    LogHistory ();
    // Mode d'emploi (constructeur par défaut) : 

    bool WriteGraph (const string dotFileName = "graph.dot") const;
    // Mode d'emploi : 
    // Écrit un fichier .dot selon le model Graphviz avec le nom/path dotFileName.
    // Renvoie vrai quand l'ecriture est reussie, faux sinon.

    bool ReadLog (const string logFileName, const bool flush = true, const bool excludeMediaFiles = false , const char timeLim[2 + 1] = "xx" );
    // Mode d'emploi :
    // Lit un fichier .log selon le model Graphviz avec le nom/path logFileName.
    // Si flush est vrai, reinitialise la structure de données target - Hits des lectures précedantes.
    // Si excludeMediaFiles est vrai, les logs où le target est un fichier image/css/js ne sont pas pris en compte
    // Si timeLim n'est pas défini à "xx" mais plutôt à une heure sur 24h (00-24) alors seulement les logs réalisés dans l'intervalle temporel [timeLim, timeLim + 1[ sont pris en compte
    // Renvoie vrai quand la lecture est reussie, faux sinon.
    //
    // Contrat :  
    // timeLim est initialisé par defaut à xx pour ne pas mettre de filtre, tout d'autre paire qui ne soit pas un chiffre 
    // n'entraînera pas d'erreur mais il est probable qu'aucun cas existe dans le fichier egal à ce qui est donné, ce qui implique que
    // le fichier résultat sera vide
    //
    // Le fichier doit être un .log


    virtual ~LogHistory ( );
    // Mode d'emploi (destructeur):


    void Show(const unsigned int nLogs = 0) const;
    // Mode d'emploi : affiche de maniére ordonnée croissante selon hits, le couple target-hits.
    // Si nLogs n'est pas null, il affiche autant de couples que nLogs. Affiche tout dans le cas contraire
    // Si nLogs est supérieur à la taille maximale du tableau, il l'affiche entièrement

    void Clear();
    // Mode d'emploi : reinitialise le tableau et le graphe (vidage)


//------------------------------------------------------------------ PRIVE
private:

//----------------------------------------------------- Méthodes privées

    bool searchFilter(const LogInfo & log, const bool excludeMediaFiles, const char timeLim[2 + 1]) const;
    // Mode d'emploi : teste si le log doit être lu selon la sélection des filtres
    // Si excludeMediaFiles est vrai, log ne sera pas pris en compte si sont target est un fichier image/css/js 
    // Si timeLim n'est pas défini à "xx" mais plutôt à une heure sur 24h (00-24) alors log ne sera pris en compte seulement si son heure
    // est dans l'intervalle temporel [timeLim, timeLim + 1[
    // Utilisé par ReadLog.
    // Contrat :  time limit est initialisé par defaut à xx pour ne pas mettre de filtre, tout d'autre paire qui ne soit pas un chiffre 
    // n'entraînera pas d'erreur mais il est probable qu'aucun cas existe dans le fichier egal à ce qui est donné, ce qui implique que
    // le fichier résultat sera vide

//----------------------------------------------------- Attributs privés
    HitCounter<string> logHits;
    GraphWriter graphWriter;
};

//-------------------------------- Autres définitions dépendantes de <LogHistory>



#endif // LogHistory_H

