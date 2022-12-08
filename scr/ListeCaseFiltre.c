#include "structure.h"
#include "fonctionBase.h" 

#include "ListeCase&Filtre.h"

int listaNCase(coord position , int n , caseMvt tab[]){ 
	
	//initialisation et/ou déclarations des variables
	int i;
	int j;
	int x=position.x;
	int y=position.y;
	int longueurLigne = 2*n+1;
	int longueurColonne=2*(n-1)+1;
	int cases=0; //nombre de cases remplie
	
	
	//ajout case ligne supérieur (voir schéma dans le rendu écrit), y constant (représenté par j) et x varie (représenté par i)
	i=(x-n+N)%N;
	j=(y-n+N)%N;
	for (int compte=0; compte < longueurLigne ; compte ++ ){
		tab[cases].position.x= i; // la valeur de l'axe des abscisses
		tab[cases].position.y= j; // la valeur fixé de l'axe des ordonnées
		// indique les mouvement associés, c'est-à-dire le mouvement nécessaire pour aller dans la direction de la case
		if (compte < n) {
			tab[cases].mvt= 0; //on va en diagonale haut gauche
		}
		else if (compte == n) {
			tab[cases].mvt= 1; //on va en haut
		}
		else if (compte > n) {
			tab[cases].mvt= 2; //on va en diagonale haut droite
		}
		i=(i+1)%N; //change la valeur de l'axe des abscisses
		cases++;   // change la prochaine case à remplir
	}
	
	
	//ajout case ligne inférieur (voir schéma dans le rendu écrit), y constant (représenté par j) et x varie (représenté par i)
	i=(x-n+N)%N;
	j=(y+n+N)%N;
	for (int compte=0; compte < longueurLigne ; compte ++ ){  
		tab[cases].position.x= i; // la valeur de l'axe des abscisses
		tab[cases].position.y= j; // la valeur fixé de l'axe des ordonnées
		// indique les mouvement associés, c'est-à-dire le mouvement nécessaire pour aller dans la direction de la case
		if (compte < n) {
			tab[cases].mvt= 5; //on va en diagonale bas gauche
		}
		else if (compte == n) {
			tab[cases].mvt= 6; //on va en bas
		}
		else if (compte > n) {
			tab[cases].mvt= 7; //on va en diagonale bas droite
		}
		i=(i+1)%N; //change la valeur de l'axe des abscisses
		cases++;   // change la prochaine case à remplir
	}
	
	
	//ajout case colonne gauche (voir schéma dans le rendu écrit), x constant (représenté par i) et y varie (représenté par j)
	j=(y-(n-1)+N)%N;
	i=(x-n+N)%N;
	for (int compte=0; compte < longueurColonne ; compte ++ ){
		tab[cases].position.x= i; // la valeur de l'axe des abscisses
		tab[cases].position.y= j; // la valeur fixé de l'axe des ordonnées
		// indique les mouvement associés, c'est-à-dire le mouvement nécessaire pour aller dans la direction de la case
		if (compte < n-1) {
			tab[cases].mvt= 0; //on va en diagonale haut gauche
		}
		else if (compte == n-1) {
			tab[cases].mvt= 3; //on va à gauche
		}
		else if (compte > n-1) {
			tab[cases].mvt= 5; //on va en diagonale bas gauche
		}
		j=(j+1)%N; //change la valeur de l'axe des ordonnées
		cases++;   // change la prochaine case à remplir
	}
	
	//ajout case colonne droite (voir schéma dans le rendu écrit), x constant (représenté par i) et y varie (représenté par j)
	j=(y-(n-1)+N)%N;
	i=(x+n+N)%N;
	for (int compte=0; compte < longueurColonne ; compte ++ ){
		tab[cases].position.x= i; // la valeur de l'axe des abscisses
		tab[cases].position.y= j; // la valeur fixé de l'axe des ordonnées
		// indique les mouvement associés, c'est-à-dire le mouvement nécessaire pour aller dans la direction de la case
		if (compte < n-1) {
			tab[cases].mvt= 2; //on va en diagonale haut droite
		}
		else if (compte == n-1) {
			tab[cases].mvt= 4; //on va à droite
		}
		else if (compte > n-1) {
			tab[cases].mvt= 7; //on va en diagonale bas droite
		}
		j=(j+1)%N; //change la valeur de l'axe des ordonnées
		cases++;   // change la prochaine case à remplir
	}
	
	return cases; //le nombre de case que l'on vient d'écrire dans le tableau
}	
	
	
		

int filtreCaseSansPuc( caseMvt tab[],  nbCaseRempli , potager potager){
	int booleen;
	for (int i=0;i<nbCaseRempli;i++){
		
		booleen=VerifPasPuceron(tab[i].position,potager)
		if( !booleen ){ //si il y a un puceron :
			
			EchangeTabCaseMvt(tab, i, nbCaseRempli-1); // 1: on échange notre case avec déjà un puceron avec la dernière du tableau
			nbCaseRempli--;                            // 2: on indique qu'on a une case rempli en moins
			
		}	
		
	}
	return nbCaseRempli;	
}




int filtreCaseAvecTomate( caseMvt tab[],  nbCaseRempli , potager potager){
	int booleen;
	for (int i=0;i<nbCaseRempli;i++){
		
		booleen=VerifSiTomate(tab[i].position,potager)
		if( !booleen ){ //si il y a pas de tomate :
			
			EchangeTabCaseMvt(tab, i, nbCaseRempli-1); // 1: on échange notre case avec déjà un puceron avec la dernière du tableau
			nbCaseRempli--;                            // 2: on indique qu'on a une case rempli en moins
			
		}		
	}
	return nbCaseRempli;	
}








