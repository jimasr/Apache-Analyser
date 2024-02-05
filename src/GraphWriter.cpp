/*************************************************************************
						 GraphWriter.cpp  -  description
							-------------------
	début                : 16/01
	copyright            : (C) 2024 par SOW Amadou - LARRAZ MARTIN Diego - ASRI Hazim - CATHERINE Noam
	e-mail               : 
*************************************************************************/

//---------- Réalisation de la classe <GraphWriter> (fichier GraphWriter.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

//------------------------------------------------------ Include personnel
#include "GraphWriter.h"
#include "HitCounter.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
//type GraphWriter::Méthode ( liste des paramètres )
// Algorithme :
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
ofstream& operator << (ofstream & ofs, const GraphWriter &graphWriter)
{
	map<pair<string, string>, int> refTargetHitMap = graphWriter.refTargetHitMap;

	map<string, int> nodeMap;

	int nodeCounter = 0;

	ofs << "digraph {" << endl;

	// print nodes
	for(set<string>::const_iterator it = graphWriter.nodes.begin(); it != graphWriter.nodes.end(); ++it) {
		ofs << "\tnode" << nodeCounter << " [label=\"" << *it << "\"];"<< endl;
		nodeMap[*it] = nodeCounter;
		nodeCounter++;
	}

	// print edges
	for(map< pair<string, string>, int>::const_iterator it = refTargetHitMap.begin(); it != refTargetHitMap.end(); ++it) {
		ofs << "\tnode" << nodeMap[it->first.first] << " -> node" << nodeMap[it->first.second] << " [label=\"" << it->second << "\"];" << endl;
	}

	ofs << "}";


	return ofs;
}

char GraphWriter::AddRelation(const string referer, const string target, const int hit)
{
	pair<string, string> key = make_pair(referer, target);

	//insert both referer and target to the set
	nodes.insert(referer);
	nodes.insert(target);

	//insert the relation to the map
	if(refTargetHitMap.count(key)) { // key exists
		refTargetHitMap[key] += hit;
		return 0;
	}
	refTargetHitMap[key] = hit;
	return 1;
}

//-------------------------------------------- Constructeurs - destructeur
GraphWriter::GraphWriter()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <GraphWriter>" << endl;
#endif

} //----- Fin de GraphWriter

GraphWriter::~GraphWriter()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <GraphWriter>" << endl;
#endif
} //----- Fin de ~GraphWriter


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
