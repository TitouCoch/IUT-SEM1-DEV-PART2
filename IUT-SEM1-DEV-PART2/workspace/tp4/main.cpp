/*
 Programme : Hanoi - itératif - avec Tableau de piles et sous-programmes 
 But :  Résolution des tours de Hanoi - version itérative - pour 3 à 9 disques
 Date de dernière modification : 04-12-2021
 Auteur : Pantxika Dagorret
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - TD n°4
*/
#include <iostream>
#include "pile.h"
using namespace std;


const unsigned int NB_TOURS = 3;     // CONSTANTE dite 'GLOBALE' : 
                                            // portée = tous les Sous-programmes
                                            // présents dans ce fichier

/* ---------- Observateurs
   ------------------------------------------------------------------*/


/* ---------- Primitives modifiant 1 tour
   ------------------------------------------------------------------*/

void remplirTour(UnePile & tour, unsigned short int nbDisques);
// But remplit la tourARemplir avec nbDisques, du plus grand (en bas) au plus 
// petit (au sommet) de la tour

/* ---------- Primitives modifiant plusieurs tours
   ------------------------------------------------------------------*/

//void initialiserTours();
// But : initialise les NB_TOURS tours du tableau lesTours

//void deplacerDisque();
// But : déplace un disque d'une tour à une autre
// pré-condition : estDeplacable(tourOrigine, tourDestination) est VRAI
//                 c'est à dire :
//
//                 estVide(tourOrigine)  = FAUX
//                 et  (
//                        (estVide(tourDestination) = VRAI ) 
//                         OU 
//                        ( estVide(tourDestination)  = FAUX
//                          et
//                          sommet(tourOrigine) < sommet(tourDestination)
//                         )
//                     )

/* ---------- Affichages
   ------------------------------------------------------------------*/

void afficherTour(UnePile tour);
// Affiche le contenu de la tour passée en paramètre

//void afficherTours(const UnePile lesTours[]);
// Affiche le contenu des tours passées en paramètre 


/* ---------- Algorithmes de résolution du problème des tours de Hanoi
   --------------------------------------------------------------------*/

void resoudreToursHanoiManuel(unsigned int nbDisques); 
// Buts : 1- faire résoudre les tours de Hanoi avec nbDisques au joueur
//        2-pour tester les primitives 
//        - initialiserTours()
//        - remplirTour()
//        - afficherTour()
//        - afficherTours()
//        - deplacerDisque()


/* ---------- Boîte à outils pour resolutionToursHanoiManuel ()
   -------------------------------------------------------------------*/

   void saisieVerifDeplacementDemande(bool& reponseOk, unsigned int& origine, unsigned int& destination);
   // saisie du choix des tours prenant part au déplacement d'un disque :
   // 12 pour deplacement d'un disque de la tour 1 vers la tour 2
   // 13 pour deplacement d'un disque de la tour 1 vers la tour 3
   // 31 pour deplacement d'un disque de la tour 3 vers la tour 1
   // ...
   // 0 si aucun deplacement demandé

   int carToChiffre (char car);
   // convertit un caractère en chiffre



/* ---------- Boîte à outils pour resolutionToursHanoiAutomatique ()
   -------------------------------------------------------------------*/


// ======================================================================
int main()
{

    const unsigned int NB_MINIMUM_DISQUES = 3;   // nbre minimum autoris� de disques
    const unsigned int NB_MAXIMUM_DISQUES = 9;   // nbre maximum autoris� de disques
    unsigned int nbDisques;                     // nbre de disques à déplacer
    
    // (clavier), NB_MINIMUM_DISQUES, NB_MINIMUM_DISQUES >> saisie du nbre de disques >> nbDisques
    do
    {
        cout << "Entrer le nbre de disques de la tour de Hanoi (entre " << NB_MINIMUM_DISQUES << " et " << NB_MAXIMUM_DISQUES << ") : ";
        cin >> nbDisques;
    }
    while (!((nbDisques >=NB_MINIMUM_DISQUES) && (nbDisques <= NB_MAXIMUM_DISQUES)));


    // nbDisques >>  résoudre Hanoi manuellement pour le nb de disques entré >> ()
    resoudreToursHanoiManuel(nbDisques);
    return 0;
    
}

// ======================================================================

// ---------- Observateurs


// ---------- Primitives modifiant 1 tour


