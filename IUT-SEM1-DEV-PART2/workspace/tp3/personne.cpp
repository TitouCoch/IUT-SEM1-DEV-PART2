/** CORPS DU MODULE */
    
//Inclusion

#include "personne.h"
#include <iostream>
using namespace std;


//Coprs de sous programme : 
void echangerP(Personne & x,Personne & y);
void afficherPersonne (const Personne personne);
void faireRemonterLaBulleP(Personne tab[], unsigned int ici);

void afficherPersonne (const Personne personne)
{
    cout << "  {" << personne.nom << ", " << personne.prenom << ", { " ;
    cout <<        personne.adresse.numRue << ", " ;
    cout <<        personne.adresse.nomRue << ", ";
    cout <<        personne.adresse.codePostal << ", ";
    cout <<        personne.adresse.nomVille << " }";
    cout << "}";
}

//Type variable

//Déclaration des sous programmes utilisé

//Coprs des sous programmes déclarés

void echangerP(Personne & x,Personne & y)
{
    Personne temp = x;
    x = y;
    y = temp;
}
void faireRemonterLaBulleP(Personne tab[], unsigned int ici)
{
    for (unsigned int i = 0; i<ici-1; i++)
    {
        if (tab[i].nom > tab[i+1].nom)
        {
            echangerP(tab[i], tab[i+1]);
        }
        
    }
    
}
void triBulleP(Personne tab[], unsigned short int lgTab)
{
    int ici;
    for ( ici = lgTab; ici>0; ici--)
    {
        faireRemonterLaBulleP(tab, ici);
    }
    
}

void afficherP (const Personne tab[],
               unsigned short int lgTab)
{
    if (lgTab > 0)
    {
        cout << "{" << endl;
        for (unsigned short int i = 0; i<lgTab-1; i++)
        {
            afficherPersonne(tab[i]) ;
            cout << ", "<< endl ;
        };
        afficherPersonne (tab[lgTab-1]);
        cout << endl <<  "} "<< endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}

