
#define N 30 //taille matrice potager
#define NbPuceron 10 //nombre puceron

#include <stdio.h>
#include <stdlib.h>


typedef struct {
		int x;
		int y;
		
		} coord;
		
typedef struct {
		 coord position;
		 int AMange;
		 int vie;
		 char mvt;
		 
		 } puceron;
		 
typedef struct {
		 char maturite;
		 int JRepousse;
		 
		 }tomate;
		 
typedef struct {

		tomate Tomate[N][N];           
		puceron EnsPuceron[NbPuceron]; //ensemble puceron
		int nbPuceronVie;
		
		}potager;
		 
		

			
