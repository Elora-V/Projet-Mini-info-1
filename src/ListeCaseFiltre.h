#ifndef ListeCaseFiltre
#define ListeCaseFiltre

#include "structure.h"

/* Description générale de ce fichier :

	Ce fichier contient les fonctions permettant de créer et modifier la liste des cases sur lequelles un puceron peut aller.
	CasesApresMvt est utilisée dans le cas où le puceron continue son mouvement.
	listaNCase, filtreCaseSansPuc et filtreCaseAvecTomate sont utilisées dans le cas où le puceron cherche une case attenantes au hasard respectant certaines conditions.
	EchangeTabCaseMvt est une fonction plus 'logistique' d'échange de case.
	
	Ces fonctions sont utiles dans les cas de mouvement et de reproduction (placement du nouvel individu).

*/



/*	Titre : CasesApresMvt
	Entrée: adresse de la case où va le puceron s'il continue son mouvement (position de la case), la position du puceron et le mouvement que le puceron fait (numero entre 0 et 7)
	Sortie: change la valeur de la case où le puceron va
	Operation: A l'aide du numéro du mouvement, on calcul la case d'arrivée du puceron si celui-ci le réalise
*/
void CasesApresMvt(coord *cases, coord *position, int *mvt);


/*	Titre : listaNCase
	Entrée: position du puceron , la distance au puceron et un tableau vide ( contenant une structure indiquant une position (x,y) et un mouvement) que l'on va remplir
	Sortie: change les cases du tableau et renvoie sa taille (nombre de cases qu'on a remplies)
	Operation: [lire le rapport] Le tableau contiendra la liste des positions se situant à n cases de notre puceron, 
	il contiendra aussi pour chacune de ces cases le mouvement à réaliser pour l'atteindre. 
*/
int listaNCase(coord position , int n , caseMvt tab[]);


/*	Titre : filtreCaseSansPuc
	Entrée: tableau modifié par la fonction listaNCase, taille de ce tableau (sortie de la fonction listaNCase) et le potager
	Sortie: change le tableau 
	Operation: change le tableau pour ne garder que les positions à une distance n du puceron qui ne contiennent pas de puceron
*/
void filtreCaseSansPuc( caseMvt tab[], int *nbCaseRempli , potager* potager);


/*	Titre : filtreCaseAvecTomate
	Entrée: tableau modifié par la fonction listaNCase, taille de ce tableau (sortie de la fonction listaNCase) et le potager
	Sortie: change le tableau
	Operation: change le tableau pour ne garder que les positions à une distance n du puceron qui contiennent des tomates
*/
void filtreCaseAvecTomate( caseMvt tab[], int *nbCaseRempli , potager *potager);


/*	Titre : EchangeTabCaseMvt
	Entrée: tableau de structure caseMvt (position et mouvement associé) ainsi que les deux indices des cases à interchanger
	Sortie: change le tableau
	Operation: recopie les informations de la case 1 en mémoire, mets les informations de la case 2 dans la case 1 et recopie les informations gardées en mémoire de la case 1 dans la case 2
*/
void EchangeTabCaseMvt( caseMvt tab[] , int indice1 , int indice2 );



#endif
