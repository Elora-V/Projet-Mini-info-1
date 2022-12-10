#ifndef Structure
#define Structure

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
		 coord Position;
		 int AMange;  //nombre de jours consécutifs où le pucerion a mangé
		 int Vie;     // vie du puceron, elle diminue de 1 à chaque tours
		 int Mvt;     // numéro de 0 à 7 correspondant à une direction (voir schéma rendu écrit)
		 char DessinMvt; //le caractère à dessiner
		 
		 } puceron;
		 
typedef struct {
		 char Maturite; //le caractère à dessiner
		 int JRepousse; //le nombre de jour depuis la dernières fois que la tomate a été mangé
		 
		 }tomate;
		 
typedef struct {

		tomate Tomate[N][N];   //le potager avec les informations des tomates        
		puceron EnsPuceron[N]; //ensemble des pucerons dans le potager
		int NbPuceronVie;      //nombre de puceron en vie
		
		}potager;
		 
typedef struct {
		
		coord Position; //coordonnée de la case
		int Mvt;        // mouvement associé pour l'atteindre ( de 0 à 7 )
		
		} caseMvt;

#endif	
