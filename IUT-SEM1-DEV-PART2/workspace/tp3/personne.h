/*MODULE  
     
     -------------------------------------------------------
But :
    Mettre à dispositon d'un programmeur des sous-programmes applicables aux ...
 
    
    Description
---------

 Date de dernière modification : xxxx
 Auteur : xxx
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°2
*/

#ifndef PERSONNE_H
#define PERSONNE_H


#include <iostream>
using namespace std;

//Type
struct Adresse 
{
    string numRue; 
    string nomRue;
    unsigned short int codePostal;
    string nomVille; 
};

struct Personne
{
    string nom;
    string prenom;
    Adresse adresse;
};

//Constante

//Operateur de comparaison

//Operateur binaire

//Autre operateur

//Accesseur

//Entrée-Sortie
void afficherP (const Personne tab[],
               unsigned short int lgTab);
// But : affiche à l'écran le contenu d'un tableau tab contenant lgTab > 0 éléments de type Personne
//       si lgTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide')


void triBulleP(Personne tab[], unsigned short int lgTab);

#endif