/********************************************************************************************************
                           LogReader.h  -  description
                             -------------------
    début                : 16/01/2024
    copyright            : (C) 2024 par SOW Amadou - LARRAZ MARTIN Diego - ASRI Hazim - CATHERINE Noam
    e-mail               :
********************************************************************************************************/

//---------- Interface de la classe <LogReader> (fichier LogReader.h) ----------------
#if ! defined ( __LOGREADER_H__ )
#define __LOGREADER_H__

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <fstream>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct Time {

    string year;
    string month;
    string day;
    string  hour;
    string min;
    string sec;

}Time;


typedef struct logInfo {
  string IPAddress;
  string logname;
  string username;
  string referer;
  string target;
  Time timeOfOperation;
  string extension;
  string status;
  string dataQuantity;
  string action;
  string navigator;
} LogInfo;
//------------------------------------------------------------------------
// Rôle de la classe <LogReader>
//
// Permet de récupérer et lire les données du fichier apache donnée dans
// le sujet.
//
//------------------------------------------------------------------------
class LogReader
{
//----------------------------------------------------------------- PUBLIC

public:
//------------------------------------------------- Surcharge d'opérateurs
    friend ifstream & operator >> (ifstream & ifs, const LogReader & logR);
    // Mode d'emploi :
  	// Prends un LogReader et un ifstream vers un fichier (.log) en entrée.
    // Utilisé comme suit :  ifstream_file >> LogReader_variable
  	//
  	// Lit la ligne du log actuellement parcouru dans le ifstream
  	// et extrait les informations pertinentes, sauvergardées dans le InfoLog pointé par infoLog.
  	//
    // Contrat :
    // Le pointeur InfoLog du LogReader fourni n'est pas NULL.
  	// ifs est un fichier (.log)

  	LogReader & operator = (const LogReader & logR);

 //file >> LogReader(&(Log))
//-------------------------------------------- Constructeurs - destructeur

		LogReader(const LogReader &logR);
    // Mode d'emploi :
    // Construit un nouvel objet LogReader en copiant les attributs de l'objet logR.
    // Contrat :
    // L'objet logR doit être correctement construit et initialisé, sinon le comportement est indéfini.
    // La copie doit être effectuée de manière appropriée pour chaque attribut de LogReader.

    LogReader (LogInfo * log, const string base = "intranet-if.insa-lyon.fr"); //Constructeur de la classe
    // Mode d'emploi :
    // Construit un nouvel objet LogReader à partir d'un pointeur sur un objet de type Infolog. 
    // Base est un domaine local qu'on cherche à enlever

    virtual ~LogReader ( );
    // Mode d'emploi :
    // Destructeur de la classe -> se lance à la fin de la durée de vie de l'instance

//----------------------------------------------------- Attributs Private
  	LogInfo * logInfo;
    string base;

};

//-------------------------------- Autres définitions dépendantes de <Xxx>
#endif // __LOGREADER_H__
