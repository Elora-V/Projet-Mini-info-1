#include "SimulationTour.h" 
#include "ListeCaseFiltre.h"
#include "fonctionBase.h"
#include "structure.h"


void reproductionPuceron( puceron*puceron, potager *potager){
	
	int caseRand;
	
	// 1 : verifions si le puceron peut se reproduire et si il y a de la place sur le champ,
	// si oui, on continu les étapes

	if ( (*puceron).AMange >= 5 && (*potager).NbPuceronVie <=N){ //il a mangé 5 tours d'affilé?

		//2 : on veut le liste des cases adjacentes au puceron,
		//c'est-à-dire les cases à une distance de 1du puceron
		caseMvt tab[N];
		int nbcase;
		nbcase=listaNCase( (*puceron).Positon , tab); //récupère la longueur de la 'liste' et la 'liste' (tableau)
		
		//3 : on applique un filtre pour ne récupérer que les cases attenantes sans puceron
		filtreCaseSansPuc(tab,&nbcase,potager);
		
		if (nbcase >0){
			//4 : on choisit une case au hasard, ça sera la position du puceron
			caseRand=rand()% nbcase;
			position pos=tab[caseRand].Position
			
			//5 : on ajoute un puceron
			
			
			
			
			//...(liaison avec fichier ini + changement position +changement dessin mvt)
			
			
			
			
			
		}
		//CHOIX:QUE FAIT ON SI REMPLIT DE PUCERON AUTOUR ? (pas repro ou repro sur une case aléatoire?)
	}
}

