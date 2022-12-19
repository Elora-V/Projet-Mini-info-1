#ifndef Affichage
#define Affichage

#include "structure.h"


/* Description générale de ce fichier :
	Ce fichier contient les fonctions qui affiche le potager.
	TabNNespace et RemplirNNPuceron permettent de récupérer un tableau du format du potager avec les informations des pucerons.
	affichagePotager et affichageSurDemande permettent l'affichage du potager.
	
*/


/*	Titre : TabNNespace
	Entrée: tableau N*N de caractère
	Sortie: modifie le tableau
	Operation: le tableau est modifié pour ne contenir que le caractère ' ' (espace)
*/
void TabNNespace(char tab[N][N]);

/*	Titre : RemplirNNpuceron
	Entrée: adresse du potager et un tableau d'espace (on utilise la fonction TabNNespace pour l'obtenir)
	Sortie: modifie le tableau
	Operation: le caractère espace est remplacé par le caractère des pucerons de EnsPuceron (du potager) à leur position
*/
void RemplirNNpuceron( potager * potager, char tab[N][N]);



/*	Titre : affichePotager
	Entrée: adresse du potager
	Sortie: affiche le potager (tomates et pucerons)
	Operation: créer un tableau du format du potager et y place les pucerons, puis parcours le potager de tomate et de puceron (du même format) pour afficher ce qui est présent sur la case
*/
void affichePotager(potager *potager);



/*	Titre : affichageSurDemande
	Entrée: entier indiquant le type d'affichage voulu, et l'adresse du potager
	Sortie: affiche le potager en fonction de la demande de l'utilisateur
	Operation: si affichage vaut 1 le potager est affiché, si affichage vaut 2 le programme demande à l'utilisateur s'il veut l'afficher, tout autre chiffre n'affiche pas le potager
*/
void affichageSurDemande(int affichage,potager*potager);

#endif
