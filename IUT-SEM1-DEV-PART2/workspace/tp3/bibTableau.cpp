/* CORPS DU MODULE */    
//Inclusion
#include "bibTableau.h"
#include <iostream>
using namespace std;

//Coprs de sous programme : 
void faireRemonterLaBulle(int tab[], unsigned int bDeb, unsigned int ici);
// Faire remonter le plus grand élement de l'intervalle bDeb jusqu'a ici par echange successif
//Pre-condition ici< nbTab
void echanger(int & x,int & y);
//echanger deux valeurs x et y

void insertion(int tab[], int ici);


//Type variable
//Déclaration des sous programmes utilisé
//Coprs des sous programmes déclarés

void afficher (int const tab[], unsigned short int lgTab)
{
    if (lgTab > 0)
    {
        cout << "{";
        for (unsigned short int i = 0; i<lgTab-1; i++)
        {
            cout << tab[i];
            cout << ", ";
        };
            cout << tab[lgTab-1];
            cout<<  "} "<< endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}


void echanger(int & x,int & y)
{
    int temp = x;
    x = y;
    y = temp;
}

void faireRemonterLaBulle(int tab[], unsigned int ici)
{
    for (unsigned int i = 0; i<ici-1; i++)
    {
        if (tab[i] > tab[i+1])
        {
            echanger(tab[i], tab[i+1]);
        }
        
    }
    
}

void triBulle(int tab[], unsigned short int lgTab)
{
    int ici;
    for ( ici = lgTab; ici>0; ici--)
    {
        faireRemonterLaBulle(tab, ici);
    }
    
}


void insertion(int tab[],int ici)
{
    int temp = tab[ici];  
    int j = ici-1;
    while (j>=1 && tab[j]>temp)
    {
        tab[j+1]=tab[j];
        j=j-1;
    }
    tab[j+1] = temp;
     
}

void triParInsertion(int tab[], unsigned short int TAILLE)
{
    for (int i = 2; i < TAILLE; i++)
    {
        insertion(tab, i);
    }
    
}