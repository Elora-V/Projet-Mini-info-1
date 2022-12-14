#ifndef FonctionBase
#define FonctionBase

#include "structure.h"


void EchangeTabCaseMvt( caseMvt tab[] ,int indice1 , int indice2 );

int VerifSiTomate(coord *position, potager *potager);

int VerifPasPuceron(coord *position ,potager *potager);

void RandPosPuc(coord*position);

void PositionSansPuceron( coord *position, potager *potager);

void TraductionMvtDessin(int mvtNb, char *mvtdessin);

void RemplirPuceron(puceron*puceron,coord position, int mvt,char dessin);

void AjoutPuceron( puceron *puceron, potager *potager);



#endif
