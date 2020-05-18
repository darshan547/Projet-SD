#include <stdio.h>
#include <stdlib.h>
#include "graphe_zones.h"



Cellule_som * ajoute_liste_sommet(Sommet *s, Cellule_som *som){
    Cellule_som * tmp = (Cellule_som *) malloc(sizeof(Cellule_som));
    
    tmp->sommet = s;
    tmp->suiv = som;
    
    return tmp;
}


void detruit_liste_somme(Cellule_som *som){

    Cellule_Sommet *tmp = som;
    
    while(tmp){ //tant tmp ne vaut pas null
        som = tmp->suiv; // on stock la suite de la liste
        
        free(tmp); // on désalloue l'element courant de la liste 
        tmp = som; // on recupere dans tmp la liste stocker dans som 
    
    }

}


void ajoute_voisin(Sommet *s1, Sommet *s2){
    
    s1->sommet_adj = ajoute_liste_sommet(s2, s1->sommet_adj); // ajout le sommet s2 dans la liste des sommets adjacents de s1
    s2->sommet_adj = ajoute_liste_sommet(s1, s2->sommet_adj);  // ajout le sommet s1 dans la liste des sommets adjacents de s2

}

int adjacent(Sommet *s1, Sommet *s2){
    int s1_s2 = 0; //boolean initialiser à 0 pour dire que s2 n'est pas adjacent à s1 
    int s2_s1 = 0; //boolean initialiser à 0 pour dire que s1 n'est pas adjacent à s2
    
    Cellule_som * tmp = s1->sommet_adj; // recupere la liste adjacent de s1
    
   
    while(tmp){  //parcours dans la liste adjacent de s1
        if(tmp->sommet == s2){ // s2 est adjacent à s1
            s1_s2 = 1; //on met le boolean a 1
            break;
        }
        
        tmp = tmp->suiv;
    }
    
    tmp = s2->sommet_adj; // recupere la liste adjacent de s2
    
    while(tmp){ //parcours dans la liste adjacent de s2
        if(tmp->sommet == s1){ // s1 est adjacent à s2
            s2_s1 = 1; //on met le boolean a 1
            break;
        }
        
        tmp = tmp->suiv;
    }
    
    return (s1_s2 && s2_s1) ? 1 : 0;
}