// ---------- Primitives modifiant plusieurs tours
void initialiserTours(UnePile tabPile[NB_TOURS])
{
    for (unsigned int i = 0; i < NB_TOURS-1; i++)
    {
        initialiser(tabPile[i]);
    }
    
}

void remplirTour (unsigned int nombreDisques, UnePile & tour)
{
    for (unsigned int i = nombreDisques; i >= 1; i++)
    {
        empiler(tour, i);
    }
    
}

void deplacerDisque (UnePile & tourOrigine, UnePile & tourDestination)
{
    unsigned int element;
    depiler(tourOrigine,element);
    empiler(tourDestination,element);
}


bool estDeplacable(UnePile tourOrigine, UnePile tourDestination)
{
    if (estVide(tourOrigine) == false)
    {
        if (estVide(tourDestination))
        {
            return true;
        }
        else
        {
            return (sommet(tourOrigine)< sommet(tourDestination));
        }
    }
}

// ---------- Affichages

void afficherTour(UnePile tour)
// paramètre passé par valeur
{
    unsigned int disque;
    cout << "{ ";
    while (!estVide(tour))
    {
        depiler(tour, disque);
        cout << disque << ". ";
    }
    cout << " }";
}

void afficherTours(UnePile tabTours[NB_TOURS])
{
    for (unsigned int i = 0; i <= NB_TOURS-1; i++)
    {
        afficherTour(tabTours[i]);
    }
    
}


// ---------- Algorithme de résolution du problème des tours de Hanoi

void resoudreToursManuel(unsigned int nbDisques)
{


    /*  A DéCOMMENTER lorsque vous aurez codé les sous-programmes suivants :
        - initialiserTours()
        - remplirTour()
        - afficherTour()
        - afficherTours()
        - deplacerDisque()
*/

    UnePile lesTours[NB_TOURS];

    unsigned int tourOrigine;       // tour origine du déplacement
    unsigned int tourDestination;   // tour destination du déplacement
    bool deplacementDemande;        // = vrai si, mors de la saisie, un déplacement est demandé, 
                                    // = faux si pas de déplacement demandé

     // Initialiser tours et éléments de la réussite
    initialiserTours(lesTours);
    remplirTour(nbDisques, lesTours[0]);
    afficherTours(lesTours); cout << endl;
       
    // faire des déplacements manuels jusqu'à gagner
    do
    {
        // saisie - verif
       saisieVerifDeplacementDemande(deplacementDemande, tourOrigine, tourDestination);

        if (deplacementDemande)
        {
            // faire le déplacement demandé
            deplacerDisque (lesTours[tourOrigine], lesTours[tourDestination]);
            afficherTours(lesTours);
        }
    } while (!(estVide(lesTours[0]) && estVide(lesTours[1])));
    
    
}


/* ---------- Boîte à outils pour Hanoi Manuel 
   -------------------------------------------------------------------*/

   void saisieVerifDeplacementDemande(bool& deplacement, unsigned int& origine, unsigned int& destination)
   {
        string demandeSaisie    ;  // la demande de déplacement saisie
        bool reponseOk ;            // indicateur de validité de la réponse saisie : "12", "21", .... "31", ou "0xx"
        
        
        deplacement = false;   // = faux si l'utilisateur saisit "0" (pas de déplacement), vrai s'il saisit une des autres combinaisons autorisées
        cout << endl << " tourOrigine-tourDestination (exple : 12), 0 si pas de deplacement " ;

        do
        {
            // saisie 
            cout << " : " ;
            cin >> demandeSaisie;

            // analyse de validité
            reponseOk = false;
            if (
                (demandeSaisie[0] == '0') 
                || (    (demandeSaisie[0] >= '1') && (demandeSaisie[0] <= '3')
                     && (demandeSaisie[1] >= '1') && (demandeSaisie[1] <= '3')
                   )
               ) 
            {
                reponseOk = true;
            }
        } while (!reponseOk);

        // demandeSaisie >> Analyse de la réponse correcte >>  >> deplacement, [origine, destination] 
        if (demandeSaisie[0] != '0')
        {
            origine = carToChiffre(demandeSaisie[0]) - 1;
            destination = carToChiffre(demandeSaisie[1]) - 1;
            deplacement = true;
        }
   }

      int carToChiffre (char car)
      {
          int chiffre;
          chiffre = int(car-int('0'));
          return chiffre;
      }

      
/* ---------- Boîte à outils pour resolutionToursHanoiAutomatique ()
   -------------------------------------------------------------------*/