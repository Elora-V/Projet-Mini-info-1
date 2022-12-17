#include "structure.h"
#include "fonctionBase.h" 
#include "ListeCaseFiltre.h"



int listaNCase(coord position , int  n , caseMvt tab[]){ 
	
	//initialisation et/ou déclarations des variables
	int i;
	int j;
	int x=position.x;
	int y=position.y;
	int longueurLigne = 2*n+1;
	int longueurColonne=2*(n-1)+1;
	int cases=0; //nombre de cases remplie
	
	
	//ajout case ligne supérieur (voir schéma dans le rendu écrit), x constant (représenté par i,ligne) et y varie (représenté par j,col)
	i=(x-n+N)%N;
	j=(y-n+N)%N;
	for (int compte=0; compte < longueurLigne ; compte ++ ){
		tab[cases].Position.x= i; // la valeur de l'axe des abscisses
		tab[cases].Position.y= j; // la valeur fixé de l'axe des ordonnées
		// indique les mouvement associés, c'est-à-dire le mouvement nécessaire pour aller dans la direction de la case
		if (compte < n) {
			tab[cases].Mvt= 0; //on va en diagonale haut gauche
		}
		else if (compte == n) {
			tab[cases].Mvt= 1; //on va en haut
		}
		else if (compte > n) {
			tab[cases].Mvt= 2; //on va en diagonale haut droite
		}
		j=(j+1)%N; //change la valeur de l'axe des abscisses
		cases++;   // change la prochaine case à remplir
	}
	
	
	//ajout case ligne inférieur (voir schéma dans le rendu écrit), x constant (représenté par i) et y varie (représenté par j)
	j=(y-n+N)%N;
	i=(x+n+N)%N;
	for (int compte=0; compte < longueurLigne ; compte ++ ){  
		tab[cases].Position.x= i; // la valeur de l'axe des abscisses
		tab[cases].Position.y= j; // la valeur fixé de l'axe des ordonnées
		// indique les mouvement associés, c'est-à-dire le mouvement nécessaire pour aller dans la direction de la case
		if (compte < n) {
			tab[cases].Mvt= 5; //on va en diagonale bas gauche
		}
		else if (compte == n) {
			tab[cases].Mvt= 6; //on va en bas
		}
		else if (compte > n) {
			tab[cases].Mvt= 7; //on va en diagonale bas droite
		}
		j=(j+1)%N; //change la valeur de l'axe des abscisses
		cases++;   // change la prochaine case à remplir
	}
	
	
	//ajout case colonne gauche (voir schéma dans le rendu écrit), y constant (représenté par j) et x varie (représenté par i)
	i=(x-(n-1)+N)%N;
	j=(y-n+N)%N;
	for (int compte=0; compte < longueurColonne ; compte ++ ){
		tab[cases].Position.x= i; // la valeur de l'axe des abscisses
		tab[cases].Position.y= j; // la valeur fixé de l'axe des ordonnées
		// indique les mouvement associés, c'est-à-dire le mouvement nécessaire pour aller dans la direction de la case
		if (compte < n-1) {
			tab[cases].Mvt= 0; //on va en diagonale haut gauche
		}
		else if (compte == n-1) {
			tab[cases].Mvt= 3; //on va à gauche
		}
		else if (compte > n-1) {
			tab[cases].Mvt= 5; //on va en diagonale bas gauche
		}
		i=(i+1)%N; //change la valeur de l'axe des ordonnées
		cases++;   // change la prochaine case à remplir
	}
	
	//ajout case colonne droite (voir schéma dans le rendu écrit), y constant (représenté par j) et x varie (représenté par i)
	i=(x-(n-1)+N)%N;
	j=(y+n+N)%N;
	for (int compte=0; compte < longueurColonne ; compte ++ ){
		tab[cases].Position.x= i; // la valeur de l'axe des abscisses
		tab[cases].Position.y= j; // la valeur fixé de l'axe des ordonnées
		// indique les mouvement associés, c'est-à-dire le mouvement nécessaire pour aller dans la direction de la case
		if (compte < n-1) {
			tab[cases].Mvt= 2; //on va en diagonale haut droite
		}
		else if (compte == n-1) {
			tab[cases].Mvt= 4; //on va à droite
		}
		else if (compte > n-1) {
			tab[cases].Mvt= 7; //on va en diagonale bas droite
		}
		i=(i+1)%N; //change la valeur de l'axe des ordonnées
		cases++;   // change la prochaine case à remplir
	}
	
	return cases; //le nombre de case que l'on vient d'écrire dans le tableau
}	
	



	
void filtreCaseSansPuc( caseMvt tab[], int * nbCaseRempli , potager *potager){
	int booleen;
	int i=0;
	coord *pos;
	
	while(i< *nbCaseRempli ){ //i parcourt le tableau, il ne doit pas dépasser celui-ci
		
		pos=&(tab[i].Position); //pos est un pointeur, on lui donne une adresse
		booleen=VerifPasPuceron(pos,potager); //potager est un pointeur, donc pas &potager
		
		if( !booleen ){ //si il y a un puceron :
			
			// 1: on échange notre case avec déjà un puceron avec la dernière du tableau (si ce n'est pas la meme)
			if (i!= *nbCaseRempli-1){ 
				EchangeTabCaseMvt(tab, i, *nbCaseRempli-1); 
			}
			// 2: on indique qu'on a une case rempli en moins
			*nbCaseRempli=*nbCaseRempli-1;
			                            
			// 3 :on voudra verifier que la case mise à la place n'a pas de puceron, donc on recule d'un cran dans le tableau
			i--; 
			
		}
		
		i++;		
	}
}





