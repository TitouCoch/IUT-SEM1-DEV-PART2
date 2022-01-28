/** CORPS DU MODULE */
    
//Inclusion

#include "bibTableau.h"
#include <iostream>
using namespace std;


//Coprs de sous programme : 


//Type variable

//Déclaration des sous programmes utilisé

//Coprs des sous programmes déclarés
void recherchePremiereOccDichoEntier(int tab[], unsigned int LG_TAB, int valRecherche, bool & trouve, unsigned int & position)
{
    if (trouve==true)
    {
        cout<<"Une occurence de "<<valRecherche<<" trouvé en position "<<position<<endl;
    }
    else
    {
        cout <<"Valeur"<<valRecherche<< "Non trouvé"<< endl;
    }
    
}


void afficher (int tab[],
               unsigned short int lgTab)
{
    if (lgTab > 0)
    {
        cout << "{";
        for (unsigned short int i = 0; i<lgTab-1; i++)
        {
            cout << tab[i] << ", " ;

        }
        cout << tab[lgTab-1] << "} "<< endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}