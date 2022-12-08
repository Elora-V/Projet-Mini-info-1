
#define N 30 //taille matrice potager
#define NbPuceron 10 //nombre puceron initial

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
		int x;
		int y;
		
		} coord;
		
typedef struct {
		 coord position;
<<<<<<< HEAD
		 int AMange;  //nombre de jours consécutifs où le pucerion a mangé
		 int vie;     // vie du puceron, elle diminue de 1 à chaque tours
		 int mvt;     // numéro de 0 à 7 correspondant à une direction (voir schéma rendu écrit)
		 char Dessinmvt; //le caractère à dessiner
=======
		 int AMange;
		 int vie;
		 int mvt;
		 char dessin_mvt;
>>>>>>> 1a3da6edad438daa8b0418bc236a3deb7c0db25d
		 
		 } puceron;
		 
typedef struct {
		 char maturite; //le caractère à dessiner
		 int JRepousse; //le nombre de jour depuis la dernières fois que la tomate a été mangé
		 
		 }tomate;
		 
typedef struct {

		tomate Tomate[N][N];   //le potager avec les informations des tomates        
		puceron EnsPuceron[N]; //ensemble des pucerons dans le potager
		int nbPuceronVie;      //nombre de puceron en vie
		
		}potager;
		 
typedef struct {
		
		coord position; //coordonnée de la case
		int mvt;        // mouvement associé pour l'atteindre ( de 0 à 7 )
		
		} caseMvt;

			
