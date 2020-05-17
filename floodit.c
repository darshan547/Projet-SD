#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "api_grille.h"
#include "api_genere_instance.h"

int main(int argc, char *argv[]) {
  clock_t temps_initial;  /* Temps initial en micro-secondes */
  clock_t temps_final;    /* Temps final en micro-secondes */
  float temps_cpu;        /* Temps total en secondes */
 
  if(argc != 5) {
    printf("Usage: %s dimension nb_de_couleurs niveau_difficulte graine\n",
           argv[0]);
    return 1;
  }

  int dim = atoi(argv[1]);
  int nbcl = atoi(argv[2]);
  int nivdif = atoi(argv[3]);
  int graine = atoi(argv[4]);

  /* Generation de l'instance */
  int **M = malloc(dim * sizeof(*M));
  if(M == NULL) {
    exit(1);
  }

  int i;
  for(i = 0; i < dim; i++) {
    M[i] = malloc(dim * sizeof(*M[i]));
    if(M[i] == NULL) {
      exit(1);
    }
  }

  gi_genere_matrice(dim, nbcl, nivdif, graine, M);

  /* Affichage de la grille */

  Grille *G = grille_init(dim,nbcl, 500);

  grille_ouvre_fenetre(G);

  for(i = 0;i<dim;i++) {
    int j;
    for(j = 0; j < dim; j++) {
      grille_attribue_couleur_case(G, i, j, M[i][j]);
    }
  }
  grille_redessine(G);
 
  /* 
     A VOUS DE JOUER
     
     
     
     
  */

  grille_attente_touche();
  grille_ferme_fenetre(G);
  grille_free(G);

  return 0;
}
