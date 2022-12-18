#ifndef FonctionBase
#define FonctionBase

#include "structure.h"

/* Description générale de ce fichier :
	Contient les fonctions pouvant être appellées dans plusieurs fichier différents ou n'aillant pas de thème particulier. 
	Cela permet aussi d'alléger les autres fichiers pour les rendre plus comprehensible.
	
	VerifSiTomate et VerifPasPuceron sont des fonctions de vérification.
	RandPosPuc, PositionSansPuceron, RemplirPuceron et AjoutPuceron sont des fonctions ayant pour but de modifier un puceron.
	TraductionMvtDessin et MotifTomate sont des fonctions qui 'traduisent' une variable en une autre quand celle-ci sont liées, ici cela les traduit en charactère pour les dessiner.
	MortTomate est la disparition d'une tomate, elle n'est utilisé que dans une fonction mais la placer ici permet d'alleger le fichier SimulationTour qui a de nombreuses fonctions.
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

//--------------------------------------------------------------------------------------------------------------------------------------------//

/*	Titre: RandPosPuc
	Entrée: adresse d'une position
	Sortie: modifie la position
	Operation: modifie la position pour lui donner un x et y aléatoire
*/
void RandPosPuc(coord*position);


/*	Titre:PositionSansPuceron
	Entrée: adresse d'une position et adresse du potager
	Sortie: modifie la position
	Operation:  modifie la position pour qu'elle ne contient pas du puceron, celle-ci est déterminée de manière aléatoirement et on vérifie qu'elle est libre 
*/
void PositionSansPuceron( coord *position, potager *potager);


/*	Titre: RemplirPuceron
	Entrée: adresse du puceron, son identifiant, sa position, son mouvement et son dessin associé
	Sortie: modifie le puceron
	Operation: modifie le puceron pour lui donner les valeurs en arguments. La fontion sert pour initier un puceron, sa vie est mise à 10 et son nombre de jour consécutif où il a mangé à 0
*/
void RemplirPuceron(insecte*puceron,int id,coord position, int mvt,char dessin);


/*	Titre: AjoutPuceron
	Entrée: adresse du puceron et du potager
	Sortie: modifie le potager
	Operation: ajoute le puceron au tableau contenant les pucerons et incremente NbPuceronVie de 1
*/
void AjoutPuceron( insecte *puceron, potager *potager);

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


#endif
