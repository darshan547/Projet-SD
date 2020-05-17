
#ifndef ZSG_H
#define ZSG_H
#include "liste_cases.h"

typedef struct {
  int dim;	/*dimension de la grille*/
  int nbcl;		/*nombre de couleurs*/
  ListeCases Lzsg; /*Liste des cases de la zone Zsg*/
  ListeCases *B;  /*Tableau de listes de cases de la bordure*/
  int **App;	/*tableau a double entree des appartenances*/
} S_Zsg;

typedef S_Zsg Zsg;

/* Initialise la structure */
void init_Zsg(Zsg **z , int dim , int nbcl);

/* Ajoute une case dans la liste Lzsg */
void ajoute_Zsg(Zsg *z, int i, int j);

/*	Ajoute une case dans la bordure d'une couleur cl donnée	*/
void ajoute_Bordure(Zsg *z, int i , int j , int cl);

/*	Renvoie 1 si une case est dans LZsg	*/
int appartient_Zsg(Zsg *z , int i , int j);

/*	Renvoie 1 si une case est dans la bordure de couleur cl donnée	*/
int appartient_Bordure(Zsg *z , int i , int j , int cl);

int agrandit_Zsg(int **M, S_Zsg *Z, int cl , int k , int l);


#endif /* LISTE_CASES_H */
