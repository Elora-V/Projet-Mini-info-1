#ifndef Affichage
#define Affichage

#include "structure.h"


/* Description générale de ce fichier :
	Ce fichier contient les fonctions qui affiche le potager.
	TabNNespace et RemplirNNPuceron permettent de récupérer un tableau du format du potager avec les informations des pucerons.
	affichagePotager et affichageSurDemande permettent l'affichage du potager.
	
/*


/*	Titre : TabNNespace
	Entrée: 
	Sortie: 
	Operation: 
*/
void TabNNespace(char tab[N][N]);

/*	Titre : RemplirNNpuceron
	Entrée: 
	Sortie: 
	Operation: 
*/
void RemplirNNpuceron( potager * potager, char tab[N][N]);



/*	Titre : affichePotager
	Entrée: 
	Sortie: 
	Operation: 
*/
void affichePotager(potager *potager);



/*	Titre : affichageSurDemande
	Entrée: 
	Sortie: 
	Operation: 
*/
void affichageSurDemande(int affichage,potager*potager);

#endif
