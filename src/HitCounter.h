/*************************************************************************
                           HitCounter  -  description
                             -------------------
    début                : 16/01/2024
    copyright            : (C) 2024 par SOW Amadou - LARRAZ MARTIN Diego - ASRI Hazim - CATHERINE Noam
    e-mail               : 
*************************************************************************/

//---------- Interface de la classe <HitCounter> (fichier HitCounter.h) ----------------
#if ! defined ( HitCounter_H )
#define HitCounter_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <string> 

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// <HitCounter> est une class générique qui permet de facilement associer 
// des elements d'un type indiqué à un compteur (Hits).
// Cette classe permet de même d'afficher de manière decroissante
// les elements de cette structure en fonction de leur Hits.
//------------------------------------------------------------------------
template <typename targetType>
class HitCounter
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
    HitCounter<targetType> & operator = ( const HitCounter<targetType> & unHitCounter );

//-------------------------------------------- Constructeurs - destructeur
    HitCounter ( const HitCounter<targetType> & unHitCounter );
    // Mode d'emploi (constructeur de copie) :
    
    HitCounter ( );
    // Mode d'emploi (constructeur)

    virtual ~HitCounter ( );
    // Mode d'emploi (destructeur)
    
    bool Augment(const targetType targt, const int nbHits);
    // Mode d'emploi : 
    // Si targt existe dans cette structure de données, augmente son compteur (Hits) de nbHits.
    // Dans le cas contraire, crée un nouveau élément dans cette structure de données avec un compteur (Hits) defini à nbHits. 
    // nbHits peut être negatif. 
    //
    // Renvoie true si targt existait déjà, false sinon.

    void Show(const unsigned int lim) const;
    // Mode d'emploi : Affiche les paires target - hits de cette structure de données
    // L'affichage est ordonné en décroissance par rapport aux hits et limité à "lim" paires affichées.
    // Si lim excède le nombre d'élements presents dans cette structure alors toutes les paires seront affichées.

    void Show() const;
    // Mode d'emploi : Affiche toutes les paires target - hits de cette structure de données
    // L'affichage est ordonné en décroissance par rapport aux hits.


    void Clear();
    // Mode d'emploi : Réinitialise cette structure de données en effaçant ses contenus (vidage).

//------------------------------------------------------------------ PRIVE
private:

//----------------------------------------------------- Méthodes privées

void printItem(typename multimap<int,targetType>::const_reverse_iterator & itc) const;
// Mode d'emploi : Affiche uen paire target - hits avec un format défini
// Utilisée par les fonctions Show.
// Contrat :
// itc est un iterateur sur une paire d'une multimap où les paires targt - hits ont été insérées pour les ordonner


//----------------------------------------------------- Attributs privés
    unordered_map<targetType, int> targetHits;
};

//-------------------------------- Autres définitions dépendantes de <HitCounter>


//------------------------------------------------- Surcharge d'opérateurs
template <typename targetType>
HitCounter<targetType> & HitCounter<targetType>::operator = ( const HitCounter<targetType> & unHitCounter )
// Algorithme :
//
{
    targetHits = unHitCounter.targetHits;
    return (*this);
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
template <typename targetType>
HitCounter<targetType>::HitCounter ( const HitCounter<targetType> & unHitCounter ) : targetHits(unHitCounter.targetHits)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <HitCounter>" << endl;
#endif
} //----- Fin de HitCounter (constructeur de copie)


template <typename targetType>
HitCounter<targetType>::HitCounter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de base de <HitCounter>" << endl;
#endif
} //----- Fin de HitCounter


template <class targetType>
HitCounter<targetType>::~HitCounter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <HitCounter>" << endl;
#endif
} //----- Fin de ~HitCounter

//----------------------------------------------------- Méthodes publiques
template <typename targetType>
bool HitCounter<targetType>::Augment( const targetType targt, const int nbHits )// Algorithme :
// Algorithme :
//
{
    if(targetHits.find(targt) != targetHits.end()){ // s'il existe, find ne donnera pas l'iterateur end
        targetHits[targt] += nbHits;
        return true;
    }   
    else{
        targetHits[targt] = nbHits;
        return false;
    }
} //----- Fin de Augment

template <typename targetType>
void HitCounter<targetType>::Show() const// Algorithme :
// Algorithme :
//
{
        // On ordonne les targets par le nombre de hits dans une nouvelle structure de données
        multimap<int,targetType> orderedHits;
        for(typename unordered_map<targetType, int>::const_iterator itc = targetHits.cbegin(); itc != targetHits.cend(); itc++)
        {
            orderedHits.insert(make_pair(itc->second,itc->first));
        }

        cout << left << setw(60) <<  "[ Targets ]"        <<    "[ Hits ]"  << endl;
        // On affiche soit tous les paires target - hits 
        for(typename multimap<int,targetType>::const_reverse_iterator crit = orderedHits.crbegin(); crit != orderedHits.crend(); crit++)
        {
            printItem(crit);
        }

} //----- Fin de Show

template <typename targetType>
void HitCounter<targetType>::Show(const unsigned int lim) const// Algorithme :
// Algorithme :
//
{
    // On ordonne les targets par le nombre de hits dans une nouvelle structure de données
    multimap<int,targetType> orderedHits;
    for(typename unordered_map<targetType, int>::const_iterator itc = targetHits.cbegin(); itc != targetHits.cend(); itc++)
    {
        orderedHits.insert(make_pair(itc->second,itc->first));
    }

    // On affiche sous forme de tableau soit tous, soit un nombre limité de paires target - hits 
    cout << left << setw(60)<< "TARGETS" << "HITS" << endl;
    int i = 0;
    typename multimap<int,targetType>::const_reverse_iterator crit = orderedHits.crbegin();
    while(i < lim && crit != orderedHits.crend())
    {
        printItem(crit);
        crit++, i++; 
    }
    
} //----- Fin de Show(unsigned int)

template <typename targetType>
void HitCounter<targetType>::Clear()
// Algorithme :
//
{
    targetHits.clear();
} //----- Fin de Clear


//----------------------------------------------------- Méthodes privées
template <typename targetType>
void HitCounter<targetType>::printItem(typename multimap<int,targetType>::const_reverse_iterator & itc) const
// Algorithme :
//
{
    cout << left << setw(60) <<  itc->second << itc->first << endl;
} //----- Fin de printItem

#endif // HitCounter_H

