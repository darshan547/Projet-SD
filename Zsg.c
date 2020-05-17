#include "Zsg.h"

#include <stdlib.h>
#include <stdio.h>

/* Initialise la structure */
void init_Zsg(Zsg **z , int dim , int nbcl){
  (*z)=malloc(sizeof(*(*z)));
  (*z)->dim = dim;
  (*z)->nbcl = nbcl;
  (*z)->Lzsg = NULL;
  (*z)->B = malloc(sizeof(*(*z)->B) * nbcl);
  printf(" ");
  for(int i=0 ; i<dim ; i++){
    (*z)->B[i]=NULL;
  }
  
  (*z)->App = malloc(sizeof(*(*z)->App) * dim);
  for(int i=0 ; i<dim ; i++){
    (*z)->App[i]=malloc(sizeof(*(*z)->App[i])*dim);
    for(int j=0 ; j<dim ; j++){
      (*z)->App[i][j]=-2;
    }
  }
}

void ajoute_Zsg(Zsg *z, int i, int j) {

  /*ajout à la zone*/
  ElementListe *element;
  element = malloc(sizeof(*element));
  if(element == NULL) {
    exit(1);
  }
	element->suiv = z->Lzsg;
	element->i = i;
	element->j = j;
	z->Lzsg = element;
	z->App[i][j]=-1 ;
	//printf("ajout dans la liste de la case (%d , %d)\n",i,j);
}

void ajoute_Bordure(Zsg *z, int i , int j , int cl){
  ElementListe *element;
  element = malloc(sizeof(*element));
  if(element == NULL) {
    exit(1);
  }
  /*on verifie si la case n'est pas déja dans la bordure et pas dans la liste Lzsg*/
	if(z->App[i][j] != cl && z->App[i][j] != -1){
		element->suiv = z->B[cl];
		element->i = i;
		element->j = j;
		z->B[cl] = element;
		z->App[i][j] = cl;
		//printf("ajout dans la bordure la case (%d , %d)\n",i,j);	
	}
}

int appartient_Zsg(Zsg *z , int i , int j){
  ListeCases ite = z->Lzsg;
  while(ite){
    if(ite->i == i && ite->j == j){
      return 1;
    }
    ite = ite->suiv;
  }
  return 0;
}

int appartient_Bordure(Zsg *z , int i , int j , int cl){
  ListeCases ite = z->B[cl];
  while(ite){
    if(ite->i == i && ite->j == j){
      return 1;
    }
    ite = ite->suiv;
  }
  return 0;
}

int agrandit_Zsg(int **M , S_Zsg *Z, int cl , int k , int l){
  int nb_modif=0;
  if(
    /*si les coordonée donnée ne dépassent pas les dimension de la matrice*/
  	k >= 0 && k <= (Z->dim)-1 && l >= 0 && l <= (Z->dim)-1){
	
	if(Z->App[k][l] != -1){
		ajoute_Zsg(Z,k,l);
		nb_modif++;
	}
	
	  /*case a droite*/
	  if(k < (Z->dim)-1){
		if( M[k+1][l] == cl && Z->App[k+1][l] != -1)
		  nb_modif += agrandit_Zsg(M,Z,cl,k+1,l);
		else
		  if(Z->App[k+1][l] == -2)
		    ajoute_Bordure(Z, k+1, l, M[k+1][l]);
	  }

	  /*case en bas*/
	  if(l < (Z->dim)-1){
		if( M[k][l+1] == cl && Z->App[k][l+1] != -1 )
		 nb_modif += agrandit_Zsg(M,Z,cl,k,l+1);
		else
		  if(Z->App[k][l+1] == -2)
		    ajoute_Bordure(Z, k, l+1, M[k][l+1]);
	  }

	  /*case a gauche*/
	  if(k > 0){
		if( M[k-1][l] == cl && Z->App[k-1][l] != -1 )
		  nb_modif += agrandit_Zsg(M,Z,cl,k-1,l);
		else
		  if(Z->App[k-1][l] == -2)
		    ajoute_Bordure(Z, k-1, l, M[k-1][l]);
	  }

	  /*case en haut*/
	  if(l > 0){
		if( M[k][l-1] == cl && Z->App[k][l-1] != -1 )
		  nb_modif += agrandit_Zsg(M,Z,cl,k,l-1);
		else
		  if(Z->App[k][l-1] == -2)
		    ajoute_Bordure(Z, k, l-1, M[k][l-1]);
	  }
	}
  return nb_modif;
}

