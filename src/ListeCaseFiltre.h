#ifndef ListeCaseFiltre
#define ListeCaseFiltre

#include "structure.h"
//a faire




int listaNCase(coord position , int n , caseMvt tab[]);

void filtreCaseSansPuc( caseMvt tab[], int *nbCaseRempli , potager* potager);

void filtreCaseAvecTomate( caseMvt tab[], int *nbCaseRempli , potager *potager);

void CasesApresMvt(coord *cases, coord *position, int *mvt);


#endif
