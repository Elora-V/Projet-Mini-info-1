
#ifndef Affichage
#define Affichage

#include "structure.h"

/* Description générale de ce fichier :
	Contient les fonctions permettant d'initialiser les tomates et les pucerons, puis de les placer dans le potager.

*/


/*	Titre : IniTomates
	Entrée: 
	Sortie: 
	Operation: 
*/
void IniTomates(tomate*tomate); 


/*	Titre : IniPotagerTomate
	Entrée: 
	Sortie: 
	Operation: 
*/
void IniPotagerTomate(potager*potager);


/*	Titre : IniPuceron
	Entrée: 
	Sortie: 
	Operation: 
*/
void IniPuceron (insecte *puceron,potager *potager);


/*	Titre : RemplissagePotagerPuceron
	Entrée: 
	Sortie: 
	Operation: 
*/
void RemplissagePotagerPuceron(potager*potager);




#endif
