/*************************************************************************
                           LogReader.cpp  -  description
                             -------------------
    début                : $16/01$
    copyright            : (C) $2024$ par SOW Amadou - LARRAZ MARTIN Diego - ASRI Hazim - CATHERINE Noam
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <LogReader> (fichier LogReader.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;
//------------------------------------------------------ Include personnel
#include "LogReader.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
ifstream  & operator >> (ifstream & ifs, const LogReader & LogR)
// Algorithme :
//
{
  int pos; // utilisé pour mémoriser une position ou chercher
  string tmp; // utilisé pour mémoriser un bout de texte à utiliser/modifier

  if (ifs.is_open())
  {
    getline(ifs,(LogR.logInfo)->IPAddress, ' ');
    getline(ifs, (LogR.logInfo)->logname,' ');
    getline(ifs, (LogR.logInfo)->username,' ');
    ifs.get(); // on efface '['
    getline(ifs, ((LogR.logInfo)->timeOfOperation).day ,'/');
    getline(ifs, ((LogR.logInfo)->timeOfOperation).month ,'/');
    getline(ifs, ((LogR.logInfo)->timeOfOperation).year ,':');
    getline(ifs, ((LogR.logInfo)->timeOfOperation).hour ,':');
    getline(ifs, ((LogR.logInfo)->timeOfOperation).min ,':');
    getline(ifs, ((LogR.logInfo)->timeOfOperation).sec ,' ');
    getline(ifs,tmp,'"'); // on ignore tout jusqu'à ", début des informations sur le target
    getline(ifs,(LogR.logInfo)->action,' ');


    // Obtention du target
    if (ifs.peek() == '/') 
    {
      // local, on prends tout jusqu'à la version HTTP
      getline(ifs,tmp,' ');
    }
    else
    {
      //on enlève le protocole http[s]://
      getline(ifs,tmp,'/');
      ifs.get();
      
      //on observe si en local intranet
      getline(ifs,tmp,' ');
      pos = tmp.find("/");
      
      if(tmp.substr(0,pos) == LogR.base) // on l'enlève dans ce cas
      {
        tmp = tmp.substr(pos);
      }
    }
    pos = tmp.rfind('?');
    if(pos != string::npos) 
    {
      tmp = tmp.substr(0, pos);
    }

    (LogR.logInfo)->target = tmp;

    // on obtient le type de fichier du target.
    pos = tmp.rfind('.');
    if (pos != string::npos && tmp.rfind('/') < pos) 
    { // pas de point avant le dernier '/' => pas d'extension
      (LogR.logInfo)->extension = tmp.substr(pos + 1);
    } 
    else 
    {
      (LogR.logInfo)->extension = "dossier";
    }

    getline(ifs,tmp,' '); // on ignore tout jusqu'au status
    getline(ifs,(LogR.logInfo)->status,' ');
    getline(ifs,(LogR.logInfo)->dataQuantity,' ');

    // Obtention du referer
    ifs.get(); // on enlève le " avant les informations sur le referer

    if (ifs.peek()== '-') // si referer anonyme
    {
      LogR.logInfo->referer = "inconnu";
      ifs.get();
      ifs.get();
    }
    else if (ifs.peek() == '/')  // local, on prends tout jusqu'à la version HTTP
    {
      getline(ifs,(LogR.logInfo)->referer,'"');
    }
    else
    {
      //on enlève le protocole http[s]://
      getline(ifs,tmp,'/');
      ifs.get();

      //on observe si en local intranet
      getline(ifs,tmp,'"');
      pos = tmp.find("/");
      
      if(tmp.substr(0,pos) == LogR.base) // on l'enlève dans ce cas
      {
        tmp = tmp.substr(pos);
      }
      (LogR.logInfo)->referer = tmp;
    

    }

   // cout << "referer1 : " << (LogR.logInfo)->referer << endl;

    getline(ifs,tmp,'"'); // On ignore jusqu'aux informations sur le navigateur
    getline(ifs,(LogR.logInfo)->navigator,'"');
    
  }
  else
    cerr << "Fichier invalide" << endl;
  
  return ifs;

} //----- Fin de operator =

LogReader & LogReader::operator = ( const LogReader & logR )
// Algorithme :
//
{
  logInfo = logR.logInfo;
  base = logR.base;
  return (*this);

} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
LogReader::LogReader (const LogReader & logR) : logInfo(logR.logInfo), base(logR.base)
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au constructeur de copie de <LogReader>" << endl;
  #endif
} //----- Fin de LogReader (constructeur de copie)


LogReader::LogReader (LogInfo * log, const string b) : logInfo(log), base(b)
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au constructeur de <LogReader>" << endl;
  #endif
} //----- Fin de LogReader


LogReader::~LogReader()
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au destructeur de <LogReader>" << endl;
  #endif
} //----- Fin de ~LogReader


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
