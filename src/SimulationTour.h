#ifndef SimulationTour
#define SimulationTour

#include "structure.h"

/* Description générale de ce fichier :

	Ce fichier contient les fonctions permettant de simuler un tour. Une étape du tour a deux fonctions associées dans le fichier : celle qui réalise l'action sur un élément et celle qui l'applique à l'ensemble de ces éléments.

*/

//-----------------------------------------------------------------------------------------------------------------------//

/*	Titre : Maturation1Tomate
	Entrée: adresse d'une tomate
	Sortie: modification de la tomate
	Operation: JRepousse comptant le nombre de jours depuis que la tomate a été mangé augmente de 1, et son caractère associé est changé en fonction
*/
void Maturation1Tomate(tomate*tomate);

/*	Titre : MaturationTouteTomate
	Entrée: adresse du potager
	Sortie: modification du potager
	Operation: applique la fonction Maturation1Tomate à tout le potager
*/
void MaturationTouteTomate(potager*potager);

//-----------------------------------------------------------------------------------------------------------------------//
/*	Titre : Puceron1Mange
	Entrée: adresse d'un puceron et du potager
	Sortie: modifie le puceron et le potager
	Operation: si le puceron est sur une case avec tomate, la tomate est mangé (on applique MortTomate du fihier fonctionBase) et le nombre de jours consécutifs où le puceron à mangé est incrementé de 1
*/
void Puceron1Mange(insecte*puceron, potager*potager);

/*	Titre : TousPuceronMange
	Entrée: adresse du potager
	Sortie: modification du potager
	Operation: applique la fonction Puceron1Mange à tous les pucerons
*/
void TousPuceronMange(potager*potager);

//-----------------------------------------------------------------------------------------------------------------------//
/*	Titre : Mvt1Puceron
	Entrée: adresse du puceron et du potager
	Sortie: modifie le potager et le puceron
	Operation: si le puceron trouve une tomate sur sa case il ne bouge pas. Si en continuant son mouvement il atterit sur une case libre avec tomate il y va, sinon il va sur une case attenante au hasard contenant une tomate et pas de puceron. Si aucune case sans puceron n'est disponible, il ne bouge pas. Si aucune case avec tomate mûre n'est disponible il va sur une case attenante sans puceron et sans tomate aléatoirement. Le potager est modifié puisqu'il contient le puceron (et donc sa position qui va changer)
*/
void Mvt1Puceron( insecte*puceron, potager *potager);

/*	Titre : MvtTousPuceron
	Entrée: adresse du potager
	Sortie: modifie le potager
	Operation: applique Mvt1Puceron a tous les pucerons du potager
*/
void MvtTousPuceron(potager *potager);

//-----------------------------------------------------------------------------------------------------------------------//
/*	Titre : reproduction1Puceron
	Entrée: adresse du puceron et du potager
	Sortie: modifie le potager et le puceron
	Operation: si le puceron à mangé pendant 5 tours consécutifs il essaie de se reproduire. Si il n'y a aucune case sans puceron autour de lui il ne se reproduit pas (pas la place pour l'enfant), sinon on ajoute un nouveau puceron sur une case attentant sans pucerons aléatoirement. En effet, on ne peut pas avoir 2 pucerons sur la même case.
*/
void reproduction1Puceron( insecte*puceron, potager *potager);

/*	Titre : reproTousPuceron
	Entrée: adresse du potager
	Sortie: modifie le potager
	Operation: applique reproduction1Puceron a tous les pucerons du potager qui ne sont pas nouveaux (présent au tour précédent)
*/
void reproTousPuceron(potager*potager);

//Prend un puceron et renvoie ses points de vie
void Vieillissement1Puceron(insecte*puceron,potager*potager,int *mort);

void VieillissementTousPuceron(potager*potager);

//-----------------------------------------------------------------------------------------------------------------------//

void Cocci1Mange(insecte*cocci, potager*potager);

void TousCocciMange(potager*potager);

//-----------------------------------------------------------------------------------------------------------------------//

void Mvt1Cocci( insecte*cocci, potager *potager);

void MvtTousCocci(potager *potager);

//-----------------------------------------------------------------------------------------------------------------------//

void reproduction1Cocci( insecte*cocci, potager *potager);

void reproTousCocci(potager*potager);

//-----------------------------------------------------------------------------------------------------------------------//

void Vieillissement1Cocci(insecte*cocci,potager*potager,int *mort);

void VieillissementTousCocci(potager*potager);


#endif

