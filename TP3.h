#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 8


////////////////// CREATION DE NOEUD /////////////////
/* Our Structur  */
struct treenode {
    int contenue;                  /* le contenue actuel dee nœud */
    struct treenode *parent;    /* Pointeur vers le parent */
    struct treenode *fils;     /* Pointeur vers le premier enfant */
    struct treenode *suivant;   /* Pointeur vers le frère suivant */
};




////////////////////////////CREATION DE GRAPHE ////////////////////////////////
struct Graph {
    int num_nodes;          /* Le nombre de sommets dans le graphe */
    int adj_matrix[MAX_NODES][MAX_NODES];   /* La matrice d'adjacence */
};


