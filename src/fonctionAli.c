##include "structure.h"

//initialiser une tomate mure
void IniTomates(tomate*tomate){
	(*tomate).maturite="O";
	(*tomate).JRepousse=5;
}

//initialiser le potager tomate
void IniPotagerTomate(potager*potager){
	for(int i=0;i<N;i++){
		for(int j=0;i<N;i++){
			tomate tomate;
				(*potager).Tomate[i][j]=IniTomates(&tomate);
		}
	}
}

//initialisation d'un puceron
void IniPuceron(puceron*puceron){
	coord position;
	RandPosPuc(&position);
	(*puceron).coord=position;
	(*puceron).AMange=0;
	(*puceron).vie=10;
	(*puceron).mvt=RandMvt();
	}

//mouvement du puceron définit aléatoirement
char RandMvt(){
	int mvtNb=rand()%4
	char mvt;
	if (mvtNb==0){
		mvt="<";
	}
	else if(mvtNb==1{
		mvt=">";
	}
	else if(mvtNb==2){
		mvt="∧";
	}
	else if(mvtNb==3){
		mvt="v";
	}                                //A CHANGER
		return mvt;
}
//srand( time( NULL ) );

//
void RandPosPuc(coord*position){
	(*position).x=rand()%N;
	(*position).y=rand()%N;
	}
	
/*void IniPotagerPuceron(potager*potager){
		for(int i=0;i<N;i++){
		for(int j=0;i<N;i++){
				(*potager).Puceron[i][j]=NULL;
		}
	}
}
*/

void RemplissagePotagerPuceron(potager*potager){
	int flag;
	(*potager).NbPuceronVie=0;
	for(int i=0;i<NbPuceron;i++){
		puceron P;
		do{
			IniPuceron(&P);
			flag=VerifPasPuceron(P.position,*potager);
		}while(!flag);
		int x=P.position.x;
		int y=P.position.y;
		(*potager).EnsPuceron[i]=P;
		(*potager).NbPuceronVie++;
	}
}

//Implémente la forme de la tomate en fontion de son jour de repousse
void MotifTomate(int JRepousse,char*Maturite){
	if(JRepousse<2){
		*Maturite='.';
	}
	else if (JRepousse>=2 && JRepousse<5){
		*Maturite='o';
	}
	else{
		*Maturite='O';
	}
}

//Assigne un symbole de mouvement à un chiffre
void DirectionMvt(int Mvt,char DessinsMvt){
	if(Mvt=0 || Mvt=7){
		DessinsMvt='\';
	}
	else if(Mvt=1){
		DessinsMvt='∧';
	}
	else if(Mvt=2 || Mvt=5){
		DessinsMvt='/';
	}
	else if(Mvt=3){
		DessinsMvt='<';
	}
	else if(Mvt=4){
		DessinsMvt='>';
	}
	else if(Mvt=6){
		DessinsMvt='v';
	}
}

//Mort d'une tomate
//Prend une tomate et renvoie son jour de repousse et son niveau de maturité
void MortTomate(tomate*tomate){
	(*tomate).JRepousse=0;  
	(*tomate).Maturite='.';  
}

//Faire Maturer une tomate
//Prend une tomate et renvoie son jour de repousse et sa maturité
void Maturation1Tomate(tomate*tomate){
	char*maturite;
	(*tomate).JRepousse ++;
	maturite=&((*tomate).Maturite);
	MotifTomate((*tomate).JRepousse,maturite);	
}

//Faire maturer toutes les tomates
//Prend le potager et renvoie le niveau de maturation
void MaturationTouteTomate(potager*potager){
	tomate*Tomate;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			Tomate=&((*potager).Tomate[i][j]);
			Maturation1Tomate();
		}
	}
}

//Nourrir un puceron
//Prend puceron et potager et renvoie si le puceron a mangé ou non
void Puceron1Mange(insecte*puceron, potager*potager){
	int SiTomate =VerifSiTomate((*puceron).Position, potager);
	if (SiTomate){ 
		(*puceron).AMange++;
		int x=(*puceron).Position.x;
		int y=(*puceron).Position.y;
		MortTomate(potager.Tomate[x][y]);
	}
	else{
		(*puceron).AMange=0;
	}
}

//Nourrir tous les pucerons
//prend le potager  
void TousPuceronMange(potager*potager){
	insecte*puceron;
	for(int i=0;i<(*potager).NbPuceronVie;i++){
		puceron=&((*potager).EnsPuceron[i]);
		Puceron1Mange(puceron,potager);
	}
}

//Faire vieillir un puceron
//Prend un puceron et renvoie ses points de vie
void Vieillissement1Puceron(insecte*puceron;potager*potager){
	(*puceron).vie=(*puceron).vie-1;
	if((*puceron).vie==0){
		MortPuceron((*puceron).identifiant;potager);
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

//Mort d'un puceron
//Prend le potager et un puceron et modifie sa "case"
void MortPuceron(int identifiant,potager*potager){
	(*potager).EnsPuceron[identifiant].Vie=0;  //mettre la vie du puceron à 0
	EchangeTableauPuceron(potager,identifiant);  //echanger case du puceron mort avec case du dernier puceron 
	(*potager).NbPuceronVie=(*potager).NbPuceronVie-1;  //on réduit de 1 le nombre de puceron en vie
}

//Echanger le dernier puceron du tableau avec le puceron qui vient de mourrir
void EchangeTableauPuceron(potager*potager,int indice){
	int dernier=(*potager).NbPuceronVie-1;
	insecte info=(*potager).EnsPuceron[indice];
	(*potager).EnsPuceron[indice]=(*potager).EnsPuceron[dernier];
	(*potager).EnsPuceron[dernier]=info;
	(*potager).EnsPuceron[indice].Id=indice;
	(*potager).EnsPuceron[dernier].Id=dernier;
}



