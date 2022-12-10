#include "structure.h"
#include "fonctionBase.h"

	
void testfonctionBase(){

	printf("je suis dans fonctionbase");
}
 /*	
void EchangeTabCaseMvt( caseMvt tab[] , int indice1 , int indice2 ){
	
	//on garde en mémoire les valeurs à l'indice 1
	int x1= tab[indice1].position.x;
	int y1= tab[indice1].position.y;
	int mvt1= tab[indice1].mvt;
	
	//on met les informations de indice 2 à indice 1
	tab[indice1]=tab[indice2];
	
	//on ecrit les informations de indice 1 dans indice 2
	tab[indice2]={ {x1,y1} , mvt1 };
	
}	


int VerifSiTomate(coord position, potager potager){
	int flag=1;
	int x= position.x;
	int y= position.y;
	if ( potager.Tomate[x][y].JRepousse <5 ){ //si la tomate est non mure
		flag=0;
	}
	return flag;
}

int VerifPasPuceron(coord position ,potager potager){
	int flag=1;
	int i=0;
	while(i<potager.nbPuceronVie && flag){
		puceron PuceTab=potager.EnsPuceron[i];
		if(position.x==PuceTab.position.x && position.y==PuceTab.position.y){
			flag=0;
		}
		i++;
	}
	return flag;
}
		
*/
