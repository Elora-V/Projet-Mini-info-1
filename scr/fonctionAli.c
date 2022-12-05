##include "structure.h"

//initialiser une tomate mure
void IniTomates(tomate*tomate){
	(*tomate).maturite="O";
	(*tomate).JRepousse=5;
}

//initialiser le potager tomate
void IniPotagerTomate(potager*potager){
	for(int i=0;i<N;i++){
		for(int j=0;i<N;i++){
			tomate tomate;
				(*potager).Tomate[i][j]=IniTomates(&tomate);
		}
	}
}

//initialisation d'un puceron
void IniPuceron(puceron*puceron){
	coord position;
	RandPosPuc(&position);
	(*puceron).coord=position;
	(*puceron).AMange=0;
	(*puceron).vie=10;
	(*puceron).mvt=RandMvt();
	}

//mouvement du puceron définit aléatoirement
char RandMvt(){
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
//srand( time( NULL ) );

//
void RandPosPuc(coord*position){
	(*position).x=rand()%N;
	(*position).y=rand()%N;
	}
	
/*void IniPotagerPuceron(potager*potager){
		for(int i=0;i<N;i++){
		for(int j=0;i<N;i++){
				(*potager).Puceron[i][j]=NULL;
		}
	}
}
*/

void RemplissagePotagerPuceron(potager*potager){
	int flag;
	(*potager).NbPuceronVie=0;
	for(int i=0;i<NbPuceron;i++){
		puceron P;
		do{
			IniPuceron(&P);
			flag=VerifPasPuceron(P);
		}while(!flag);
		int x=P.position.x;
		int y=P.position.y;
		(*potager).EnsPuceron[i]=P;
		(*potager).NbPuceronVie++;
	}
}

int VerifPasPuceron(puceron P,potager potager){
	int flag=1;
	int i=0;
	while(i<potager.nbPuceronVie && flag){
		puceron PuceTab=potager.EnsPuceron[i];
		if(P.position.x==PuceTab.position.x && .position.y==PuceTab.position.y){
			flag=0;
		}
		i++;
	}
	return flag;
}
		
		





