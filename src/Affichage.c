#include "Affichage.h" 
#include "fonctionBase.h"
#include "structure.h"


//----------------------------------------------------------------------------------------------------------------------------------TabNNespace--------------------//

void TabNNespace(char tab[N][N]){
	for(int i=0;i<N;i++){
		for (int j=0;j<N;j++) {
			tab[i][j]=' ';
		}
	}
}

//------------------------------------------------------------------------------------------------------------------------------------RemplirNNpuceron------------------//

void RemplirNNpuceron( potager* potager, char tab[N][N]){
	int x;
	int y;
	//on remplace le caractère ' ' par le caractère du puceron pour chacun d'entre eux :
	for (int i=0; i< (*potager).NbPuceronVie ;i++){
		//récupère la position du puceron
		x=(*potager).EnsPuceron[i].Position.x;
		y=(*potager).EnsPuceron[i].Position.y;
		//on met sont caractère dans le tableau
		tab[x][y]=(*potager).EnsPuceron[i].DessinMvt;
	}
}



//------------------------------------------------------------------------------------------------------------------------------------RemplirNNcocci------------------//

void RemplirNNcocci( potager* potager, char tab[N][N]){
	int x;
	int y;
	//on remplace le caractère ' ' par le caractère de la coccinelle pour chacune d'entre elles :
	for (int i=0; i< (*potager).NbCoccinelleVie ;i++){
		//récupère la position de la coccinelle
		x=(*potager).EnsCoccinelle[i].Position.x;
		y=(*potager).EnsCoccinelle[i].Position.y;
		//on met sont caractère dans le tableau
		tab[x][y]=(*potager).EnsCoccinelle[i].DessinMvt;
	}
}


//---------------------------------------------------------------------------------------------------------------------------------affichePotager---------------------//


void affichePotager(potager *potager){
	
	printf("\n");  
	char tomate; //le caractère de la tomate
	char p; //le caractère du puceron
	char c; //le caractère de la coccinelle
	char tabPuceron[N][N]; // tableau du format du potager, il contiendra les caractères des pucerons
	char tabCocci[N][N]; // tableau du format du potager, il contiendra les caractères des coccinelles
	TabNNespace(tabPuceron); // on les rempli d'espace
	TabNNespace(tabCocci);
	RemplirNNpuceron(potager, tabPuceron); //on met les pucerons dans un tableau NxN
	RemplirNNcocci(potager, tabCocci); //on met les coccinelles dans un tableau NxN
	
	
	//affichage potager (tomate et puceron):
	for (int i=0;i<N;i++){
		
		for (int j=0;j<N;j++){
			tomate=(*potager).Tomate[i][j].Maturite;
			p=tabPuceron[i][j];
			c=tabCocci[i][j];
			//on affiche :
			printf("\033[47;31m%c",c); //couleur rouge pour coccinelles
			if (tomate=='O'){
				printf("\033[47;31m%c",tomate);//couleur rouge pour tomate 
			}else{
				printf("\033[47;32m%c",tomate);//couleur verte pour tomate 
			}
			printf("\033[47;32m%c ",p); //couleur verte pour pucerons
			printf("\033[0m"); //remet la couleur normale
			
		}
		printf("\n");
		
	}	
	
}


//------------------------------------------------------------------------------------------------------------------------------affichageSurDemande------------------------//

void affichageSurDemande(int affichage,potager *potager){
		int oui_non;
		if (affichage==1){ //si tous les affichages
			affichePotager(potager); // on affiche le potager
		}else if (affichage==2){ //sinon on pose la question
			printf("\nAffichage du tour? (0:non , 1:oui)\n");
			scanf("%d",&oui_non);
			if(oui_non){
				affichePotager(potager); // on affiche le potager
			}
		}
}





