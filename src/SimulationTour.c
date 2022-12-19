#include "SimulationTour.h" 
#include "ListeCaseFiltre.h"
#include "fonctionBase.h"
#include "structure.h"


//=====================================================================================================================================================//


//----------------------------------------------------------------------------------------------------------Maturation1Tomate-------------------//

void Maturation1Tomate(tomate*tomate){
	char*maturite;
	(*tomate).JRepousse ++;
	maturite=&((*tomate).Maturite);
	MotifTomate((*tomate).JRepousse,maturite);	
}


//-------------------------------------------------------------------------------------------------------MaturationTouteTomate----------------------//

void MaturationTouteTomate(potager*potager){
	tomate*Tomate;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			Tomate=&((*potager).Tomate[i][j]);//adresse tomate 
			Maturation1Tomate(Tomate);
		}
	}
}

//=====================================================================================================================================================//


//----------------------------------------------------------------------------------------------------------Puceron1Mange-------------------//

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

//-------------------------------------------------------------------------------------------------------------TousPuceronMange----------------//

void TousPuceronMange(potager*potager){
	insecte*puceron;
	for(int i=0;i<(*potager).NbPuceronVie;i++){
		puceron=&((*potager).EnsPuceron[i]);
		Puceron1Mange(puceron,potager);
	}
}


//=====================================================================================================================================================//

//--------------------------------------------------------------------------------------------------------Mvt1Puceron---------------------//

void Mvt1Puceron( insecte*puceron, potager *potager){
	
	coord *position;
	position=&((*puceron).Position); //adresse de la position
	
	
	// 1 : verifie qu'il n'y a pas de tomate mure sur sa case apres qu'elles aient poussées (si oui il ne bouge pas, sinon on continue dans la focntion)
	// et verifie qu'il existe une place sans puceron
	if ( 1-VerifSiTomate(position, potager) && (*potager).NbPuceronVie < N*N ){ // 1-verifSiTomate permet de faire 'non verif si tomate' 
		
		coord cases; //case où il ira potentiellement
		int *mvt;
		mvt =&((*puceron).Mvt); //adresse du mouvement du puceron
		
		// 2 : On continue le mouvement du puceron si possible
		CasesApresMvt(&cases, position, mvt); //recupère la position du puceron s'il continue sont mouvement
		
		if ( VerifPasPuceron(&cases, potager) && VerifSiTomate(&cases, potager) ){ //si cette case est libre et a une tomate 
			(*puceron).Position=cases; //le puceron y va
		}
		
		// 3 : Si c'est pas possible on cherche une case attenantes qui respectent les conditions
		else {
		
			caseMvt tab[24];//au max on a 24 cases, voir le schema du rapport avec une distance de 3 pour la coccinelle
			int nbcase;
			nbcase=listaNCase( (*puceron).Position, 1, tab); //récupère la longueur de la 'liste' et la 'liste' (tableau) des cases attenantes
			
			//4 : on applique un filtre pour ne récupérer que les cases attenantes sans puceron
			
			filtreCaseSansPuc(tab,&nbcase,potager);	
			
			if ( nbcase != 0 ){ 
			
				//5 : si il y a des cases disponibles on applique un filtre pour ne récupérer que les cases attenantes avec tomate
				// s'il n'y a pas de cases disponibles autour il ne bouge pas
				
				int caseRand;
				char dessin;
				int mvtpuceron;
				caseMvt CaseChoisi;
				
				filtreCaseAvecTomate(tab, &nbcase ,potager);
				
				/*for (int l=0;l<nbcase;l++){
				
				printf("case sans puceron avec tomate %d: %d %d \n",l, tab[l].Position.x,tab[l].Position.y);
				}*/
				
				if ( nbcase == 0 ){ 
				
					// 6 : si il est entouré de tomate non mure, on prend quand même une case non mure
					//pour cela on doit refaire la liste de cases libres (pas très optimal)
					caseMvt tab2[24];
					int nbcase2;
					nbcase2=listaNCase( (*puceron).Position, 1, tab2);
					filtreCaseSansPuc(tab2,&nbcase2,potager);
					
					caseRand=rand()%nbcase2; 
					CaseChoisi=tab2[caseRand];
				
				} else{
					// 7 : sinon choix d'une case attenante au hasard respectant les conditions
					caseRand=rand()%nbcase; 
					CaseChoisi=tab[caseRand];
					
				} 
				
				mvtpuceron =CaseChoisi.Mvt; //recupère son mouvement
				(*puceron).Position= CaseChoisi.Position; //on lui change sa position
				(*puceron).Mvt= mvtpuceron; //on lui change son mouvement
				
				
				TraductionMvtDessin(mvtpuceron, &dessin); //recupère le dessin du mouvement
				
				
				(*puceron).DessinMvt= dessin; // on lui change son dessin	
			}
		}
	}
}


//---------------------------------------------------------------------------------------------------------MvtTousPuceron--------------------//

void MvtTousPuceron(potager *potager){
	insecte *puceron;
	for (int i=0; i<(*potager).NbPuceronVie;i++){
		puceron= &((*potager).EnsPuceron[i]); //adresse du puceron
		
		Mvt1Puceron( puceron, potager);
	}
}

//=====================================================================================================================================================//

//---------------------------------------------------------------------------------------------------------reproduction1Puceron--------------------//

void reproduction1Puceron( insecte*puceron, potager *potager){
	
	// 1 : verifions si le puceron peut se reproduire et si il y a de la place sur le champ,
	// si oui, on continu les étapes

	if ( (*puceron).AMange >= 5 && (*potager).NbPuceronVie < N*N){ //il a mangé 5 tours d'affilé?
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
			
			dessin='/';
			
			insecte enfant;
			RemplirPuceron(&enfant,pos, mvt ,dessin);
			AjoutPuceron( &enfant, potager);
			
			//6 : s'il s'est reproduit, il devra attendre d'avoir remangé 5 tomates pour se reproduire encore une fois
			(*puceron).AMange=0;
	
		}
		
	}
}

//---------------------------------------------------------------------------------------------------------reproTousPuceron--------------------//

void reproTousPuceron(potager*potager){
	insecte *puceron;
	int max=(*potager).NbPuceronVie; //on garde en memoire la valeur car elle bouge dans la boucle
	for (int i=0; i< max;i++){
		puceron= &((*potager).EnsPuceron[i]); //adresse du puceron
		reproduction1Puceron( puceron, potager);
	}

}

//Prend un puceron et renvoie ses points de vie
void Vieillissement1Puceron(insecte*puceron,potager*potager){
	(*puceron).vie=(*puceron).vie-1;
	if((*puceron).vie==0){
		MortPuceron((*puceron).Id,potager);
	}
}

//Faire vieillir tous les pucerons
void VieillissementTousPuceron(potager*potager){  
	insecte*puceron;
	for (int i=0,i<N,i++){
		puceron=&((*potager).EnsPuceron[i]);
		Vieillissement1Puceron(puceron);
	}
}



