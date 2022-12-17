#ifndef Structure
#define Structure

#define N 30 //taille matrice potager
#define NbPuceron 10 //nombre puceron initial

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//-------------------------------------------------------------------------------------------------------------------------Structure d'une coordonnée (x,y)------------------//

typedef struct {
		int x; //numero de ligne
		int y; //numero de colonne
		
		} coord;

//-------------------------------------------------------------------------------------------------------------------------Structure d'un insecte------------------//
		
typedef struct {
		 coord Position;
		 int AMange;  //nombre de jours consécutifs où le pucerion a mangé
		 int Vie;     // vie du puceron, elle diminue de 1 à chaque tours
		 int Mvt;     // numéro de 0 à 7 correspondant à une direction (voir schéma rendu écrit)
		 char DessinMvt; //le caractère à dessiner
		 
		 } insecte;
	
	
//-------------------------------------------------------------------------------------------------------------------------Structure d'une tomate------------------//
 
typedef struct {
		 char Maturite; //le caractère à dessiner
		 int JRepousse; //le nombre de jour depuis la dernières fois que la tomate a été mangé
		 
		 }tomate;


//-------------------------------------------------------------------------------------------------------------------------Structure du potager------------------//
		 
typedef struct {

		tomate Tomate[N][N];   //le potager avec les informations des tomates        
		insecte EnsPuceron[N*N]; //ensemble des pucerons dans le potager
		int NbPuceronVie;      //nombre de puceron en vie
		
		}potager;
		

//-------------------------------------------------------------------------------------------------------------------------Structure caseMvt------------------//

//Cette structure est utile pour la recherche de case attenante.
		 
typedef struct {
		
		coord Position; //coordonnée de la case
		int Mvt;        // mouvement associé pour l'atteindre ( de 0 à 7 )
		
		} caseMvt;

#endif	
