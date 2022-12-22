
#ifndef Affichage
#define Affichage

#include "structure.h"

/* Description générale de ce fichier :
	Contient les fonctions permettant d'initialiser les tomates et les pucerons, puis de les placer dans le potager.

*/


/*	Titre : IniTomates
	Entrée: adresse tomate
	Sortie: modification tomate
	Operation: initie une tomate avec un nombre de jour de repousse à 5 et un dessin correspondant à 'O'
*/
void IniTomates(tomate*tomate); 


/*	Titre : IniPotagerTomate
	Entrée: adresse du potager
	Sortie: modifie le potager de tomate
	Operation: applique la fonction IniTomates pour planter des tomates mûres dans tout le potager
*/
void IniPotagerTomate(potager*potager);


/*	Titre : IniPuceron
	Entrée: adresse d'un puceron et du potager
	Sortie: modifie le puceron 
	Operation: initie les valeurs du puceron (la position et le mouvement de manière aléatoire), la position doit être sans puceron (on ne veut pas 2 pucerons au même endroit)
*/
void IniPuceron (insecte *puceron,potager *potager);


/*	Titre : RemplissagePotagerPuceron
	Entrée: adresse du potager
	Sortie: modifie le potager (EnsPuceron)
	Operation: applique la fonction iniPuceron et place le puceron dans le potager, on fait cette action NbPuceron fois (nombre de puceron à placer dans le potager en début de partie)
*/
void RemplissagePotagerPuceron(potager*potager);

void IniCocci (insecte *cocci,potager *potager);

void RemplissagePotagerCocci(potager*potager);


#endif
