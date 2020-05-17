CC = gcc
CFLAGS = -W -Wall -Os `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`
EXEC = floodit floodit_partie1

all: $(EXEC)

api_genere_instance.o: api_genere_instance.c api_genere_instance.h
	$(CC) $(CFLAGS) -c api_genere_instance.c

api_grille.o: api_grille.c api_grille.h
	$(CC) $(CFLAGS) -c api_grille.c

liste_cases.o: liste_cases.c liste_cases.h
	$(CC) $(CFLAGS) -c liste_cases.c

Zsg.o: Zsg.c Zsg.h liste_cases.h
	 $(CC) $(CFLAGS) -c Zsg.c

fonctions.o: fonctions.c fonctions.h liste_cases.h Zsg.h
	$(CC) $(CFLAGS) -c fonctions.c

floodit.o: floodit.c
	$(CC) $(CFLAGS) -c floodit.c 

floodit: floodit.o liste_cases.o  api_grille.o api_genere_instance.o fonctions.o Zsg.o
	$(CC) -o floodit floodit.o liste_cases.o api_grille.o api_genere_instance.o fonctions.o Zsg.o $(LDFLAGS)

floodit_partie1.o: floodit_partie1.c
	$(CC) $(CFLAGS) -c floodit_partie1.c 

floodit_partie1: floodit_partie1.o liste_cases.o  api_grille.o api_genere_instance.o fonctions.o Zsg.o
	$(CC) -o floodit_partie1 floodit_partie1.o liste_cases.o api_grille.o api_genere_instance.o fonctions.o Zsg.o $(LDFLAGS)

clean:
	rm -f *.o $(EXEC)

