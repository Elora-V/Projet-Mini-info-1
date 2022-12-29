
# faire make all, puis ./all

CC=gcc
flags=-Wall

# compiler le tout :----------
	
all: simulation

simulation:MainProjet.o SimulationTour.o Affichage.o ListeCaseFiltre.o fonctionBase.o Initialisation.o
	$(CC) MainProjet.o SimulationTour.o Affichage.o ListeCaseFiltre.o fonctionBase.o Initialisation.o -o all $(flags)

MainProjet.o: MainProjet.c SimulationTour.h Initialisation.h Affichage.h ListeCaseFiltre.h fonctionBase.h structure.h
	$(CC) -c MainProjet.c $(flags)



# compiler les sous-fichiers:--------------

Simulation.o: SimulationTour.c ListeCaseFiltre.h fonctionBase.h structure.h
	$(CC) -c SimulationTour.c $(flags)

Affichage.o: Affichage.c structure.h
	$(CC) -c Affichage.c $(flags)

ListeCase.o: ListeCaseFiltre.c fonctionBase.h structure.h
	$(CC) -c ListeCaseFiltre.c $(flags)

Initialisation.o: Initialisation.c fonctionBase.h structure.h
	$(CC) -c Initialisation.c $(flags)

fonctionBase.o: fonctionBase.c structure.h
	$(CC) -c fonctionBase.c $(flags)




# cible de nettoyage-------------

clean:
	rm -f *.o
	
mrpropre: 
	rm -f all
