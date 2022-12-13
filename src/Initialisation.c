#include "structure.h"
#include "fonctionBase.h"
#include "Initialisation.h"


//initialiser une tomate mure
void IniTomates(tomate*tomate){
	(*tomate).Maturite='O';
	(*tomate).JRepousse=5;
}

//initialiser le potager tomate
void IniPotagerTomate(potager*potager){
	tomate tomate;   	//declaration d'une tomate
	IniTomates(&tomate);	//on lui initie ses valeurs
	//on remplit le champ
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			(*potager).Tomate[i][j]=tomate; //on la plante dans sa case 
		}
	}
}

//initialisation d'un puceron

//A CHANGER, PREND EN PARAM POSITION, MVT ET DESSIN MVT
void IniPuceron(puceron*puceron, coord position){
	coord position;
	
	(*puceron).Position=position;
	(*puceron).AMange=0;
	(*puceron).Vie=10;
	(*puceron).Mvt=random;
	(*puceron).DessinMvt='<'; //a changer, mis ca pour test
}





//mouvement du puceron définit aléatoirement            //A CHANGER, pour le moment jsp encore comment, dc laisse comme ça
/*char RandMvt(){
	int mvtNb=rand()%4
	char mvt;
	if (mvtNb==0){
		mvt="<";
		}
	else if(mvtNb==1{
		mvt=">";
		}
	else if(mvtNb==2){
		mvt="∧";
		}
	else if(mvtNb==3){
		mvt="v";
		}                               
		return mvt;
}
*/



void RandPosPuc(coord*position){
	(*position).x= rand()%N;
	(*position).y=rand()%N;
	}
	

// CHANGER CAR INIPUCERON A CHANGE
void RemplissagePotagerPuceron(potager*potager){
	int flag;
	int position; //contiendra la position du puceron
	int mvt;	//contiendra le mvt du puceron
	char dessin;	//contiendra le dessin du puceron
	(*potager).NbPuceronVie=0;      //initie le nombre de puceron dans le champ à 0
	puceron P;			//declaration d'un puceron
	
	//on veut mettre NbPuceron dans le champ:
	for(int i=0;i<NbPuceron;i++){
		do{
			
			RandPosPuc(&position); //position aléatoire
			flag=VerifPasPuceron(P.Position,potager); //regarde si un puceron est déjà sur cette case
		}while(!flag);
		
		//quand on a trouvé une case libre on créé le puceron
		mvt= rand()%8;  //mouvement au hasard
			
			//
			// ...application fonction qui traduit mvt en dessin
			//
		IniPuceron(&P,position,mvt,dessin);   //initie le puceron	
		AjoutPuceron(&P, potager); //ajout du puceron dans le champ	
		
	}
}

//IL FAUT CREE LA FONCTION AJOUT PUCERON, VOIR SCRIPT CI-DESSOUS
	
/*//si la case est libre, on met le puceron :
		(*potager).EnsPuceron[i]=P;		
		(*potager).NbPuceronVie++;*/		





