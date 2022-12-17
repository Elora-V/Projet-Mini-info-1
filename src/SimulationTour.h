#ifndef SimulationTour
#define SimulationTour

#include "structure.h"

/* Description générale de ce fichier :

	Ce fichier contient les fonctions permettant de simuler un tour. Une étape du tour a deux fonctions associées dans le fichier : celle qui réalise l'action sur un élément et celle qui l'applique à l'ensemble de ces éléments.

*/

//-----------------------------------------------------------------------------------------------------------------------//

/*	Titre : Maturation1Tomate
	Entrée: 
	Sortie: 
	Operation: 
*/
void Maturation1Tomate(tomate*tomate);

/*	Titre : MaturationTouteTomate
	Entrée: 
	Sortie: 
	Operation: 
*/
void MaturationTouteTomate(potager*potager);

//-----------------------------------------------------------------------------------------------------------------------//
/*	Titre : Puceron1Mange
	Entrée: 
	Sortie: 
	Operation: 
*/
void Puceron1Mange(insecte*puceron, potager*potager);

/*	Titre : TousPuceronMange
	Entrée: 
	Sortie: 
	Operation: 
*/
void TousPuceronMange(potager*potager);

//-----------------------------------------------------------------------------------------------------------------------//
/*	Titre : Mvt1Puceron
	Entrée: 
	Sortie: 
	Operation: 
*/
void Mvt1Puceron( insecte*puceron, potager *potager);

/*	Titre : MvtTousPuceron
	Entrée: 
	Sortie: 
	Operation: 
*/
void MvtTousPuceron(potager *potager);

//-----------------------------------------------------------------------------------------------------------------------//
/*	Titre : reproduction1Puceron
	Entrée: 
	Sortie: 
	Operation: 
*/
void reproduction1Puceron( insecte*puceron, potager *potager);

/*	Titre : reproTousPuceron
	Entrée: 
	Sortie: 
	Operation: 
*/
void reproTousPuceron(potager*potager);


#endif
