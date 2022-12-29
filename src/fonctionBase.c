#include "structure.h"
#include "fonctionBase.h"

		
//==============================================================================================================================================================================================//

//------------------------------------------------------------------------------------------------------------------------------VerifSiTomate-----------------//

int VerifSiTomate(coord *position, potager* potager){
	int flag=1;
	int x= (*position).x;
	int y= (*position).y;
	if ( (*potager).Tomate[x][y].JRepousse <5 ){ //si la tomate est présente
		flag=0;
	}
	return flag;
}

//------------------------------------------------------------------------------------------------------------------------------VerifPasPuceron-----------------//

int VerifPasPuceron(coord *position ,potager *potager){
	int flag=1;
	int i=0;
	while(i<(*potager).NbPuceronVie && flag){
	
		if((*position).x==(*potager).EnsPuceron[i].Position.x && (*position).y==(*potager).EnsPuceron[i].Position.y){
			flag=0;
			
		}
		i++;
	}
	return flag;
}

//------------------------------------------------------------------------------------------------------------------------------VerifPasPuceronInd-----------------//

int VerifPuceronInd(coord *position ,potager *potager, int * indice){
	int flag=0; // on part du principe qu'il n'y a pas de puceron
	int i=0;
	while(i<(*potager).NbPuceronVie && !flag){
	
		if((*position).x==(*potager).EnsPuceron[i].Position.x && (*position).y==(*potager).EnsPuceron[i].Position.y){
			flag=1; // il y a un puceron
			*indice=(*potager).EnsPuceron[i].Id; //on récupère l'indice du puceron qui se situe sur la case
			
		}
		i++;
	}
	return flag;
}


//------------------------------------------------------------------------------------------------------------------------------VerifPasCocci-----------------//

int VerifPasCocci(coord *position ,potager *potager){
	int flag=1;
	int i=0;
	while(i<(*potager).NbCoccinelleVie && flag){
	
		if((*position).x==(*potager).EnsCoccinelle[i].Position.x && (*position).y==(*potager).EnsCoccinelle[i].Position.y){
			flag=0;
			
		}
		i++;
	}
	return flag;
}
		
		

//==============================================================================================================================================================================================//


//------------------------------------------------------------------------------------------------------------------------------PositionSansPuceron-----------------//

void PositionSansPuceron(coord *position, potager *potager){
	
	if( (*potager).NbPuceronVie < N*N ){ //on ne peut pas chercher une position qui n'existe pas (boucle infini)
		int flag;
		do{		
			RandPos(position); //position aléatoire
			flag=VerifPasPuceron(position,potager); //regarde si un puceron est déjà sur cette case
			}while(!flag);
	} else {
		printf("\nPlus de place sans puceron\n");
	}
}


//------------------------------------------------------------------------------------------------------------------------------AjoutPuceron-----------------//

void AjoutPuceron( insecte *puceron, potager *potager){
		(*potager).EnsPuceron[(*potager).NbPuceronVie]=*puceron;		
		(*potager).NbPuceronVie++;	
}

//------------------------------------------------------------------------------------------------------------------------------MortPuceron-----------------//

void MortPuceron(int identifiant,potager*potager){
	if (identifiant!=(*potager).NbPuceronVie-1){
		EchangeTableauPuceron(potager,identifiant);  //echanger case du puceron mort avec case du dernier puceron 
	}
	(*potager).NbPuceronVie=(*potager).NbPuceronVie-1;  //on réduit de 1 le nombre de puceron en vie
}

//------------------------------------------------------------------------------------------------------------------------------EchangeTableauPuceron-----------------//

void EchangeTableauPuceron(potager*potager,int indice){
	int dernier=(*potager).NbPuceronVie-1;
	insecte info=(*potager).EnsPuceron[indice];
	(*potager).EnsPuceron[indice]=(*potager).EnsPuceron[dernier];
	(*potager).EnsPuceron[dernier]=info;
	(*potager).EnsPuceron[indice].Id=indice;
	(*potager).EnsPuceron[dernier].Id=dernier;
}
	
