#include "structure.h"
#include "fonctionBase.h" 
#include "Initialisation.h"
#include "ListeCaseFiltre.h"
#include "Affichage.h"
#include "SimulationTour.h"

int main(){
	
	srand( time( NULL ) );
	//initialisation
	
	potager potager; //declaration du potager
	IniPotagerTomate(&potager); //remplissage de tomate mure
	RemplissagePotagerPuceron(&potager); //remplissage de puceron
	printf( "\nEtat initial du potager : il y a %d pucerons. \n",potager.NbPuceronVie);
	affichePotager(&potager); // on affiche le potager
	
	
	
	
	
	return 0;

}

