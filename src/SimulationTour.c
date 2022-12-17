#include "SimulationTour.h" 
#include "ListeCaseFiltre.h"
#include "fonctionBase.h"
#include "structure.h"

void Maturation1Tomate(tomate*tomate){
	char*maturite;
	(*tomate).JRepousse ++;
	maturite=&((*tomate).Maturite);
	MotifTomate((*tomate).JRepousse,maturite);	
}

void MaturationTouteTomate(potager*potager){
	tomate*Tomate;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			Tomate=&((*potager).Tomate[i][j]);//adresse tomate 
			Maturation1Tomate(Tomate);
		}
	}
}

void Puceron1Mange(insecte*puceron, potager*potager){
	tomate *Tomate;
	coord *pos=(&(*puceron).Position); //adresse de la position du puceron
	int SiTomate =VerifSiTomate(pos, potager);
	if (SiTomate){ 
		(*puceron).AMange++;
		int x=(*puceron).Position.x;
		int y=(*puceron).Position.y;		
		Tomate=&((*potager).Tomate[x][y]);
		MortTomate(Tomate);
	}
	else{
		(*puceron).AMange=0;
	}
}

void TousPuceronMange(potager*potager){
	insecte*puceron;
	for(int i=0;i<(*potager).NbPuceronVie;i++){
		puceron=&((*potager).EnsPuceron[i]);
		Puceron1Mange(puceron,potager);
	}
}

void reproduction1Puceron( insecte*puceron, potager *potager){
	
	// 1 : verifions si le puceron peut se reproduire et si il y a de la place sur le champ,
	// si oui, on continu les étapes

	if ( (*puceron).AMange >= 5 && (*potager).NbPuceronVie <N){ //il a mangé 5 tours d'affilé?

		//2 : on veut la liste des cases adjacentes au puceron,
		//c'est-à-dire les cases à une distance de 1 du puceron
		caseMvt tab[N];
		int nbcase;
		nbcase=listaNCase( (*puceron).Position, 1, tab); //récupère la longueur de la 'liste' et la 'liste' (tableau)
		
		
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
			
			insecte enfant;
			RemplirPuceron(&enfant,pos, mvt ,dessin);
			AjoutPuceron( &enfant, potager);
			
			//6 : s'il s'est reproduit, il devra attendre d'avoir remangé 5 tomates pour se reproduire encore une fois
			(*puceron).AMange=0;
	
		}
		
	}
}


void reproTousPuceron(potager*potager){
	insecte *puceron;
	int max=(*potager).NbPuceronVie; //on garde en memoire la valeur car elle bouge dans la boucle
	for (int i=0; i< max;i++){
	
		puceron= &((*potager).EnsPuceron[i]); //adresse du puceron
		reproduction1Puceron( puceron, potager);
	}

}


void Mvt1Puceron( insecte*puceron, potager *potager){
	
	coord *position;
	position=&((*puceron).Position); //adresse de la position
	
	// 1 : verifie qu'il n'y a pas de tomate mure sur sa case apres qu'elles aient poussé (si oui il ne bouge pas, sinon on continue dans la focntion)
	// et verifie qu'il existe une place sans puceron
	if ( 1-VerifSiTomate(position, potager) && (*potager).NbPuceronVie < 30 ){ // 1-verifSiTomate permet de faire 'non verif si tomate' 
		
		coord cases; //case où il ira potentiellement
		int *mvt;
		mvt =&((*puceron).Mvt); //adresse du mouvement du puceron
		
		// 2 : On continue le mouvement du puceron si possible
		CasesApresMvt(&cases, position, mvt); //recupère la position du puceron s'il continue sont mouvement
		printf("\ncontinue mvt\n");
		if ( VerifPasPuceron(&cases, potager) && VerifSiTomate(&cases, potager) ){ //si cette case est libre et a une tomate 
			(*puceron).Position=cases; //le puceron y va
		}
		
		// 3 : Si c'est pas possible on cherche une case attenantes qui respectent les conditions
		else {
		
			caseMvt tab[N];
			int nbcase;
			nbcase=listaNCase( (*puceron).Position, 1, tab); //récupère la longueur de la 'liste' et la 'liste' (tableau) des cases attenantes
			
			//4 : on applique un filtre pour ne récupérer que les cases attenantes sans puceron
			filtreCaseSansPuc(tab,&nbcase,potager);
			if ( nbcase == 0 ){ 
			
				/*
				// 5 : si il est entouré de puceron, il va sur une case au hasard libre
				coord caseHasard;
				PositionSansPuceron(&caseHasard, potager); //choix case au hasard libre
				(*puceron).Position=caseHasard; // on lui change sa position*/
				
			} else {
				//6 : sinon on applique un filtre pour ne récupérer que les cases attenantes avec tomate
				filtreCaseSansPuc(tab,&nbcase,potager);
				if ( nbcase == 0 ){ 
					/*// 7 : si il est entouré de tomate non mure ou avec puceron, il va sur une case au hasard libre
					//il existe le cas puceron sur une case avec tomate à cette étape car les descendants des pucerons de l'étape reproduction n'ont pas mangé
					coord caseHasard;
					PositionSansPuceron(&caseHasard, potager); //choix case au hasard libre
					(*puceron).Position=caseHasard; // on lui change sa position*/
				
				} else{
					// 8 : sinon choix d'une case attenante au hasard respectant les conditions
					int caseRand=rand()%nbcase; 
					char dessin;
					int mvtpuceron =tab[caseRand].Mvt; //recupère son mouvement
					(*puceron).Position= tab[caseRand].Position; //on lui change sa position
					(*puceron).Mvt= mvtpuceron; //on lui change son mouvement
					TraductionMvtDessin(mvtpuceron, &dessin); //recupère le dessin du mouvement
					(*puceron).DessinMvt= dessin; // on lui change son dessin
				} 	
			}
		}
	}
}


void MvtTousPuceron(potager *potager){
	insecte *puceron;
	for (int i=0; i<(*potager).NbPuceronVie;i++){
		puceron= &((*potager).EnsPuceron[i]); //adresse du puceron
		Mvt1Puceron( puceron, potager);
	}
}







