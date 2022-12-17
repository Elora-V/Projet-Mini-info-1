#include "structure.h"
#include "fonctionBase.h"

		
void EchangeTabCaseMvt( caseMvt tab[] , int indice1 , int indice2 ){
	
	//on garde en mémoire les valeurs à l'indice 1
	int x1= tab[indice1].Position.x;
	int y1= tab[indice1].Position.y;
	int mvt1= tab[indice1].Mvt;
	
	//on met les informations de indice 2 à indice 1
	tab[indice1]=tab[indice2];
	
	//on ecrit les informations de indice 1 dans indice 2
	tab[indice2].Position.x= x1;
	tab[indice2].Position.y= y1;
	tab[indice2].Mvt= mvt1;
	
}	


int VerifSiTomate(coord *position, potager* potager){
	int flag=1;
	int x= (*position).x;
	int y= (*position).y;
	if ( (*potager).Tomate[x][y].JRepousse <5 ){ //si la tomate est non mure
		flag=0;
	}
	return flag;
}

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
		

//position aleatoire
void RandPosPuc(coord*position){
	(*position).x= rand()%N;
	(*position).y=rand()%N;
	}

//position aléatoire du champ sans puceron
void PositionSansPuceron( coord *position, potager *potager){
	
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
			
		
		
void TraductionMvtDessin(int mvtNb, char *mvtDessin){
	
	
	*mvtDessin='<';       //a changer, par default pr tester
	/*if (mvtNb==0){
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
		return mvt;*/
}


//on remplit les informations d'un puceron
void RemplirPuceron(insecte*puceron,coord position, int mvt,char dessin){
	
	(*puceron).Position=position;
	(*puceron).AMange=0;
	(*puceron).Vie=10;
	(*puceron).Mvt=mvt;
	(*puceron).DessinMvt=dessin;
}


void AjoutPuceron( insecte *puceron, potager *potager){
		(*potager).EnsPuceron[(*potager).NbPuceronVie]=*puceron;		
		(*potager).NbPuceronVie++;	
}
	


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

void MortTomate(tomate*tomate){
	(*tomate).JRepousse=0;
	(*tomate).Maturite='.';

}

