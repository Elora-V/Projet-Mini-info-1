#include "SimulationTour.h" 
#include "ListeCaseFiltre.h"
#include "fonctionBase.h"
#include "structure.h"


void reproduction1Puceron( puceron*Puceron, potager *potager){

	
	
	// 1 : verifions si le puceron peut se reproduire et si il y a de la place sur le champ,
	// si oui, on continu les étapes

	if ( (*Puceron).AMange >= 5 && (*potager).NbPuceronVie <N){ //il a mangé 5 tours d'affilé?

		//2 : on veut la liste des cases adjacentes au puceron,
		//c'est-à-dire les cases à une distance de 1 du puceron
		caseMvt tab[N];
		int nbcase;
		nbcase=listaNCase( (*Puceron).Position, 1, tab); //récupère la longueur de la 'liste' et la 'liste' (tableau)
		
		
		//3 : on applique un filtre pour ne récupérer que les cases attenantes sans puceron
		filtreCaseSansPuc(tab,&nbcase,potager);
		
		
		if (nbcase >0){//si il existe au moins une case correspondante à nos condistions
			
			//4 : on choisit une case au hasard, ça sera la position du nouveau puceron
			int caseRand=rand()% nbcase;
			coord pos=tab[caseRand].Position;
			int mvt=tab[caseRand].Mvt;
			char dessin;
			TraductionMvtDessin(mvt, &dessin); //récupère la version dessin du mouvement
			
			//5 : on ajoute un puceron
			
			puceron enfant;
			RemplirPuceron(&enfant,pos, mvt ,dessin);
			AjoutPuceron( &enfant, potager);
	
		}
		
	}
}


void reproTousPuceron(potager*potager){
	puceron *puceron;
	int max=(*potager).NbPuceronVie; //on garde en memoire la valeur car elle bouge dans la boucle
	for (int i=0; i< max;i++){
	
		puceron= &((*potager).EnsPuceron[i]); //adresse du puceron
		reproduction1Puceron( puceron, potager);
	}

}

