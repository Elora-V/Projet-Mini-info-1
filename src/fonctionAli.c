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
		}                                //A CHANGER
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
			flag=VerifPasPuceron(P.position,*potager);
		}while(!flag);
		int x=P.position.x;
		int y=P.position.y;
		(*potager).EnsPuceron[i]=P;
		(*potager).NbPuceronVie++;
	}
}


void Maturation1Tomate(tomate*tomate){
	#IniTomate(tomate*tomate); ?
	#PuceronMange(  ) ?
	(*tomate).JRepousse ++;
	if((*tomate).JRepousse<2){
		(*tomate).Maturite='.';
	}
	else if ((*tomate).JRepousse>2 && (*tomate).JRepousse<5){
		(*tomate).Maturite='o';
	}
	else{
		(*tomate).Maturite='O';
	}
}

void MaturationTouteTomate (potager*potager){
	...
	
}
				
void Puceron1Mange(insecte*puceron, potager*potager){
	int flag =VerifSiTomate((*puceron).Position, potager);
	if (flag){ 
		(*puceron).AMange++;
	}
}

void TousPuceronMange(){
	
	...
	
	
}

void Vieillissement1Puceron(insecte*puceron){
	(*puceron).vie=(*puceron).vie-1;
	}

void VieillissementTousPuceron(potager*potager){  /*je sais pas s'il faut rajouter EnsPuceron aussi en argumet*/
	int i;
	insecte *puceron;
	for (i=0,i<N,i++){
		puceron=&( (*potager).EnsPuceron[i] );
		Vieillissement1Puceron(puceron);
	}


void MortPuceron(insecte*puceron,potager * potager){
	(*puceron).Vie=0;
	...
}






