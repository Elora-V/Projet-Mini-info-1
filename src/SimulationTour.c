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
//=====================================================================================================================================================//
//=====================================================================================================================================================//
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
		
		if ( VerifPasPuceron(&cases, potager) && VerifPasCocci(&cases, potager) && VerifSiTomate(&cases, potager) ){ //si cette case est libre et a une tomate 
			(*puceron).Position=cases; //le puceron y va
		}
		
		// 3 : Si c'est pas possible on cherche une case attenantes qui respectent les conditions
		else {
		
			caseMvt tab[24];//au max on a 24 cases, voir le schema du rapport avec une distance de 3 pour la coccinelle
			int nbcase;
			nbcase=listaNCase( (*puceron).Position, 1, tab); //récupère la longueur de la 'liste' et la 'liste' (tableau) des cases attenantes
			
			//4 : on applique un filtre pour ne récupérer que les cases attenantes sans pucerons et sans coccinelles
			
			filtreCaseSansPuc(tab,&nbcase,potager);	
			if (nbcase != 0 ){
				filtreCaseSansCocci(tab,&nbcase,potager);	
			}
			
			//5 : si il y a des cases disponibles on applique un filtre pour ne récupérer que les cases attenantes avec tomate
			// s'il n'y a pas de cases disponibles autour il ne bouge pas
			
			if ( nbcase != 0 ){ 
			
				int caseRand;
				char dessin;
				int mvtpuceron;
				caseMvt CaseChoisi;
				
				filtreCaseAvecTomate(tab, &nbcase ,potager);
				
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
		
		
		if (nbcase >0){//si il existe au moins une case correspondante à nos conditions
			
			//4 : on choisit une case au hasard, ça sera la position du nouveau puceron
			int caseRand=rand()% nbcase;
			coord pos=tab[caseRand].Position;
			int mvt=tab[caseRand].Mvt;
			int id = (*potager).NbPuceronVie;
			char dessin;
			TraductionMvtDessin(mvt, &dessin); //récupère la version dessin du mouvement
			
			//5 : on ajoute un puceron
			
			insecte enfant;
			RemplirInsecte(&enfant, id,pos, mvt ,dessin,11);  //11 pour compenser du vieillisement prématuré dans ce tour
			
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

//=====================================================================================================================================================//

//---------------------------------------------------------------------------------------------------------Vieillissement1Puceron--------------------//

void Vieillissement1Puceron(insecte*puceron,potager*potager,int *mort){
	*mort=0;
	(*puceron).Vie = (*puceron).Vie - 1;
	if( (*puceron).Vie <=0 ){
		*mort=1;
		MortPuceron((*puceron).Id,potager);
	}
}

//---------------------------------------------------------------------------------------------------------VieillissementTousPuceron--------------------//

void VieillissementTousPuceron(potager*potager){  
	insecte*puceron;
	int i=0;
	int mort;
	while (i < (*potager).NbPuceronVie ){
		puceron=&((*potager).EnsPuceron[i]);
		Vieillissement1Puceron(puceron,potager,&mort);
		if (mort){
			i--;  //si le puceron est mort, la case i contient un autre puceron, celui-ci doit aussi passer par la fonction vieillisement donc on recule i
		}
		i++;
	}
}

//=====================================================================================================================================================//
//=====================================================================================================================================================//
//=====================================================================================================================================================//
//=====================================================================================================================================================//


//----------------------------------------------------------------------------------------------------------Cocci1Mange-------------------//

void Cocci1Mange(insecte*cocci, potager*potager){
	tomate *Tomate;
	coord *pos=(&(*cocci).Position); //adresse de la position de la coccinelle
	int indicePuceron;
	int SiPuceron =VerifPuceronInd(pos ,potager, &indicePuceron);
	if (SiPuceron){ // si on a un puceron sur la case :
		(*cocci).AMange++;
		
		MortPuceron( indicePuceron, potager);
	}
	//pas de else car pas necessaire de manger 3 tours d'affilés
}

//-------------------------------------------------------------------------------------------------------------TousCocciMange----------------//

void TousCocciMange(potager*potager){
	insecte*cocci;
	for(int i=0;i<(*potager).NbCoccinelleVie;i++){
		cocci=&((*potager).EnsCoccinelle[i]);
		Cocci1Mange(cocci,potager);
	}
}


//=====================================================================================================================================================//

//--------------------------------------------------------------------------------------------------------Mvt1Cocci---------------------//

void Mvt1Cocci( insecte*cocci, potager *potager){
	
	// 1 : verifie qu'il existe une place sans coccinelle dans le potager, si il n'y a pas de place on est sûr qu'elle ne bougera pas
	
	if ( (*potager).NbCoccinelleVie < N*N ){ 
		
		coord cases; //case où elle ira potentiellement
		int *mvt;
		mvt =&((*cocci).Mvt); //adresse du mouvement de la coccinelle
		coord *position;
		position=&((*cocci).Position); //adresse de la position
	
		// 2 : On continue le mouvement de la coccinelle si possible
		
		CasesApresMvt(&cases, position, mvt); //recupère la position de la coccinelle si elle continue sont mouvement
		
		if ( VerifPasCocci(&cases, potager) && !VerifPasPuceron(&cases,potager) ){ //si cette case est libre et a un puceron (renvoi 'faux' de la fonction VerifPasPuceron)
			(*cocci).Position=cases; //elle y va
		}
		
		// 3 : Si c'est pas possible on cherche une case attenantes qui respectent les conditions
		
		else {
			caseMvt tab[24]; //contiendra des informations sur les cases où aller
			int nbcase; // 'taille' du tableau tab
			caseMvt tabLibre[24];//ce tableau conservera les informations des cases libres pour n=1, on ne veut appliquer aucun filtre sur le tableau
			int nbcaseLibre; // 'taille' du tableau tabLibre
			caseMvt tabInter[24];//ce tableau conservera les informations des cases dans le cas où un tableau intermediaire est necessaire (pour ne pas perdre d'informations et de ne pas recreer le tableau perdu)
			int nbcaseInter; // 'taille' du tableau tabInter
			
			caseMvt CaseChoisi; //la case choisi de la coccinelle dans un tableau de case pour une distance de 1
			int caseRand=-1; // valeur aléatoire pour la case choisie
			int mvtcocci; // le mouvement choisi
			char dessin; //le dessin choisi
			int Abouge=0; //on a pas bouge
			
			// 4 : Cas n=1 ------------------------------------------------------------------------------
			
			// recupère cases disponibles
			
			nbcase=listaNCase( (*cocci).Position, 1 , tab); //récupère la longueur de la 'liste' et la 'liste' (tableau) des cases à une distance 1 de la coccinelle
			filtreCaseSansCocci(tab,&nbcase,potager); // enleve les cases avec coccinelles
			
			if( nbcaseLibre !=0 ){ // si il y a au moins une case disponible on peut continuer la fonction (sinon on ne bouge pas)
				
				CopieTableauMvt(tab,nbcase, tabLibre,&nbcaseLibre ); //copie notre tableau tab dans tabLibre pour savoir les cases où on peut aller (car mouvement de 1 case)
				filtreCaseAvecPuc(tab, &nbcase ,potager); // enleve cases sans pucerons
				
				if ( nbcase != 0 ){ //si on a une case avec puceron : on y va
				
					ChoixCaseTabPosition( nbcase, tab, cocci ); //change la coccinelle de position en prenant une case au hasard dans le tableau
				}

			 	else {  
			 	
			 		// 5 : Cas n=2 (on a besoin de regarder plus loin) -----------------------------------
			 		nbcase=listaNCase( (*cocci).Position, 2 , tab); //récupère la longueur de la 'liste' et la 'liste' (tableau) des cases à une distance 2 de la coccinelle
					filtreCaseAvecPuc(tab,&nbcase,potager); // enleve cases sans pucerons
					if ( nbcase!=0) { 
						
						CopieTableauMvt(tabLibre,nbcaseLibre, tabInter,&nbcaseInter ); //le tableau inter prend la valuer de tabLibre
						filtreCaseMvtVersPuc( tab, & nbcase,  tabInter,&nbcaseInter); //on filtre le tableau de case à une distance 1, on garde celles qui vont vers un puceron
						if (nbcaseInter != 0) { // si on peut se diriger vers un puceron sans être déranger par une coccinelle sur le chemin : on y va
							
							ChoixCaseTabPosition( nbcaseInter, tabInter, cocci ); //change la coccinelle de position en prenant une case au hasard dans le tableau
							Abouge=1; //on a bougé donc veut pas faire le cas n=3
						}
						
					}
					
					if( !Abouge ) {
						
						// 6 : Cas n=3 (on regarde plus loin)
			 	
			 			nbcase=listaNCase( (*cocci).Position, 3 , tab); //récupère la longueur de la 'liste' et la 'liste' (tableau) des cases à une distance 3 de la coccinelle
						filtreCaseAvecPuc(tab,&nbcase,potager); // enleve cases sans pucerons
			 			if ( nbcase!=0) { // s'il existe des pucerons à 3 cases on veut aller vers eux
			 				
			 				CopieTableauMvt(tabLibre,nbcaseLibre, tabInter,&nbcaseInter ); //le tableau inter prend la valuer de tabLibre
							filtreCaseMvtVersPuc( tab, & nbcase,  tabInter,&nbcaseInter); //on filtre le tableau de case à une distance 1 (inter), on garde celles qui vont vers un puceron
							if (nbcaseInter!=0) { // si on peut se diriger vers un puceron sans être déranger par une coccinelle sur le chemin : on y va
				 				
				 				ChoixCaseTabPosition( nbcaseInter, tabInter, cocci ); //change la coccinelle de position en prenant une case au hasard dans le tableau
								
							}else{ //si on est deranger par coccinelle on va sur une case disponibles à coté au hasard
							
								ChoixCaseTabPosition( nbcaseLibre, tabLibre, cocci ); //change la coccinelle de position en prenant une case libre au hasard dans le tableau de distance 1
							}
			 			} else { // si il y a pas de puceron à 3 cases, on va sur une case disponibles à coté au hasard
			 	
							ChoixCaseTabPosition( nbcaseLibre, tabLibre, cocci ); //change la coccinelle de position en prenant une case libre au hasard dans le tableau de distance 1
						}
					}		
				}
			}
		}
	}
}	
				
							

//---------------------------------------------------------------------------------------------------------MvtTousCocci--------------------//

void MvtTousCocci(potager *potager){
	insecte *cocci;
	for (int i=0; i<(*potager).NbCoccinelleVie;i++){
		cocci= &((*potager).EnsCoccinelle[i]); //adresse de la coccinelle
		
		Mvt1Cocci( cocci, potager);
	}
}

//=====================================================================================================================================================//

//---------------------------------------------------------------------------------------------------------reproduction1Cocci--------------------//

void reproduction1Cocci( insecte*cocci, potager *potager){
	
	// 1 : verifions si la coccinelle peut se reproduire et si il y a de la place sur le champ,
	// si oui, on continu les étapes

	if ( (*cocci).AMange >= 3 && (*potager).NbPuceronVie < N*N){ //elle a mangé 5 tours d'affilé?
		//2 : on veut la liste des cases adjacentes à la coccinelle,
		//c'est-à-dire les cases à une distance de 1 
		caseMvt tab[N];
		int nbcase;
		nbcase=listaNCase( (*cocci).Position, 1, tab); //récupère la longueur de la 'liste' et la 'liste' (tableau)
		
		
		//3 : on applique un filtre pour ne récupérer que les cases attenantes sans puceron
		filtreCaseSansCocci(tab,&nbcase,potager);
		
		
		if (nbcase >0){//si il existe au moins une case correspondante à nos conditions
			
			//4 : on choisit une case au hasard, ça sera la position de la  nouvelle coccinelle
			int caseRand=rand()% nbcase;
			coord pos=tab[caseRand].Position;
			int mvt=tab[caseRand].Mvt;
			int id = (*potager).NbPuceronVie;
			char dessin;
			TraductionMvtDessin(mvt, &dessin); //récupère la version dessin du mouvement
			
			//5 : on ajoute une coccinelle
			
			insecte enfant;
			RemplirInsecte(&enfant, id,pos, mvt ,dessin,21);  //21 pour compenser du vieillisement prématuré dans ce tour
			
			AjoutCocci( &enfant, potager);
			
			//6 : si elle s'est reproduite, elle devra attendre d'avoir remangé 3 pucerons pour se reproduire encore une fois
			(*cocci).AMange=0;
	
		}
		
	}
}

//---------------------------------------------------------------------------------------------------------reproTousCocci--------------------//

void reproTousCocci(potager*potager){
	insecte *cocci;
	int max=(*potager).NbCoccinelleVie; //on garde en memoire la valeur car elle bouge dans la boucle
	for (int i=0; i< max;i++){
		cocci= &((*potager).EnsCoccinelle[i]); //adresse de la coccinelle
		reproduction1Cocci( cocci, potager);
	}

}

//=====================================================================================================================================================//

//---------------------------------------------------------------------------------------------------------Vieillissement1Puceron--------------------//

void Vieillissement1Cocci(insecte*cocci,potager*potager,int *mort){
	*mort=0;
	(*cocci).Vie = (*cocci).Vie - 1;
	if( (*cocci).Vie <=0 ){
		*mort=1;
		MortCocci((*cocci).Id,potager);
	}
}

//---------------------------------------------------------------------------------------------------------VieillissementTousPuceron--------------------//

void VieillissementTousCocci(potager*potager){  
	insecte*cocci;
	int i=0;
	int mort;
	while (i < (*potager).NbCoccinelleVie ){
		cocci=&((*potager).EnsCoccinelle[i]);
		Vieillissement1Cocci(cocci,potager,&mort);
		if (mort){
			i--;  //si la coccinelle est morte, la case i contient une autre coccinelle, celle-ci doit aussi passer par la fonction vieillisement donc on recule i
		}
		i++;
	}
}


