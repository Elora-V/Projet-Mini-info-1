#include "structure.h"
#include "fonctionBase.h" 
#include "Initialisation.h"
#include "ListeCaseFiltre.h"
#include "Affichage.h"
#include "SimulationTour.h"

int main(){
	
	srand( time( NULL ) );
	
	int maxTour;
	int t=0;
	printf( "\nCombien de tour au maximum voulez-vous faire ?\n");
	scanf("%d",&maxTour);
	
	//initialisation---------------------------------------------------
	
	potager potager; //declaration du potager
	IniPotagerTomate(&potager); //remplissage de tomate mure
	RemplissagePotagerPuceron(&potager); //remplissage de puceron
	printf( "\nEtat initial du potager : il y a %d pucerons. \n",potager.NbPuceronVie);
	affichePotager(&potager); // on affiche le potager
	
	//simulation des tours--------------------------------------------
	
	while ( t<maxTour && potager.NbPuceronVie != 0){
		
		printf(" \n ----------------------------------------------------------- \n                        Tour %d \n ----------------------------------------------------------- \n", t+1);
		
		// 1 : maturation tomate
		// 2 : mouvement puceron
		MvtTousPuceron(&potager);
		// 3 : nourriture puceron
		// 4 : reproduction puceron
		// 5 : veillissement puceron
		
		// 6 : affichage potager
		printf( "\nIl y a %d pucerons. \n",potager.NbPuceronVie);
		affichePotager(&potager); // on affiche le potager
		
		// 7 :incrémentation nombre de tour
		t++;	
	
	}
	
	
	return 0;

}

