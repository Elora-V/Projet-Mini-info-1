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
	int introCocci;
	int t=1;
	int affichage;
	printf( "\nCombien de tour au maximum voulez-vous faire ?\n");
	scanf("%d",&maxTour);
	printf( "\nA quel tour voulez-vous ajouter les coccinelles (0 si vous les voulez dès le début) ?\n");
	scanf("%d",&introCocci);
	printf("Voulez-vous un affichage à tous les tours (1), un affichage seulement quand vous repondrez oui à la question posée à chaque tour (2), ou aucun affichage (3 ou autre chiffre)?\nL'option 2 permet d'afficher petit à petit les tours, au lieu que tout s'affiche, puis de devoir remonter dans la console pour voir le premier affichage.\nVous choissisez l'option :\n");
	scanf("%d",&affichage);
	
	
	
	//initialisation--------------------------------------------------------
	
	potager potager; //declaration du potager
	IniPotagerTomate(&potager); //remplissage de tomate mure
	RemplissagePotagerPuceron(&potager); //remplissage de puceron
	
	if (introCocci == 0){
		RemplissagePotagerCocci(&potager); //remplissage de coccinelle
		TousCocciMange(&potager); //mange puceron si sur une case avec puceron
	}
	printf( "\nEtat initial du potager : il y a %d pucerons et %d coccinelles. \n",potager.NbPuceronVie, potager.NbCoccinelleVie);
	affichageSurDemande(affichage, &potager); // on affiche le potager

	
	//simulation des tours-----------------------------------------------------
	
	while ( t<=maxTour && potager.NbPuceronVie != 0){
		
		printf(" \n ----------------------------------------------------------- \n                        Tour %d \n ----------------------------------------------------------- \n", t);
		
		if (introCocci == t){
			RemplissagePotagerCocci(&potager); //remplissage de coccinelle
			TousCocciMange(&potager); //mange puceron si sur une case avec puceron
		}
		
		// 1 : maturation tomate
		MaturationTouteTomate(&potager);
		// 2 : mouvement puceron
		MvtTousPuceron(&potager);
		// 3 : mouvement coccinelle
		MvtTousCocci(&potager);
		// 4 : nourriture coccinelle
		TousCocciMange(&potager); 
		// 5 : nourriture puceron
		TousPuceronMange(&potager);
		// 5 : reproduction puceron
		reproTousPuceron(&potager);
		TousCocciMange(&potager); //si nouveau puceron arive sur une case avec coccinelle il se fait manger
		// 6 : veillissement puceron
		VieillissementTousPuceron(&potager);
		// 7 : reproduction coccinelle
		reproTousCocci(&potager);
		TousCocciMange(&potager); // si ils arrivent sur une case avec coccinelle
		// 8 : veillisement coccinelle
		VieillissementTousCocci(&potager);
		// 9 : affichage potager en fonction de la réponse de l'utilisateur
		printf( "\nEtat initial du potager : il y a %d pucerons et %d coccinelles. \n",potager.NbPuceronVie, potager.NbCoccinelleVie);
		affichageSurDemande(affichage, &potager);
		
		
		// 10 :incrémentation nombre de tour
		t++;	
	
	}
	
	
	return 0;

}

