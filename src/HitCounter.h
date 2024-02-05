/*************************************************************************
                           HitCounter  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
// Rôle de la classe <HitCounter>
//
//
//------------------------------------------------------------------------
template <typename targetType>
class HitCounter
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
    HitCounter<targetType> & operator = ( const HitCounter<targetType> & unHitCounter );
    // Mode d'emploi :
    //
    // Contrat :
    //
   

//-------------------------------------------- Constructeurs - destructeur
    HitCounter ( const HitCounter<targetType> & unHitCounter );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    
    HitCounter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
   
    virtual ~HitCounter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    bool Augment(const targetType targt, const int nbHits);

    void Show(const unsigned int lim) const;

    void Show() const;

    void Clear();
    
//------------------------------------------------------------------ PRIVE
private:

//----------------------------------------------------- Méthodes privées

void printItem(typename multimap<int,targetType>::const_reverse_iterator & itc) const;

//----------------------------------------------------- Attributs privés
    unordered_map<targetType, int> targetHits;
};

//-------------------------------- Autres définitions dépendantes de <HitCounter>



template <typename targetType>
HitCounter<targetType> & HitCounter<targetType>::operator = ( const HitCounter<targetType> & unHitCounter )
// Algorithme :
//
{
    targetHits = unHitCounter.targetHits;
    return (*this);
} //----- Fin de operator =


template <typename targetType>
HitCounter<targetType>::HitCounter ( const HitCounter<targetType> & unHitCounter )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <HitCounter>" << endl;
#endif
    targetHits = unHitCounter.targetHits;
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


template <typename targetType>
bool HitCounter<targetType>::Augment(const targetType targt, const int nbHits)// Algorithme :
// Algorithme :
//
{
    if(targetHits.find(targt) != targetHits.end()){ 
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
        // On ordonne les targets par le nombre de hits
        multimap<int,targetType> orderedHits;
        for(typename unordered_map<targetType, int>::const_iterator itc = targetHits.cbegin(); itc != targetHits.cend(); itc++)
        {
            orderedHits.insert({itc->second,itc->first});
        }

        cout << left << setw(20) <<  "[ Targets ]"        <<    "[ Hits ]"  << endl;
        // On affiche soit tous, soit un nombre limité de paires target - hits 
       
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
    // On ordonne les targets par le nombre de hits
    multimap<int,targetType> orderedHits;
    for(typename unordered_map<targetType, int>::const_iterator itc = targetHits.cbegin(); itc != targetHits.cend(); itc++)
    {
        orderedHits.insert({itc->second,itc->first});
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


// privé
template <typename targetType>
void HitCounter<targetType>::printItem(typename multimap<int,targetType>::const_reverse_iterator & itc) const
// Algorithme :
//
{
    cout << left << setw(60) <<  itc->second << itc->first << endl;
} //----- Fin de printItem

#endif // HitCounter_H

