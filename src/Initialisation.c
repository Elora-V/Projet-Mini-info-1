#include "structure.h"
#include "fonctionBase.h"
#include "Initialisation.h"


//----------------------------------------------------------------------------------------------------------------------------------------IniTomates---------------------------//

void IniTomates(tomate*tomate){
	(*tomate).Maturite='O';
	(*tomate).JRepousse=20;
}

//----------------------------------------------------------------------------------------------------------------------------------------IniPotagerTomate-------------------------//


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
			


//----------------------------------------------------------------------------------------------------------------------------------------------IniPuceron----------------//


void IniPuceron (insecte *puceron,potager *potager){
	coord position; //contiendra la position du puceron
	int mvt;	//contiendra le mvt du puceron
	char dessin;	//contiendra le dessin du puceron
	int id= (*potager).NbPuceronVie;
	
	mvt=rand()%8; //on donne un mouvement au hasard
	TraductionMvtDessin(mvt, &dessin); //on récupère sa version dessinée
	
	PositionSansPuceron(&position, potager); //on recupère une position sans puceron
	
	RemplirInsecte(puceron,id, position,mvt,dessin,10); //on remplit les informations
	
}	

//----------------------------------------------------------------------------------------------------------------------------------------RemplissagePotagerPuceron--------------------//


void RemplissagePotagerPuceron(potager*potager){
	
	insecte puceron;		//declaration d'un puceron
	(*potager).NbPuceronVie=0;      //initie le nombre de puceron dans le champ à 0
				
	//on veut mettre NbPuceron dans le champ:
	for(int i=0;i<NbPuceron;i++){
	
		IniPuceron (&puceron,potager);
		AjoutPuceron(&puceron, potager); //ajout du puceron dans le champ	
		
	}
}



//----------------------------------------------------------------------------------------------------------------------------------------------IniCocci----------------//


void IniCocci (insecte *cocci,potager *potager){
	coord position; //contiendra la position de la coccinelle
	int mvt;	//contiendra le mvt de la coccinelle
	char dessin;	//contiendra le dessin de la coccinelle
	int id= (*potager).NbCoccinelleVie;
	
	mvt=rand()%8; //on donne un mouvement au hasard
	TraductionMvtDessin(mvt, &dessin); //on récupère sa version dessinée
	
	PositionSansCocci(&position, potager); //on recupère une position sans coccinelles
	
	RemplirInsecte(cocci,id, position,mvt,dessin,20); //on remplit les informations
	
}	

//----------------------------------------------------------------------------------------------------------------------------------------RemplissagePotagerCocci--------------------//


void RemplissagePotagerCocci(potager*potager){
	
	insecte cocci;		//declaration d'une coccinelle
	(*potager).NbCoccinelleVie=0;      //initie le nombre de coccinelle dans le champ à 0
				
	//on veut mettre NbCocci dans le champ:
	for(int i=0;i<NbCocci;i++){
	
		IniCocci(&cocci,potager);
		AjoutCocci(&cocci, potager); //ajout de la coccinelle dans le champ	
		
	}
}

	





