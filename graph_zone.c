#include "graph_zone.h"

#include <stdlib.h>
#include <stdio.h>



Cellule_som* ajoute_liste_sommet(Sommet* s , Cellule_som* cs){
	Cellule_som* ncs = malloc(sizeof(*ncs));
	ncs->sommet = s;
	ncs->suiv = cs;
	return ncs; 
}

void detruit_liste_somme(Cellule_som* cs){
	Cellule_som ite = cs;
	while(ite){
		Cellule_som tmp=ite;
		ite=ite->suiv;
		free(tmp);
	}
}

void ajoute_voisin(Sommet* s1, Sommet* s2){
	s1 -> sommet_adj = ajoute_liste_sommet(s2,s1->sommet_adj);
	s2 -> sommet_adj = ajoute_liste_sommet(s1,s2->sommet_adj);
}

int adjacent(Sommet* s1, Sommet* s2){
	Cellule_som ite1 = s1->sommet_adj;
	while(ite1){
		if(ite1->sommet == s2){
			return 1;
		}
		ite1 = ite1->suiv;
	}

	return 0;
}


