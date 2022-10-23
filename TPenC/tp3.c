#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define N 4
#define M 5
#define tailleTab1D(n) sizeof(n)/sizeof(n[0])

//	     -
//	    - -
//	  -  |  -
//       -   .   -  Declarer fonction, puis definir la fonction
//      -----------   

/*Mes déclarations de fonctions: */

float IMC(float taille, float poids);

void liretable1D(int table[]);
void liretable1Df(float table[],int taille);

float moyennetable1D(int table[]);

int sumtable1D(int table[]);

int prodscalaire(int t1[N],int t2[N]);

void liretable2D(int nr, int nc,int table[nr][nc]);

int EleveMax(float tab[],int taille);

/*------------------------------------------------------------------------------------

                              Exo 1 : fonction
                             
--------------------------------------------------------------------------------------------------------*/                             

float IMC(float taille, float poids){
	return (poids/(powf(taille,2))) ; 
	}
	
/*int main(){
	float taille;
	float poids;
	printf("Ecrire taille en m:");
	scanf("%f",&taille);
	printf("puis poids en kg :");
	scanf("%f",&poids);
	float imc=IMC(taille, poids);
	printf("IMC de %f . \n",imc);
	return (0);
}*/


/*------------------------------------------------------------------------------------

                              Exo 2 : tableau 1
                             
--------------------------------------------------------------------------------------------------------*/                             

void liretable1D(int table[]){
	for(int i=0;i<N;i++){
		printf("%d ",table[i]);
	}
	printf("\n");
}

void liretable1Df(float table[],int taille){
	for(int i=0;i<taille;i++){
		printf("%f ",table[i]);
	}
	printf("\n");
}

//N def par 100 dans arguments précompliation

/*int main(){
	int table[N];
	for(int i=0; i<N;i++){
	table[i]=i+1;
	}
	liretable1D(table);
	printf("\n");
	return(0);
}*/


/*------------------------------------------------------------------------------------

                              Exo 3 : tableau 2
                             
--------------------------------------------------------------------------------------------------------*/                             
//N def par 40

float moyennetable1D(int table[]){
	int sum=0;
	int n=N;
	for(int i=0;i<n;i++){
		sum=sum+table[i];
	}
	return (sum/n);
}

/*int main(){
	srand(time(NULL));
	int tablAlea[N];
	for(int i=0;i<N;i++){
		tablAlea[i]=rand()%21;
	}
	liretable1D(tablAlea);
	printf("\n");
	float mean=moyennetable1D(tablAlea);
	printf("la moyenne est %f.\n",mean);
	return (0);
}*/

/*------------------------------------------------------------------------------------

                              Exo 4 : exo bonus tableau
                             
--------------------------------------------------------------------------------------------------------*/                             


//def N a 20

int sumtable1D(int table[]){
	int sum=0;
	for(int i=0;i<N;i++){sum=sum+table[i];} 
	return (sum);
}

int prodscalaire(int t1[],int t2[]){
	int result=0;
	for(int i=0;i<N;i++){
		result=result+ (t1[i]*t2[i]);
	}
	return (result);
}

/*int main(){
	int t1[N];
	int t2[N];
	t1[0]=0;
	t2[0]=39;
	for(int i=1;i<N;i++){
		t1[i]=t1[i-1]+2;	
	}
	for(int i=1;i<N;i++){
		t2[i]=t2[i-1]-2;	
	}
	printf("t1 : \n");
	liretable1D(t1);
	printf("t2 : \n");
	liretable1D(t2);
	
	int somme1=sumtable1D(t1);
	int somme2=sumtable1D(t2);
	printf("Somme t1 : %d, somme t2 : %d. \n",somme1,somme2);
	
	int t3[N];
	for(int i=0;i<N;i++){
		t3[i]=t1[i]+t2[i];
	}
	printf("\n t3 : \n");
	liretable1D(t3);
	
	int prodscal=prodscalaire(t1,t2);
	printf("\n Le produit scalaire de t1 et t2 est %d. \n", prodscal);
	
	return(0);
}*/





/*------------------------------------------------------------------------------------

                              Exo 5 : chaine caractère
                             
--------------------------------------------------------------------------------------------------------*/                             

/*int main(int argc, char *argv[]){
	
	printf("Bonjour %s !\n",argv[1]);
	
	return (0);
}*/




/*------------------------------------------------------------------------------------

                              Exo 6 : matrice 1
                             
--------------------------------------------------------------------------------------------------------*/   

void liretable2D(int nr, int nc,int table[nr][nc]){
	for (int i=0;i<nr;i++){
		for (int j=0;j<nc;j++){
			printf("%d  ",table[i][j]) ;
		}
		printf("\n");
	}
}
//def N par 4 et M par 5
/*int main(){
	int mat[N][M];
	int nb=0;
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			mat[i][j] = nb ;
			nb++;
		}
	}
	liretable2D(N,M,mat);
	printf("\n");
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			if (mat[i][j]%4==0){ mat[i][j]=0;}
		}
	}
	liretable2D(N,M,mat);
	return (0);
}*/



/*------------------------------------------------------------------------------------

                              Exo 7 : matrice 2
                             
--------------------------------------------------------------------------------------------------------*/  

int EleveMax(float tab[],int taille){  //renverra le premier eleve si plusieur on le max
	float max=0;
	int eleve;
	for(int i=0;i<taille;i++){
		if ( tab[i]>max){
			max=tab[i];
			eleve=i+1;
		}
	}
	return(eleve);
}                          
//N=5, M=4                          
/*int main(){
	int note[M][N]={ {12,13.5,8,11},
			{7.5,18,12,13.75},
			{6,8,15,17},
			{10.75,12,7,19},
			{14,10,12,12.75}};
	float m1=moyennetable1D(note[0]);
	float m2=moyennetable1D(note[1]);
	float m3=moyennetable1D(note[2]);
	float m4=moyennetable1D(note[3]);
	float m5=moyennetable1D(note[4]);
	printf(" moyenne eleve 1 : %f, \n moyenne eleve 2 : %f, \n moyenne eleve 3 : %f, \n moyenne eleve 4 : %f, \n moyenne eleve 5 : %f, \n",m1,m2,m3,m4,m5);
	float moyennes[M]={m1,m2,m3,m4,m5};
	liretable1Df(moyennes,M);
	int eleve=EleveMax(moyennes,M);
	printf("Le meilleur élève est le %d.\n",eleve);
	return (0);
}*/


//test taille tableau 2D
int main(){
	int matrice[45][3];
	int nbcol=tailleTab1D(matrice[0]);
	int tailTot= sizeof(matrice)/sizeof(matrice[0][0]); //nb case totale
	int nbligne= tailTot/nbcol;
	printf("ligne %d , col %d \n", nbligne, nbcol);
	return (0);
}

/*------------------------------------------------------------------------------------

                              Exo 8 : ballon d'or
                             
--------------------------------------------------------------------------------------------------------*/          




/*------------------------------------------------------------------------------------

                              Exo 9 : traitement d'image
                             
--------------------------------------------------------------------------------------------------------*/                             
                   


