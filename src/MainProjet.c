#include "structure.h"
#include "fonctionBase.h" 
#include "Initialisation.h"
#include "ListeCaseFiltre.h"
#include "Affichage.h"
#include "SimulationTour.h"


int main(){
	
	srand( time( NULL ) );
	//initialisation variable pour le choix de l'utilisateur----------------
	int maxTour;
	int t=0;
	int affichage;
	printf( "\nCombien de tour au maximum voulez-vous faire ?\n");
	scanf("%d",&maxTour);
	printf("Voulez-vous un affichage à tous les tours (1), un affichage seulement quand vous repondrez oui à la question posée à chaque tour (2), ou aucun affichage (3 ou autre chiffre)?\nL'option 2 permet d'afficher petit à petit les tours, au lieu que tout s'affiche, puis de devoir remonter dans la console pour voir le premier affichage.\nVous choissisez l'option :\n");
	scanf("%d",&affichage);
	
	
	
	//initialisation--------------------------------------------------------
	
	potager potager; //declaration du potager
	IniPotagerTomate(&potager); //remplissage de tomate mure
	RemplissagePotagerPuceron(&potager); //remplissage de puceron
	printf( "\nEtat initial du potager : il y a %d pucerons. \n",potager.NbPuceronVie);
	affichageSurDemande(affichage, &potager); // on affiche le potager

	
	//simulation des tours-----------------------------------------------------
	
	while ( t<maxTour && potager.NbPuceronVie != 0){
		
		printf(" \n ----------------------------------------------------------- \n                        Tour %d \n ----------------------------------------------------------- \n", t+1);
		
		// 1 : maturation tomate
		MaturationTouteTomate(&potager);
		// 2 : mouvement puceron
		MvtTousPuceron(&potager);
		// 3 : nourriture puceron
		TousPuceronMange(&potager);
		// 4 : reproduction puceron
		reproTousPuceron(&potager);
		// 5 : veillissement puceron
		
		// 6 : affichage potager en fonction de la réponse de l'utilisateur
		printf( "\nIl y a %d pucerons. \n",potager.NbPuceronVie);
		affichageSurDemande(affichage, &potager);
		
		
		// 7 :incrémentation nombre de tour
		t++;	
	
	}
	
	
	return 0;

}

