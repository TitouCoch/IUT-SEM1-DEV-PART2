/**  MODULE bibTableaux 
     regroupe des sous-programmes applicables à des tableaux
     -------------------------------------------------------
But :
    Mettre à dispositon d'un programmeur des sous-programmes applicables aux tableaux.
    Conformes aux exercices des TD n°1 et et 3 de R1.01
    
    Il peut s'agit de tableaux d'entiers ou d'enregistrements de type Personne.
    Les tableaux manipulés doivent être triés par ordre décroissant de valeur.
    Dans le cas des tableaux d'enregistrements de type Personne, ils seront triés par ordre 
    décroissant de nom.
---------

 Date de dernière modification : xxxx
 Auteur : xxx
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°2
*/

#ifndef BIBTABLEAU_H
#define BIBTABLEAU_H
#include "personne.h"
#include <iostream>
using namespace std;

//Type

//Constante

//Operateur de comparaison

//Operateur binaire

//Autre operateur

//Accesseur


//Entrée-Sortie

void triBulle(int tab[], unsigned short int lgTab);
//But : trie le tableau en faisant remonter les plus grandes valeurs avec la technique bulle

void afficher(int const tab[], unsigned short int lgTab);
// But : affiche à l'écran le contenu d'un tableau tab contenant lgTab > 0 éléments de type Personne
//       si lgTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide')

void triParInsertion(int tab[], unsigned short int TAILLE);



#endif