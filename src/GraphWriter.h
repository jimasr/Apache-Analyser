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
	// Mode d'emploi (surcharge de l'opérateur <<): 
	// prends un ofstream et un GraphWriter en entrée et écrit dans le output file stream sous forme 
	// d'un graphe dot
  
//-------------------------------------------- Constructeurs - destructeur
	GraphWriter();
	// Mode d'emploi (constructeur par defaut) : 

	char AddRelation(const string referer, const string target, const int hit);
	// Mode d'emploi : ajout d'une relation entre deux noeuds dans le graph, si le noeud n'existe pas, il est créé
	// s'il existe, on ajoute le hit à la relation
	// Contrat : hit doit être positif

	void Clear();

	virtual ~GraphWriter();
	// Mode d'emploi (destructeur) : 
  
//----------------------------------------------------- Attributs Private
private:
	map<pair<string, string>, int> refTargetHitMap; //map de referer, le target et le nombre de hit
	set<string> nodes; //valeurs uniques de noeuds
};

//-------------------------------- Autres définitions dépendantes de <Xxx>
#endif // __GRAPHWRITER_H__

