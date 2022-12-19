#include "structure.h"
#include "fonctionBase.h"

		
//==============================================================================================================================================================================================//

//------------------------------------------------------------------------------------------------------------------------------VerifSiTomate-----------------//

int VerifSiTomate(coord *position, potager* potager){
	int flag=1;
	int x= (*position).x;
	int y= (*position).y;
	if ( (*potager).Tomate[x][y].JRepousse <5 ){ //si la tomate est non mure
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
		

//==============================================================================================================================================================================================//


//------------------------------------------------------------------------------------------------------------------------------RandPosPuc-----------------//

void RandPosPuc(coord*position){
	(*position).x= rand()%N;
	(*position).y=rand()%N;
	}

//------------------------------------------------------------------------------------------------------------------------------PositionSansPuceron-----------------//

void PositionSansPuceron(coord *position, potager *potager){
	
	if( (*potager).NbPuceronVie < N*N ){ //on ne peut pas chercher une position qui n'existe pas (boucle infini)
		int flag;
		do{		
			RandPosPuc(position); //position aléatoire
			flag=VerifPasPuceron(position,potager); //regarde si un puceron est déjà sur cette case
			}while(!flag);
	} else {
		printf("\nPlus de place sans puceron\n");
	}
}

//------------------------------------------------------------------------------------------------------------------------------RemplirPuceron-----------------//
			
void RemplirPuceron(insecte*puceron, int id ,coord position, int mvt,char dessin){
	
	(*puceron).Id=id;
	(*puceron).Position=position;
	(*puceron).AMange=0;
	(*puceron).Vie=10;
	(*puceron).Mvt=mvt;
	(*puceron).DessinMvt=dessin;
}

//------------------------------------------------------------------------------------------------------------------------------AjoutPuceron-----------------//

void AjoutPuceron( insecte *puceron, potager *potager){
		(*potager).EnsPuceron[(*potager).NbPuceronVie]=*puceron;		
		(*potager).NbPuceronVie++;	
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
	if(JRepousse<2){
		*Maturite='.';
	}
	else if (JRepousse>=2 && JRepousse<5){
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

void MortPuceron(int identifiant,potager*potager){
	(*potager).EnsPuceron[identifiant].Vie=0;  //mettre la vie du puceron à 0
	if (identifiant!=(*potager).NbPuceronVie-1){
		EchangeTableauPuceron(potager,identifiant);  //echanger case du puceron mort avec case du dernier puceron 
	}
	(*potager).NbPuceronVie=(*potager).NbPuceronVie-1;  //on réduit de 1 le nombre de puceron en vie
}


void EchangeTableauPuceron(potager*potager,int indice){
	int dernier=(*potager).NbPuceronVie-1;
	insecte info=(*potager).EnsPuceron[indice];
	(*potager).EnsPuceron[indice]=(*potager).EnsPuceron[dernier];
	(*potager).EnsPuceron[dernier]=info;
	(*potager).EnsPuceron[indice].Id=indice;
	(*potager).EnsPuceron[dernier].Id=dernier;
}

