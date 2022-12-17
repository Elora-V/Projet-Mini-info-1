#ifndef SimulationTour
#define SimulationTour

#include "structure.h"

void Maturation1Tomate(tomate*tomate);
void MaturationTouteTomate(potager*potager);
void Puceron1Mange(insecte*puceron, potager*potager);
void TousPuceronMange(potager*potager);
void reproduction1Puceron( insecte*puceron, potager *potager);
void reproTousPuceron(potager*potager);
void Mvt1Puceron( insecte*puceron, potager *potager);
void MvtTousPuceron(potager *potager);

#endif