//==============================================================================================================================================================================================//


//------------------------------------------------------------------------------------------------------------------------------PositionCocci-----------------//

void PositionSansCocci(coord *position, potager *potager){
	
	if( (*potager).NbCoccinelleVie < N*N ){ //on ne peut pas chercher une position qui n'existe pas (boucle infini)
		int flag;
		do{		
			RandPos(position); //position aléatoire
			flag=VerifPasCocci(position,potager); //regarde si un puceron est déjà sur cette case
			}while(!flag);
	} else {
		printf("\nPlus de place sans coccinelles\n");
	}
}


//------------------------------------------------------------------------------------------------------------------------------AjoutCocci-----------------//

void AjoutCocci( insecte *cocci, potager *potager){
		(*potager).EnsCoccinelle[(*potager).NbCoccinelleVie]=*cocci;		
		(*potager).NbCoccinelleVie++;	
}

//------------------------------------------------------------------------------------------------------------------------------MortCocci-----------------//

void MortCocci(int identifiant,potager*potager){
	if (identifiant!=(*potager).NbCoccinelleVie-1){
		EchangeTableauCocci(potager,identifiant);  //echanger case de la coccinelle morte avec case de la derniere coccinelle 
	}
	(*potager).NbCoccinelleVie=(*potager).NbCoccinelleVie-1;  //on réduit de 1 le nombre de puceron en vie
}

//------------------------------------------------------------------------------------------------------------------------------EchangeTableauCocci-----------------//

void EchangeTableauCocci(potager*potager,int indice){
	int dernier=(*potager).NbCoccinelleVie-1;
	insecte info=(*potager).EnsCoccinelle[indice];
	(*potager).EnsCoccinelle[indice]=(*potager).EnsCoccinelle[dernier];
	(*potager).EnsCoccinelle[dernier]=info;
	(*potager).EnsCoccinelle[indice].Id=indice;
	(*potager).EnsCoccinelle[dernier].Id=dernier;
}


		
//==============================================================================================================================================================================================//


//------------------------------------------------------------------------------------------------------------------------------TraductionMvtDessin-----------------//
		
void TraductionMvtDessin(int Mvt, char *DessinsMvt){
	
	//lire le rapport pour comprendre l'association chiffre-caractère
	
	if(Mvt==0 || Mvt==7){
		*DessinsMvt='\\'; /* double backslash necessaire sinon il attend la suite, comme \n ou \t, \\ indique qu'on veut le caractère \*/
	}
	else if(Mvt==1){
		*DessinsMvt='^';
	}
	else if(Mvt==2 || Mvt==5){
		*DessinsMvt='/';
	}
	else if(Mvt==3){
		*DessinsMvt='<';
	}
	else if(Mvt==4){
		*DessinsMvt='>';
	}
	else if(Mvt==6){
		*DessinsMvt='v';
	}
}

//------------------------------------------------------------------------------------------------------------------------------MotifTomate-----------------//

void MotifTomate(int JRepousse,char*Maturite){
	if(JRepousse<=4){
		*Maturite='.';
	}
	else if (JRepousse>=5 && JRepousse<20){
		*Maturite='o';
	}
	else{
		*Maturite='O';
	}
}

//==============================================================================================================================================================================================//

//------------------------------------------------------------------------------------------------------------------------------MortTomate-----------------//


void MortTomate(tomate*tomate){
	(*tomate).JRepousse=0;
	(*tomate).Maturite='.';

}


//------------------------------------------------------------------------------------------------------------------------------RandPosPuc-----------------//

void RandPos(coord*position){
	(*position).x= rand()%N;
	(*position).y=rand()%N;
	}

//------------------------------------------------------------------------------------------------------------------------------RemplirInsecte-----------------//
			
void RemplirInsecte(insecte*puceron, int id ,coord position, int mvt,char dessin, int vie){
	
	(*puceron).Id=id;
	(*puceron).Position=position;
	(*puceron).AMange=0;
	(*puceron).Vie=vie;
	(*puceron).Mvt=mvt;
	(*puceron).DessinMvt=dessin;
}



