
#include <stdio.h> 
#include <math.h>

/* ----------------------------------------------------------------------------


                                Exercice 1: table de multiplication                       
                                    
---------------------------------------------------------------------------------*/

/*------------ Version 1 : fonction affichant la table de 6 de 1 à 10: 6 * 1 = 6 ....*/
	/*int main(){
		for( int i=1; i<=10; i++){
		printf( "6 * %d = %d \n",i, i*6);
		}
		return 0;
	}*/



/*-------------Version 2: procedure affichant la table de 6*/

	/*necessaire sinon table6 non déclaré car fonction après le main : */
	/*void table6();  
	int main(){ 
		table6();	
		return 0;
	}
	
	void table6(){
		for( int i=1; i<=10; i++){
		printf( "6 * %d = %d \n",i, i*6);
		}
	}*/
	
/* --------------Version 3: affiche la table de n de 1 à 10*/
	/*void table(int n);  
	int main(){ 
		printf("vous voulez la table de :");
		int n;
		scanf("%d",&n);
		table(n);	
		return 0;
	}*/
	
	
void table(int n){
	for( int i=1; i<=10; i++){
	printf( "%d * %d = %d \n",n,i, i*n);
	}
}
	
/*-------------Version 4: affiche les table de 2 à 10*/
	/*int main(){ 
		for(int i=2;i<=10;i++){
			printf("table de %d : \n",i);
			table(i);	
			printf("\n \n \n");
			}
		return 0;
	}*/
	
/* -----------Version 5: affiche les tables entre deux nombres*/
	/*int main(){ 
			printf("Vous voulez les tables entre ... et ... (faire entrez entre les 2 chiffre) \n");
			int a;
			int b;
			scanf("%d",&a);
			scanf("%d",&b);
			for(int i=a;i<=b;i++){
				printf("table de %d : \n",i);
				table(i);	
				printf("\n \n \n");
				}
			return 0;
		}*/
			


/* ----------------------------------------------------------------------------


                                Exercice 2: nombre premier                      
                                    
---------------------------------------------------------------------------------*/	
/* regarde si nb est premier, nb entier positif, renvoie 0 si non premier, 1 si premier*/
int nbPrem(int nb){	
		if (nb ==0 || nb ==1){ return (0);} /* car 0 et 1 pas nb prem*/
		else{
			int j=2;
			while (j<=sqrt(nb)){  
				if(nb%j==0) {return (0);}; /*arret qd trouve un diviseur: pas premier */
				j++;
			}
			return (1);
		}
	}
	
/* ------------Version 1: nb premier de 0 à 100 */	
	/*int main(){
		int result; 
		for (int i=0; i<=100; i++){
			result=nbPrem(i); //1 si premier, 0 sinon
			if (result){
				printf("%d \n", i);
			}
		}
		return 0;
		} */
	
/*------------Version 2: affiche les 100 premiers nombres premiers*/

	/*int main(){
		int sum =0; //nombre de nb prem affiché
		int nb =0;   // parcours les chiffres de 0 à ...
		int result; //un booleen pr savoir si premiers
		while (sum<100){
			result=nbPrem(nb);
			if (result){
				printf("%d \n", nb);
				sum++;
			}
			nb++;
		}
		return (0);
	}*/
	
/*---------question 3 : plus complexe*/

/*---------question 4 : voir ma fonction nbPrem*/

/*---------Version 5 : compte le nombre de nombre premier entre a et b inclus*/

	int main(){
		printf("Vous voulez le nombre de nb premier entre ... et ... (faire entrez entre les 2 chiffre) \n");
		int a;
		int b;
		int sum=0; //compteur de nb prem
		scanf("%d",&a);
		scanf("%d",&b);
		for (int i=a; i<=b; i++){
			sum=sum+ nbPrem(i);	
		}
		printf("Le nombre de nombre premier est %d. \n",sum);
	return 0;
	}
	


	
	
	
	
	
	
	
	
	
	
	
