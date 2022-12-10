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
void IniPuceron(puceron*puceron){
	coord position;
	int random= rand()%8;
	RandPosPuc(&position);
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
	


void RemplissagePotagerPuceron(potager*potager){
	int flag;
	(*potager).NbPuceronVie=0;      //initie le nombre de puceron dans le champ à 0
	puceron P;			//declaration d'un puceron
	
	//on veut mettre NbPuceron dans le champ:
	for(int i=0;i<NbPuceron;i++){
		do{
			IniPuceron(&P);   //initie le puceron
			flag=VerifPasPuceron(P.Position,potager); //regarde si un puceron est déjà sur cette case
		}while(!flag);
		//si la case est libre, on met le puceron :
		(*potager).EnsPuceron[i]=P;		
		(*potager).NbPuceronVie++;
	}
}

	
		





