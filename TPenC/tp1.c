
#include <stdio.h>  /*librairie pr avoir lire et ecrire*/
#include <math.h>



/* affiche bonjour */

void afficher(){
	printf("Hello !\n");
}


/* demande age à l'utilisateur */
int lireage(){
	int a;
	printf("Ecrire age:");
	scanf("%d",&a);
	return a;
}

/* min 2 valeur*/
int min2val(int a, int b){
	if (a<b){return (a);}
	else {return (b);}
}

/* ecrit racine poly 2*/
void ecriracine(float a,float b,float c){
	float d= b*b -4*a*c;
	/*return printf("%f", d);*/
	if (d >0 ){ printf("%f et %f \n", (-b +sqrtf(d))/(2*a) , (-b -sqrtf(d))/(2*a) );}
	else if (d==0){ printf("%f", -b/(2*a));}
	else{printf("pas reel\n");}
}

/*affiche bonjour en fonction age*/
void afficheBonjour(int age){
	/*if (age<0){printf("Bonjour bizarrerie à âge négatif? \n");}
	On n'a plus besoin de ca car c'est verifier avant que pas negatif*/
	if (age<8){printf("Bonjour bambin ! \n");}
	else if (age<18 ){printf("Bonjour mineur ! \n");}
	else if (age==18){printf("Bonjour tout jeune majeur ! \n");}
	else {printf("Bonjour adulte ! \n");}
	printf( "Tu as %d ans. \n",age);
	}
	

/* --------------------------------------------------------------------------------

			fonction main
----------------------------------------------------------------------------------*/	
	
/* Premiere version main pr afficher 10 fois bonjour*/
			/*
			int main() {
				for (int i=0;i<10;i++){
					afficher();
				}
				return 0;
			} */ 

/* Seconde version, dire bonjour en fonction age*/
			/*
			int main() {
				int age;
				do {
					age=lireage();
				} while(age <0);
				
				afficheBonjour(age);
				return 0;
			}*/

/* exo 1: min de 2 var*/
			/*int main(){
				int a; int b;
				printf("Ecrire a, puis b \n"); 
				scanf("%d",&a);
				scanf("%d",&b);
				printf(" le min est %d \n", min2val(a,b));
				return 0;
			}*/

/* exo 2: min de 3 var*/
			/*int main(){
				int a; int b; int c;
				int min;
				printf("Ecrire a, puis b et c \n"); 
				scanf("%d",&a);
				scanf("%d",&b);
				scanf("%d",&c);
				min= min2val(a,b);
				min=min2val(c,min);
				printf(" le min est %d \n", min);
				return 0;
			}*/

/* exo 3: signe produit */
			/*int main(){
				int a; int b; 
				char signe;
				printf("Ecrire a, puis b  \n"); 
				scanf("%d",&a);
				scanf("%d",&b);
				if ((a<0 || b<0 ) && !(a<0 && b<0)){signe ='-';}
				else {signe='+';}
				
				printf(" le signe du produit est %c. \n", signe);
				return 0;
			}*/





/*exo 4:  racine poly 2*/
			/*int main(){
				float a; float b; float c;
				printf("Ecrire a, puis b et c de ax**2+bx+c\n"); 
				scanf("%f",&a);
				scanf("%f",&b);
				scanf("%f",&c);
				if (a !=0){ecriracine(a,b,c);}
				else { printf("c'est un poly du second degres");}	
				return 0;
			}*/


/* exo 5: annee biss*/
		/*int main(){
			int a;
			printf("annee \n");
			scanf("%d", &a);
			if ((a%4 !=0 ) || (a%4==0 && a%100==0 && a%400!=0) ){ printf("pas bis\n ");}
			else{printf("bis \n");}
			return 0;
		}*/


/* exo 6: date*/
		int main(){
			int j1;int j2;int m1;int m2; int a1; int a2;
			int nbj1;  int nbj2;  int diff;
			int m; int a;
			printf("jjmmaaaa 2 fois \n");
			scanf("%2d%2d%4d",&j1,&m1,&a1);
			scanf("%2d%2d%4d",&j2,&m2,&a2);
			nbj1= j1+30*m1+365*a1;
			nbj2= j2+30*m2+365*a2;
			diff=nbj2-nbj1;
			printf("nb diff j %d \n",diff);
			a= diff/365;
			diff=diff-a*365;
			m=diff/30;
			diff=diff-m*30;
			printf("il y une diff de %d ans, %d mois, %d jours. \n", a,m,diff);
			
			return 0;
		}
		