void filtreCaseAvecTomate( caseMvt tab[], int * nbCaseRempli , potager *potager){
	int booleen;
	int i=0;
	coord *pos;
	
	while(i< *nbCaseRempli ){ //i parcourt le tableau, il ne doit pas dépasser celui-ci
		
		
		pos=&(tab[i].Position); //adresse de la position
		booleen=VerifSiTomate(pos,potager);
		
		
		if( !booleen ){ //si il y a pas de tomate :
			
			
			// 1: on échange notre case avec déjà un puceron avec la dernière du tableau (si ce n'est pas la meme)
			if (i!= *nbCaseRempli-1){ 
				EchangeTabCaseMvt(tab, i, *nbCaseRempli-1); 
			}
			// 2: on indique qu'on a une case rempli en moins
			
			*nbCaseRempli=*nbCaseRempli-1;
			
			                            
			// 3 :on voudra verifier que la case mise à la place n'a pas de puceron, donc on recule d'un cran dans le tableau
			i--; 
			
		}
		
		i++;		
	}
}


void CasesApresMvt(coord *cases, coord *position, int *mvt){
	
	//choix du x de la case (ligne)
	if (*mvt == 0 || *mvt == 1 || *mvt == 2){ //si c'est un mouvement vers la gauche
		(*cases).x=( (*position).x - 1 + N )%N;
		
	} else if (*mvt == 5 || *mvt == 6 || *mvt == 7){ //si c'est un mouvement vers la droite
		(*cases).x=( (*position).x + 1 + N )%N;
		
	}else { //pas de mouvement de x
		(*cases).x= (*position).x ;
		
	}

	//choix du y de la case (colonne)
	if (*mvt == 0 || *mvt == 3 || *mvt == 5){ //si c'est un mouvement vers le haut
		(*cases).y=( (*position).y - 1 + N )%N;
		
	} else if (*mvt == 2 || *mvt == 4 || *mvt == 7){ //si c'est un mouvement vers le bas
		(*cases).y=( (*position).y + 1 + N )%N;
		
	}else{
		(*cases).y=(*position).y;
		
	}
}









