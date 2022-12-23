#ifndef FonctionBase
#define FonctionBase

#include "structure.h"

/* Description générale de ce fichier :
	Contient les fonctions pouvant être appellées dans plusieurs fichiers différents ou n'aillant pas de thème particulier. 
	Cela permet aussi d'alléger les autres fichiers pour les rendre plus comprehensible.
	
	VerifSiTomate, VerifPasPuceron, VerifPuceronInd et VerifPasCocci sont des fonctions de vérification d'entité sur les cases.
	PositionSansPuceron, AjoutPuceron, MortPuceron et EchangeTableauPuceron sont des fonctions ayant pour but de modifier un puceron, leurs homologues permettent de réaliser la même chose pour les cccinelles.
	TraductionMvtDessin et MotifTomate sont des fonctions qui 'traduisent' une variable en une autre quand celle-ci sont liées, ici cela les traduit en charactère pour les dessiner.
	MortTomate est la disparition d'une tomate, elle n'est utilisé que dans une fonction mais la placer ici permet d'alleger le fichier SimulationTour qui a de nombreuses fonctions.
	RandPos donne une position aléatoire.
	RemplirInsecte rempli les informations donné en entrée dans un insecte.
*/


//--------------------------------------------------------------------------------------------------------------------------------------------//

/*	Titre: VerifSiTomate
	Entrée: adresse d'une position et adresse du potager
	Sortie: 0 si il n'y a pas de tomate mûre sur la case, 1 sinon
	Operation: regarde sur la case du potager associé à la position si la tomate est mûre
*/	
int VerifSiTomate(coord *position, potager *potager);

/*	Titre: VerifPasPuceron
	Entrée: adresse d'une position et adresse du potager
	Sortie: 0 si il n'y a un puceron sur la case, 1 sinon
	Operation: parcours EnsPuceron (tableau de tous les pucerons du potager) pour regarder si la position contient un puceron ou non
*/
int VerifPasPuceron(coord *position ,potager *potager);


/*	Titre: VerifPuceronInd
	Entrée: adresse d'une position, adresse du potager et adress d'un indice
	Sortie: 0 si il  a un puceron sur la case, 1 sinon. De plus la valeur de l'indice est changé par l'identifiant du puceron sur la case s'il y en a un.
	Operation: parcours EnsPuceron (tableau de tous les pucerons du potager) pour regarder si la position contient un puceron ou non et récupère son identifiant
*/
int VerifPuceronInd(coord *position ,potager *potager, int * indice);


/*	Titre: VerifPasCocci
	Entrée: adresse d'une position et adresse du potager
	Sortie: 0 si il n'y a une coccinelle sur la case, 1 sinon
	Operation: parcours EnsCoccinelle (tableau de toutes les coccinelles du potager) pour regarder si la position contient une coccinelle ou non
*/
int VerifPasCocci(coord *position ,potager *potager);

//--------------------------------------------------------------------------------------------------------------------------------------------//


/*	Titre:PositionSansPuceron
	Entrée: adresse d'une position et adresse du potager
	Sortie: modifie la position
	Operation:  modifie la position pour qu'elle ne contient pas de puceron, celle-ci est déterminée de manière aléatoirement  parmi les cases sans pucerons
*/
void PositionSansPuceron( coord *position, potager *potager);



/*	Titre: AjoutPuceron
	Entrée: adresse du puceron et du potager
	Sortie: modifie le potager
	Operation: ajoute le puceron au tableau contenant les pucerons et incremente NbPuceronVie de 1
*/
void AjoutPuceron( insecte *puceron, potager *potager);


/*	Titre: MortPuceron
	Entrée: identifiant du puceron et adresse du potager
	Sortie: modifie le potager
	Operation: echange le puceron à l'identifiant donné avec le dernier du tableau EnsPuceron, reduit NbPuceronVie de 1
*/
void MortPuceron(int identifiant,potager*potager);


/*	Titre: EchangeTableauPuceron
	Entrée: adresse du potager et identifiant du puceron
	Sortie: modifie le potager
	Operation: echange le puceron à l'identifiant donné avec le dernier du tableau EnsPuceron, utilisé pour la fonction MortPuceron
*/
void EchangeTableauPuceron(potager*potager,int indice);

//--------------------------------------------------------------------------------------------------------------------------------------------//


/*	Titre:PositionSanscocci
	Entrée: adresse d'une position et adresse du potager
	Sortie: modifie la position
	Operation:  modifie la position pour qu'elle ne contient pas de coccinelle, celle-ci est déterminée de manière aléatoirement parmi les cases sans coccinelle
*/
void PositionSansCocci(coord *position, potager *potager);


/*	Titre: AjoutCocci
	Entrée: adresse de la coccinelle et du potager
	Sortie: modifie le potager
	Operation: ajoute la coccinelle au tableau contenant les coccinelles et incremente NbCoccinelleVie de 1
*/
void AjoutCocci( insecte *cocci, potager *potager);

/*	Titre: MortCocci
	Entrée: identifiant de la coccinelle et adresse du potager
	Sortie: modifie le potager
	Operation: echange la coccinelle à l'identifiant donné avec la derniere du tableau EnsCoccinelle, reduit NbCoccinelleVie de 1
*/
void MortCocci(int identifiant,potager*potager);


/*	Titre: EchangeTableauCocci
	Entrée: adresse du potager et identifiant de la coccinelle
	Sortie: modifie le potager
	Operation: echange la coccinelle à l'identifiant donné avec la derniere du tableau EnsCoccinelle, utilisé pour la fonction Mortcoccinelle
*/
void EchangeTableauCocci(potager*potager,int indice);

//--------------------------------------------------------------------------------------------------------------------------------------------//

/*	Titre: TraductionMvtDessin
	Entrée: un mouvement (entier de 0 à 7) et l'adresse d'un caractère
	Sortie: modifie le caractère
	Operation: le caractère devient celui associé au chiffre du mouvement, par exemple 0 est associé à '\' (voir les autres correspondance sur le rapport)
*/
void TraductionMvtDessin(int mvtNb, char *mvtdessin);


/*	Titre: MotifTomate
	Entrée: nombre de jour depuis que la tomate est mangée et l'adresse du dessin de la tomate (caractère)
	Sortie: modifie le dessin de la tomate
	Operation: le caractère devient celui associé au chiffre JRepousse, par exemple 5 est associé à 'O' (voir les autres correspondance dans l'énoncé)
*/
void MotifTomate(int JRepousse,char*Maturite);

//--------------------------------------------------------------------------------------------------------------------------------------------//


/*	Titre: MortTomate
	Entrée: l'adresse d'une tomate
	Sortie: modifie la tomate
	Operation: met le nombre de jour depuis qu'elle a été mangé à 0 et change son dessin (caractère) par '.'
*/
void MortTomate(tomate*tomate);

/*	Titre: RandPosPuc
	Entrée: adresse d'une position
	Sortie: modifie la position
	Operation: modifie la position pour lui donner un x et y aléatoire
*/
void RandPos(coord*position);

/*	Titre: RemplirInsecte
	Entrée: adresse du puceron (ou coccinelle), son identifiant, sa position, son mouvement, son dessin associé et sa vie
	Sortie: modifie le puceron (ou coccinelle)
	Operation: modifie l'insecte pour lui donner les valeurs en arguments. La fontion sert pour initier un puceron (ou coccinelle), son nombre de jour consécutif où il a mangé est mis à 0
*/
void RemplirInsecte(insecte*puceron,int id,coord position, int mvt,char dessin,int vie);



#endif
