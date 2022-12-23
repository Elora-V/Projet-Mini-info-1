#ifndef ListeCaseFiltre
#define ListeCaseFiltre

#include "structure.h"

/* Description générale de ce fichier :

	Ce fichier contient les fonctions permettant de créer et modifier la liste des cases sur lequelles un puceron et une coccinelle peuvent aller.
	CasesApresMvt est utilisée dans le cas où le puceron/ la coccinelle continue son mouvement.
	listaNCase créer la liste des cases à une distance n de notre position
	ChoixCaseTabPosition permet de choisir une de ces cases et d'y aller
	
	filtreCaseSansPuc, filtreCaseAvecPuc, filtreCaseSansCocci, filtreCaseAvecTomate et filtreCaseMvtVersPuc sont utilisées pour filtrer un tableau de case pour n'avoir que des cases respectant certaines conditions.
	EchangeTabCaseMvt et CopieTableauMvt sont des fonctions 'logistique' d'échange de case et de copie de tableau.
	
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


/*	Titre : ChoixCaseTabPosition
	Entrée: taille du tableau en argument, tableau modifié par la fonction listaNCase, et l'adresse d'un insecte
	Sortie: change l'insecte
	Operation: change la position et le mouvement de l'insecte vers la case choisi, cette case est choisi aléatoirement dans le tableau contenant les cases respectants les conditions
*/
void ChoixCaseTabPosition(int nbcase, caseMvt tab[], insecte *Insecte );


//------------------------------------------------------------------------------------------------------------------------------------------------------//

/*	Titre : filtreCaseSansPuc
	Entrée: tableau modifié par la fonction listaNCase, taille de ce tableau (sortie de la fonction listaNCase) et le potager
	Sortie: change le tableau 
	Operation: change le tableau pour ne garder que les positions à une distance n qui ne contiennent pas de puceron
*/
void filtreCaseSansPuc( caseMvt tab[], int *nbCaseRempli , potager* potager);


/*	Titre : filtreCaseAvecPuc
	Entrée: tableau modifié par la fonction listaNCase, taille de ce tableau (sortie de la fonction listaNCase) et le potager
	Sortie: change le tableau 
	Operation: change le tableau pour ne garder que les positions à une distance n  qui  contiennent des pucerons
*/
void filtreCaseAvecPuc( caseMvt tab[], int * nbCaseRempli , potager *potager);


/*	Titre : filtreCaseSansCocci
	Entrée: tableau modifié par la fonction listaNCase, taille de ce tableau (sortie de la fonction listaNCase) et le potager
	Sortie: change le tableau 
	Operation: change le tableau pour ne garder que les positions à une distance n qui ne contiennent pas de coccinelles
*/
void filtreCaseSansCocci( caseMvt tab[], int * nbCaseRempli , potager *potager);

/*	Titre : filtreCaseAvecTomate
	Entrée: tableau modifié par la fonction listaNCase, taille de ce tableau (sortie de la fonction listaNCase) et le potager
	Sortie: change le tableau
	Operation: change le tableau pour ne garder que les positions à une distance n qui contiennent des tomates
*/
void filtreCaseAvecTomate( caseMvt tab[], int *nbCaseRempli , potager *potager);


/*	Titre : filtreCaseMvtVersPuc
	Entrée: tableau contenant les cases avec des pucerons à une distance >1, sa 'taille', tableau des cases libres (sans coccinelles) à une distance de 1
	Sortie: change le tableau tabLibre des cases à une distance de 1
	Operation: change le tableau pour ne garder que les positions qui vont vers un puceron, c'est-à-dire les cases de tabLibre qui ont un mouvement commun à l'une des cases de TabPuc
*/
void filtreCaseMvtVersPuc( caseMvt tabPuc[], int * nbCasePuc , caseMvt tabLibre[], int *nbCaseLibre);

//------------------------------------------------------------------------------------------------------------------------------------------------------//

/*	Titre : EchangeTabCaseMvt
	Entrée: tableau de structure caseMvt (position et mouvement associé) ainsi que les deux indices des cases à interchanger
	Sortie: change le tableau
	Operation: recopie les informations de la case 1 en mémoire, mets les informations de la case 2 dans la case 1 et recopie les informations gardées en mémoire de la case 1 dans la case 2
*/
void EchangeTabCaseMvt( caseMvt tab[] , int indice1 , int indice2 );


/*	Titre : CopieTableauMvt
	Entrée: 2 tableaux de structure caseMvt (position et mouvement associé) ainsi que les deux indices de leur 'longueur' (cases remplies)
	Sortie: le tableau 2 prend les valeurs du tableau 1
	Operation: recopie les informations du tableau 1 dans le tableau 2
*/
void CopieTableauMvt(caseMvt tab1[],int nbcase1, caseMvt tab2[],int *nbcase2 );



#endif
