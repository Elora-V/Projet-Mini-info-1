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
	Operation: si le puceron est sur une case avec tomate, la tomate est mangé (on applique MortTomate du fihier fonctionBase) et le nombre de jours consécutifs où le puceron a mangé est incrementé de 1
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

//-----------------------------------------------------------------------------------------------------------------------//

/*	Titre : Vieillissement1Puceron
	Entrée: adresse du puceron, du potager et d'un booléen 'mort'
	Sortie: modifie le potager et 'mort'
	Operation: réduit la vie du puceron de 1, si sa vie tombe à 0 il meurt, 'mort' vaut 1 dans le cas où le puceron est mort (0 sinon)
*/
void Vieillissement1Puceron(insecte*puceron,potager*potager,int *mort);


/*	Titre : VieillissementTousPuceron
	Entrée: adresse du potager
	Sortie: modifie le potager 
	Operation: applique Vieillissement1Puceron a tous les pucerons du potager
*/
void VieillissementTousPuceron(potager*potager);

//-----------------------------------------------------------------------------------------------------------------------//


/*	Titre : Cocci1Mange
	Entrée: adresse de la coccinelle et du potager
	Sortie: modifie la coccinelle et le potager
	Operation: si la coccinelle est sur une case avec puceron, le puceron est mangé (on applique MortPuceron du fihier fonctionBase) et le nombre de jours où la coccinelle a mangé est incrementé de 1
*/
void Cocci1Mange(insecte*cocci, potager*potager);


/*	Titre : TousCocciMange
	Entrée: adresse du potager
	Sortie: modification du potager
	Operation: applique la fonction Cocci1Mange à toutes les coccinelles
*/
void TousCocciMange(potager*potager);

//-----------------------------------------------------------------------------------------------------------------------//


/*	Titre : Mvt1Cocci
	Entrée: adresse de la coccinelle et du potager
	Sortie: modifie le potager et la coccinelle
	Operation: Si en continuant son mouvement la coccinelle atterit sur une case avec puceron elle y va, sinon elle va sur une case attenante en direction d'un puceron au hasard. Si aucune case 	sans coccinelles n'est disponible, elle ne bouge pas. Si aucune case vers un puceron n'est disponible elle va sur une case attenante sans coccinelle. La coccinelle regardera d'abord les pucerons disponibles à une distance de 1 case, puis de 2 et de 3. Si une coccinelle lui bloque le passage en direction d'un puceron elle va aller vers un autre puceron.
*/
void Mvt1Cocci( insecte*cocci, potager *potager);


/*	Titre : MvtTousCocci
	Entrée: adresse du potager
	Sortie: modifie le potager
	Operation: applique Mvt1Cocci a toutes les coccinelles du potager
*/
void MvtTousCocci(potager *potager);

//-----------------------------------------------------------------------------------------------------------------------//


/*	Titre : reproduction1Cocci
	Entrée: adresse de la coccinelle et du potager
	Sortie: modifie le potager et la coccinelle
	Operation: si la coccinelle à mangé pendant 3 tours elle essaie de se reproduire. Si il n'y a aucune case sans coccinelle autour d'elle, elle ne se reproduit pas (pas la place pour l'enfant), sinon on ajoute une nouvelle coccinelle sur une case attentant sans coccinelless aléatoirement. En effet, on ne peut pas avoir 2 coccinelles sur la même case.
*/
void reproduction1Cocci( insecte*cocci, potager *potager);


/*	Titre : reproTousCocci
	Entrée: adresse du potager
	Sortie: modifie le potager
	Operation: applique reproduction1Cocci a toutes les coccinelles du potager qui ne sont pas nouvelles (présente au tour précédent)
*/
void reproTousCocci(potager*potager);

//-----------------------------------------------------------------------------------------------------------------------//


/*	Titre : Vieillissement1Cocci
	Entrée: adresse de la coccinelle, du potager et d'un booléen 'mort'
	Sortie: modifie le potager et 'mort'
	Operation: réduit la vie de la coccinelle de 1, si sa vie tombe à 0 elle meurt, 'mort' vaut 1 dans le cas où la coccinelle est morte (0 sinon)
*/
void Vieillissement1Cocci(insecte*cocci,potager*potager,int *mort);


/*	Titre : VieillissementTousCocci
	Entrée: adresse du potager
	Sortie: modifie le potager 
	Operation: applique Vieillissement1Cocci a toutes les coccinelles du potager
*/
void VieillissementTousCocci(potager*potager);


#endif

