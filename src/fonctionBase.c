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


int VerifSiTomate(coord position, potager* potager){
	int flag=1;
	int x= position.x;
	int y= position.y;
	if ( (*potager).Tomate[x][y].JRepousse <5 ){ //si la tomate est non mure
		flag=0;
	}
	return flag;
}

int VerifPasPuceron(coord position ,potager *potager){
	int flag=1;
	int i=0;
	while(i<(*potager).NbPuceronVie && flag){
		if(position.x==(*potager).EnsPuceron[i].Position.x && position.y==(*potager).EnsPuceron[i].Position.y){
			flag=0;
		}
		i++;
	}
	return flag;
}
		

