#ifndef graph_Zone_H
#define graph_Zone_H

typedef struct sommet Sommet;

/*Element d'une liste chainee de pointeur sur sommets*/
typedef struct cellule_som{
	Sommet * sommet;
	struct cellule_som * suiv;
}Cellule_som

struct sommet{
	int num;	/*Numero du sommet (sert uniquement a l'affichage) */
	int cl;		/*Couleur d'origine du sommet-zone*/
	ListeCase cases;	/*Listes des cases de cette liste*/
	int nbcase_som;		/*Nombre de cases de cette liste*/

	Cellule_som * sommet_adj; /* Liste des aretes pointeurs sur les sommets adjacents*/
}

typedef struct graphe_zone{
	int nbsom;		/*Nombre de sommets dans le graphe*/
	Cellule_som * som; /*Liste chainee des sommets du graphe*/
	Sommet **mat; /*Matrice de pointeurs sur les sommets indiquant a quel sommet appartient une case (i,j) de la grille*/
}Graphe_zone;

Cellule_som* ajoute_liste_sommet(Sommet* s , Cellule_som* cs);

void detruit_liste_somme(Cellule_som* cs);


#endif /* graph_Zone_H */