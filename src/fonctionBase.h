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
	Entrée:
	Sortie:
	Operation:
*/	
int VerifSiTomate(coord *position, potager *potager);

/*	Titre: VerifPasPuceron
	Entrée:
	Sortie:
	Operation:
*/
int VerifPasPuceron(coord *position ,potager *potager);

//--------------------------------------------------------------------------------------------------------------------------------------------//

/*	Titre: RandPosPuc
	Entrée:
	Sortie:
	Operation:
*/
void RandPosPuc(coord*position);


/*	Titre:PositionSansPuceron
	Entrée:
	Sortie:
	Operation:
*/
void PositionSansPuceron( coord *position, potager *potager);


/*	Titre: RemplirPuceron
	Entrée:
	Sortie:
	Operation:
*/
void RemplirPuceron(insecte*puceron,int id,coord position, int mvt,char dessin);


/*	Titre: AjoutPuceron
	Entrée:
	Sortie:
	Operation:
*/
void AjoutPuceron( insecte *puceron, potager *potager);

//--------------------------------------------------------------------------------------------------------------------------------------------//

/*	Titre: TraductionMvtDessin
	Entrée:
	Sortie:
	Operation:
*/
void TraductionMvtDessin(int mvtNb, char *mvtdessin);


/*	Titre: MotifTomate
	Entrée:
	Sortie:
	Operation:
*/
void MotifTomate(int JRepousse,char*Maturite);

//--------------------------------------------------------------------------------------------------------------------------------------------//


/*	Titre: MortTomate
	Entrée:
	Sortie:
	Operation:
*/
void MortTomate(tomate*tomate);


#endif
