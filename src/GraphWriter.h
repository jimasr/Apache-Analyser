/********************************************************************************************************
                           GraphWriter.h  -  description
                             -------------------
    début                : 16/01/2024
    copyright            : (C) 2024 par SOW Amadou - LARRAZ MARTIN Diego - ASRI Hazim - CATHERINE Noam
    e-mail               : 
********************************************************************************************************/

//---------- Interface de la classe <LogReader> (fichier LogReader.h) ----------------
#if ! defined ( __GRAPHWRITER_H__ )
#define __GRAPHWRITER_H__

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <fstream>
#include <map>
#include <set>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GraphWriter>
//
// Permet de récupérer et lire les données du fichier apache donnée dans
// le sujet.
//
//------------------------------------------------------------------------
class GraphWriter
{
//----------------------------------------------------------------- PUBLIC

public:

//------------------------------------------------- Surcharge d'opérateurs
	friend ofstream& operator << (ofstream & ofs, const GraphWriter &graphWriter);
	// Mode d'emploi : necessite l'implementation de to_string method pour la classe T
	//
	// Contrat : 
	//
  
//-------------------------------------------- Constructeurs - destructeur
	GraphWriter(); //Constructeur par defaut de la classe
	// Mode d'emploi :
	//
	// Contrat :
	//

	char AddRelation(const string referer, const string target, const int hit);
	// Mode d'emploi : 
	//
	// Contrat : returns 0 if the relation already exists, 1 otherwise
	//

	virtual ~GraphWriter();
	// Mode d'emploi : 
	//
	// Contrat : 
	//
  
//----------------------------------------------------- Attributs Private
private:
	map<pair<string, string>, int> refTargetHitMap;
	set<string> nodes; //unique values of nodes;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>
#endif // __GRAPHWRITER_H__

