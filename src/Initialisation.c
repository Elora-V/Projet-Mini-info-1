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

			


//initialisation puceron avec ses informations
void IniPuceron (puceron *puceron){
	coord position; //contiendra la position du puceron
	int mvt;	//contiendra le mvt du puceron
	char dessin;	//contiendra le dessin du puceron
	
	mvt=rand()%8 //on donne un mouvement au hasard
	TraductionMvtDessin(mvt, &dessin) //on récupère sa version dessinée
	
	PositionSansPuceron( &position, potager) //on recupère une position sans puceron
	
	RemplirPuceron(puceron, position,mvt,dessin)) //on remplit les informations
	
}	


void RemplissagePotagerPuceron(potager*potager){
	
	puceron puceron;		//declaration d'un puceron
	(*potager).NbPuceronVie=0;      //initie le nombre de puceron dans le champ à 0
				
	//on veut mettre NbPuceron dans le champ:
	for(int i=0;i<NbPuceron;i++){
		
		IniPuceron (&puceron)	
		AjoutPuceron(&P, potager); //ajout du puceron dans le champ	
		
	}
}

	





